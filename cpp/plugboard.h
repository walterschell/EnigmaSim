#ifndef PLUGBOARD_H
#define PLUGBOARD_H
#include <string>
class Plugboard
{
public:
	Plugboard(const std::string &settings);
	char translate_char(char c) const;
private:
	char translation_table[26];
};


#endif
