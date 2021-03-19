#ifndef LIST_HPP
# define LIST_HPP

template <typename T>
struct	ListNode
{
	ListNode(const T &e) : data(e), next(0), prev(0) {}

	T				data;
	ListNode<T>		*next;
	ListNode<T> 	*previous;
};

template<typename T>
Class	List
{
public:

private:

};

#endif
