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
			class Allocator = std::allocator<std::pair<const Key, T> >
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
			typedef	typename rep_type::const_iterator			const_iterator;
			typedef	typename rep_type::size_type				size_type;
			typedef	typename rep_type::difference_type			difference_type;
			typedef	typename rep_type::reverse_iterator			reverse_iterator;
			typedef	typename rep_type::const_reverse_iterator	const_reverse_iterator;

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

			/* Constructors: */

			explicit map(const Compare& comp = Compare(), const Allocator& alloc = Allocator())
				: _alloc(alloc), _comp(comp), _rbt(comp, alloc)
			{}

			template <class InputIt>
			map(InputIt first, InputIt last, const Compare &comp = Compare(), const Allocator& alloc = Allocator())
				: _alloc(alloc), _comp(comp), _rbt(comp, alloc)
			{
				insert(first, last);
			}

			map(const map &other)
				: _alloc(other._alloc), _comp(other._comp), _rbt(_comp, _alloc)
			{
				if (!(other.empty()))
					insert(other.begin(), other.end());
			}

			/* Destructors: */

			~map(void)
			{};

			/* operator= */

			map&	operator=(const map &other)
			{
				if (&other == this)
					return (*this);
				clear();
				if (!(other.empty()))
					insert(other.begin(), other.end());
				return (*this);
			}

			/* Element access: */

			T&		operator[](const Key& key)
			{
				return insert(std::make_pair(key, T())).first->second;
			}

			/* iterators: */

			iterator		begin(void)
			{
				return (_rbt.begin());
			}

			const_iterator		begin(void) const
			{
				return (_rbt.begin());
			}

			iterator		end(void)
			{
				return (_rbt.end());
			}

			const_iterator		end(void) const
			{
				return (_rbt.end());
			}

			reverse_iterator	rbegin(void)
			{
				return (reverse_iterator(end()));
			}

			const_reverse_iterator	rbegin(void) const
			{
				return (const_reverse_iterator(end()));
			}

			reverse_iterator	rend(void)
			{
				return (reverse_iterator(begin()));
			}

			reverse_iterator	rend(void) const
			{
				return (cont_reverse_iterator(begin()));
			}

			/* Capacity: */

			bool			empty(void) const
			{
				return (_rbt.get_size() == 0);
			}

			size_type		size(void) const
			{
				return (_rbt.get_size());
			}

			size_type		max_size(void) const
			{
				return (allocator_type().max_size());
			}


			/* Modifiers: */

			void 	clear(void)
			{
				_rbt.clear();
			}

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

			void 		erase(iterator pos)
			{
				_rbt.delete_node(pos._node);
			}

			void 		erase(iterator first, iterator last)
			{
				RBT_node<value_type>	*to_delete;
				while (first != last)
				{
					to_delete = first._node;
					first++;
					_rbt.delete_node(to_delete);
				}
			}

			size_type	erase(const key_type& key)
			{
				RBT_node<value_type>	*to_delete = _rbt.search_node(key);
				if (to_delete == nullptr)
					return 0;
				else
				{
					_rbt.delete_node(to_delete);
					return 1;
				}
			}

			void 		swap(map& other)
			{
				_rbt.swap(other._rbt);
			}



			/* Lookup: */

			size_type	count(const Key& key) const
			{
				if (_rbt.search_node(key) == nullptr)
					return (0);
				else
					return (1);
			}

			iterator		find(const Key& key)
			{
				return (_rbt.find(key));
			}

			const_iterator	find(const Key& key) const
			{
				return (_rbt.find(key));
			}

			std::pair<iterator,iterator>	equal_range( const Key& key )
			{
				return(make_pair(_rbt.lower_bound(key), _rbt.upper_bound(key)));
			}

			std::pair<const_iterator,const_iterator> equal_range( const Key& key ) const
			{
				return(make_pair(_rbt.lower_bound(key), _rbt.upper_bound(key)));
			}

			iterator		lower_bound(const Key &key)
			{
				return (_rbt.lower_bound(key));
			}

			const_iterator	lower_bound(const Key &key) const
			{
				return (_rbt.lower_bound(key));
			}

			iterator		upper_bound(const Key &key)
			{
				return (_rbt.upper_bound(key));
			}

			const_iterator	upper_bound(const Key &key) const
			{
				return (_rbt.upper_bound(key));
			}

			/* Observers: */

			key_compare		key_comp() const
			{
				return (key_compare());
			}

			value_compare	value_comp() const
			{
				return (value_compare(key_compare()));
			}

			void 		print(void)
			{
				_rbt.print_tree();
			}

		private:

			allocator_type								_alloc;
			key_compare									_comp;
			RedBlackTree<Key, T, Compare, Allocator>	_rbt;

	};

	/* Non-member function overloads: */
	template< class Key, class T, class Compare, class Alloc >
	bool operator==( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs )
	{
		if (lhs.size() != rhs.size())
			return (false);
		typename map<Key, T>::const_iterator itl = lhs.begin();
		typename map<Key, T>::const_iterator itr = rhs.begin();
		while (itl != lhs.end())
		{
			if (*itl != *itr)
				return (false);
			itl++;
			itr++;
		}
		return (true);
	}

	template< class Key, class T, class Compare, class Alloc >
	bool operator!=( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs )
	{
		return (!(lhs == rhs));
	}

	template< class Key, class T, class Compare, class Alloc >
	bool operator<( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs )
	{
		typename map<Key, T>::const_iterator itl = lhs.begin();
		typename map<Key, T>::const_iterator itr = rhs.begin();
		while (itl != lhs.end() && itr != rhs.end())
		{
			if (*itl < *itr)
				return (true);
			else if (*itl > *itr)
				return (false);
			itl++;
			itr++;
		}
		if (lhs.size() >= rhs.size())
			return (false);
		return (true);
	}

	template< class Key, class T, class Compare, class Alloc >
	bool operator<=( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs )
	{
		return (!(rhs < lhs));
	}

	template< class Key, class T, class Compare, class Alloc >
	bool operator>=( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs )
	{
		return (!(lhs < rhs));
	}

	template< class Key, class T, class Compare, class Alloc >
	bool operator>( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs )
	{
		return (rhs < lhs);
	}



	template <class Key, class T, class Compare, class Alloc>
	void	swap(map<Key, T, Compare, Alloc> &x, map<Key, T, Compare, Alloc> &y)
	{
		x.swap(y);
	};
};

#endif
