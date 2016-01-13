#ifndef ENIGMA_H
#define ENIGMA_H
#include "rotor.h"
#include "plugboard.h"
#include <string>
#include <vector>
class Enigma
{
public:
    Enigma() = default;
    Enigma(const std::string &rotorspec, const std::string &ring_settings, const std::string &plugboard_settings);
    void set_window_positions(const std::string &new_positions);
    std::string get_window_positions() const;
    char translate_char(char c) const;
    void step_rotors();
    char push_button(char c);
    std::string process_message(const std::string &message);
private:
    std::vector<Rotor> rotors;
    Wheel reflector;
    Plugboard plugboard;
};

#endif