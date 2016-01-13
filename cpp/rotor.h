#ifndef ROTOR_H
#define ROTOR_H
#include <string>
#include <vector>

class Wheel
{
public:
    Wheel() = default;
    Wheel(const std::string &wiring);
    char translate_forward(char c) const;
protected:
    std::vector<int> forward_shifts;
};
class Rotor : public Wheel 
{
public:
    Rotor() = default;
    Rotor(const std::string &wiring, const std::string &init_turnovers, char ring_setting);
    char translate_forward(char c) const;
    char translate_reverse(char c) const;
    void step_rotor();
    void set_window_position(char c);
    char get_window_position() const;
    bool in_turnover_position() const;
private:
    std::vector<int> reverse_shifts;
    int ring_offset;
    int window_offset;
    std::string turnovers;
    
};
Wheel WheelFactory(const std::string &wheelname);
Rotor RotorFactory(const std::string &rotorname, char ring_setting);

#endif