#include <iostream>
#include <string>
#include "plugboard.h"
#include "test.h"
int main()
{
	int passcount;
    int failcount;
    Plugboard plugboard("AZ BY CX");
	std::string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::string translated_alphabet_expected = "ZYXDEFGHIJKLMNOPQRSTUVWCBA";
    std::string translated_alphabet_actual;
    std::string alpha_expected;
	for (char c : alpha)
	{
        translated_alphabet_actual += plugboard.translate_char(c);
    }
    ASSERT_EQUAL(translated_alphabet_actual, translated_alphabet_expected);
	for (char c : translated_alphabet_expected)
    {
        alpha_expected += plugboard.translate_char(c);
    }
    ASSERT_EQUAL(alpha_expected, alpha);

}
