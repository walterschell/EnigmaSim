ROTOR_I_WIRING = 'EKMFLGDQVZNTOWYHXUSPAIBRCJ'
def alphaord(c):
    return ord(c)-ord("A")

def ordalpha(n):
    return chr(n+ord("A"))

def construct_shifts(rotor_wiring):
    results =[]
    for i in range(26):
        shift = alphaord(rotor_wiring[i]) - i
        results.append(shift)    
    return results
def shift_num(n, offset):
    result = n + offset
    while result < 0:
        result += 26
    return result % 26
def shift_char(c, offset):
    return ordalpha(shift_num(alphaord(c), offset))
def self_test():
    has_failed = False
    testvec = [('A', 0),
               ('B',  1),
               ('Z', 25)
              ]
    testvec2 = [(0, 4),
                (1, 9),
                (6, -3)
               ]
    testvec3 = [('A', 26, 'A'),
                ('A', -26, 'A'),
                ('A', 1, 'B'),
                ('B', -1, 'A'),
                ('Z', 1, 'A'),
                ('A', -1, 'Z')
                ]
    for test in testvec:
        print 'Testing that %s is %d' % test
        if alphaord(test[0]) != test[1]:
            print 'Fail'
            has_failed = True
        else:
             print 'Success'
    for test in testvec:
        print 'Testing that %d is %s' % (test[1], test[0])
        if ordalpha(test[1]) != test[0]:
            print 'Result: %s' % ordalpha(test[1])
            print 'Fail'
            has_failed = True
        else:
            print 'Success'
    shifts = construct_shifts(ROTOR_I_WIRING)
    for test in testvec2:
        print 'Testing that offset at position %d is %d' % test
        try:
            if shifts[test[0]] != test[1]:
                print 'Fail. Got %d' % shifts[test[0]]
                has_failed = True
            else:
                print 'Success'

        except:
            print 'FAIL: Out of bounds'
            has_failed = True
    for test in testvec3:
        print 'Testing that shifting %s by %d is %s' % test
        if shift_char(test[0], test[1]) != test[2]:
            print 'Fail, got: %s' % shift_char(test[0], test[1])
            has_failed = True
        else:
            print 'Success'
    if not has_failed:
        print 'Overall SUCCESS'
    else:
        print 'Overall FAIL'


if __name__ == '__main__':
    self_test()
