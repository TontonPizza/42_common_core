#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>

template <typename T>
int		easyfind(T & t, int n)
{
	typename T::iterator it;
	it = std::find(t.begin(), t.end(), n);
	if (it == t.end())
	{
		throw (std::runtime_error("not found"));
	}
	return *it;
}
