from utils import alphaord
messages = []
class Message:
    def ciphertext(self):
        return self.raw_ciphertext[self.offset:]
    def ring_settings(self):
        results = []
        for c in self.raw_ring_settings:
            results.append(str(alphaord(c) +1))
        return ' '.join(results)

message = Message()
message.raw_ciphertext = 'NKMOWYXFKKRXYABMLSWE' +\
                     'YTJXCTETEFIDLMPJBJOM' +\
                     'OZDDAUKQGXFXMZPDWUQU' +\
                     'NHAANSRHYTFGKOEQMIVS' +\
                     'FYCRKXCUJQHUNBMJSHWZ' +\
                     'VVKZNWXFLZXEOWDPYAWX' +\
                     'ZDUMYYRJZNXZACRUCZLD' +\
                     'AMZPMUEQNLJWVFGOPSIZ' +\
                     'AUSSPS'
message.rotors = 'II I III'
message.plugboard = 'BC DE FG HI JK LX MQ NO ST VZ'
message.raw_ring_settings = 'TIP'
message.offset = 5
message.window_positions = 'SEE'
messages.append(message)

message = Message()
message.raw_ciphertext = 'KHLPTCWSEBDDIRBZUUBGKJANBVGIVDVDZZIGAKBZCJMMVEMVXLTHNLDYGRVQAKJMRVZIXHMDNOMTAUTPZDWOINNMOLAHCDKCZTPPEORFIBXCMNWQNIDDCHPTXQQBC'
message.rotors = 'IV III II'
message.plugboard = 'CY EL FH GS IJ KQ MW PV RZ TU'
message.raw_ring_settings = 'PKF'
message.offset = 5
message.window_positions = 'PIK'
messages.append(message)








