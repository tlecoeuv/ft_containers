#ifndef REDBLACKTREE_HPP
# define REDBLACKTREE_HPP

#include <memory>
#include <cstddef>
#include <limits>
#include <iostream>
#include <cstdio>

#define INDENT_STEP 4

namespace	ft
{
	enum  	color
	{
		RED,
		BLACK
	};

	template <class	Pair>
	struct		RBT_node
	{
		color		color;
		Pair		*pair;
		RBT_node	*left;
		RBT_node	*right;
		RBT_node	*parent;

		/* get relationnals: */

		RBT_node		*grandparent(void)
		{
			if (parent == nullptr)
				return nullptr;
			return (parent->parent);
		}

		RBT_node		*sibling(void)
		{
			if (parent == nullptr)
				return nullptr;
			if (this == parent->left)
				return (parent->right);
			else
				return (parent->left);
		}

		RBT_node		*uncle(void)
		{
			if (parent == nullptr)
				return nullptr;
			if (grandparent() == nullptr)
				return nullptr;
			return (parent->sibling());
		}
	};

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

		typedef	RBT_node<value_type>				node;

		RedBlackTree(const key_compare& comp = key_compare(),
			const allocator_type &alloc = allocator_type())
			: _alloc(alloc), _comp(comp), _root(nullptr)
		{};

		~RedBlackTree(void)
		{};

	public:

		node	*new_node(const value_type &p, color c)
		{
			node	*res = new node;

			res->pair = _alloc.allocate(1);
			_alloc.construct(res->pair, p);

			res->parent = nullptr;
			res->left = nullptr;
			res->right = nullptr;
			res->color = c;

			return (res);
		}

		void 	replace_node(node *oldn, node *newn)
		{
			if (oldn->parent == nullptr)
				_root = newn;
			else
			{
				if (oldn == oldn->parent->left)
					oldn->parent->left = newn;
				else
					oldn->parent->right = newn;
			}
			if (newn != nullptr)
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
				_root = y;
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
				_root = y;
			else if (x == x->parent->left)
				x->parent->left = y;
			else
				x->parent->right = y;
			y->right = x;
			x->parent = y;
		}*/

		/*Insertion: https://iq.opengenus.org/red-black-tree-insertion/ */

		void 	insert(const value_type &p)
		{
			node	*inserted_node = new_node(p, RED);
			if (_root == nullptr)
				_root = inserted_node;
			else
			{
				node	*n = _root;
				while (1)
				{
					int		comp_result = _comp(p.first, n->pair->first);
					if (p.first == n->pair->first)
					{
						std::cout << "key already exist" << std::endl;
						return ;
					}
					else if (comp_result == true)
					{
						if (n->left == nullptr)
						{
							n->left = inserted_node;
							break ;
						}
						else
							n = n->left;
					}
					else
					{
						if (n->right == nullptr)
						{
							n->right = inserted_node;
							break ;
						}
						else
							n = n->right;
					}
				}
				inserted_node->parent = n;
			}
			insert_case1(inserted_node);
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
		        fputs(" ", stdout);
		    if (n->color == BLACK)
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
		    print_tree_helper(_root, 0);
		    puts("");
		}


		allocator_type	_alloc;
		key_compare		_comp;
		node			*_root;
	};
};

#endif
