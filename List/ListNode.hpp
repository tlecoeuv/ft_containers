#ifndef LISTNODE_HPP
# define LISTNODE_HPP

namespace ft
{
	template <typename T>
	struct	listNode
	{
		T				*data;
		listNode<T>		*next;
		listNode<T> 	*previous;
	};
};

#endif
