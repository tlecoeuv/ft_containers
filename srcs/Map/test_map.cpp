#include "Map.hpp"

int		main()
{
	ft::map<int, int>			test;
	ft::map<int, int>::iterator	it1;
	ft::map<int, int>::iterator	it2;

	std::cout << "test.empty(): " << test.empty() << std::endl;

	it1 = (test.insert(std::pair<int, int>(5, 5))).first;
	test.insert(std::pair<int, int>(2, 2));
	test.insert(std::pair<int, int>(8, 8));
	test.insert(std::pair<int, int>(1, 1));
	test.insert(std::pair<int, int>(4, 4));
	it2 = test.insert(it1, std::pair<int, int>(7, 7));
	test.insert(std::pair<int, int>(9, 9));

	std::cout << "it 1: " << (*it1).first << " it2: " << (*it2).first << std::endl;

	for (ft::map<int, int>::iterator it = test.begin(); it != test.end(); it++)
		std::cout << " "<< (*it).first;
	std::cout << std::endl;

	for (ft::map<int, int>::reverse_iterator it = test.rbegin(); it != test.rend(); it++)
		std::cout << " "<< (*it).first;
	std::cout << std::endl;

	for (ft::map<int, int>::const_iterator it = test.begin(); it != test.end(); it++)
		std::cout << " "<< (*it).first;
	std::cout << std::endl;

	for (ft::map<int, int>::const_reverse_iterator it = test.rbegin(); it != test.rend(); it++)
		std::cout << " "<< (*it).first;
	std::cout << std::endl;

	std::cout << test[8] << std::endl;
	std::cout << test[12] << std::endl;
	std::cout << "test contains " << test.size() << " elements.\n";
	std::cout << "test.empty(): " << test.empty() << std::endl;

	test.erase(test.begin());
	for (ft::map<int, int>::iterator it = test.begin(); it != test.end(); it++)
		std::cout << " "<< (*it).first;
	std::cout << std::endl;

	ft::map<int, int>			test_swap;
	test_swap.insert(std::pair<int, int>(17, 2));
	test_swap.insert(std::pair<int, int>(18, 8));
	std::cout << "before swap: " << std::endl;
	for (ft::map<int, int>::iterator it = test.begin(); it != test.end(); it++)
		std::cout << " "<< (*it).first;
	std::cout << std::endl;
	for (ft::map<int, int>::iterator it = test_swap.begin(); it != test_swap.end(); it++)
		std::cout << " "<< (*it).first;
	std::cout << std::endl;
	test.swap(test_swap);
	std::cout << "after swap: " << std::endl;
	for (ft::map<int, int>::iterator it = test.begin(); it != test.end(); it++)
		std::cout << " "<< (*it).first;
	std::cout << std::endl;
	for (ft::map<int, int>::iterator it = test_swap.begin(); it != test_swap.end(); it++)
		std::cout << " "<< (*it).first;
	std::cout << std::endl;

	test.clear();
	std::cout << test.size() << std::endl;
	std::cout << "yo!" << std::endl;
}
