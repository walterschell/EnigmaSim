#include "cRoter.h"

cRoter::cRoter()
{
    //ctor
}

cRoter::cRoter(char* szWiring, int nOffset, int nNotchPosition)
{
   this->szWiring    = szWiring;
   this->nOffset     = nOffset;
   this->nNotch      = nNotchPosition;


   populateOutVectors(OutputVector);
   populateInVectors(InputVector);  
}

cRoter::~cRoter()
{
    //dtor
}

int cRoter::charToNum(char x)
{
    int nValue = int(x);
    nValue = (nValue - int('A')) % 26;
    //std::cout << "Character: " << x << " Is Value: " << nValue << std::endl ;
    return nValue;
}

char cRoter::numToChar(int nOffset,  int nIndex)
{
    char myChar = char((nOffset % 26) + ((int)'A' + nIndex));
    //std::cout << myChar << std::endl;
    return myChar;
}

const std::vector<int> cRoter::populateOutVectors(std::vector<int>& OutVec)
{
	//std::vector<int>  Out(26);
	OutVec.resize(26);
	for (unsigned int i = 0; i < 26; i++)
	{
		OutVec[i] = (charToNum(szWiring[i]) - charToNum(szAlpha[i]));
		std::cout << "Converting szWiring[" << i << "]: " << szWiring[i] << " - " << szAlpha[i] << " (" << charToNum(szAlpha[i]) << ")   = " << OutVec[i]  << std::endl;

	}
	return OutVec;
}

const std::vector<int> cRoter::populateInVectors(std::vector<int>& InVec)
{
	//std::vector<int>  InVec(26);
	InVec.resize(26); 
	std::cout << "\n\n";
	for (unsigned int i = 0; i < 26; i++)
    {
        InVec[charToNum(szWiring[i])]=(charToNum(szAlpha[i]) - charToNum(szWiring[i]));
		std::cout << "Converting Input Vector[" << i << "]: " << szAlpha[i] << " - " << szWiring[i] << " (" << charToNum((szAlpha[i]) - charToNum(szWiring[i])) << ")   = " << InVec[charToNum(szWiring[i])] << std::endl;
    }
    return InVec;
}

int cRoter::printRoters()
{
	//This function works.  When looking at the output we can see that if we decrypt what the system gives back an E is an A 
	//Additionally as you follow this back all the way across and compare the input with the orginal alphabet and the encryption applied everything lines up.   
	

	std::cout << "\nOrginal  Alphabet \t:"; 
	for (int i = 0; i < 26;  i++)
		std::cout << "|" << szAlpha[i];  

	std::cout << "\n------------------------------------------------------------------------------\nConfirming Ecryption\t:";
	int nIndex = 0;  
	for (std::vector<int>::iterator iter = OutputVector.begin(); iter != OutputVector.end(); ++iter)
	{

		std::cout << "|" << numToChar(*iter, nIndex);
		nIndex += 1; 
	}

    std::cout <<"\nReversing Encryption \t:";
	nIndex = 0;
	//This confirms we con decrypt our character
	for (std::vector<int>::iterator iter = InputVector.begin(); iter != InputVector.end(); ++iter)
	{
		std::cout << "|" << numToChar(*iter, nIndex);
		nIndex += 1;  
	}
    return 0;
}
