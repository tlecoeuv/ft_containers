#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <memory>
#include <cstddef>
#include <limits>
#include <iostream>
#include "VectorIterator.hpp"
#include "../utils/iteratorUtils.hpp"

namespace	ft
{
	template<class T, class Allocator = std::allocator<T> >
	class	vector
	{
		public:

		typedef	T									value_type;
		typedef	Allocator							allocator_type;
		typedef	size_t								size_type;
		typedef	ptrdiff_t							difference_type;
		typedef	typename Allocator::reference		reference;
		typedef	typename Allocator::const_reference	const_reference;
		typedef typename Allocator::pointer			pointer;
		typedef typename Allocator::const_pointer	const_pointer;

		typedef	vectorIterator<T>						iterator;
		typedef vectorIterator<const T>					const_iterator;
		typedef	ft::reverse_iterator<iterator>			reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;

		/* member functions: */

		/* Constructors: */

		vector (const allocator_type &alloc = allocator_type())
			: _alloc(alloc), _tab(nullptr), _size(0), _capacity(0)
		{};

		vector (size_type count, const T& value = T(),
										const Allocator& alloc = Allocator())
			: _alloc(alloc), _tab(nullptr), _size(count), _capacity(count)
		{
			_tab = _alloc.allocate(count);

			for(size_type i = 0; i < _size; i++)
				_alloc.construct(&_tab[i], value);
		};

		template <class InputIt>
		vector (InputIt first, InputIt last, const Allocator& alloc = Allocator())
			: _alloc(alloc)
		{
			_capacity = distance(first, last);
			_size = _capacity;
			_tab = _alloc.allocate(_capacity);

			for (size_type i = 0; i < _size; i++)
			{
				_alloc.construct(&_tab[i], *first);
				first++;
			}
		};

		vector (const vector &other)
			: _alloc(other._alloc), _size(0), _capacity(0), _tab(nullptr)
		{
			reserve(other._size);
			assign(other.begin(), other.end());
		}

		/* Destructor: */

		~vector (void)
		{
			if (_capacity > 0)
				_alloc.deallocate(_tab, _capacity);
		};

		/* operator=: */

		vector&		operator=(const vector& other)
		{
			if (&other == this)
				return (*this);
			clear();
			if (_capacity < other._size)
			{
				_alloc.deallocate(_tab, _capacity);
				_capacity = other._size;
				_tab = _alloc.allocate(_capacity);
			}
			_size = other._size;

			for (size_type i = 0; i < _size; i++)
				_alloc.construct(&_tab[i], other[i]);
			return (*this);
		};

		/* assign: */

		void 	assign(size_type count, const T& value)
		{
			clear();
			if (_capacity >= count)
			{
				_size = count;
				for (size_type i = 0; i < _size; i++)
					_alloc.construct(&_tab[i], value);
			}
			else
			{
				_alloc.deallocate(_tab, _capacity);
				_capacity = count;
				_tab = _alloc.allocate(_capacity);
				_size = count;
				for (size_type i = 0; i < _size; i++)
					_alloc.construct(&_tab[i], value);
			}
		};

		template <class InputIt>
		void 	assign(InputIt first, InputIt last)
		{
			clear();
			_size = distance(first, last);
			if (_capacity >= _size)
			{
				for (size_type i = 0; i < _size; i++)
				{
					_alloc.construct(&_tab[i], *first);
					first++;
				}
			}
			else
			{
				_alloc.deallocate(_tab, _capacity);
				_capacity = _size;
				_tab = _alloc.allocate(_capacity);
				for (size_type i = 0; i < _size; i++)
				{
					_alloc.construct(&_tab[i], *first);
					first++;
				}
			}

		};

		/* Element access: */

		reference		at(size_type pos)
		{
			if (pos >= _size)
				//throw (std::out_of_range("vector"));
				throw (std::out_of_range(
					"vector::_M_range_check: __n (which is "
					+ std::to_string(pos) + ") >= this->size() (which is "
					+ std::to_string(_size) + ")"));
			return(_tab[pos]);
		};

		const_reference	at(size_type pos) const
		{
			if (pos >= _size)
				throw (std::out_of_range("vector"));
				/*throw (std::out_of_range(
					"vector::_M_range_check: __n (which is "
					+ std::to_string(pos) + ") >= this->size() (which is "
				 	+ std::to_string(_size) + ")"));*/
			return(_tab[pos]);
		};

		reference		operator[](size_type pos)
		{
			return (_tab[pos]);
		};

		const_reference	operator[](size_type pos) const
		{
			return (_tab[pos]);
		};

		reference		front(void)
		{
			return(_tab[0]);
		};

		const reference	front(void) const
		{
			return(_tab[0]);
		};

		reference		back(void)
		{
			return(_tab[_size - 1]);
		};

		const reference	back(void) const
		{
			return(_tab[_size - 1]);
		};

		/* iterators: */

		iterator		begin(void)
		{
			return (iterator(_tab));
		};

		const_iterator	begin(void) const
		{
			return (const_iterator(_tab));
		};

		iterator		end(void)
		{
			return (iterator(_tab + _size));
		};

		const_iterator	end(void) const
		{
			return (const_iterator(_tab + _size));
		};

		reverse_iterator		rbegin(void)
		{
			return (reverse_iterator(end()));
		};

		const_reverse_iterator	rbegin(void) const
		{
			return (const_reverse_iterator(end()));
		};

		reverse_iterator		rend(void)
		{
			return (reverse_iterator(begin()));
		};

		const_reverse_iterator	rend(void) const
		{
			return (const_reverse_iterator(begin()));
		};



		/* Capacity: */

		bool		empty(void) const
		{
			return (_size == 0);
		};

		size_type	size(void) const
		{
			return (_size);
		};

		size_type	max_size(void) const
		{
			return (allocator_type().max_size());
		};

		void 	reserve(size_type new_cap)
		{
			pointer	tmp;

			if (new_cap > max_size())
				throw (std::length_error("vector::reserve"));
			else if (new_cap > _capacity)
			{
				tmp = _alloc.allocate(new_cap);
				if (_capacity > 0)
				{
					for (size_type i = 0; i < _size; i++)
						_alloc.construct(&tmp[i], _tab[i]);
					_alloc.deallocate(_tab, _capacity);
				}
				_capacity = new_cap;
				_tab = tmp;
			}
		};

		size_type	capacity(void) const
		{
			return (_capacity);
		};

		/* Modifiers: */

		void 	clear(void)
		{
			for (size_type i = 0; i < _size; i++)
				_alloc.destroy(&_tab[i]);
			_size = 0;
		};

		iterator	insert(iterator pos, const T& value)
		{
			size_t dist = distance(begin(), pos);

			if (_capacity == 0)
				reserve(1);
			else if ((_size + 1) > _capacity)
				reserve(_size * 2);
			_size++;
			for (size_t i = _size - 1; i > dist; i--)
				_alloc.construct(&_tab[i], _tab[i - 1]);
			_alloc.construct(&_tab[dist], value);
			return(iterator(_tab + dist));
		};

		void 		insert(iterator pos, size_type count, const T& value)
		{
			if (count == 0)
				return ;
			size_t dist = distance(begin(), pos);
			if ((_size + count) > _capacity)
			{
				if ((_size * 2) >= (_size + count))
					reserve(_size * 2);
				else
					reserve(_size + count);
			}
			for (size_t i = 0; i < count; i++)
				insert(begin() + dist, value);
		};

		template <class InputIt>
		void 		insert(iterator pos, InputIt first, InputIt last)
		{
			size_t dist = distance(begin(), pos);
			size_t count = distance(first, last);
			if (count == 0)
				return ;

			if ((_size + count) > _capacity)
			{
				if ((_size * 2) >= (_size + count))
					reserve(_size * 2);
				else
					reserve(_size + count);
			}
			while (first != last)
			{
				insert(begin() + dist, *first);
				dist++;
				first++;
			}

		};

		iterator	erase(iterator pos)
		{
			size_t dist = distance(begin(), pos);

			_alloc.destroy(&_tab[dist]);
			_size--;
			for (size_t i = dist; i < _size; i++)
				_tab[i] = _tab[i + 1];
			return (iterator(_tab + dist));
		};

		iterator	erase(iterator first, iterator last)
		{
			size_t	dist = distance(begin(), first);
			size_t	count = distance(first, last);

			for (size_t i = dist; i < (dist + count); i++)
				_alloc.destroy(&_tab[i]);
			_size -= count;
			for (size_t i = dist; i < _size; i++)
				_tab[i] = _tab[i + count];
			return (iterator(_tab + dist));
		};

		void 		push_back(const T& value)
		{
			if (_capacity == 0)
				reserve(1);
			else if ((_size + 1) > _capacity)
				reserve(_size * 2);
			_alloc.construct(&_tab[_size], value);
			_size++;
		};

		void 		pop_back(void)
		{
			if (_size == 0)
				return ;
			erase(--end());
		};

		void 		resize(size_type count, T value = T())
		{
			if (count > max_size())
				throw (std::length_error("vector::resize"));
			if (count < _size)
			{
				while (_size > count)
				{
					_size--;
					_alloc.destroy(&_tab[_size]);
				}
			}
			else
				insert(end(), (count - _size), value);
		};

		void 		swap(vector& other)
		{
			if (&other == this)
				return ;

			pointer		tmp_tab;
			size_type	tmp_size;
			size_type	tmp_capacity;

			tmp_tab = other._tab;
			tmp_size = other._size;
			tmp_capacity = other._capacity;

			other._tab = _tab;
			other._size = _size;
			other._capacity = _capacity;

			_tab = tmp_tab;
			_size = tmp_size;
			_capacity = tmp_capacity;
		};

		private:

		allocator_type	_alloc;
		pointer			_tab;
		size_type		_size;
		size_type		_capacity;
	};

	/* Non-Member functions: */

	template <class T, class Alloc>
	bool operator==(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		if (lhs.size() != rhs.size())
			return (false);
		for (size_t i = 0; i < lhs.size(); i++)
			if (lhs[i] != rhs[i])
				return (false);
		return (true);
	};

	template <class T, class Alloc>
	bool	operator!=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		return (!(lhs == rhs));
	};

	template <class T, class Alloc>
	bool	operator<(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		for (size_t i = 0, j = 0; i < lhs.size() && j < rhs.size(); i++, j++)
			if (lhs[i] < rhs[j])
				return (true);
			else if (lhs[i] > rhs[j])
				return (false);
		if (lhs.size() >= rhs.size())
			return (false);
		return (true);
	};

	template <class T, class Alloc>
	bool	operator<=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		return (!(rhs < lhs));
	};

	template <class T, class Alloc>
	bool	operator>(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		return (rhs < lhs);
	};

	template <class T, class Alloc>
	bool	operator>=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		return (!(lhs < rhs));
	};

	template <class T, class Alloc>
	void	swap(vector<T, Alloc> &lhs, vector<T, Alloc> &rhs)
	{
		lhs.swap(rhs);
	};

};

#endif
