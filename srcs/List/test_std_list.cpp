/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_list_og.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofernan <rofernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 14:42:40 by rofernan          #+#    #+#             */
/*   Updated: 2021/05/26 11:54:32 by tlecoeuv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>

struct is_near {
bool	operator() (int first, int second)
{
	return (abs(first - second) < 5);
}
};

bool	comp(int first, int second)
{
	return (first > second);
}

struct is_odd {
bool	operator() (const int& value) {
	return (value % 2) == 1;
}
};

template <class T>
void	print_cap(std::list<T> lst)
{
	std::cout << "vec.size():\t" << lst.size() << std::endl;
	std::cout << "vec.max_size():\t" << lst.max_size() << std::endl;
	std::cout << "vec.empty():\t" << lst.empty() << std::endl;
	std::cout << std::endl;
}

template <class T>
void	print_content(std::list<T> lst)
{
	std::cout << "print content with iterarors:\n";
	for (typename std::list<T>::iterator it = lst.begin(); it != lst.end(); it++)
		std::cout << "|" << *it << "|";
	std::cout << std::endl;
}

template <class T>
void	print_access(std::list<T> lst)
{
	std::cout << "lst.front():\t" << lst.front() << std::endl;
	std::cout << "lst.back():\t" << lst.back() << std::endl;
	std::cout << std::endl;
}

template <class T>
void	print_reverse(std::list<T> lst)
{
	std::cout << "print content with reverse iterarors:\n";
	for (typename std::list<T>::reverse_iterator it = lst.rbegin(); it != lst.rend(); it++)
		std::cout << "|" << *it << "|";
	std::cout << std::endl;
}

int main(void)
{
	std::cout << "################# TESTS ORIGINAL LIST #################" << std::endl;

	std::list<int> lst;
	std::list<int>::iterator it = lst.begin();
	std::list<int>::iterator it2 = lst.begin();

	print_cap(lst);
	print_content(lst);
	print_access(lst);

	lst.push_back(3);
	lst.push_back(1234);
	lst.push_back(2);
	lst.push_back(10);
	lst.push_back(45);

	print_cap(lst);
	print_content(lst);
	print_access(lst);

	std::cout << "erasing 3rd value...\n";
	it = lst.begin();
	for (int i = 0; i < 3; i++)
		it++;

	std::cout << "return value of erase: " << *lst.erase(it) << std::endl;

	print_cap(lst);
	print_content(lst);

	it = lst.end();
	std::cout << "return value of erase end: " << *lst.erase(--it) << std::endl;

	print_cap(lst);
	print_content(lst);

	std::cout << "return value of erase begin: " << *lst.erase(lst.begin()) << std::endl;

	print_cap(lst);
	print_content(lst);

	lst.push_front(42);
	lst.push_front(66);
	lst.push_back(9999);
	lst.push_back(45);
	lst.push_back(333333);

	std::cout << "push front and push back values: " << std::endl;

	print_cap(lst);
	print_content(lst);

	std::cout << "erase begin+2 to begin+5: " << std::endl;
	it = lst.begin();
	for (int i = 0; i < 2; i++)
		it++;
	it2 = lst.begin();
	for (int i = 0; i < 5; i++)
		it2++;
	std::cout << "return value of erase range: " << *lst.erase(it, it2) << std::endl;
	print_cap(lst);
	print_content(lst);

	std::list<int> lst2(lst);
	std::cout << "print lst2: " << std::endl;
	lst2.push_front(1010101);
	lst2.push_back(949494902);
	print_cap(lst2);
	print_content(lst2);

	std::list<int> lst3;
	lst3 = lst2;
	std::cout << "print lst3: " << std::endl;
	print_cap(lst3);
	print_content(lst3);

	std::cout << "swap lst lst2: " << std::endl;
	std::cout << "print lst: " << std::endl;
	lst.swap(lst2);
	print_cap(lst);
	print_content(lst);

	std::cout << "print lst2: " << std::endl;
	print_cap(lst2);
	print_content(lst2);

	std::cout << "print lst4(lst.begin(), lst.end()): " << std::endl;
	std::list<int> lst4(lst.begin(), lst.end());
	print_cap(lst4);
	print_content(lst4);

	std::cout << "lst4.resize(9, 654321): " << std::endl;
	lst4.resize(9, 654321);
	print_cap(lst4);
	print_content(lst4);

	std::cout << "lst4.resize(4): " << std::endl;
	lst4.resize(4);
	print_cap(lst4);
	print_content(lst4);

	std::cout << "insert value at position 4: " << std::endl;
	it = lst4.begin();
	for (int i = 0; i < 4; i++)
		it++;
	std::cout << "return value of insert: " << *lst4.insert(it, 999) << std::endl;
	print_cap(lst4);
	print_content(lst4);

	std::cout << "insert value at position 2: " << std::endl;
	it = lst4.begin();
	for (int i = 0; i < 2; i++)
		it++;
	std::cout << "return value of insert: " << *lst4.insert(it, 777) << std::endl;
	print_cap(lst4);
	print_content(lst4);

	lst2.push_back(543);
	lst2.push_back(78979);
	lst2.push_back(12344);
	print_content(lst2);

	std::cout << "insert values at position 4: " << std::endl;
	it = lst4.begin();
	for (int i = 0; i < 4; i++)
		it++;
	lst4.insert(it, 5, 80);
	print_cap(lst4);
	print_content(lst4);

	std::cout << "insert lst2 at position 5: " << std::endl;
	it = lst4.begin();
	for (int i = 0; i < 5; i++)
		it++;
	lst4.insert(it, lst2.begin(), lst2.end());
	print_cap(lst4);
	print_content(lst4);

	std::cout << "return value of erase lst2 begin to end: " << *lst2.erase(lst2.begin(), lst2.end()) << std::endl;
	print_cap(lst2);
	print_content(lst2);



	/* OPERATIONS */

	std::cout << "\n\n\n******************** TESTS OPERATIONS ********************\n";

	for (int i = 0; i < 10; i++)
		lst.push_back(i + 1);
	for (int i = 15; i > 0; i--)
		lst2.push_front(i);

	std::cout << "********** LST **********\n";
	print_cap(lst);
	print_content(lst);

	std::cout << "********** LST2 **********\n";
	print_cap(lst2);
	print_content(lst2);

	std::cout << "********** SPLICE 1 value **********\n";
	it = lst.begin();
	for (int i = 0; i < 4; i++)
		it++;
	std::cout << "it: " << *it << std::endl;
	it2 = lst2.begin();
	for (int i = 0; i < 12; i++)
		it2++;
	std::cout << "it2: " << *it2 << std::endl;
	lst.splice(it, lst2, it2);

	std::cout << "********** LST **********\n";
	print_cap(lst);
	print_content(lst);

	std::cout << "********** LST2 **********\n";
	print_cap(lst2);
	print_content(lst2);

	std::cout << "********** SPLICE 5 values **********\n";
	it = lst2.begin();
	for (int i = 0; i < 7; i++)
		it++;
	std::cout << "it: " << *it << std::endl;
	it2 = lst2.begin();
	for (int i = 0; i < 12; i++)
		it2++;
	std::cout << "it2: " << *it2 << std::endl;
	lst.splice(lst.end(), lst2, it, it2);

	std::cout << "********** LST **********\n";
	print_cap(lst);
	print_content(lst);

	std::list<int>::reverse_iterator rit = lst.rbegin();
	std::cout << "rit: " << *rit << std::endl;
	std::cout << std::endl;

	std::cout << "********** LST2 **********\n";
	print_cap(lst2);
	print_content(lst2);

	std::cout << "********** REMOVE 8s FROM LST **********\n";
	lst.remove(8);
	print_cap(lst);
	print_content(lst);

	std::cout << "********** REMOVE 10s FROM LST **********\n";
	lst.remove(10);
	print_cap(lst);
	print_content(lst);

	std::cout << "********** REMOVE 12s FROM LST **********\n";
	lst.remove(12);
	print_cap(lst);
	print_content(lst);

	std::cout << "********** REMOVE 1s FROM LST **********\n";
	lst.remove(1);
	print_cap(lst);
	print_content(lst);

	std::cout << "********** REVERSE LST **********\n";
	lst.reverse();
	print_cap(lst);
	print_content(lst);

	lst.push_back(2);
	lst.push_back(2);
	lst.push_back(2);
	print_cap(lst);
	print_content(lst);

	std::cout << "********** UNIQUE LST **********\n";
	lst.unique();
	print_cap(lst);
	print_content(lst);

	lst.push_back(2);
	lst.push_back(2);
	lst.push_back(2);
	lst.push_back(5);
	lst.push_back(6);
	lst.push_back(911);
	lst.push_back(1);
	print_cap(lst);
	print_content(lst);

	std::cout << "********** UNIQUE LST TEST 2 **********\n";
	lst.unique();
	print_cap(lst);
	print_content(lst);

	lst.push_front(11);
	lst.push_front(11);
	print_cap(lst);
	print_content(lst);

	std::cout << "********** UNIQUE LST TEST 3 **********\n";
	lst.unique();
	print_cap(lst);
	print_content(lst);

	std::cout << "********** UNIQUE LST PREDICATE **********\n";
	lst.unique(is_near());
	print_cap(lst);
	print_content(lst);

	std::cout << "********** SORT LST **********\n";
	lst.sort();
	print_cap(lst);
	print_content(lst);

	std::cout << "********** SORT LST comp **********\n";
	lst.sort(comp);
	print_cap(lst);
	print_content(lst);

	std::cout << "********** REVERSE LST **********\n";
	lst.reverse();
	print_cap(lst);
	print_content(lst);

	std::cout << "********** MERGE LST LST2 **********\n";
	lst.merge(lst2);
	print_cap(lst);
	print_content(lst);

	std::cout << "********** LST2 **********\n";
	print_cap(lst2);
	print_content(lst2);

	std::cout << "********** LST2 ASSIGN(6, 111) **********\n";
	lst2.assign(6, 111);
	print_cap(lst2);
	print_content(lst2);

	std::cout << "********** MERGE LST LST2 comp **********\n";
	lst.merge(lst2, comp);
	print_cap(lst);
	print_content(lst);

	std::cout << "********** SORT LST **********\n";
	lst.sort();
	print_cap(lst);
	print_content(lst);

	std::cout << "********** LST2 ASSIGN(3, 222) **********\n";
	lst2.assign(3, 222);
	print_cap(lst2);
	print_content(lst2);

	std::cout << "********** REVERSE LST **********\n";
	lst.reverse();
	print_cap(lst);
	print_content(lst);

	std::cout << "********** MERGE LST LST2 comp **********\n";
	lst.merge(lst2, comp);
	print_cap(lst);
	print_content(lst);

	std::cout << "********** SORT EMPTY LST2 **********\n";
	lst2.sort();
	print_cap(lst2);
	print_content(lst2);

	std::cout << "********** LST UNIQUE **********\n";
	lst.unique();
	print_cap(lst);
	print_content(lst);

	std::cout << "********** PRINT REVERSE ITERATOR LST **********\n";
	print_cap(lst);
	print_reverse(lst);

	std::cout << "********** LST REMOVE IF ODD **********\n";
	lst.remove_if(is_odd());
	print_cap(lst);
	print_content(lst);

	std::cout << "********** LST2 **********\n";
	print_cap(lst2);
	print_content(lst2);

	std::cout << "********** LST2 ASSIGN (5, 999) **********\n";
	lst2.assign(5, 999);
	print_cap(lst2);
	print_content(lst2);

	std::cout << "********** LST SPLICE LST2 **********\n";
	lst.splice(lst.begin(), lst2);
	print_cap(lst);
	print_content(lst);

	std::cout << "********** LST2 **********\n";
	print_cap(lst2);
	print_content(lst2);

	std::list<int> lst5(lst);
	std::cout << "********** LST5 **********\n";
	print_cap(lst5);
	print_content(lst5);

	std::cout << "********** ERASE LST5 **********\n";
	while (!lst5.empty())
        lst5.pop_back();
	print_cap(lst5);
	print_content(lst5);

	std::cout << "********** ADD VALUES TO LST5 **********\n";
	lst5.push_back(100);
	lst5.push_front(200);
	lst5.push_back(300);
	print_cap(lst5);
	print_content(lst5);

	std::cout << "********** CLEAR LST5 **********\n";
	lst5.clear();
	print_cap(lst5);
	print_content(lst5);

	lst5.clear();
	print_cap(lst5);
	print_content(lst5);

	/* RELATIONAL OPERATORS */

	std::cout << "\n\n\n******************** TESTS RELATIONAL OPERATORS ********************\n";

	std::list<int> foo (3,100);
	std::list<int> bar (2,200);

	if (foo == bar) std::cout << "foo and bar are equal\n";
	if (foo != bar) std::cout << "foo and bar are not equal\n";
	if (foo < bar) std::cout << "foo is less than bar\n";
	if (foo > bar) std::cout << "foo is greater than bar\n";
	if (foo <= bar) std::cout << "foo is less than or equal to bar\n";
	if (foo >= bar) std::cout << "foo is greater than or equal to bar\n";

	std::cout << std::endl;

	std::list<int> a;
	a.push_back(10);
	a.push_back(20);
	a.push_back(30);
  	std::list<int> b;
	b.push_back(10);
	b.push_back(20);
	b.push_back(30);
  	std::list<int> c;
	c.push_back(30);
	c.push_back(20);
	c.push_back(10);
	std::list<int> d;
	d.push_back(30);
	d.push_back(20);

  	if (a == b) std::cout << "a and b are equal\n";
  	if (b != c) std::cout << "b and c are not equal\n";
  	if (b < c) std::cout << "b is less than c\n";
  	if (c > b) std::cout << "c is greater than b\n";
  	if (a <= b) std::cout << "a is less than or equal to b\n";
  	if (a >= b) std::cout << "a is greater than or equal to b\n";
	if (c < d) std::cout << "c is less than d\n";
  	if (c > d) std::cout << "c is greater than d\n";

	return (0);
}
