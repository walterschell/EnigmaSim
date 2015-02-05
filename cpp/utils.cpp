#include "utils.h"

std::vector<int> construct_shifts(const std::string &wiring)
{
	std::vector<int> results;
	int offset;
	for (int i = 0; i < 26; i++)
	{
		offset = alphaord(wiring[i]) - i;
		results.push_back(offset);
	}
	return results;
}
int shift_num(int num, int offset)
{
	int result = num + offset;
	while (result < 0)
	{
		result += 26;
	}
	return result % 26;
}
char shift_char(char c, int offset)
{
	return ordalpha(shift_num(alphaord(c), offset));
}
