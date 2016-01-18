from rotor import Rotor
from rotor import Wheel
from rotor import UKW_B_WIRING
from rotor import rotor_descriptions
from messages import messages
from plugboard import Plugboard

class Enigma:
    def __init__(self, codebook_rotors, codebook_ring_settings, codebook_plugboard_settings):
        rotor_names = codebook_rotors.split(' ')
        ring_settings = codebook_ring_settings.split(' ')
        if len(rotor_names) != 3:
            raise Exception('%s did not yeild 3 rotors' % codebook_rotors)
        if len(ring_settings) != 3:
            raise Exception('%s did not yeild 3 ring settings' % ring_settings)
        self.rotors = []
        for i in range(3):
            r = rotor_names[i]
            ring_setting = int(ring_settings[i])
            wiring = rotor_descriptions[r]['wiring']
            turnovers = rotor_descriptions[r]['turnovers']
            rotor = Rotor(wiring, turnovers, ring_setting)
            self.rotors.append(rotor)
        self.plugboard = Plugboard(codebook_plugboard_settings)
        self.reflector = Wheel(UKW_B_WIRING)
    def set_window_positions(self, new_positions):
        for i in range(3):
            self.rotors[i].set_window_position(new_positions[i])
    def get_window_positions(self):
            results = ''
            for rotor in self.rotors:
                results+=(rotor.get_window_position())
            return results
    def step(self):
        do_step = [False, False, True]
        if self.rotors[1].in_turnover_position():
            do_step[0] = True
            do_step[1] = True
        if self.rotors[2].in_turnover_position():
            do_step[1] = True
        for i in range(3):
            if do_step[i]:
                self.rotors[i].step()
    def translate_char(self, c):
        forward = self.plugboard.translate(c)
        for i in [2,1,0]:
            forward = self.rotors[i].translate_forward(forward)
        reverse = self.reflector.translate_forward(forward)
        for i in [0, 1, 2]:
            reverse = self.rotors[i].translate_reverse(reverse)
        final = self.plugboard.translate(reverse)
        return final
    def press_key(self, c):
        self.step()
        return self.translate_char(c)
    def process_string(self, s):
        results = ''
        for c in s:
            results += self.press_key(c)
        return results
def self_test():
    enigma = Enigma('III II I', '1 1 1', '')
    enigma.set_window_positions('ADO')
    print enigma.get_window_positions()
    for i in range(6):
        enigma.step()
        print enigma.get_window_positions()
    for message in messages:
        enigma = Enigma(message.rotors, message.ring_settings(), message.plugboard)
        enigma.set_window_positions(message.window_positions)
        print 'Decoding ->%s<-' % message.ciphertext()
        raw_decrypt = enigma.process_string(message.ciphertext())
        print 'Raw_decrypt: %s' % raw_decrypt
        decrypt = raw_decrypt.replace('X', ' ')
        print 'Decrypt: %s' % decrypt
        print 'Final Rotor Positions: %s' % enigma.get_window_positions()
if __name__ == '__main__':
    self_test()    
