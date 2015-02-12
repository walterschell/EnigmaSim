#include "utils.h"
#include <iostream>
using std::cout;
#define ASSERT_EQUAL(EXPRESSION, EXPECTED) \
cout << "Testing that " << #EXPRESSION << " equals " << EXPECTED << ": "; \
if (EXPRESSION != EXPECTED) \
{ \
	failcount++; \
	cout << "FAIL Got: " << EXPRESSION << "\n"; \
} \
else \
{ \
	passcount++; \
	cout << "PASS\n"; \
}

int main()
{
	int failcount = 0;
	int passcount = 0;
	std::string ROTOR_I_WIRING = "EKMFLGDQVZNTOWYHXUSPAIBRCJ";
	ASSERT_EQUAL(alphaord('A'), 0);
	ASSERT_EQUAL(alphaord('B'), 1);
	ASSERT_EQUAL(alphaord('Z'), 25);

	ASSERT_EQUAL(ordalpha(0), 'A');
	ASSERT_EQUAL(ordalpha(1), 'B');
	ASSERT_EQUAL(ordalpha(25), 'Z');

	std::vector<int> test_shifts = construct_shifts(ROTOR_I_WIRING);
	ASSERT_EQUAL(test_shifts[0], 4);
	ASSERT_EQUAL(test_shifts[1], 9);
	ASSERT_EQUAL(test_shifts[6], -3);
    std::vector<int> test_reverse_shifts = construct_reverse_shifts(ROTOR_I_WIRING);
	ASSERT_EQUAL(shift_num(test_reverse_shifts[4]), 22);
	ASSERT_EQUAL(shift_num(test_reverse_shifts[10]), 17);
	ASSERT_EQUAL(shift_num(test_reverse_shifts[3]), 3);
	ASSERT_EQUAL(shift_char('A', 26), 'A');
	ASSERT_EQUAL(shift_char('A', -26), 'A');
	ASSERT_EQUAL(shift_char('A', 1), 'B');
	ASSERT_EQUAL(shift_char('B', -1), 'A');
	ASSERT_EQUAL(shift_char('A', -1), 'Z');
	ASSERT_EQUAL(shift_char('Z', 1), 'A');
	ASSERT_EQUAL(shift_char('A', 27), 'B');

}
