#ifndef RBT_ITERATOR_HPP
# define RBT_ITERATOR_HPP

#include "RBT_node.hpp"

namespace	ft
{
	template <class Pair>
	struct	RBT_iterator
	{
		typedef Pair					value_type;
		typedef	Pair&					reference;
		typedef Pair*					pointer;
		typedef	ptrdiff_t				difference_type;
		typedef	size_t					size_type;

		RBT_iterator(void) : _node(nullptr), _header(nullptr)
		{}

		RBT_iterator(RBT_node<value_type> *x, RBT_node<value_type> *h)
			: _node(x), _header(h)
		{}

		RBT_iterator(const RBT_iterator &rhs)
			: _node(rhs._node), _header(rhs._header)
		{}

		~RBT_iterator() {}

		reference		operator*(void) const
		{
			return(*(_node->pair));
		}

		pointer			operator->(void) const
		{
			return(_node->pair);
		}

		RBT_iterator	&operator=(const RBT_iterator& it)
		{
			_node = it._node;
			_header = it._header;
			return (*this);
		}

		bool			operator==(const RBT_iterator& it)
		{
			return (_node == it._node);
		}

		bool			operator!=(const RBT_iterator& it)
		{
			return (_node != it._node);
		}

		RBT_iterator	&operator++(void)
		{
			if (_node == _header->right)
				_node = _header;
			else if (!(_node->right->is_leaf()))
			{
				_node = _node->right;
				while (!(_node->left->is_leaf()))
					_node = _node->left;
			}
			else
			{
				while (_node->parent && _node == _node->parent->right)
					_node = _node->parent;
				if (_node->parent)
					_node = _node->parent;
			}
			return (*this);
		}

		RBT_iterator	operator++(int)
		{
			RBT_iterator	tmp(*this);

			operator++();
			return (tmp);
		}

		RBT_iterator	&operator--(void)
		{
			if (_node == _header)
				_node = _header->right;
			else if (!(_node->left->is_leaf()))
			{
				_node = _node->left;
				while (!(_node->right->is_leaf()))
					_node = _node ->right;
			}
			else
			{
				while (_node->parent && _node == _node->parent->left)
					_node = _node->parent;
				if (_node->parent)
					_node = _node->parent;
			}
			return(*this);
		}

		RBT_iterator	operator--(int)
		{
			RBT_iterator	tmp(*this);

			operator--();
			return (tmp);
		}



		RBT_node<value_type>	*_node;
		RBT_node<value_type>	*_header;
	};

	template <class Pair>
	struct	RBT_const_iterator
	{
		typedef Pair					value_type;
		typedef	Pair&					reference;
		typedef Pair*					pointer;
		typedef	ptrdiff_t				difference_type;
		typedef	size_t					size_type;

		RBT_const_iterator(void) : _node(nullptr)
		{}

		RBT_const_iterator(RBT_node<value_type> *x, RBT_node<value_type> *h)
			: _node(x), _header(h)
		{}

		RBT_const_iterator(const RBT_iterator<value_type> &rhs)
			: _node(rhs._node), _header(rhs._header)
		{}

		~RBT_const_iterator() {}

		reference		operator*(void) const
		{
			return(*(_node->pair));
		}

		pointer			operator->(void) const
		{
			return(_node->pair);
		}

		RBT_const_iterator	&operator=(const RBT_const_iterator& it)
		{
			_node = it._node;
			return (*this);
		}

		bool			operator==(const RBT_const_iterator& it)
		{
			return (_node == it._node);
		}

		bool			operator!=(const RBT_const_iterator& it)
		{
			return (_node != it._node);
		}

		RBT_const_iterator	&operator++(void)
		{
			if (_node == _header->right)
				_node = _header;
			else if (!(_node->right->is_leaf()))
			{
				_node = _node->right;
				while (!(_node->left->is_leaf()))
					_node = _node->left;
			}
			else
			{
				while (_node->parent && _node == _node->parent->right)
					_node = _node->parent;
				if (_node->parent)
					_node = _node->parent;
			}
			return (*this);
		}

		RBT_const_iterator	operator++(int)
		{
			RBT_const_iterator	tmp(*this);

			operator++();
			return (tmp);
		}

		RBT_const_iterator	&operator--(void)
		{
			if (_node == _header)
				_node = _header->right;
			else if (!(_node->left->is_leaf()))
			{
				_node = _node->left;
				while (!(_node->right->is_leaf()))
					_node = _node ->right;
			}
			else
			{
				while (_node->parent && _node == _node->parent->left)
					_node = _node->parent;
				if (_node->parent)
					_node = _node->parent;
			}
			return(*this);
		}

		RBT_const_iterator	operator--(int)
		{
			RBT_const_iterator	tmp(*this);

			operator--();
			return (tmp);
		}



		RBT_node<value_type>	*_node;
		RBT_node<value_type>	*_header;
	};
};

#endif
