#ifndef MAP_HPP
# define MAP_HPP

#include <memory>
#include <cstddef>
#include <limits>
#include <iostream>
#include "../utils/iteratorUtils.hpp"
#include "RedBlackTree/RedBlackTree.hpp"

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
			typedef Compare						key_compare;
			typedef	Allocator					allocator_type;

			typedef	typename Allocator::reference		reference;
			typedef	typename Allocator::const_reference	const_reference;
			typedef	typename Allocator::pointer			pointer;
			typedef	typename Allocator::const_pointer	const_pointer;

			typedef	RedBlackTree<Key, T, Compare, Allocator>	rep_type;

			typedef	typename rep_type::iterator					iterator;
			//typedef	typename rep_type::const_iterator			const_iterator;
			typedef	typename rep_type::size_type				size_type;
			typedef	typename rep_type::difference_type			difference_type;
			//typedef	typename rep_type::reverse_iterator			reverse_iterator;
			//typedef	typename rep_type::const_reverse_iterator	const_reverse_iterator;

			class value_compare
			{
				friend class map<Key, T, Compare, Allocator>;

				typedef bool		result_type;
				typedef value_type	first_argument_type;
				typedef value_type	second_argument_type;

				protected:
					Compare		comp;

					value_compare(Compare c) : comp(c)
					{}

				public:

					bool	operator()(const value_type& lhs, const value_type& rhs) const
					{
						return (comp(lhs.first, rhs.first));
					}

			};

			explicit map(const Compare& comp = Compare(), const Allocator& alloc = Allocator())
				: _alloc(alloc), _comp(comp), _rbt(comp, alloc)
			{};

			~map(void)
			{};

			std::pair<iterator, bool>	insert(const value_type& value)
			{
				return(_rbt.insert(value));
			}

			iterator	insert(iterator hint, const value_type& value)
			{
				(void)hint;

				return (insert(value).first);
			}

			template <class InputIt>
			void 		insert(InputIt first, InputIt last)
			{
				while (first != last)
				{
					insert(*first);
					first++;
				}
			}

		private:

			allocator_type								_alloc;
			key_compare									_comp;
			RedBlackTree<Key, T, Compare, Allocator>	_rbt;

	};
};

#endif
