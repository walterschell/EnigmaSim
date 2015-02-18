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


   OutputVector = populateOutVectors();
   InputVector  = populateInVectors();  
}

cRoter::~cRoter()
{
    //dtor
}

int cRoter::charToNum(char x)
{
    int nValue = int(x);
    nValue = (nValue - int('A')) % 26;
    std::cout << nValue << std::endl;
    return nValue;
}

char cRoter::numToChar(int x)
{
    char myChar = char((x % 26) + (int)'A');
    std::cout << myChar << std::endl;
    return myChar;
}

const std::vector<int> cRoter::populateOutVectors()
{
	std::vector<int>  Out(26);
	for (unsigned int i = 0; i < 26; i++)
	{
		Out[i] = (charToNum(szWiring[i]) - charToNum(szAlpha[i]));
	}
	return Out;
}

const std::vector<int> cRoter::populateInVectors()
{
	std::vector<int>  InVec(26);
	for (unsigned int i = 0; i < 26; i++)
    {
        InVec[charToNum(szWiring[i])]=(charToNum(szAlpha[i]) - charToNum(szWiring[i]));
    }
    return InVec;
}

int cRoter::printRoters()
{
    for( std::vector<int>::iterator iter = OutputVector().begin(); iter != OutputVector().end(); ++iter)
        std::cout << numToChar(*iter);

    std::cout <<std::endl;
    for( std::vector<int>::iterator iter = InputVector().begin(); iter != InputVector().end(); ++iter)
        std::cout << numToChar(*iter);

    return 0;
}
