#include "plugboard.h"
#include "utils.h"
#include <vector>
Plugboard::Plugboard(const std::string &settings)
{
	std::vector<std::string> swaps;
	int index=0;
	int last_index = 0;
	while (1)
	{
		index = settings.find(" ", last_index);
		swaps.push_back(settings.substr(last_index, index - last_index));
		last_index = index + 1;
		if (index == std::string::npos)
		{
			break;
		}
	}
	for (int i = 0; i < 26; i++)
	{
		translation_table[i] = ordalpha(i);
	}
	for (auto swap : swaps)
	{
		translation_table[alphaord(swap[0])] = swap[1];
		translation_table[alphaord(swap[1])] = swap[0];
	}
}
char Plugboard::translate_char(char c) const
{
	return translation_table[alphaord(c)];
}
