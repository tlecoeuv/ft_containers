#ifndef LISTITERATOR_HPP
# define LISTITERATOR_HPP

#include "ListNode.hpp"
#include <cstddef>

namespace ft
{
	template <typename T>
	class listIterator
	{
		public:

		listIterator(void) : _node(nullptr) {}

		listIterator(listNode<T> *node) : _node(node) {}

		listIterator(const listIterator &rhs) : _node(rhs._node) {}

		~listIterator() {}

		T		operator*(void) const
		{
			return (*(_node->data));
		}

		T*		operator->(void) const
		{
			return (_node->data);
		}

		listIterator	&operator=(listIterator const &rhs)
		{
			_node = rhs._node;
			return (*this);
		}

		listIterator	&operator++()
		{
			_node = _node->next;
			return (*this);
		}

		listIterator	&operator--()
		{
			_node = _node->previous;
			return (*this);
		}

		listIterator	operator++(int)
		{
			listIterator	ret(*this);
			_node = _node->next;
			return (ret);
		}

		listIterator	operator--(int)
		{
			listIterator	ret(*this);
			_node = _node->previous;
			return (ret);
		}

		bool	operator==(const listIterator<T> &rhs) const
		{
			return ((*this)._node == rhs._node);
		}

		bool	operator!=(const listIterator<T> &rhs) const
		{
			return ((*this)._node != rhs._node);
		}

		listNode<T>		*_node;
	};

	template <typename T>
	class constlistIterator
	{
		public:

		constlistIterator(void) : _node(nullptr) {}

		constlistIterator(listNode<T> *node) : _node(node) {}

		constlistIterator(const constlistIterator &rhs) : _node(rhs._node) {}

		constlistIterator(const listIterator<T> &rhs) : _node(rhs._node) {}

		~constlistIterator() {}

		const T		operator*(void) const
		{
			return (*(_node->data));
		}

		const T*	operator->(void) const
		{
			return (_node->data);
		}

		constlistIterator	&operator=(constlistIterator const &rhs)
		{
			_node = rhs._node;
			return (*this);
		}

		constlistIterator	&operator++()
		{
			_node = _node->next;
			return (*this);
		}

		constlistIterator	&operator--()
		{
			_node = _node->previous;
			return (*this);
		}

		constlistIterator	operator++(int)
		{
			constlistIterator	ret(*this);
			_node = _node->next;
			return (ret);
		}

		constlistIterator	operator--(int)
		{
			constlistIterator	ret(*this);
			_node = _node->previous;
			return (ret);
		}

		bool	operator==(const constlistIterator<T> &rhs) const
		{
			return ((*this)._node == rhs._node);
		}

		bool	operator!=(const constlistIterator<T> &rhs) const
		{
			return ((*this)._node != rhs._node);
		}

		listNode<T>		*_node;
	};

	template <typename T>
	class ReverselistIterator
	{
		public:

		ReverselistIterator() {}

		ReverselistIterator(listNode<T> *node) : _node(node) {}

		~ReverselistIterator() {}

		T		operator*(void) const
		{
			return (*(_node->data));
		}

		T*	operator->(void) const
		{
			return (_node->data);
		}

		ReverselistIterator	&operator=(ReverselistIterator const &rhs)
		{
			_node = rhs._node;
			return (*this);
		}

		ReverselistIterator	&operator++()
		{
			_node = _node->previous;
			return (*this);
		}

		ReverselistIterator	&operator--()
		{
			_node = _node->next;
			return (*this);
		}

		ReverselistIterator	operator++(int)
		{
			ReverselistIterator	ret(*this);
			_node = _node->previous;
			return (ret);
		}

		ReverselistIterator	operator--(int)
		{
			ReverselistIterator	ret(*this);
			_node = _node->next;
			return (ret);
		}

		bool	operator==(const ReverselistIterator<T> &rhs) const
		{
			return ((*this)._node == rhs._node);
		}

		bool	operator!=(const ReverselistIterator<T> &rhs) const
		{
			return ((*this)._node != rhs._node);
		}

		listNode<T>		*_node;
	};

	template <typename T>
	class constReverselistIterator
	{
		public:

		constReverselistIterator() {}

		constReverselistIterator(listNode<T> *node) : _node(node) {}

		~constReverselistIterator() {}

		const T		operator*(void) const
		{
			return (*(_node->data));
		}

		const T*	operator->(void) const
		{
			return (_node->data);
		}

		constReverselistIterator	&operator=(constReverselistIterator const &rhs)
		{
			_node = rhs._node;
			return (*this);
		}

		constReverselistIterator	&operator++()
		{
			_node = _node->previous;
			return (*this);
		}

		constReverselistIterator	&operator--()
		{
			_node = _node->next;
			return (*this);
		}

		constReverselistIterator	operator++(int)
		{
			constReverselistIterator	ret(*this);
			_node = _node->previous;
			return (ret);
		}

		constReverselistIterator	operator--(int)
		{
			constReverselistIterator	ret(*this);
			_node = _node->next;
			return (ret);
		}

		bool	operator==(const constReverselistIterator<T> &rhs) const
		{
			return ((*this)._node == rhs._node);
		}

		bool	operator!=(const constReverselistIterator<T> &rhs) const
		{
			return ((*this)._node != rhs._node);
		}

		listNode<T>		*_node;
	};

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
};

#endif
