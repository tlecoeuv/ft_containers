#ifndef LISTITERATOR_HPP
# define LISTITERATOR_HPP

#include "ListNode.hpp"
#include <cstddef>

namespace ft
{
	template <typename T>
	class ListIterator
	{
		public:

		ListIterator(void) : _node(nullptr) {}

		ListIterator(ListNode<T> *node) : _node(node) {}

		ListIterator(const ListIterator &rhs) : _node(rhs._node) {}

		~ListIterator() {}

		T		operator*(void) const
		{
			return (*(_node->data));
		}

		T*		operator->(void) const
		{
			return (_node->data);
		}

		ListIterator	&operator=(ListIterator const &rhs)
		{
			_node = rhs._node;
			return (*this);
		}

		ListIterator	&operator++()
		{
			_node = _node->next;
			return (*this);
		}

		ListIterator	&operator--()
		{
			_node = _node->previous;
			return (*this);
		}

		ListIterator	operator++(int)
		{
			ListIterator	ret(*this);
			_node = _node->next;
			return (ret);
		}

		ListIterator	operator--(int)
		{
			ListIterator	ret(*this);
			_node = _node->previous;
			return (ret);
		}

		bool	operator==(ListIterator<T> &rhs) const
		{
			return ((*this)._node == rhs._node);
		}

		bool	operator!=(ListIterator<T> &rhs) const
		{
			return ((*this)._node != rhs._node);
		}

		ListNode<T>		*_node;
	};

	template <typename T>
	class constListIterator
	{
		public:

		constListIterator(void) : _node(nullptr) {}

		constListIterator(ListNode<T> *node) : _node(node) {}

		constListIterator(const constListIterator &rhs) : _node(rhs._node) {}

		constListIterator(const ListIterator<T> &rhs) : _node(rhs._node) {}

		~constListIterator() {}

		T		operator*(void) const
		{
			return (*(_node->data));
		}

		T*		operator->(void) const
		{
			return (_node->data);
		}

		constListIterator	&operator=(constListIterator const &rhs)
		{
			_node = rhs._node;
			return (*this);
		}

		constListIterator	&operator++()
		{
			_node = _node->next;
			return (*this);
		}

		constListIterator	&operator--()
		{
			_node = _node->previous;
			return (*this);
		}

		constListIterator	operator++(int)
		{
			constListIterator	ret(*this);
			_node = _node->next;
			return (ret);
		}

		constListIterator	operator--(int)
		{
			constListIterator	ret(*this);
			_node = _node->previous;
			return (ret);
		}

		bool	operator==(constListIterator<T> &rhs) const
		{
			return ((*this)._node == rhs._node);
		}

		bool	operator!=(constListIterator<T> &rhs) const
		{
			return ((*this)._node != rhs._node);
		}


		private:

		ListNode<T>		*_node;
	};

	template <typename T>
	class ReverseListIterator
	{
		public:

		ReverseListIterator() {}

		ReverseListIterator(ListNode<T> *node) : _node(node) {}

		~ReverseListIterator() {}

		T		operator*(void) const
		{
			return (*(_node->data));
		}

		T*		operator->(void) const
		{
			return (_node->data);
		}

		ReverseListIterator	&operator=(ReverseListIterator const &rhs)
		{
			_node = rhs._node;
			return (*this);
		}

		ReverseListIterator	&operator++()
		{
			_node = _node->previous;
			return (*this);
		}

		ReverseListIterator	&operator--()
		{
			_node = _node->next;
			return (*this);
		}

		ReverseListIterator	operator++(int)
		{
			ReverseListIterator	ret(*this);
			_node = _node->previous;
			return (ret);
		}

		ReverseListIterator	operator--(int)
		{
			ReverseListIterator	ret(*this);
			_node = _node->next;
			return (ret);
		}

		bool	operator==(ReverseListIterator<T> &rhs) const
		{
			return ((*this)._node == rhs._node);
		}

		bool	operator!=(ReverseListIterator<T> &rhs) const
		{
			return ((*this)._node != rhs._node);
		}


		private:

		ListNode<T>		*_node;
	};
};

#endif
