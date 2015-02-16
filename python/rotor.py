from utils import alphaord
from utils import ordalpha
from utils import shift_num
from utils import shift_char
from utils import construct_shifts
from utils import construct_reverse_shifts

ROTOR_I_WIRING   = 'EKMFLGDQVZNTOWYHXUSPAIBRCJ'
ROTOR_II_WIRING  = 'AJDKSIRUXBLHWTMCQGZNPYFVOE'
ROTOR_III_WIRING = 'BDFHJLCPRTXVZNYEIWGAKMUSQO'
ROTOR_IV_WIRING  = 'ESOVPZJAYQUIRHXLNFTGKDCMWB'
ROTOR_V_WIRING   = 'VZBRGITYUPSDNHLXAWMJQOFECK'

ROTOR_I_TURNOVERS   = ['Q']
ROTOR_II_TURNOVERS  = ['E']
ROTOR_III_TURNOVERS = ['V']
ROTOR_IV_TURNOVERS  = ['J']
ROTOR_V_TURNOVERS   = ['Z']


class Rotor:
    def __init__(self, wiring, turnovers, ring_setting):
        self.forward_shifts = construct_shifts(rotor_wiring)
        self.reverse_shifts = construct_reverse_shifts(rotor_wiring)
        self._window_position = 0
        self.ring_setting = ring_setting - 1

    def set_window_position(self, new_position):
        self._window_postion = shift_num(new_position, -1)
    def get_window_position(self):
        return shift_num(self._window_position, 1)

    def translate_forward(self, char):
        cumulative_rotor_rotation = self._window_position + self.ring_setting
        shift_index = shift_num(alphaord(char), cumulative_rotor_rotation)
        return shift_char(char, self.forward_shifts[shift_index])
    def translate_reverse(self, char):
        cumulative_rotor_rotation = self._window_position + self.ring_setting
        shift_index = shift_num(alphaord(char), cumulative_rotor_rotation)
        return shift_char(char, self.reverse_shifts[shift_index])

def self_test():
    rotor = Rotor(ROTOR_I_WIRING, ROTOR_I_TURNOVERS, 1)
    ALPHABET = ''
    for i in range(26):
        ALPHABET += ordalpha(i)
    rotor_i_wiring = ''
    print 'Testing that forward translation equals wiring'
    for c in ALPHABET:
        rotor_i_wiring += rotor.translate_forward(c)
    if rotor_i_wiring == ROTOR_I_WIRING:
        print 'SUCCESS!'
    else:
        print 'FAILURE: Got %s' % rotor_i_wiring
    print 'Testing that reverse translation of wiring equal alphabet'
    alp


if __name__ == '__test__':
    self_test()

