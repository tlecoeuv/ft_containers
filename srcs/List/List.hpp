#ifndef LIST_HPP
# define LIST_HPP

#include <memory>
#include <cstddef>
#include <limits>
#include <iostream>
#include "ListNode.hpp"
#include "ListIterator.hpp"
#include "../utils/iteratorUtils.hpp"

namespace ft
{
	template <class T, class Allocator = std::allocator<T> >
	class	list
	{
		public:

		typedef	T			value_type;
		typedef	Allocator	allocator_type;
		typedef	T*			pointer;
		typedef	const T*	const_pointer;
		typedef T&			reference;
		typedef	const T&	const_reference;
		typedef	size_t		size_type;
		typedef	ptrdiff_t	difference_type;

		typedef listIterator<T>				iterator;
		typedef constlistIterator<T>		const_iterator;
		typedef	ReverselistIterator<T>		reverse_iterator;
		typedef constReverselistIterator<T>	const_reverse_iterator;

		/* Constructors: */

		list(const allocator_type &alloc = allocator_type())
		{
			_alloc = alloc;
			_init_list();
		};

		list(size_type count, const T& value = T(), const Allocator& alloc = Allocator())
		{
			_alloc = alloc;
			_init_list();
			assign(count, value);
		};

		template <class InputIt>
		list(InputIt  first, InputIt last, const Allocator& alloc = Allocator())
		{
			_alloc = alloc;
			_init_list();
			assign(first, last);
		};

		list(const list& other)
		{
			_alloc = other._alloc;
			_init_list();
			assign(other.begin(), other.end());
		};

		/* Destructors: */

		~list(void)
		{
			clear();
			_alloc.deallocate(_root->data, 1);
			delete _root;
		};

		/* operator= */

		list	&operator=(const list &rhs)
		{
			if (this != &rhs)
			{
				_alloc = rhs._alloc;
				assign(rhs.begin(), rhs.end());
			}
			return (*this);
		}

		/* Element access: */

		reference			front(void)
		{
			return (*_root->next->data);
		};

		const_reference		front(void) const
		{
			return (*_root->next->data);
		};

		reference			back(void)
		{
			return (*_root->previous->data);
		};

		const_reference		back(void) const
		{
			return (*_root->previous->data);
		};

		/* iterators: */

		iterator		begin(void)
		{
			return (iterator(_root->next));
		};

		const_iterator	begin(void) const
		{
			return (const_iterator(_root->next));
		};

		iterator		end(void)
		{
			return (iterator(_root));
		};

		const_iterator	end(void) const
		{
			return (const_iterator(_root));
		};

		reverse_iterator rbegin()
		{
			return (reverse_iterator(_root->previous));
		};

		reverse_iterator rend()
		{
			return (reverse_iterator(_root));
		};

		/* Capacity: */

		bool		empty() const
		{
			if (_size == 0)
				return (true);
			return (false);
		};

		size_type	size(void) const
		{
			return (_size);
		};

		size_type	max_size(void) const
		{
			return (std::numeric_limits<size_type>::max() / sizeof(listNode<T>));
		};

		/* Modifiers: */

		template <class InputIterator>
		void 	assign(InputIterator first, InputIterator last)
		{
			if (!empty())
				clear();
			while (first != last)
			{
				push_back(*first);
				first++;
			}
		};

		void 	assign(size_type n, const T& val)
		{
			if (!empty())
				clear();
			for (size_type i = 0; i < n; i++)
				push_back(val);
		};

		void 	push_back(const T& value)
		{
			listNode<T> *new_node = new listNode<T>;
			new_node->data = _alloc.allocate(1);
			_alloc.construct(new_node->data, value);
			if (empty())
			{
				_root->next = new_node;
				_root->previous = new_node;
				new_node->next = _root;
				new_node->previous = _root;
			}
			else
			{
				new_node->previous = _root->previous;
				new_node->next = _root;
				_root->previous->next = new_node;
				_root->previous = new_node;
			}
			_size++;
		};

		void 	pop_back(void)
		{
			if (empty())
				return ;

			listNode<T> *to_delete = _root->previous;
			_root->previous = to_delete->previous;
			_root->previous->next = _root;

			_alloc.deallocate(to_delete->data, 1);
			delete to_delete;
			_size--;
		};


		void 	push_front(const T& value)
		{
			listNode<T> *new_node = new listNode<T>;
			new_node->data = _alloc.allocate(1);
			_alloc.construct(new_node->data, value);
			if (empty())
			{
				_root->next = new_node;
				_root->previous = new_node;
				new_node->next = _root;
				new_node->previous = _root;
			}
			else
			{
				new_node->previous = _root;
				new_node->next = _root->next;
				_root->next->previous = new_node;
				_root->next = new_node;
			}
			_size++;
		};

		void 	pop_front(void)
		{
			if (empty())
				return ;

			listNode<T> *to_delete = _root->next;
			_root->next = to_delete->next;
			_root->next->previous = _root;

			_alloc.deallocate(to_delete->data, 1);
			delete to_delete;
			_size--;
		};

		iterator	insert(iterator pos, const T& value)
		{
			iterator	it;
			listNode<T>	*new_node = new listNode<T>;
			new_node->data = _alloc.allocate(1);
			_alloc.construct(new_node->data, value);
			listNode<T>	*ptr;

			it = begin();
			ptr = _root->next;
			while (it != pos && ptr != _root)
			{
				ptr = ptr->next;
				it++;
			}
			new_node->previous = ptr->previous;
			ptr->previous = new_node;
			new_node->next = ptr;
			new_node->previous->next = new_node;
			_size++;
			return (iterator(new_node));
		};

		void 		insert(iterator pos, size_type count, const T& value)
		{
			for (size_t i = 0; i < count; i++)
				insert(pos, value);
		};

		template <class InputIt>
		void 		insert(iterator pos, InputIt first, InputIt last)
		{
			while (first != last)
			{
				insert(pos, *first);
				first++;
			}

		};

		iterator	erase(iterator pos)
		{
			listNode<T>	*ptr;
			listNode<T> *ret;

			if (pos == --end())
			{
				pop_back();
				return (begin());
			}
			ptr = pos._node;
			ret = ptr->next;
			ptr->previous->next = ptr->next;
			ptr->next->previous = ptr->previous;
			_alloc.deallocate(ptr->data, 1);
			delete ptr;
			_size--;

			return (iterator(ret));
		};

		iterator	erase(iterator first, iterator last)
		{
			iterator	to_erase;

			while (first != last)
			{
				to_erase = first;
				first++;
				erase(to_erase);
			}
			return (last);
		};

		void 		swap(list& other)
		{
			list	save(other);
			other = *this;
			*this = save;
		};

		void 		resize(size_type n, value_type val = value_type())
		{
			if (_size > n)
			{
				while (_size > n)
					pop_back();
			}
			else if (_size < n)
			{
				while (_size < n)
					push_back(val);
			}
		};

		void 		clear(void)
		{
			if (empty())
				return ;
			listNode<T> *to_delete;
			listNode<T> *next_node;
			to_delete = _root->next;
			while (to_delete != _root)
			{
				next_node = to_delete->next;
				_alloc.deallocate(to_delete->data, 1);
				delete to_delete;
				to_delete = next_node;
			}
			_size = 0;
			_root->next = _root;
			_root->previous = _root;
		};

		/* Operations: */

		void 	splice(iterator position, list& x)
		{
			splice(position, x, x.begin(), x.end());
		};

		void 	splice(iterator position, list& x, iterator i)
		{
			i._node->previous->next = i._node->next;
			i._node->next->previous = i._node->previous;

			i._node->next = position._node;
			i._node->previous = position._node->previous;
			i._node->previous->next = i._node;
			i._node->next->previous = i._node;

			x._size--;
			_size++;
		};

		void 	splice(iterator position, list& x, iterator first, iterator last)
		{
			size_t	dist = distance(first, last);
			listNode<T>		*x_before_first = first._node->previous;
			listNode<T>		*x_before_last = last._node->previous;
			listNode<T>		*pos = position._node;
			listNode<T>		*before_pos = position._node->previous;

			before_pos->next = first._node;
			pos->previous = x_before_last;
			first._node->previous = before_pos;
			x_before_last->next = pos;

			x_before_first->next = last._node;
			last._node->previous = x_before_first;

			x._size = x._size - dist;
			_size = _size + dist;
		};

		void 	remove(const value_type& val)
		{
			iterator ite = end();
			for (iterator it = begin(); it != ite; it++)
			{
				if (*it == val)
				{
					it = erase(it);
					it--;
				}
			}
		};

		template <class Predicate>
		void 	remove_if(Predicate pred)
		{
			iterator ite = end();
			for (iterator it = begin(); it != ite; it++)
			{
				if (pred(*it))
				{
					it = erase(it);
					it--;
				}
			}
		};

		void 	unique(void)
		{
			if (_size <= 1)
				return ;
			iterator	ite = end();
			iterator	it = begin();
			iterator	prev = begin();
			it++;

			while (it != ite)
			{
				if (*it == *prev)
				{
					it = erase(it);
				}
				else
				{
					prev++;
					it++;
				}
			}
		};

		template <class BinaryPredicate>
		void 	unique(BinaryPredicate binary_pred)
		{
			if (_size <= 1)
				return ;
			iterator	ite = end();
			iterator	it = begin();
			iterator	prev = begin();
			it++;

			while (it != ite)
			{
				if (binary_pred(*it, *prev))
				{
					it = erase(it);
				}
				else
				{
					prev++;
					it++;
				}
			}
		};

		void 	merge(list& x)
		{
			if (&x == this || x.empty())
				return ;

			iterator	it_this = begin();
			iterator	ite_this = end();
			iterator	it_x = x.begin();
			iterator	ite_x = x.end();

			while(it_x != ite_x)
			{
				if (it_this != ite_this && *it_this < *it_x)
					it_this++;
				else
				{
					iterator	to_splice = it_x;
					it_x++;
					splice(it_this, x, to_splice);
				}
			}
		};

		template <class Compare>
		void 	merge(list& x, Compare comp)
		{
			if (&x == this || x.empty())
				return ;

			iterator	it_this = begin();
			iterator	ite_this = end();
			iterator	it_x = x.begin();
			iterator	ite_x = x.end();

			while(it_x != ite_x)
			{
				if (it_this != ite_this && comp(*it_this, *it_x))
					it_this++;
				else
				{
					iterator	to_splice = it_x;
					it_x++;
					splice(it_this, x, to_splice);
				}
			}
		};

		void 	sort(void)
		{
			listNode<T>		*ptr1 = _root->next;
			listNode<T>		*ptr2;
			listNode<T>		*save;
			listNode<T>		*min;

			while (ptr1 != _root)
			{
				ptr2 = ptr1;
				min = ptr1;
				while (ptr2 != _root)
				{
					if (*(ptr2->data) < *(min->data))
						min = ptr2;
					ptr2 = ptr2->next;
				}
				_swap_nodes(min, ptr1);
				save = min;
				min = ptr1;
				ptr1 = save;
				ptr1 = ptr1->next;
			}
		};

		template <class Compare>
		void 	sort(Compare comp)
		{
			listNode<T>		*ptr1 = _root->next;
			listNode<T>		*ptr2;
			listNode<T>		*save;
			listNode<T>		*min;

			while (ptr1 != _root)
			{
				ptr2 = ptr1;
				min = ptr1;
				while (ptr2 != _root)
				{
					if (comp(*(ptr2->data), *(min->data)))
						min = ptr2;
					ptr2 = ptr2->next;
				}
				_swap_nodes(min, ptr1);
				save = min;
				min = ptr1;
				ptr1 = save;
				ptr1 = ptr1->next;
			}
		};

		void 	reverse(void)
		{
			listNode<T>		*save;
			listNode<T>		*ptr;
			if (_size == 0)
				return ;

			save = _root->next;
			_root->next = _root->previous;
			_root->previous = save;
			ptr = _root->next;
			while (ptr != _root)
			{
				save = ptr->next;
				ptr->next = ptr->previous;
				ptr->previous = save;
				ptr = ptr->next;
			}
		};

		private:

		listNode<T>		*_root;
		size_type		_size;
		allocator_type	_alloc;

		void 	_init_list(void)
		{
			_root = new listNode<T>;
			_root->data = _alloc.allocate(1);
			_alloc.construct(_root->data, T());
			_root->previous = _root;
			_root->next = _root;
			_size = 0;
		};

		void 	_swap_nodes(listNode<T> *a, listNode<T> *b)
		{
			listNode<T>		*save_next = b->next;
			listNode<T>		*save_previous = b->previous;
			listNode<T>		*save;

			if (a == b)
				return ;

			if (a->next == b || a->previous == b)
			{
				if (a->previous == b)
				{
					save = a;
					a = b;
					b = save;
				}
				b->previous = a->previous;
				a->previous = b;
				a->next = b->next;
				b->next = a;
			}
			else
			{
				b->next = a->next;
				b->previous = a->previous;
				a->next = save_next;
				a->previous = save_previous;
			}
			a->previous->next = a;
			a->next->previous = a;
			b->previous->next = b;
			b->next->previous = b;
		}
	};

	/* Non-member function overloads: */

	template <class T, class Alloc>
	bool	operator==(const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
	{
		if (lhs.size() != rhs.size())
			return (false);
		constlistIterator<T>	itl = lhs.begin();
		constlistIterator<T>	itr = rhs.begin();
		constlistIterator<T>	itle = lhs.end();
		constlistIterator<T>	itre = rhs.end();

		while (itl != itle && itr != itre)
		{
			if (*itl != *itr)
				return (false);
			itl++;
			itr++;
		}
		return (true);
	};

	template <class T, class Alloc>
	bool	operator!=(const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
	{
		return (!(lhs == rhs));
	};

	template <class T, class Alloc>
	bool 	operator<(const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
	{
		constlistIterator<T>	itl = lhs.begin();
		constlistIterator<T>	itr = rhs.begin();
		constlistIterator<T>	itle = lhs.end();
		constlistIterator<T>	itre = rhs.end();
		while (itl != itle && itr != itre)
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
	};

	template <class T, class Alloc>
	bool	operator<=(const list<T, Alloc> &lhs, const list<T, Alloc> &rhs) {
		return (!(rhs < lhs));
	};

	template <class T, class Alloc>
	bool	operator>(const list<T, Alloc> &lhs, const list<T, Alloc> &rhs) {
		return (rhs < lhs);
	};

	template <class T, class Alloc>
	bool	operator>=(const list<T, Alloc> &lhs, const list<T, Alloc> &rhs) {
		return (!(lhs < rhs));
	};

	template <class T, class Alloc>
	void	swap (list<T, Alloc> &x, list<T, Alloc> &y) {
		x.swap(y);
	};
};

#endif
