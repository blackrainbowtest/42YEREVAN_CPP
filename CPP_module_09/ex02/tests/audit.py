#!/usr/bin/env python3
"""Audit production code and test-only value comparison instrumentation.
Run from any directory: python3 tests/audit.py
"""
from pathlib import Path
import os
import random
import re
import subprocess
import tempfile

ROOT = Path(__file__).resolve().parents[1]
FLAGS = ['-Wall', '-Wextra', '-Werror', '-std=c++98']
HARNESS = r'''
#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <iostream>
#include "instrumented.cpp"

static size_t check(const std::vector<int> &values)
{
    std::vector<int> reference(values);
    std::sort(reference.begin(), reference.end());
    std::vector<FJItem> v;
    std::deque<FJItem> d;
    for (size_t i = 0; i < values.size(); ++i)
    {
        v.push_back(FJItem(values[i], i));
        d.push_back(FJItem(values[i], i));
    }
    comparisons = 0;
    v = fordJohnsonRecursive(v);
    size_t vc = comparisons;
    comparisons = 0;
    d = fordJohnsonDeque(d);
    assert(vc == comparisons);
    assert(v.size() == reference.size() && d.size() == reference.size());
    std::vector<bool> seenV(values.size(), false), seenD(values.size(), false);
    for (size_t i = 0; i < values.size(); ++i)
    {
        assert(v[i].value == reference[i] && d[i].value == reference[i]);
        assert(v[i].id < values.size() && d[i].id < values.size());
        assert(!seenV[v[i].id] && !seenD[d[i].id]);
        seenV[v[i].id] = true;
        seenD[d[i].id] = true;
        assert(values[v[i].id] == v[i].value);
        assert(values[d[i].id] == d[i].value);
    }
    // Exercise the actual class wrappers independently of recursive helpers.
    PmergeMe p;
    p._vector = values;
    p._deque.assign(values.begin(), values.end());
    p.sortVector();
    p.sortDeque();
    assert(p._vector == reference);
    assert(std::vector<int>(p._deque.begin(), p._deque.end()) == reference);
    return vc;
}

int main(int argc, char **argv)
{
    int maxN = argc > 1 ? std::atoi(argv[1]) : 9;
    const size_t bounds[] = {0, 0, 1, 3, 5, 7, 10, 13, 16, 19};
    size_t cases = 0;
    for (int n = 0; n <= maxN; ++n)
    {
        std::vector<int> values;
        for (int i = 1; i <= n; ++i) values.push_back(i);
        size_t maximum = 0;
        do
        {
            size_t count = check(values);
            maximum = std::max(maximum, count);
            assert(count <= bounds[n]);
            ++cases;
        } while (std::next_permutation(values.begin(), values.end()));
        assert(maximum == bounds[n]);
        std::cout << "n=" << n << " worst comparisons=" << maximum << std::endl;
    }
    for (size_t n = 1; n <= 7; ++n)
    {
        size_t total = 1;
        for (size_t i = 0; i < n; ++i) total *= 3;
        for (size_t code = 0; code < total; ++code)
        {
            size_t rest = code;
            std::vector<int> values(n, 1);
            for (size_t i = 0; i < n; ++i)
            {
                values[i] += rest % 3;
                rest /= 3;
            }
            check(values);
            ++cases;
        }
    }
    std::srand(42);
    for (size_t trial = 0; trial < 300; ++trial)
    {
        std::vector<int> values(1 + std::rand() % 513, 1);
        for (size_t i = 0; i < values.size(); ++i)
            values[i] += std::rand() % 100;
        check(values);
        ++cases;
    }
    const size_t sizes[] = {3000, 3001, 10000};
    for (size_t k = 0; k < 3; ++k)
    {
        std::vector<int> values(sizes[k], 1);
        for (size_t i = 0; i < values.size(); ++i)
            values[i] += std::rand() % INT_MAX;
        values[0] = INT_MAX;
        check(values);
        std::sort(values.begin(), values.end());
        check(values);
        std::reverse(values.begin(), values.end());
        check(values);
        std::fill(values.begin(), values.end(), 7);
        check(values);
        cases += 4;
    }
    PmergeMe original;
    original._vector.push_back(42);
    original._deque.push_back(42);
    PmergeMe copied(original), assigned;
    assigned = original;
    original = original;
    original._vector[0] = 1;
    original._deque[0] = 1;
    assert(copied._vector[0] == 42 && copied._deque[0] == 42);
    assert(assigned._vector[0] == 42 && assigned._deque[0] == 42);
    for (size_t n = 0; n < 1000; ++n)
    {
        std::vector<size_t> order = makeJacobsthalOrder(n);
        assert(order.size() == (n ? n - 1 : 0));
        std::vector<bool> seen(n, false);
        for (size_t i = 0; i < order.size(); ++i)
        {
            assert(order[i] > 0 && order[i] < n && !seen[order[i]]);
            seen[order[i]] = true;
        }
    }
    std::cout << "PASS " << cases << " sequences; both containers, IDs, wrappers, canonical form, Jacobsthal coverage" << std::endl;
}
'''

def run(args, **kwargs):
    return subprocess.run([str(x) for x in args], cwd=ROOT, check=True, **kwargs)


def cli(binary):
    rng = random.Random(42)
    valid = [[1], [2, 1], [3, 1, 2], [3, 5, 9, 7, 4], [1, 2147483647, 1],
             list(range(1, 102)), list(range(100, 0, -1)), [7] * 3000]
    valid += [[rng.randint(1, 2147483647) for _ in range(n)] for n in (3000, 3001, 10000)]
    for values in valid:
        result = run([binary, *map(str, values)], capture_output=True, text=True)
        lines = result.stdout.splitlines()
        assert len(lines) == 4 and not result.stderr
        assert lines[0].startswith('Before:') and lines[1].startswith('After:')
        assert list(map(int, lines[0].split()[1:])) == values
        assert list(map(int, lines[1].split()[1:])) == sorted(values)
        for line, container in zip(lines[2:], ('vector', 'deque')):
            assert re.fullmatch(r'Time to process a range of ' + str(len(values)) +
                                r' elements with std::' + container + r':\s+\d+\.\d{5} us', line)
    invalid = [[], [''], ['0'], ['-1'], ['+1'], ['1a'], ['1.5'], ['1 2'],
               [' 1'], ['1 '], ['2147483648'], ['9' * 1000], ['1', 'bad', '2'], ['-0']]
    for values in invalid:
        result = subprocess.run([str(binary), *values], cwd=ROOT, capture_output=True, text=True)
        assert result.returncode != 0 and 'Error' in result.stderr and not result.stdout
    run([binary, '0001', '0002147483647'], capture_output=True)
    print('PASS CLI: 12 valid and 14 invalid cases', flush=True)


def main():
    run(['make', 're'])
    before = (ROOT / 'PmergeMe').stat().st_mtime_ns
    run(['make', 'all'])
    assert (ROOT / 'PmergeMe').stat().st_mtime_ns == before
    with tempfile.TemporaryDirectory(prefix='pmerge-audit-') as tmp:
        tmp = Path(tmp)
        source = (ROOT / 'src/PmergeMe.cpp').read_text()
        assert source.count('input[i].value <= input[i + 1].value') == 2
        assert source.count('mid->value < pending[index].value') == 2
        source = source.replace('input[i].value <= input[i + 1].value',
                                '(++comparisons, input[i].value <= input[i + 1].value)')
        source = source.replace('mid->value < pending[index].value',
                                '(++comparisons, mid->value < pending[index].value)')
        (tmp / 'instrumented.cpp').write_text('#include <cstddef>\nstatic size_t comparisons = 0;\n' + source)
        (tmp / 'PmergeMe.hpp').write_text((ROOT / 'include/PmergeMe.hpp').read_text().replace('private:', 'public:'))
        (tmp / 'harness.cpp').write_text(HARNESS)
        run(['c++', *FLAGS, '-O2', tmp / 'harness.cpp', '-o', tmp / 'harness'])
        run([tmp / 'harness', '9'])
        cli(ROOT / 'PmergeMe')
        run(['clang++', *FLAGS, '-Wno-self-assign-overloaded', '-O1', '-g',
             '-fsanitize=address,undefined', '-fno-omit-frame-pointer',
             tmp / 'harness.cpp', '-o', tmp / 'sanitized'])
        run([tmp / 'sanitized', '7'], env={**os.environ, 'ASAN_OPTIONS': 'detect_leaks=1'})
        run(['clang++', *FLAGS, '-O1', '-g', '-fsanitize=address,undefined',
             '-fno-omit-frame-pointer', '-Iinclude', 'src/main.cpp', 'src/PmergeMe.cpp', '-o', tmp / 'cli-san'])
        cli(tmp / 'cli-san')
        # Debug iterators catch invalidated vector/deque iterator use.
        run(['c++', *FLAGS, '-O1', '-D_GLIBCXX_DEBUG', tmp / 'harness.cpp', '-o', tmp / 'debug'])
        run([tmp / 'debug', '7'])
    header = ROOT / 'include/PmergeMe.hpp'
    stamp = header.stat()
    try:
        os.utime(header, ns=(stamp.st_atime_ns, (ROOT / 'PmergeMe').stat().st_mtime_ns + 2_000_000_000))
        plan = run(['make', '-n'], capture_output=True, text=True).stdout
        assert 'src/PmergeMe.cpp' in plan and 'src/main.cpp' in plan
    finally:
        os.utime(header, ns=(stamp.st_atime_ns, stamp.st_mtime_ns))
    run(['make', 'clean'])
    assert not (ROOT / 'obj').exists() and (ROOT / 'PmergeMe').exists()
    run(['make', 'all'])
    run(['make', 'fclean'])
    assert not (ROOT / 'obj').exists() and not (ROOT / 'PmergeMe').exists()
    run(['make', '-j4', 're'])
    print('PASS Makefile: all/no relink, header dependencies, clean, fclean, parallel re', flush=True)

if __name__ == '__main__':
    main()
