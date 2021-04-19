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

	template <class Iter>
	class	reverse_iterator
	{
		public:

		typedef	Iter							iterator_type;

		typedef typename Iter::value_type		value_type;
		typedef typename Iter::difference_type	difference_type;
		typedef typename Iter::reference		reference;
		typedef typename Iter::pointer			pointer;
		typedef typename Iter::size_type		size_type;

		reverse_iterator() : _it()
		{};

		reverse_iterator(Iter it) : _it(it)
		{};

		template <class U>
		reverse_iterator(const reverse_iterator<U>& other) : _it(other._it)
		{};

		~reverse_iterator(void)
		{};

		template<class U>
		reverse_iterator& operator=(const reverse_iterator<U> &other)
		{
			_it = other._it;
			return (*this);
		};

		iterator_type	base() const
		{
			return (_it);
		};

		reference	operator*() const
		{
			iterator_type tmp = _it;
			return (*(--tmp));
		};

		reverse_iterator	operator+(difference_type n) const
		{
			return (reverse_iterator(_it - n));
		};

		reverse_iterator&	operator++(void)
		{
			--_it;
			return (*this);
		};

		reverse_iterator	operator++(int)
		{
			reverse_iterator	tmp = *this;
			++(*this);
			return(tmp);
		};

		reverse_iterator	operator+=(difference_type n)
		{
			_it -= n;
			return (*this);
		};

		reverse_iterator	operator-(difference_type n) const
		{
			return (reverse_iterator(_it + n));
		};

		reverse_iterator&	operator--(void)
		{
			++_it;
			return (*this);
		};

		reverse_iterator	operator--(int)
		{
			reverse_iterator	tmp = *this;
			--(*this);
			return (tmp);
		};

		reverse_iterator	operator-=(difference_type n)
		{
			_it += n;
		};

		pointer		operator->(void) const
		{
			return (&(operator*()));
		};

		reference	operator[](difference_type n) const
		{
			return (_it[-n - 1]);
		};

		private:

		Iter	_it;
	};

	template <class Iterator>
	bool operator!= (const reverse_iterator<Iterator>& lhs,
                        const reverse_iterator<Iterator>& rhs)
	{
		return (lhs.base() != rhs.base());
	};

	template <class Iterator_L, class Iterator_R>
    bool operator!=(const reverse_iterator<Iterator_L>& lhs,
                        const reverse_iterator<Iterator_R>& rhs)
	{
		return (lhs.base() != rhs.base());
	};

	template <class Iterator>
    bool operator<(const reverse_iterator<Iterator>& lhs,
                        const reverse_iterator<Iterator>& rhs)
	{
		return (lhs.base() > rhs.base());
	};

	template <class Iterator_L, class Iterator_R>
	bool operator<(const reverse_iterator<Iterator_L>& lhs,
					   const reverse_iterator<Iterator_R>& rhs)
	{
		return (lhs.base() > rhs.base());
	};

	template <class Iterator>
    bool operator<=(const reverse_iterator<Iterator>& lhs,
                        const reverse_iterator<Iterator>& rhs)
	{
		return (lhs.base() >= rhs.base());
	};

	template <class Iterator_L, class Iterator_R>
    bool operator<=(const reverse_iterator<Iterator_L>& lhs,
                        const reverse_iterator<Iterator_R>& rhs)
	{
		return (lhs.base() >= rhs.base());
	};

	template <class Iterator>
    bool operator>(const reverse_iterator<Iterator>& lhs,
                        const reverse_iterator<Iterator>& rhs)
	{
		return (lhs.base() < rhs.bash());
	};

	template <class Iterator_L, class Iterator_R>
    bool operator>(const reverse_iterator<Iterator_L>& lhs,
                        const reverse_iterator<Iterator_R>& rhs)
	{
		return (lhs.base() < rhs.base());
	};

	template <class Iterator>
    bool operator>=(const reverse_iterator<Iterator>& lhs,
                        const reverse_iterator<Iterator>& rhs)
	{
		return (lhs.base() <= rhs.base());
	};

	template <class Iterator_L, class Iterator_R>
    bool operator>=(const reverse_iterator<Iterator_L>& lhs,
                        const reverse_iterator<Iterator_R>& rhs)
	{
		return (lhs.base() <= rhs.base());
	};

	template <class Iterator>
    reverse_iterator<Iterator>operator+
			(typename reverse_iterator<Iterator>::difference_type n,
            	const reverse_iterator<Iterator>& rev_it)
	{
		return (rev_it + n);
	};

	template <class Iterator>
    typename reverse_iterator<Iterator>::difference_type operator-(
            const reverse_iterator<Iterator>& lhs,
            const reverse_iterator<Iterator>& rhs)
	{
		return (lhs.base() - rhs.base());
	};


};

#endif
