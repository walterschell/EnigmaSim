from utils import alphaord

class Plugboard:
    def __init__(self, pairs):
        alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        self.translation_table = []
        for c in alphabet:
            self.translation_table.append(c)
        for pair in pairs.split(" "):
            self.translation_table[alphaord(pair[0])] = pair[1]
            self.translation_table[alphaord(pair[1])] = pair[0]
    def translate(self, c):
        return self.translation_table[alphaord(c)]

def self_test():
    plug = Plugboard("HZ PQ UE")
    print "testing that H is Z"
    if plug.translate("H") == "Z":
        print "Pass"
    else:
        print "FAIL, Got %s" % plug.translate("H")
    print "testing that Z is H"
    if plug.translate("Z") == "H":
        print "Pass"
    else:
        print "FAIL, Got %s" % plug.translate("Z")
    print "testing that P is Q"
    if plug.translate("P") == "Q":
        print "Pass"
    else:
        print "FAIL, Got %s" % plug.translate("P")
    print "testing that Q is P"
    if plug.translate("Q") == "P":
        print "Pass"
    else:
        print "FAIL, Got %s" % plug.translate("Q")
    print "testing junk B"
    if plug.translate("B") == "B":
        print "Pass"
    else:
        print "FAIL, Got %s" % plug.translate("B")

if __name__ == '__main__':
    self_test()
