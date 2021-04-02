#include "List.hpp"
#include <iostream>
#include <list>

void 	test_swap(void);

int		main()
{
	ft::List<int>	test;

	test.push_front(0);
	test.push_back(1);
	test.push_back(2);
	test.push_back(3);
	test.push_back(17);

	std::cout << "size: " << test.size() << std::endl;
	std::cout << "front: " << test.front() << std::endl;
	std::cout << "back: " << test.back() << std::endl;
	std::cout << "-------------------------" << std::endl;

	std::cout << "Iterators test" << std::endl;

	ft::List<int>::iterator it = test.begin();
	ft::List<int>::iterator ite = test.end();

	while (it != ite)
	{
		std::cout << *it << std::endl;
		it++;
	}

	ft::List<int>::reverse_iterator rit = test.rbegin();
	ft::List<int>::reverse_iterator rite = test.rend();

	while (rit != rite)
	{
		std::cout << *rit << std::endl;
		rit++;
	}

	std::cout << "assign test" << std::endl;
	ft::List<int> first;
  	ft::List<int> second;
 	first.assign((size_t)7,100);                      // 7 ints with value 100
 	second.assign(first.begin(),first.end()); // a copy of first
	int myints[]={1776,7,4};
	first.assign (myints,myints+3);            // assigning from array

  	std::cout << "Size of first: " << int (first.size()) << '\n';
  	std::cout << "Size of second: " << int (second.size()) << '\n';

	std::cout << "insert test" << std::endl;
	it = test.begin();
	it++;
	test.insert(it, 111);
	test.insert(it, (size_t)4, 112);
	test.insert(it, myints, myints+3);
	for(it = test.begin(); it != ite; it++)
		std::cout << *it << std::endl;

	std::cout << "erase test" << std::endl;
	it = test.begin();
	it++;
	it = test.erase(it);
	it++;
	it++;
	test.erase(it, ite);
	for(it = test.begin(); it != ite; it++)
		std::cout << *it << std::endl;

	ft::List<int>::const_iterator const_it;

	const_it = first.begin();
	ft::List<int> copy(test);

	std::cout << "test swap:" << std::endl;

	first.swap(second);
	std::cout << "Size of first: " << int (first.size()) << '\n';
  	std::cout << "Size of second: " << int (second.size()) << '\n';

  	return 0;
}
