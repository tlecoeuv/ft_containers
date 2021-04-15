#include "List.hpp"
#include <iostream>
#include <list>

void 	test_swap(void);

bool mycomparison (int first, int second)
{
	return (first < second);
}

int		main()
{
	ft::list<int>	test;

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

	ft::list<int>::iterator it = test.begin();
	ft::list<int>::iterator ite = test.end();

	while (it != ite)
	{
		std::cout << *it << std::endl;
		it++;
	}

	ft::list<int>::reverse_iterator rit = test.rbegin();
	ft::list<int>::reverse_iterator rite = test.rend();

	while (rit != rite)
	{
		std::cout << *rit << std::endl;
		rit++;
	}

	std::cout << "assign test" << std::endl;
	ft::list<int> first;
  	ft::list<int> second;
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

	ft::list<int>::const_iterator const_it;

	const_it = first.begin();
	ft::list<int> copy(test);

	std::cout << "test swap:" << std::endl;

	first.swap(second);
	std::cout << "Size of first: " << int (first.size()) << '\n';
  	std::cout << "Size of second: " << int (second.size()) << '\n';

	std::cout << "test resize:" << std::endl;

	ft::list<int> mylist;
	for (int i=1; i<10; ++i)
		mylist.push_back(i);
	mylist.resize(5);
	mylist.resize(8,100);
	mylist.resize(12);

	ft::list<int>::iterator mite = mylist.end();
	for (ft::list<int>::iterator mit = mylist.begin(); mit != mite; mit++)
		std::cout << ' ' << *mit;
	std::cout << std::endl;

	std::cout << "test splice:" << std::endl;

	ft::list<int> splice_list;

	it = mylist.begin();
	it++;

	std::cout << "size before splice: mylist: " << mylist.size() << " splice_list: " << splice_list.size() << std::endl;

	ite = splice_list.end();
	splice_list.splice(splice_list.end(), mylist, it, mite);
	for (it = splice_list.begin(); it != ite; it++)
		std::cout << ' ' << *it;
	std::cout << std::endl;
	ite = mylist.end();
	for (it = mylist.begin(); it != ite; it++)
		std::cout << ' ' << *it;
	std::cout << std::endl;
	std::cout << "size after splice: mylist: " << mylist.size() << " splice_list: " << splice_list.size() << std::endl;

	ite = splice_list.end();
	splice_list.splice(splice_list.end(), mylist, mylist.begin());
	for (it = splice_list.begin(); it != ite; it++)
		std::cout << ' ' << *it;
	std::cout << std::endl;
	ite = mylist.end();
	for (it = mylist.begin(); it != ite; it++)
		std::cout << ' ' << *it;
	std::cout << std::endl;

	ite = splice_list.end();
	mylist.splice(mylist.end(), splice_list);
	for (it = splice_list.begin(); it != ite; it++)
		std::cout << ' ' << *it;
	std::cout << std::endl;
	ite = mylist.end();
	for (it = mylist.begin(); it != ite; it++)
		std::cout << ' ' << *it;
	std::cout << std::endl;

	std::cout << "test remove" << std::endl;

	mylist.remove(0);
	for (it = mylist.begin(); it != ite; it++)
		std::cout << ' ' << *it;
	std::cout << std::endl;
	mylist.remove(2);
	mylist.remove(1);
	for (it = mylist.begin(); it != ite; it++)
		std::cout << ' ' << *it;
	std::cout << std::endl;

	std::cout << "test unique" << std::endl;

	mylist.unique();
	for (it = mylist.begin(); it != ite; it++)
		std::cout << ' ' << *it;
	std::cout << std::endl;

	std::cout << "test merge" << std::endl;

	first.clear();
	second.clear();
	first.push_back(2);
	first.push_back(5);
	first.push_back(8);
	second.push_back(1);
	second.push_back(5);
	second.push_back(7);
	second.push_back(7);

	first.merge(second, mycomparison);

	ite = first.end();
	size_t dist = ft::distance(first.begin(), first.end());
	std::cout << "dist: " << dist << "size: " << first.size() << std::endl;
	for (it = first.begin(); it != first.end(); it++)
		std::cout << ' ' << *it;
	std::cout << std::endl;

	ft::list<int>	a;
	ft::list<int>	b;
	ft::list<int>	c;

	a.push_back(10);
	a.push_back(20);
	a.push_back(30);
	b.push_back(10);
	b.push_back(20);
	b.push_back(30);
	c.push_back(30);
	c.push_back(20);
	c.push_back(10);

	if (a==b) std::cout << "a and b are equal\n";
	if (b!=c) std::cout << "b and c are not equal\n";
	if (b<c) std::cout << "b is less than c\n";
	if (c>b) std::cout << "c is greater than b\n";
	if (a<=b) std::cout << "a is less than or equal to b\n";
	if (a>=b) std::cout << "a is greater than or equal to b\n";

	std::cout << "test reverse: " << std::endl;

	a.reverse();
	std::cout << "should be 30 20 10" << std::endl;
	for (it = a.begin(); it != a.end(); it++)
		std::cout << ' ' << *it;
	std::cout << std::endl;
	a.reverse();
	std::cout << "should be 10 20 30" << std::endl;
	for (it = a.begin(); it != a.end(); it++)
		std::cout << ' ' << *it;
	std::cout << std::endl;

	std::cout << "test sort: " << std::endl;

	ft::list<int>	d;
	d.push_back(30);
	d.push_back(20);
	d.push_back(10);
	d.push_back(27);
	d.push_back(10);
	d.push_back(2);
	d.push_back(17);
	d.sort();
	std::cout << "should be sorted" << std::endl;
	for (it = d.begin(); it != d.end(); it++)
		std::cout << ' ' << *it;
	std::cout << std::endl;

	d.reverse();
	std::cout << "yo !" << std::endl;
	for (it = d.begin(); it != d.end(); it++)
		std::cout << ' ' << *it;
	std::cout << std::endl;
	std::cout << "yo2 !" << std::endl;
	d.reverse();
	std::cout << "yo !" << std::endl;
	for (it = d.begin(); it != d.end(); it++)
		std::cout << ' ' << *it;
	std::cout << std::endl;
	std::cout << "yo3 !" << std::endl;
	d.sort(mycomparison);
	std::cout << "should be sorted" << std::endl;
	for (it = d.begin(); it != d.end(); it++)
		std::cout << ' ' << *it;
	std::cout << std::endl;

	return 0;
}
