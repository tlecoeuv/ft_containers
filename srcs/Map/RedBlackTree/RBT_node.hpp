#ifndef RBT_NODE_HPP
# define RBT_NODE_HPP

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

		bool			is_leaf(void)
		{
			if (pair == nullptr)
				return (true);
			else
				return (false);
		}
	};
};

#endif
