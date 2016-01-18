from utils import alphaord
from utils import ordalpha
from utils import shift_num
from utils import shift_char
from utils import construct_shifts
from utils import construct_reverse_shifts
import re

ROTOR_I_WIRING   = 'EKMFLGDQVZNTOWYHXUSPAIBRCJ'
ROTOR_II_WIRING  = 'AJDKSIRUXBLHWTMCQGZNPYFVOE'
ROTOR_III_WIRING = 'BDFHJLCPRTXVZNYEIWGAKMUSQO'
ROTOR_IV_WIRING  = 'ESOVPZJAYQUIRHXLNFTGKDCMWB'
ROTOR_V_WIRING   = 'VZBRGITYUPSDNHLXAWMJQOFECK'

UKW_A_WIRING = 'EJMZALYXVBWFCRQUONTSPIKHGD'
UKW_B_WIRING = 'YRUHQSLDPXNGOKMIEBFZCWVJAT'
UKW_C_WIRING = 'FVPJIAOYEDRZXWGCTKUQSBNMHL'

ROTOR_I_TURNOVERS   = ['Q']
ROTOR_II_TURNOVERS  = ['E']
ROTOR_III_TURNOVERS = ['V']
ROTOR_IV_TURNOVERS  = ['J']
ROTOR_V_TURNOVERS   = ['Z']

rotor_descriptions = {
                        'I' : {
                                'wiring' : ROTOR_I_WIRING,
                                'turnovers' : ROTOR_I_TURNOVERS
                              },

                        'II' : {
                                'wiring' : ROTOR_II_WIRING,
                                'turnovers' : ROTOR_II_TURNOVERS
                              },
                        'III' : {
                                'wiring' : ROTOR_III_WIRING,
                                'turnovers' : ROTOR_III_TURNOVERS
                              },
                        'IV' : {
                                'wiring' : ROTOR_IV_WIRING,
                                'turnovers' : ROTOR_IV_TURNOVERS
                              },
                        'V' : {
                                'wiring' : ROTOR_V_WIRING,
                                'turnovers' : ROTOR_V_TURNOVERS
                              },
                        'UKW_A' : {
                                'wiring' : UKW_A_WIRING,
                              },
                        'UKW_B' : {
                                'wiring' : UKW_B_WIRING,
                              },
                        'UKW_C' : {
                                'wiring' : UKW_C_WIRING,
                              },
                }


class Rotor:
    def __init__(self, rotor_wireing, ring_setting):
        self.rotor_wireing = rotor_wireing
        self.shifts = construct_shifts(self.rotor_wireing)
        self.r_shifts = construct_reverse_shifts(self.rotor_wireing)
        self.window_position = "A"
        self.ring = ring_setting
    def forwardTransform(self, c):
        shift_index = shift_num(alphaord(c),(alphaord(self.window_position) - alphaord(self.ring)))
        shift_amount = self.shifts[shift_index]
        return shift_char(c, shift_amount)
    def reverseTransform(self, c):
        shift_index = shift_num(alphaord(c),(alphaord(self.window_position) - alphaord(self.ring)))
        return shift_char(c, self.r_shifts[shift_index])
    def rotate(self):
        self.window_position = shift_char(self.window_position, 1)
    def setWindowPosition(self, newPosition):
        self.window_position = newPosition
    def getWindowPosition(self):
        return self.window_position

def self_test():
    rotor = Rotor(ROTOR_I_WIRING, "A")
    alphabet_expected = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
    rotor_I_wiring_actual = ''
    print 'Testing that encoding alphabet in order equals wiring'
    for c in alphabet_expected:
        rotor_I_wiring_actual += rotor.forwardTransform(c)
    if rotor_I_wiring_actual == ROTOR_I_WIRING:
        print 'PASS'    
    else:
        print 'FAIL: Got %s' % rotor_I_wiring_actual
    print 'Testing that reverse encoding wiring equals alphabet'
    alphabet_actual = ""
    for c in ROTOR_I_WIRING:
        alphabet_actual += rotor.reverseTransform(c)
    if alphabet_actual == alphabet_expected:
        print "PASS"
    else:
        print "FAIL: Got %s" % alphabet_actual
    print "rotateing rotor"
    rotor.rotate()
    print "checking window position is B"
    if rotor.getWindowPosition() == "B":
        print "PASS"
    else:
        print "FAIL: got %s" % rotor.getWindowPosition()
    print "testing that forward encoding of a is j"
    if rotor.forwardTransform("A") == "J":
        print "PASS"
    else:
        print "FAIL: got %s" % rotor.forwardTransform("A")
    print "Testing that reverse transform of J is A"
    if rotor.reverseTransform("J") == "A":
        print 'PASS'
    else:
        print 'FAIL: Got %s' % rotor.reverseTransform("J")
    rotor2 = Rotor(ROTOR_I_WIRING, "F")
    rotor2.setWindowPosition("Y")
    print "Testing window position"
    if rotor2.getWindowPosition() == "Y":
        print "Pass"
    else:
        print "FAIL: Got %s" % rotor2.getWindowPosition()
    print "testing forward transform of A to W"
    if rotor2.forwardTransform("A") == "W":
        print "Pass"
    else:
        print "FAIL, Got %s" % rotor2.forwardTransform("A")
    print "testing reverse transform of W to A"
    if rotor2.reverseTransform("W") == "A":
        print "Pass"
    else:
        print "FAIL, Got %s" % rotor2.reverseTransform("W")
if __name__ == '__main__':
    self_test()
