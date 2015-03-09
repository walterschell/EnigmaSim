#include "enigma.h"
#include "test.h"
#include <string>

int main()
{
    int passcount;
    int failcount;
    Enigma enigma("III II I", "AAA", "");
    enigma.set_window_positions("ADO");
    ASSERT_EQUAL(enigma.get_window_positions(), "ADO");
    enigma.step_rotors();
    ASSERT_EQUAL(enigma.get_window_positions(), "ADP");
    enigma.step_rotors();
    ASSERT_EQUAL(enigma.get_window_positions(), "ADQ");
    enigma.step_rotors();
    ASSERT_EQUAL(enigma.get_window_positions(), "AER");
    enigma.step_rotors();
    ASSERT_EQUAL(enigma.get_window_positions(), "BFS");
    enigma.step_rotors();
    ASSERT_EQUAL(enigma.get_window_positions(), "BFT");
    enigma.step_rotors();
    ASSERT_EQUAL(enigma.get_window_positions(), "BFU");
    std::string ciphertext = "NKMOWYXFKKRXYABMLSWEYTJXCTETEFIDLMPJBJOMOZDDAUKQGXFXMZPDWUQUNHAANSRHYTFGKOEQMIVSFYCRKXCUJQHUNBMJSHWZVVKZNWXFLZXEOWDPYAWXZDUMYYRJZNXZACRUCZLDAMZPMUEQNLJWVFGOPSIZAUSSPS";
    Enigma enigma2("II I III", "TIP", "BC DE FG HI JK LX MQ NO ST VZ");
    enigma2.set_window_positions("SEE");
    std::cout << "Decoded message: " << enigma2.process_message(ciphertext.substr(5));
 
}