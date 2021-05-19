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

	test.print();

	std::cout << "count 2: " << test.count(2) << std::endl;
	std::cout << "count 20: " << test.count(20) << std::endl;

	std::cout << "find 9: " << (*(test.find(9))).first << std::endl;

	std::cout << "lower bound 6: " << (*(test.lower_bound(6))).first << std::endl;
	std::cout << "lower bound 5: " << (*(test.lower_bound(5))).first << std::endl;
	std::cout << "upper bound 6: " << (*(test.upper_bound(6))).first << std::endl;
	std::cout << "upper bound 5: " << (*(test.upper_bound(5))).first << std::endl;
	std::pair<ft::map<int, int>::iterator, ft::map<int, int>::iterator>	eq = test.equal_range(6);
	std::cout << "equal bound 6: " << (*(eq.first)).first << ", " << (*(eq.second)).first << std::endl;

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

	test.insert(std::pair<int, int>(7, 0));
	test.insert(std::pair<int, int>(3, 0));
	test.print();
	for (ft::map<int, int>::iterator it = test.begin(); it != test.end(); it++)
		std::cout << " "<< (*it).first;
	std::cout << std::endl;
	test.erase(test.begin(), test.end());
}
