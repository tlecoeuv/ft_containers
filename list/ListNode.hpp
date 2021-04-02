#ifndef LISTNODE_HPP
# define LISTNODE_HPP

namespace ft
{
	template <typename T>
	struct	ListNode
	{
		T				*data;
		ListNode<T>		*next;
		ListNode<T> 	*previous;
	};
};

#endif
