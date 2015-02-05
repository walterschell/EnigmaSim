#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <vector>

inline int alphaord(char c)
{
	return (int)(c - (int)'A');
}
inline char ordalpha(int n)
{
	return (char)(n + (int)'A');
}
std::vector<int> construct_shifts(const std::string &wiring);
int shift_num(int num, int offset);
char shift_char(char c, int offset);


#endif
