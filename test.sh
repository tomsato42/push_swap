#!/bin/bash

valg='valgrind -q'

test_ok()
{
	expected_out=$(./push_swap $1 | $valg ./checker_linux $1 2>/dev/null)
	out=$($valg ./push_swap $1 | $valg ./checker $1 2>/dev/null)
	if [ "$expected_out" == "$out" ]; then
		echo -n '.'
	else
		echo 'F'
		echo 'Expexted "OK" but you are not'
		echo "input : $1 out : $out"
	fi
	expected_err=$(./push_swap $1 | $valg ./checker_linux $1 2>&1 1>/dev/null)
	err=$($valg ./push_swap $1 | $valg ./checker $1 2>&1 1>/dev/null)
	if [ "$expected_out" == "$out" ]; then
		echo -n '.'
	else
		echo 'F'
		echo 'Expexted "" but you are not'
		echo "input : $1 out : $err"
	fi
}

test_none()
{
    expected_out=$($valg ./push_swap $1 | $valg ./checker $1 2>/dev/null)
    out=$($valg ./push_swap $1 | $valg ./checker $1 2>/dev/null)
    if [ "$expected_out" == "$out" ]; then
        echo -n '.'
    else
        echo 'F'
        echo 'Expexted "OK" but you are not'
        echo "input : $1 out : $out"
    fi
    expected_err=$($valg ./push_swap $1 | $valg ./checker $1 2>&1 1>/dev/null)
    err=$($valg ./push_swap $1 | $valg ./checker $1 2>&1 1>/dev/null)
    if [ "$expected_err" == "$err" ]; then
        echo -n '.'
    else
        echo 'F'
        echo 'Expexted "" but you are not'
        echo "input : $1 out : $err"
    fi
}

test_error()
{
    expected_out=$($valg ./checker_linux $1 2>&1)
    out=$($valg ./checker $1 2>&1)
    if [ "$expected_out" == "$out" ]; then
        echo -n '.'
    else
        echo 'F'
        echo 'Expected "" but you are not'
        echo "input : $1 out : $out"
    fi
    expected_err=$($valg ./checker_linux $1 2>&1 1>/dev/null)
    err=$($valg ./checker $1 2>&1 1>/dev/null)
    if [ "$expected_err" == "$err" ]; then
        echo -n '.'
    else
        echo 'F'
        echo 'Expected "Error" but you are not'
        echo "input : $1 out : $err"
    fi
}

test_error_stdin()
{
	expected_err=$(echo "$1" | ./checker_linux 3 2 1 2>&1 1>/dev/null )
    err=$(echo "$1" | $valg ./checker 3 2 1 2>&1 1>/dev/null )
    if [[ "$err" == "$expected_err" ]]; then
        echo -n '.'
    else
        echo 'F'
        echo 'Expected "Error" but you are not'
		echo "input : $1, err : $err"
    fi
	expected_out=$(echo "$1" | ./checker_linux 3 2 1 2>/dev/null)
	out=$(echo "$1" | $valg ./checker 3 2 1 2>/dev/null)
    if [[ "$out" == "$expected_out" ]]; then
        echo -n '.'
    else
        echo 'F'
        echo 'Expected "" but you are not'
    fi
}
make push_swap
make checker

test_ok '2 3 1'
test_ok '1 2 3'
test_ok '1'
test_ok '10 4 5 6 2 3'
test_ok '2147483647'
test_ok '-2147483648'
test_ok '2 1 0 -1 -2'
test_ok '-2 -3 -1 -5 -4'

test_none ''
test_none ' '
test_none '  '

test_error 'input not number'
test_error '\"\" 1'
test_error '7 7'
test_error '1 2 2'
test_error '2147483648'
test_error '-2147483649'
test_error '21474836479'
test_error '9223372036854775807'
test_error '-9223372036854775808'
test_error '984190842390823490823490823490843908342909843980349823498042390842390834290823490842390823490824398024390823498243980234980234980234980243908234908243908243908243689436798523857249875984759834790857290423904234723234798234278234749832432749827984327823945798247982782347984329843298743298742398743298743298743298743298742398743298743298743298743298743298743298742379843298743298743298743298743298743298743278432984732987432987432987423987432798432789432798432789432798423798432789432789432789432'

test_error_stdin "adwadwa\ndwdaw\ndwadwada\n"
test_error_stdin "pa\npb\nppap"
test_error_stdin "pa\npb\np"

echo ""
