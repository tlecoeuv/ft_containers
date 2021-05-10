#include "Map.hpp"

int		main()
{
	ft::map<int, int>			test;
	ft::map<int, int>::iterator	it1;
	ft::map<int, int>::iterator	it2;

	it1 = (test.insert(std::pair<int, int>(5, 5))).first;
	test.insert(std::pair<int, int>(2, 2));
	test.insert(std::pair<int, int>(8, 8));
	test.insert(std::pair<int, int>(1, 1));
	test.insert(std::pair<int, int>(4, 4));
	it2 = test.insert(it1, std::pair<int, int>(7, 7));
	test.insert(std::pair<int, int>(9, 9));

	std::cout << "it 1: " << (*it1).first << " it2: " << (*it2).first << std::endl;
}
