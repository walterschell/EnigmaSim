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
std::vector<int> construct_reverse_shifts(const std::string &wiring);
int shift_num(int num, int offset=0);
char shift_char(char c, int offset);
std::vector<std::string> split(const std::string &data);

#endif
