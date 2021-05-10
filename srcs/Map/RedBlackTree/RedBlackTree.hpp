#ifndef REDBLACKTREE_HPP
# define REDBLACKTREE_HPP

#include <memory>
#include <cstddef>
#include <limits>
#include <iostream>
#include <cstdio>
#include "RBT_node.hpp"
#include "RBT_iterator.hpp"

#define INDENT_STEP 4

namespace	ft
{
	template<
			class Key, class T,
			class Compare = std::less<Key>,
			class Allocator = std::allocator<std::pair<const Key, T>>
			>
	class	RedBlackTree
	{
		public:

		typedef	Key									key_type;
		typedef	T									mapped_type;
		typedef std::pair<const Key, T>				value_type;
		typedef	size_t								size_type;
		typedef	ptrdiff_t							difference_type;
		typedef Compare								key_compare;
		typedef	Allocator							allocator_type;
		typedef	typename Allocator::reference		reference;
		typedef	typename Allocator::const_reference	const_reference;
		typedef	typename Allocator::pointer			pointer;
		typedef	typename Allocator::const_pointer	const_pointer;

		typedef	RBT_iterator<value_type>			iterator;


		typedef	RBT_node<value_type>				node;

		RedBlackTree(const key_compare& comp = key_compare(),
			const allocator_type &alloc = allocator_type())
			: _alloc(alloc), _comp(comp)
		{
			_header = new node;
			_header->color = RED;
			_header->parent = nullptr;
			_header->left = _header;
			_header->right = _header;
		}

		~RedBlackTree(void)
		{
			destructor_helper(_root());
			delete _header;
		}

	public:

		node	*new_node(const value_type &p, color c)
		{
			node	*res = new node;
			node	*leaf1 = new node;
			node	*leaf2 = new node;

			res->pair = _alloc.allocate(1);
			_alloc.construct(res->pair, p);
			leaf1->pair = nullptr;
			leaf2->pair = nullptr;

			res->parent = nullptr;
			leaf1->parent = res;
			leaf2->parent = res;

			res->left = leaf1;
			res->right = leaf2;
			leaf1->left = nullptr;
			leaf1->right = nullptr;
			leaf2->left = nullptr;
			leaf2->right = nullptr;

			res->color = c;
			leaf1->color = BLACK;
			leaf2->color = BLACK;

			return (res);
		}

		/* search */

		node	*search_node(key_type k)
		{
			node	*n = _root();
			while (!n->is_leaf())
			{
				int	comp_result = _comp(k, n->pair->first);
				if (k == n->pair->first)
					return (n);
				else if (comp_result == true)
					n = n->left;
				else
					n = n->right;
			}
			return (nullptr);
		}

		void 	replace_node(node *oldn, node *newn)
		{
			if (oldn->parent == nullptr)
				_header->parent = newn;
			else
			{
				if (oldn == oldn->parent->left)
					oldn->parent->left = newn;
				else
					oldn->parent->right = newn;
			}
			newn->parent = oldn->parent;
		}

		void 	left_rotate(node *n)
		{
			node	*r = n->right;
			replace_node(n, r);
			n->right = r->left;
			if (r->left != nullptr)
				r->left->parent = n;
			r->left = n;
			n->parent = r;
		}

		void 	right_rotate(node *n)
		{
			node	*L = n->left;
			replace_node(n, L);
			n->left = L->right;
			if (L->right != nullptr)
				L->right->parent = n;
			L->right = n;
			n->parent = L;
		}

		/* Rotation: https://www.youtube.com/watch?v=95s3ndZRGbk */
		/*void 	left_rotate(node *x)
		{
			node	*y = x->right;

			x->right = y->left;			//y's left subtree -> x's right subtree.
			if (x->right != nullptr)		//handle parent links.
				x->right->parent = x;
			y->parent = x->parent;
			if (x->parent == nullptr)		//case x was root.
				_root() = y;
			else if (x == x->parent->left)	//case x is a left child.
				x->parent->left = y;
			else							//case x is a right child.
				x->parent->right = y;
			y->left = x;					//put x on y's left.
			x->parent = y;					//parent's links.
		}

		void 	right_rotate(node *x)
		{
			node	*y = x->left;

			x->left = y->right;
			if (x->left != nullptr)
				x->left->parent = x;
			y->parent = x->parent;
			if (x->parent == nullptr)
				_root() = y;
			else if (x == x->parent->left)
				x->parent->left = y;
			else
				x->parent->right = y;
			y->right = x;
			x->parent = y;
		}*/

		/*Insertion: https://iq.opengenus.org/red-black-tree-insertion/ */

		std::pair<iterator, bool> 	insert(const value_type &p)
		{
			node	*inserted_node = new_node(p, RED);
			if (_root() == nullptr)
			{
				_header->parent = inserted_node;
				_header->right = inserted_node;
				_header->left = inserted_node;
			}
			else
			{
				node	*n = _root();
				while (1)
				{
					int		comp_result = _comp(p.first, n->pair->first);
					if (p.first == n->pair->first)
						return (std::make_pair(iterator(n, _header), false));
					else if (comp_result == true)
					{
						if (n->left->is_leaf())
						{
							delete n->left;
							n->left = inserted_node;
							break ;
						}
						else
							n = n->left;
					}
					else
					{
						if (n->right->is_leaf())
						{
							delete n->right;
							n->right = inserted_node;
							break ;
						}
						else
							n = n->right;
					}
				}
				inserted_node->parent = n;
				if (n == _rightmost() && inserted_node == n->right)
					_header->right = inserted_node;
				else if (n == _leftmost() && inserted_node == n->left)
					_header->left = inserted_node;
			}
			insert_case1(inserted_node);
			return (std::make_pair(iterator(inserted_node, _header), true));
		}

		void 	insert_case1(node *n)
		{
			if (n->parent == nullptr)
				n->color = BLACK;
			else
				insert_case2(n);
		}

		void 	insert_case2(node *n)
		{
			if (n->parent->color == BLACK)
				return ;
			else
				insert_case3(n);
		}

		void 	insert_case3(node *n)
		{
			if (n->uncle() != nullptr && n->uncle()->color == RED)
			{
				n->parent->color = BLACK;
				n->uncle()->color = BLACK;
				n->grandparent()->color = RED;
				insert_case1(n->grandparent());
			}
			else
				insert_case4(n);
		}

		void 	insert_case4(node *n)
		{
			if (n == n->parent->right && n->parent == n->grandparent()->left)
			{
				left_rotate(n->parent);
				n = n->left;
			}
			else if (n == n->parent->left && n->parent == n->grandparent()->right)
			{
				right_rotate(n->parent);
				n = n->right;
			}
			insert_case5(n);
		}

		void 	insert_case5(node *n)
		{
			n->parent->color = BLACK;
			n->grandparent()->color = RED;
			if (n == n->parent->left && n->parent == n->grandparent()->left)
				right_rotate(n->grandparent());
			else if (n == n->parent->right && n->parent == n->grandparent()->right)
				left_rotate(n->grandparent());
		}

		/* Deletion: https://www.youtube.com/watch?v=eO3GzpCCUSg */

		void 	delete_node(node *n)
		{
			if (n == nullptr || n->is_leaf())
				return ;
			color	n_color = n->color;
			node	*replacement;
			node	*x;

			if (n == _leftmost())
				_header->left = n->parent;
			else if (n == _rightmost())
				_header->right = n->parent;

			if (n->left->is_leaf() && n->right->is_leaf())
			{
				replacement = x = n->right;
				delete n->left;
				n->left = nullptr;
			}
			else if (!n->left->is_leaf() && n->right->is_leaf())
			{
				replacement = x = n->left;
				delete n->right;
				n->right = nullptr;
			}
			else if (!n->right->is_leaf() && n->left->is_leaf())
			{
				replacement = x = n->right;
				delete n->left;
				n->left = nullptr;
			}
			else
			{
				replacement = n->right;
				while (!replacement->left->is_leaf())
					replacement = replacement->left;
				x = replacement->right;
			}
			delete_and_replace(n, replacement, x);
			initial_step2(replacement, x, n_color);
		}

		void 	delete_and_replace(node *n, node *replacement, node *x)
		{
			if (replacement->is_leaf() && x->is_leaf())
				replace_node(n, replacement);
			else if (replacement == x)
				replace_node(n, replacement);
			else								//peut etre leaks.
			{
				replace_node(replacement, x);
				replace_node(n, replacement);
				delete replacement->left;
				replacement->left = n->left;
				replacement->right = n->right;
				replacement->left->parent = replacement;
				replacement->right->parent = replacement;
			}
			_alloc.deallocate(n->pair, 1);
			delete n;
			n = nullptr;
		}

		void 	initial_step2(node *replacement, node *x, color n_color)
		{
			if (n_color == RED)
			{
				if (replacement->is_leaf() || replacement->color == RED)
					return ;
				else
					replacement->color = RED;
			}
			else if (n_color == BLACK
					&& (!replacement->is_leaf() && replacement->color == RED))
			{
				replacement->color = BLACK;
				return ;
			}
			choose_case(x);
		}

		void 	choose_case(node *x)
		{
			node	*w = x->sibling();

			if (x->color == RED)
				delete_case0(x);
			else
			{
				if (w->color == RED)
					delete_case1(x, w);
				else
				{
					if (w->left->color == BLACK && w->right->color == BLACK)
						delete_case2(x, w);
					else if ((x == x->parent->left && w->right->color == RED)
						|| (x == x->parent->right && w->left->color == RED))
						delete_case4(x, w);
					else
						delete_case3(x, w);
				}
			}
		}

		void 	delete_case0(node *x)
		{
			x->color = BLACK;
		}

		void 	delete_case1(node *x, node *w)
		{
			w->color = BLACK;
			x->parent->color = RED;
			if (x == x->parent->left)
				left_rotate(x->parent);
			else
				right_rotate(x->parent);
			choose_case(x);
		}

		void 	delete_case2(node *x, node *w)
		{
			w->color = RED;
			x = x->parent;
			if (x->color == RED)
				x->color = BLACK;
			else
				choose_case(x);
		}

		void 	delete_case3(node *x, node *w)
		{
			w->color = RED;
			if (x == x->parent->left)
			{
				w->left->color = BLACK;
				right_rotate(w);
			}
			else
			{
				w->right->color = BLACK;
				left_rotate(w);
			}
			w = x->sibling();
			delete_case4(x, w);
		}

		void 	delete_case4(node *x, node *w)
		{
			w->color = x->parent->color;
			x->parent->color = BLACK;
			if (x == x->parent->left)
			{
				w->right->color = BLACK;
				left_rotate(x->parent);
			}
			else
			{
				w->left->color = BLACK;
				right_rotate(x->parent);
			}
		}

		/* iterator functions: */

		iterator		begin(void)
		{
			return (iterator(_leftmost(), _header));
		}

		iterator		end(void)
		{
			return(iterator(_header, _header));
		}

		/* destroy: */

		void 	destructor_helper(node *n)
		{
			if (n == nullptr)
				return ;
			if (n->right != nullptr)
				destructor_helper(n->right);
			if (n->left != nullptr)
				destructor_helper(n->left);

			if (n->pair != nullptr)
				_alloc.deallocate(n->pair, 1);
			delete n;
			n = nullptr;
		}

		/* printer: */

		void print_tree_helper(node *n, int indent)
		{
		    int i;
		    if (n == nullptr)
		    {
		        fputs("<empty tree>", stdout);
		        return;
		    }
		    if (n->right != nullptr)
		    {
		        print_tree_helper(n->right, indent + INDENT_STEP);
		    }
		    for(i = 0; i < indent; i++)
			{
		        fputs(" ", stdout);
			}
			if (n->is_leaf())
				std::cout << "L" << std::endl;
		    else if (n->color == BLACK)
		        std::cout<<n->pair->first<<std::endl;
		    else
		        std::cout<<"<"<<n->pair->first<<">"<<std::endl;
		    if (n->left != nullptr)
		    {
		        print_tree_helper(n->left, indent + INDENT_STEP);
		    }
		}

		void print_tree(void)
		{
		    print_tree_helper(_root(), 0);
			std::cout << "right: " << _rightmost()->pair->first << std::endl;
			std::cout << "left: " << _leftmost()->pair->first << std::endl;
		    puts("");
		}

	private:

		node 	*_root(void)
		{
			return (_header->parent);
		}

		node	*_leftmost(void)
		{
			return (_header->left);
		}

		node	*_rightmost(void)
		{
			return (_header->right);
		}


		allocator_type	_alloc;
		key_compare		_comp;
		node			*_header;
	};
};

#endif
