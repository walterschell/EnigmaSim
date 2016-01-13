#include "test.h"
#include "rotor.h"
#include <string>
int main()
{
    int passcount;
    int failcount;
    Rotor rotor1 = RotorFactory("I", 'A');
    const std::string  alphabet_expected = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::string rotor_I_wiring_actual = "";
    std::string rotor_I_wiring_expected = "EKMFLGDQVZNTOWYHXUSPAIBRCJ";
    std::string alphabet_actual;
    for (char c : alphabet_expected)
    {
        rotor_I_wiring_actual += rotor1.translate_forward(c);
    }
    ASSERT_EQUAL(rotor_I_wiring_actual, rotor_I_wiring_expected);
    for (char c : rotor_I_wiring_expected)
    {
        alphabet_actual += rotor1.translate_reverse(c);
    }
    rotor1.step_rotor();
    ASSERT_EQUAL(rotor1.get_window_position(), 'B');
    ASSERT_EQUAL(rotor1.translate_forward('A'), 'J');
    ASSERT_EQUAL(rotor1.translate_reverse('J'), 'A');
    Rotor rotor2 = RotorFactory("I", 'F');
    rotor2.set_window_position('Y');
    ASSERT_EQUAL(rotor2.get_window_position(), 'Y');
    ASSERT_EQUAL(rotor2.translate_forward('A'), 'W');
    ASSERT_EQUAL(rotor2.translate_reverse('W'), 'A');
    
}