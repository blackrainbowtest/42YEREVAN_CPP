#!/bin/bash

LOG_FILE="float_stress_tests.log"

{
	echo "===== build ====="
	make re
	echo

	echo "===== float stress tests ====="

	tests=(
		"0.0f"
		"31.0f"
		"32.0f"
		"55.0f"
		"55.5f"
		"126.0f"
		"127.0f"
		"128.0f"
		"-1.0f"
		"2147483646.0f"
		"2147483647.0f"
		"2147483648.0f"
		"-2147483648.0f"
		"-2147483649.0f"
		"16777215.0f"
		"16777216.0f"
		"16777217.0f"
		"16777218.0f"
		"nanf"
		"+inff"
		"-inff"
		"nan"
		"+inf"
		"-inf"
		"0.00001f"
		"-0.00001f"
		"42.42f"
		"-42.42f"
		"42.000f"
		"42.f"
		".42f"
		"-.42f"
		"+.42f"
		"340282346638528859811704183484516925440.0f"
		"340282346638528859811704183484516925441.0f"
		"999999999999999999999999999999999999999.0f"
		"55f"
		"55ff"
		"55.0ff"
		"55.0f0"
		"f"
		".f"
		"+"
		"-"
		"."
		"42..0f"
	)

	for test in "${tests[@]}"; do
		echo
		echo "----- ./convert $test -----"
		./convert "$test"
		status=$?
		echo "exit status: $status"
	done
} > "$LOG_FILE" 2>&1

echo "Done. Results written to $LOG_FILE"
