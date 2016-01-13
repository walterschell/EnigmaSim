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
std::vector<int> construct_reverse_shifts(const std::string &wiring)
{
    std::vector<int> results(26);
    int offset;
    for (int i = 0; i < 26; i++)
    {
        offset = i - alphaord(wiring[i]);
        results[alphaord(wiring[i])] = offset;
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
std::vector< std::string > split(const std::string& data)
{
    std::vector<std::string> results;
    int index=0;
    int last_index = 0;
    while (1)
    {
        index = data.find(" ", last_index);
        results.push_back(data.substr(last_index, index - last_index));
        last_index = index + 1;
        if (index == std::string::npos)
        {
            return results;
        }
    }
}

