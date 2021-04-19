#ifndef VECTORITERATOR_HPP
# define VECTORITERATOR_HPP

#include <cstddef>

namespace ft
{
	template <typename T>
	class	vectorIterator
	{
		public:

		typedef	vectorIterator<T>	iterator;
		typedef	T					value_type;
		typedef	ptrdiff_t			difference_type;
		typedef	T&					reference;
		typedef T*					pointer;
		typedef	size_t				size_type;

		vectorIterator() : _ptr(nullptr)
		{};

		vectorIterator(pointer ptr) : _ptr(ptr)
		{};

		vectorIterator(const iterator &x) : _ptr(x._ptr)
		{};

		~vectorIterator(void)
		{};

		iterator	&operator=(const iterator &rhs)
		{
			_ptr = rhs._ptr;
			return (*this);
		};

		bool		operator==(const iterator &rhs) const
		{
			return (_ptr == rhs._ptr);
		};

		bool		operator!=(const iterator &rhs) const
		{
			return (_ptr != rhs._ptr);
		};

		reference	operator*(void) const
		{
			return (*_ptr);
		};

		pointer		operator->(void) const
		{
			return (&(operator*()));
		};

		iterator	&operator++(void)
		{
			_ptr++;
			return (*this);
		};

		iterator	operator++(int)
		{
			iterator tmp(*this);
			_ptr++;
			return (tmp);
		};

		iterator	&operator--(void)
		{
			_ptr--;
			return (*this);
		};

		iterator	operator--(int)
		{
			iterator tmp(*this);
			_ptr--;
			return (tmp);
		};

		iterator	operator+(difference_type n) const
		{
			return (_ptr + n);
		};

		iterator	operator-(difference_type n) const
		{
			return (_ptr - n);
		};

		iterator	&operator+=(difference_type n)
		{
			_ptr += n;
			return (*this);
		};

		iterator	&operator-=(difference_type n)
		{
			_ptr -= n;
			return (*this);
		};

		bool	operator<(const iterator &rhs) const
		{
			return (_ptr < rhs._ptr);
		};

		bool	operator>(const iterator &rhs) const
		{
			return (_ptr > rhs._ptr);
		};

		bool	operator<=(const iterator &rhs) const
		{
			return (_ptr <= rhs._ptr);
		};

		bool	operator>=(const iterator &rhs) const
		{
			return (_ptr >= rhs._ptr);
		};

		reference	operator[](size_type n) const
		{
			return (_ptr[n]);
		}

		operator	vectorIterator<const T> () const
		{
			return (vectorIterator<const T>(this->_ptr));
		}


		private:

		pointer		_ptr;
	};

	/*template <typename T>
	class	reverseVectorIterator
	{
		public:

		typedef	reverseVectorIterator<T>	iterator;
		typedef	T							value_type;
		typedef	ptrdiff_t					difference_type;
		typedef	T&							reference;
		typedef T*							pointer;
		typedef	size_t						size_type;

		reverseVectorIterator() : _ptr(nullptr)
		{};

		reverseVectorIterator(pointer ptr) : _ptr(ptr)
		{};

		reverseVectorIterator(const iterator &x) : _ptr(x._ptr)
		{};

		~reverseVectorIterator(void)
		{};

		iterator	&operator=(const iterator &rhs)
		{
			_ptr = rhs._ptr;
			return (*this);
		};

		bool		operator==(const iterator &rhs) const
		{
			return (_ptr == rhs._ptr);
		};

		bool		operator!=(const iterator &rhs) const
		{
			return (_ptr != rhs._ptr);
		};

		reference	operator*(void) const
		{
			return (*_ptr);
		};

		pointer		operator->(void) const
		{
			return (&(operator*()));
		};

		iterator	&operator++(void)
		{
			_ptr++;
			return (*this);
		};

		iterator	operator++(int)
		{
			iterator tmp(*this);
			_ptr++;
			return (tmp);
		};

		iterator	&operator--(void)
		{
			_ptr--;
			return (*this);
		};

		iterator	operator--(int)
		{
			iterator tmp(*this);
			_ptr--;
			return (tmp);
		};

		iterator	operator+(difference_type n) const
		{
			return (_ptr + n);
		};

		iterator	operator-(difference_type n) const
		{
			return (_ptr - n);
		};

		iterator	&operator+=(difference_type n)
		{
			_ptr += n;
			return (*this);
		};

		iterator	&operator-=(difference_type n)
		{
			_ptr -= n;
			return (*this);
		};

		bool	operator<(const iterator &rhs) const
		{
			return (_ptr < rhs._ptr);
		};

		bool	operator>(const iterator &rhs) const
		{
			return (_ptr > rhs._ptr);
		};

		bool	operator<=(const iterator &rhs) const
		{
			return (_ptr <= rhs._ptr);
		};

		bool	operator>=(const iterator &rhs) const
		{
			return (_ptr >= rhs._ptr);
		};

		reference	operator[](size_type n) const
		{
			return (_ptr[n]);
		}

		operator	reverseVectorIterator<const T> () const
		{
			return (reverseVectorIterator<const T>(this->_ptr));
		}


		private:

		pointer		_ptr;
	};*/
};

#endif
