#ifndef CROTER_H
#define CROTER_H

#include <vector>
#include <string>
#include <iostream>

class cRoter
{
    private:
        int nOffset = 0;
        int nNotch  = 0;
        std::string szWiring;
        std::string szAlpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        std::vector<int> OutputVector;    //This vector contains our shift to get us the encrypted letter
		std::vector<int> InputVector;    //This vector contains the inverse of our shift to get us back to the original vector

        //NAME  :    charToNum
        //AUTHOR:    Robert P Jaramillo
        //DATE  :    16 FEB 2015
        //IN    :    x,  a character to convert to a integer
        //OUT   :    The value of the char passed in from 0 - 25 with a being 0
        //           Additionally  this function implements wrap around
        int charToNum(char x);

        //NAME  :    numToChar
        //AUTHOR:    Robert P Jaramillo
        //DATE  :    16 FEB 2015
        //IN    :    x, a integer to convert to a letter from A to Z
        //OUT   :    The char passed in converted to a letter A - Z
        //           Additionally  this function implements wrap around
        char numToChar(int nOffset, int nIndex);

        //NAME  :    PopulateOutVector
        //AUTHOR:    Robert P Jaramillo
        //DATE  :    16 FEB 2015
        //IN    :    
		//OUT   :    0 indicates success 1 indicates failure
		const std::vector<int> populateOutVectors(std::vector<int>& InVec);

		//NAME  :    PopulateInVector
		//AUTHOR:    Robert P Jaramillo
		//DATE  :    16 FEB 2015
		//IN    :    
		//OUT   :    0 indicates success 1 indicates failure
		const std::vector<int> populateInVectors(std::vector<int>& InVec);
		
		//NAME  :    shiftVectors
        //AUTHOR:    Robert P Jaramillo
        //DATE  :    16 FEB 2015
        //IN    :    int nShifts,  The number of times to shift each roter, all other data is contained in the class
        //OUT   :    0 indicates success 1 indicates failure
        int shiftVectors(int nShifts);



    public:

        cRoter();
        cRoter(char* szWiring, int nOffset, int nNotchPosition);

        virtual ~cRoter();

		int printRoters();

    protected:

    private:
};
#endif // CROTER_H
