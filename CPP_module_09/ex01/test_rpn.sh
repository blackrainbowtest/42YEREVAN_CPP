#!/usr/bin/env bash
# CPP Module 09 - Exercise 01: RPN test runner
set -u

if [[ -t 1 && -z "${NO_COLOR:-}" ]]; then
    GREEN=$'\033[0;32m'
    RED=$'\033[0;31m'
    CYAN=$'\033[0;36m'
    BOLD=$'\033[1m'
    RESET=$'\033[0m'
else
    GREEN=''
    RED=''
    CYAN=''
    BOLD=''
    RESET=''
fi

pass() {
    printf '%s[PASS]%s %s\n' "$GREEN" "$RESET" "$1"
    ((passed+=1))
}

fail() {
    printf '%s[FAIL]%s %s\n' "$RED" "$RESET" "$1"
    ((failed+=1))
}

if [[ ! -x ./RPN ]]; then
    printf '%sExecutable ./RPN not found. Running make...%s\n' "$CYAN" "$RESET"
    if ! make || [[ ! -x ./RPN ]]; then
        printf '%sERROR: Failed to build ./RPN%s\n' "$RED" "$RESET" >&2
        exit 1
    fi
fi

passed=0
failed=0

run_ok() {
    local label="$1" expression="$2" expected="$3" actual status
    actual=$(./RPN "$expression" 2>&1)
    status=$?
    if [[ $status -eq 0 && "$actual" == "$expected" ]]; then
        pass "$label"
    else
        fail "$label"
        printf '  Input: %q\n  Expected stdout: %s (exit 0)\n  Actual combined output: %s (exit %s)\n' "$expression" "$expected" "$actual" "$status"
    fi
}

run_error() {
    local label="$1" expression="$2" stdout_file stderr_file status
    stdout_file=$(mktemp)
    stderr_file=$(mktemp)
    ./RPN "$expression" >"$stdout_file" 2>"$stderr_file"
    status=$?
    if [[ ! -s "$stdout_file" && -s "$stderr_file" ]]; then
        pass "$label"
    else
        fail "$label"
        printf '  Input: %q\n  Expected: no stdout, error on stderr\n  Exit: %s\n' "$expression" "$status"
        printf '  stdout: '; cat "$stdout_file"; printf '\n  stderr: '; cat "$stderr_file"; printf '\n'
    fi
    rm -f "$stdout_file" "$stderr_file"
}

run_ok 'Subject example 1' '8 9 * 9 - 9 - 9 - 4 - 1 +' '42'
run_ok 'Subject example 2' '7 7 * 7 -' '42'
run_ok 'Subject example 3' '1 2 * 2 / 2 * 2 4 - +' '0'
run_ok 'Subtraction order' '8 3 -' '5'
run_ok 'Negative result' '3 8 -' '-5'
run_ok 'Division order' '8 2 /' '4'
run_ok 'Integer division' '7 2 /' '3'
run_ok 'Single operand' '5' '5'
run_ok 'Zero operand' '0' '0'
run_ok 'Nested operations' '9 2 3 + *' '45'
run_ok 'Whitespace padding' '  4 5 +  ' '9'
run_error 'Subject invalid parentheses' '(1 + 1)'
run_error 'Division by zero' '4 0 /'
run_error 'Missing operand' '1 +'
run_error 'Extra operand' '1 2 3 +'
run_error 'Empty expression' ''
run_error 'Invalid character' '1 a +'
run_error 'Operator only' '+'
run_error 'Two operands without operator' '1 2'

# Missing argument: must report an error to stderr.
stdout_file=$(mktemp)
stderr_file=$(mktemp)
./RPN >"$stdout_file" 2>"$stderr_file"
if [[ ! -s "$stdout_file" && -s "$stderr_file" ]]; then
    pass 'Missing command-line argument'
else
    fail 'Missing command-line argument (expected stderr only)'
fi
rm -f "$stdout_file" "$stderr_file"

printf '\n%s%s========== RPN TEST RESULTS ==========%s\n' "$BOLD" "$CYAN" "$RESET"
printf '%sPassed: %d%s\n' "$GREEN" "$passed" "$RESET"
printf '%sFailed: %d%s\n' "$RED" "$failed" "$RESET"
printf '%sTotal:  %d%s\n' "$BOLD" "$((passed + failed))" "$RESET"
[[ "$failed" -eq 0 ]]
