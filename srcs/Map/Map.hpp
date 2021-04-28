#ifndef MAP_HPP
# define MAP_HPP

#include <memory>
#include <cstddef>
#include <limits>
#include <iostream>
#include "../utils/iteratorUtils.hpp"

namespace	ft
{
	template<
			class Key, class T,
			class Compare = std::less<Key>,
			class Allocator = std::allocator<std::pair<const Key, T>>
			>
	class	map
	{
		public:

			typedef	Key							key_type;
			typedef	T							mapped_type;
			typedef std::pair<const Key, T>		value_type;
			typedef	size_t						size_type;
			typedef	ptrdiff_t					difference_type;
			typedef Compare						key_compare;
			typedef	Allocator					allocator_type;
			typedef	Allocator::reference		reference;
			typedef	Allocator::const_reference	const_reference;
			typedef	Allocator::pointer			pointer;
			typedef	Allocator::const_pointer	const_pointer;

		private:

	};
};

#endif
