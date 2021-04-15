#include "Vector.hpp"

int		main()
{
	ft::vector<int>				vec1((size_t)10, 3);

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

	for (ft::vector<int>::const_iterator it = vec1.begin(); it != vec1.end(); it++)
		std::cout << "|"<< *it << "| ";
	std::cout << std::endl;
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
	ft::vector<int>	vec1It(vec1.begin(), vec1.end());
	for (ft::vector<int>::const_iterator it = vec1It.begin(); it != vec1It.end(); it++)
	   std::cout << "|"<< *it << "| ";
	std::cout << std::endl;

	std::cout << "construct copy:" << std::endl;
	ft::vector<int>	vec1Copy(vec1);
	for (ft::vector<int>::const_iterator it = vec1Copy.begin(); it != vec1Copy.end(); it++)
	   std::cout << "|"<< *it << "| ";
	std::cout << std::endl;
	std::cout << "capacity: " << vec1Copy.capacity() << std::endl;

	std::cout << "operator = :" << std::endl;
	ft::vector<int>	vec1op;
	vec1op.reserve(22);
	vec1op = vec1;
	for (ft::vector<int>::const_iterator it = vec1op.begin(); it != vec1op.end(); it++)
	   std::cout << "|"<< *it << "| ";
	std::cout << std::endl;
	std::cout << "capacity: " << vec1op.capacity() << std::endl;

	std::cout << "assign :" << std::endl;
	vec1.assign((size_t)5, 42);
	for (ft::vector<int>::const_iterator it = vec1.begin(); it != vec1.end(); it++)
	   std::cout << "|"<< *it << "| ";
	std::cout << std::endl;
	std::cout << "capacity: " << vec1.capacity() << " size: " << vec1.size() <<std::endl;

	std::cout << "assign with iterators:" << std::endl;
	vec1.assign(vec1Copy.begin(), vec1Copy.end());
	for (ft::vector<int>::const_iterator it = vec1.begin(); it != vec1.end(); it++)
	   std::cout << "|"<< *it << "| ";
	std::cout << std::endl;
	std::cout << "capacity: " << vec1.capacity() << " size: " << vec1.size() <<std::endl;

	return (0);
}
