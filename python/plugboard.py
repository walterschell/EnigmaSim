from utils import alphaord
from utils import ordalpha
from utils import shift_num
from utils import shift_char
from utils import construct_shifts
from utils import construct_reverse_shifts

class Plugboard:
    def __init__(self, plugboard_settings):
        swaps = plugboard_settings.split()
        self.shifts = 260 * [0]
        for pair in swaps:
            from_index = alphaord(pair[0])
            to_index = alphaord(pair[1])
            difference = to_index - from_index
            self.shifts[from_index] = difference
            self.shifts[to_index] = -difference
    def translate(self, char):
        return shift_char(char, self.shifts[alphaord(char)])

def self_test():
    plugboard = Plugboard('AZ BY')
    testvec  = 'ZYCDEFGHIJKLMNOPQRSTUVWXBA'
    alphabet = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
    print 'Testing forward translation'
    result = ''
    for c in alphabet:
        result += plugboard.translate(c)
    if result == testvec:
        print 'SUCCESS' 
    else:
        print 'FAILURE'
    print 'Testing reverse translation'
    result = ''
    for c in testvec:
        result += plugboard.translate(c)
    if result ==alphabet:
        print 'SUCCESS'
    else:
        print 'FAILURE'


if __name__ == '__main__':
    self_test()
        
