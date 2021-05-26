/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StackTest.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgermai <thgermai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 16:23:37 by thgermai          #+#    #+#             */
/*   Updated: 2021/05/26 14:48:10 by tlecoeuv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "test_header.hpp"
#include "../../srcs/Stack/Stack.hpp"
#include <stack>

static void		empty_test()
{
	print_small_header("-> Empty()");

	ft::stack<int>			q;
	std::stack<int>			rq;
	bool					error = false;

	if (q.empty() != rq.empty())
		error = true;
	q.push(15);
	rq.push(15);
	if (q.empty() != rq.empty())
		error = true;
	q.pop();
	rq.pop();
	if (q.empty() != rq.empty())
		error = true;
	if (error)
		std::cerr << WRONG << REDE << BOLD << "Empty() test failed" << RESET << std::endl;
	else
		std::cout << VALID << BOLD << GREEN << " Empty() test passed" << RESET << std::endl;
	std::cout << std::endl;
}

static void		size_test()
{
	print_small_header("-> Size()");

	ft::stack<int>			q;
	std::stack<int>			rq;
	bool					error = false;

	if (q.size() != rq.size())
		error = true;
	for (int i = 0; i < 12; ++i)
	{
		q.push(42);
		rq.push(42);
	}
	if (q.size() != rq.size())
		error = true;
	for (int i = 0; i < 3; ++i)
	{
		q.pop();
		rq.pop();
	}
	if (q.size() != rq.size())
		error = true;
	if (error)
		std::cerr << WRONG << REDE << BOLD << "Size() test failed" << RESET << std::endl;
	else
		std::cout << VALID << BOLD << GREEN << " Size() test passed" << RESET << std::endl;
	std::cout << std::endl;
}

static void		back_test()
{
	print_small_header("-> Top()");

	ft::stack<int>			q;
	std::stack<int>			rq;
	bool					error = false;

	for (int i = 0; i < 10; ++i)
	{
		int rdm = rand() % 50;
		q.push(rdm);
		rq.push(rdm);
	}
	while (!q.empty())
	{
		if (q.top() != rq.top())
			error = true;
		q.pop();
		rq.pop();
	}
	if (error)
		std::cerr << WRONG << REDE << BOLD << "Top() test failed" << RESET << std::endl;
	else
		std::cout << VALID << BOLD << GREEN << " Top() test passed" << RESET << std::endl;
	std::cout << std::endl;
}

void			StackTest()
{
	print_header("stack Tester :\n");
	empty_test();
	size_test();
	back_test();
	std::cout << "Press any key to go back to main menu" << std::endl;
	std::cin.get();
}
