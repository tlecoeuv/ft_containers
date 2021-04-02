#ifndef LIST_HPP
# define LIST_HPP

#include <memory>
#include <cstddef>
#include <limits>
#include "ListNode.hpp"
#include "ListIterator.hpp"

namespace ft
{
	template <class T, class Allocator = std::allocator<T>>
	class	List
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

		typedef ListIterator<T>			iterator;
		typedef constListIterator<T>	const_iterator;
		typedef	ReverseListIterator<T>	reverse_iterator;

		/* Constructors: */

		List(const allocator_type &alloc = allocator_type())
		{
			_alloc = alloc;
			_init_List();
		};

		List(size_type count, const T& value = T(), const Allocator& alloc = Allocator())
		{
			_alloc = alloc;
			_init_List();
			assign(count, value);
		};

		template <class InputIt>
		List(InputIt  first, InputIt last, const Allocator& alloc = Allocator())
		{
			_alloc = alloc;
			_init_List();
			assign(first, last);
		};

		List(const List& other)
		{
			_alloc = other._alloc;
			_init_List();
			assign(other.begin(), other.end());
		};

		/* Destructors: */

		~List(void)
		{
			clear();
			_alloc.deallocate(_root->data, 1);
			delete _root;
		};

		/* operator= */

		List	&operator=(const List &rhs)
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
			return (std::numeric_limits<size_type>::max() / sizeof(ListNode<T>));
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
			ListNode<T> *new_node = new ListNode<T>;
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

			ListNode<T> *to_delete = _root->previous;
			_root->previous = to_delete->previous;
			_root->previous->next = _root;

			_alloc.deallocate(to_delete->data, 1);
			delete to_delete;
			_size--;
		};


		void 	push_front(const T& value)
		{
			ListNode<T> *new_node = new ListNode<T>;
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

			ListNode<T> *to_delete = _root->next;
			_root->next = to_delete->next;
			_root->next->previous = _root;

			_alloc.deallocate(to_delete->data, 1);
			delete to_delete;
			_size--;
		};

		iterator	insert(iterator pos, const T& value)
		{
			iterator	it;
			ListNode<T>	*new_node = new ListNode<T>;
			new_node->data = _alloc.allocate(1);
			_alloc.construct(new_node->data, value);
			ListNode<T>	*ptr;

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
			iterator	it;
			ListNode<T>	*ptr;
			ListNode<T> *ret;

			it = begin();
			ptr = _root->next;
			while (it != pos && ptr != _root)
			{
				ptr = ptr->next;
				it++;
			}
			ptr->previous->next = ptr->next;
			ptr->next->previous = ptr->previous;
			ret = ptr->next;
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

		void 		swap(List& other)
		{
			List	save(other);
			other = *this;
			*this = save;
		};

		void 		clear(void)
		{
			if (empty())
				return ;
			ListNode<T> *to_delete;
			ListNode<T> *next_node;
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

		/* non-member functions: */




		private:

		ListNode<T>		*_root;
		size_type		_size;
		allocator_type	_alloc;

		void 	_init_List(void)
		{
			_root = new ListNode<T>;
			_root->data = _alloc.allocate(1);
			_alloc.construct(_root->data, T());
			_root->previous = _root;
			_root->next = _root;
			_size = 0;
		};
	};
};

#endif
