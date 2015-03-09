test: test_plugboard test_utils test_enigma test_rotor
	./test_rotor
	./test_plugboard
	./test_utils
	./test_enigma
clean:
	rm -f *.o test_plugboard test_utils
test_plugboard: test_plugboard.o utils.o plugboard.o
	g++ -ggdb -o test_plugboard test_plugboard.o utils.o plugboard.o
	
test_utils: test_utils.o utils.o
	g++ -ggdb -o test_utils utils.o test_utils.o
	
utils.o: utils.cpp
	g++ -ggdb -std=c++11 -c utils.cpp

plugboard.o: plugboard.cpp
	g++ -ggdb -std=c++11 -c plugboard.cpp

test_plugboard.o: test_plugboard.cpp
	g++ -ggdb -std=c++11 -c test_plugboard.cpp
	
test_utils.o: test_utils.cpp
	g++ -ggdb -std=c++11 -c test_utils.cpp	
	
rotor.o: rotor.cpp
	g++ -ggdb -std=c++11 -c rotor.cpp
	
enigma.o: enigma.cpp
	g++ -ggdb -std=c++11 -c enigma.cpp
	
main.o: main.cpp
	g++ -ggdb -std=c++11 -c main.cpp
test_enigma.o: test_enigma.cpp
	g++ -ggdb -std=c++11 -c test_enigma.cpp
test_enigma: test_enigma.o plugboard.o rotor.o utils.o enigma.o
	g++ -o test_enigma test_enigma.o plugboard.o rotor.o utils.o enigma.o
test_rotor.o: test_rotor.cpp
	g++ -ggdb -std=c++11 -c test_rotor.cpp
test_rotor: test_rotor.o utils.o rotor.o
	g++ -o test_rotor test_rotor.o utils.o rotor.o

main: main.o rotor.o utils.o plugboard.o enimga.o
	g++ -o enigma main.o rotor.o utils.o plugboard.o enigma.o