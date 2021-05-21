#ifndef QUEUE_HPP
# define QUEUE_HPP

#include "../List/List.hpp"

namespace ft
{
	template <class T, class Container = list<T> >
	class queue
	{
	public:
		typedef T			value_type;
		typedef Container	container_type;
		typedef size_t		size_type;

		queue(const container_type &ctnr = container_type()) : _ctnr(ctnr)
		{}

		bool				empty() const
		{
			return (_ctnr.empty());
		}

		size_type			size()
		{
			return (_ctnr.size());
		}

		value_type			&front()
		{
			return (_ctnr.front());
		}

		const value_type	&front() const
		{
			return (_ctnr.front());
		}

		value_type			&back()
		{
			return (_ctnr.back());
		}

		const value_type	&back() const
		{
			return (_ctnr.back());
		}

		void	push(const value_type &val)
		{
			_ctnr.push_back(val);
		}

		void	pop()
		{
			_ctnr.pop_front();
		}

	private:
		container_type		_ctnr;

		template <class S, class C>
		friend bool	operator==(const queue<S, C> &lhs, const queue<S, C> &rhs);
		template <class S, class C>
		friend bool	operator!=(const queue<S, C> &lhs, const queue<S, C> &rhs);
		template <class S, class C>
		friend bool	operator<(const queue<S, C> &lhs, const queue<S, C> &rhs);
		template <class S, class C>
		friend bool	operator<=(const queue<S, C> &lhs, const queue<S, C> &rhs);
		template <class S, class C>
		friend bool	operator>(const queue<S, C> &lhs, const queue<S, C> &rhs);
		template <class S, class C>
		friend bool	operator>=(const queue<S, C> &lhs, const queue<S, C> &rhs);
	};

	template <class T, class Container>
	bool	operator==(const queue<T, Container> &lhs, const queue<T, Container> &rhs)
	{
		return (lhs._ctnr == rhs._ctnr);
	};
	template <class T, class Container>
	bool	operator!=(const queue<T, Container> &lhs, const queue<T, Container> &rhs)
	{
		return (lhs._ctnr != rhs._ctnr);
	};
	template <class T, class Container>
	bool	operator<(const queue<T, Container> &lhs, const queue<T, Container> &rhs)
	{
		return (lhs._ctnr < rhs._ctnr);
	};
	template <class T, class Container>
	bool	operator<=(const queue<T, Container> &lhs, const queue<T, Container> &rhs)
	{
		return (lhs._ctnr <= rhs._ctnr);
	};
	template <class T, class Container>
	bool	operator>(const queue<T, Container> &lhs, const queue<T, Container> &rhs)
	{
		return (lhs._ctnr > rhs._ctnr);
	};
	template <class T, class Container>
	bool	operator>=(const queue<T, Container> &lhs, const queue<T, Container> &rhs)
	{
		return (lhs._ctnr >= rhs._ctnr);
	};
	template <class T, class Container>
	void	swap(queue<T, Container> &x, queue<T, Container> &y)
	{
		x.swap(y);
	};
};

#endif
