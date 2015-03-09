#include "rotor.h"
#include "utils.h"
#include <map>
class RotorSpec
{
public:
    std::string wiring;
    std::string turnovers;
};
std::map<std::string, RotorSpec> rotorspecs = {
    {"I"  , {"EKMFLGDQVZNTOWYHXUSPAIBRCJ", "Q"}},
    {"II" , {"AJDKSIRUXBLHWTMCQGZNPYFVOE", "E"}},
    {"III", {"BDFHJLCPRTXVZNYEIWGAKMUSQO", "V"}},
    {"IV" , {"ESOVPZJAYQUIRHXLNFTGKDCMWB", "J"}},
    {"V"  , {"VZBRGITYUPSDNHLXAWMJQOFECK", "Z"}},
    {"UKW-A", {"EJMZALYXVBWFCRQUONTSPIKHGD", ""}},
    {"UKW-B", {"YRUHQSLDPXNGOKMIEBFZCWVJAT", ""}},
    {"UKW-C", {"FVPJIAOYEDRZXWGCTKUQSBNMHL", ""}}
};

Wheel::Wheel(const std::string& wiring)
{
    forward_shifts = construct_shifts(wiring);
}
char Wheel::translate_forward(char c) const
{
    return shift_char(c, forward_shifts[alphaord(c)]);
}

Rotor::Rotor(const std::string& wiring, const std::string &init_turnovers, char ring_setting) : Wheel(wiring)
{
    turnovers = init_turnovers;
    reverse_shifts = construct_reverse_shifts(wiring);
    ring_offset = -alphaord(ring_setting);
    window_offset = 0;
}
void Rotor::set_window_position(char c)
{
    window_offset = alphaord(c);
}
char Rotor::get_window_position() const
{
    return ordalpha(window_offset);
}
void Rotor::step_rotor()
{
    window_offset = shift_num(window_offset, 1);
}
char Rotor::translate_forward(char c) const
{
    int shift_index = shift_num(alphaord(c) + ring_offset + window_offset, 0);
    return shift_char(c, forward_shifts[shift_index]);
}
char Rotor::translate_reverse(char c) const
{
    int shift_index = shift_num(alphaord(c) + ring_offset + window_offset, 0);
    return shift_char(c, reverse_shifts[shift_index]);
}
Wheel WheelFactory(const std::string& wheelname)
{
    return Wheel(rotorspecs[wheelname].wiring);
}
Rotor RotorFactory(const std::string& rotorname, char ring_setting)
{
    return Rotor(rotorspecs[rotorname].wiring, rotorspecs[rotorname].turnovers, ring_setting);
}

bool Rotor::in_turnover_position() const
{
    return (turnovers.find_first_of(get_window_position()) != std::string::npos);
}

