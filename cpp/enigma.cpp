#include "enigma.h"
#include "utils.h"
Enigma::Enigma(const std::string& rotorspec, const std::string& ring_settings, const std::string& plugboard_settings) 
: plugboard(plugboard_settings)
{
    std::vector<std::string> rotor_names = split(rotorspec);
    for (int i = 0; i < 3; i++)
    {
        rotors.push_back(RotorFactory(rotor_names[i], ring_settings[i]));
    }
    reflector = WheelFactory("UKW-B");
}
std::string Enigma::get_window_positions() const
{
    std::string results;
    results += rotors[0].get_window_position();
    results += rotors[1].get_window_position();
    results += rotors[2].get_window_position();
    return results;
}
void Enigma::set_window_positions(const std::string& new_positions)
{
    rotors[0].set_window_position(new_positions[0]);
    rotors[1].set_window_position(new_positions[1]);
    rotors[2].set_window_position(new_positions[2]);
}

void Enigma::step_rotors()
{
    if (rotors[1].in_turnover_position())
    {
        rotors[0].step_rotor();
        rotors[1].step_rotor();
        rotors[2].step_rotor();
    }
    else if (rotors[2].in_turnover_position())
    {
        rotors[1].step_rotor();
        rotors[2].step_rotor();
    }
    else
    {
        rotors[2].step_rotor();
    }
}
std::string Enigma::process_message(const std::string& message)
{
    std::string result;
    for (auto c : message)
    {
        char result_c = push_button(c);
        if (result_c == 'X')
        {
            result_c = ' ';
        }
        result += result_c;
    }
    return result;
}

char Enigma::push_button(char c)
{
    step_rotors();
    return translate_char(c);
}

char Enigma::translate_char(char c) const
{
    char forward_c = plugboard.translate_char(c);
    forward_c = rotors[2].translate_forward(forward_c);
    forward_c = rotors[1].translate_forward(forward_c);
    forward_c = rotors[0].translate_forward(forward_c);
    char reverse_c = reflector.translate_forward(forward_c);
    reverse_c = rotors[0].translate_reverse(reverse_c);
    reverse_c = rotors[1].translate_reverse(reverse_c);
    reverse_c = rotors[2].translate_reverse(reverse_c);
    char final_char = plugboard.translate_char(reverse_c);
    return final_char;
}

