#include <iostream>
#include <vector>
#include <iterator>

#include "Vector.hpp"

template <class T>
void 	print_vector(std::vector<T> vec)
{
	for (typename std::vector<T>::const_iterator it = vec.begin(); it != vec.end(); it++)
	   std::cout << "|"<< *it << "| ";
	std::cout << std::endl;
	std::cout << "capacity: " << vec.capacity()
				<< " size: " << vec.size() <<std::endl;
}

int		main()
{
	std::vector<int>				vec1((size_t)10, 3);

	for (int i = 0; i < 10; i++)
		std::cout << "|"<< vec1[i] << "| ";
	std::cout << std::endl;
	std::cout << vec1.at(0) << std::endl;
	try
	{
		std::cout << vec1.at(10);
	}
	catch (std::out_of_range const &exc)
	{
		std::cout << exc.what() << '\n';
	}
	vec1[2] = 2;
	vec1.at(1) = 12;
	vec1.front() = 17;
	vec1.back() = 20;
	for (int i = 0; i < 10; i++)
		std::cout << "|"<< vec1[i] << "| ";
	std::cout << std::endl;

	print_vector(vec1);
	std::cout << std::endl;
	std::cout << "empty: " << vec1.empty() << " size: " << vec1.size()
				<< " max_size: " << vec1.max_size() << std::endl;

	try
	{
		vec1.reserve(2305843009213693951 + 1);
	}
	catch (std::length_error const &exc)
	{
		std::cout << exc.what() << '\n';
	}
	vec1.reserve(20);
	std::cout << "capacity: " << vec1.capacity() << std::endl;

	std::cout << "construct it:" << std::endl;

	std::vector<int>	vec1It(vec1.begin(), vec1.end());
	print_vector(vec1It);

	std::cout << "construct copy:" << std::endl;

	std::vector<int>	vec1Copy(vec1);
	print_vector(vec1Copy);

	std::cout << "operator = :" << std::endl;

	std::vector<int>	vec1op;
	vec1op.reserve(22);
	vec1op = vec1;
	print_vector(vec1op);

	std::cout << "assign :" << std::endl;

	vec1.assign((size_t)5, 42);
	print_vector(vec1);

	std::cout << "assign with iterators:" << std::endl;

	vec1.assign(vec1Copy.begin(), vec1Copy.end());
	print_vector(vec1);

	std::cout << "insert :" << std::endl;

	vec1.insert(vec1.begin(), (size_t)10, 50);
	print_vector(vec1);
	std::vector<int>::const_iterator itRet = vec1.insert(vec1.begin(), 51);
	std::cout << "it ret:" << *itRet << std::endl;
	print_vector(vec1);
	vec1.insert(vec1.begin(), vec1Copy.begin(), vec1Copy.end());
	print_vector(vec1);

	vec1.insert(vec1.end(), (size_t)10, 50);
	print_vector(vec1);
	std::vector<int>::const_iterator itRet2 = vec1.insert(vec1.end(), 51);
	std::cout << "it ret:" << *itRet2 << std::endl;
	print_vector(vec1);
	vec1.insert(vec1.end(), vec1Copy.begin(), vec1Copy.end());
	print_vector(vec1);

	return (0);
}
