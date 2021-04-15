#ifndef ITERATORUTILS_H
# define ITERATORUTILS_H

#include <cstddef>

namespace ft
{
	template <class InputIt>
	size_t		distance(InputIt first, InputIt last)
	{
		size_t	dist = 0;
		while (first != last)
		{
			first++;
			dist++;
		}
		return(dist);
	}
}

#endif
