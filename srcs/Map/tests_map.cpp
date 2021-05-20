/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_map.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofernan <rofernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 18:47:18 by rofernan          #+#    #+#             */
/*   Updated: 2021/05/20 13:05:30 by tlecoeuv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Map.hpp"

template <class S, class T>
void	print_cap(ft::map<S, T> &mp)
{
	std::cout << "mp.size():\t" << mp.size() << std::endl;
	std::cout << "mp.max_size():\t" << mp.max_size() << std::endl;
	std::cout << "mp.empty():\t" << mp.empty() << std::endl;
	std::cout << std::endl;
}

template <class S, class T>
void	print_content_iterator(ft::map<S, T> mp)
{
	std::cout << "print content with iterarors:\n";
	for (typename ft::map<S, T>::iterator it = mp.begin(); it != mp.end(); it++)
		std::cout << it->first << " -> " << it->second << std::endl;
	std::cout << std::endl;
}

template <class S, class T>
void	print_reverse_iterator(ft::map<S, T> mp)
{
	std::cout << "print content with reverse iterarors:\n";
	for (typename ft::map<S, T>::reverse_iterator it = mp.rbegin(); it != mp.rend(); it++)
		std::cout << it->first << " -> " << it->second << std::endl;
	std::cout << std::endl;
}

int main(void)
{
	std::cout << "################# TESTS MY MAP #################" << std::endl;

	ft::map<std::string, int> mp;
	ft::map<std::string, int> mp2;
	ft::map<std::string, int> mp3;

	std::cout << "********** MP EMPTY **********" << std::endl;
	// mp.print();
	print_cap(mp);
	print_content_iterator(mp);

	std::cout << "********** MP2 EMPTY **********" << std::endl;
	// mp.print();
	print_cap(mp);
	print_content_iterator(mp);

	std::cout << "********** MP INSERT **********" << std::endl;
	std::pair<ft::map<std::string, int>::iterator, bool> ret = mp.insert(std::make_pair("l", 10));
	std::cout << "return insert: " << ret.first->first << " -> " << ret.first->second << " - bool: " << ret.second << std::endl;

	std::cout << "********** MP[] NOT EXISTING **********" << std::endl;
	std::cout << mp["b"] << std::endl;
	mp["a"] = 4;
	mp["q"] = 2;
	mp["i"] = 8;
	mp["p"] = mp["a"];
	mp["o"] = 15;
	std::cout << "mp[\"a\"]: " << mp["a"] << std::endl;
	std::cout << "mp[\"q\"]: " << mp["q"] << std::endl;
	std::cout << "mp[\"o\"]: " << mp["o"] << std::endl;

	// mp.print();
	print_cap(mp);
	print_content_iterator(mp);
	print_reverse_iterator(mp);

	std::cout << "********** MP INSERT EXISTING ELEMENT **********" << std::endl;
	ret = mp.insert(std::make_pair("i", 10));
	std::cout << "return insert: " << ret.first->first << " -> " << ret.first->second << " - bool: " << ret.second << std::endl;

	// mp.print();
	print_cap(mp);
	print_content_iterator(mp);

	std::cout << "********** OPERATOR = FROM EXISTING TO EMPTY ; MP2 = MP **********" << std::endl;
	mp2 = mp;
	// mp2.print();
	print_cap(mp2);
	print_content_iterator(mp2);

	std::cout << "********** OPERATOR = FROM EMPTY TO EXISTING ; MP2 = MP3 **********" << std::endl;
	mp2 = mp3;
	// mp2.print();
	print_cap(mp2);
	print_content_iterator(mp2);
	print_reverse_iterator(mp2);

	mp2 = mp;

	std::cout << "********** ERASE MP BEGIN **********" << std::endl;
	mp.erase(mp.begin());
	// mp.print();
	print_cap(mp);
	print_content_iterator(mp);

	std::cout << "********** ERASE MP END - 1 **********" << std::endl;
	ft::map<std::string, int>::iterator it = mp.end();
	it--; // erase mp.end() is segfault
	mp.erase(it);
	// mp.print();
	print_cap(mp);
	print_content_iterator(mp);

	std::cout << "********** ERASE MP ELEMENT WITH ITERATOR **********" << std::endl;
	it = mp.begin();
	it++;
	it++;
	std::cout << "it : " << it->first << std::endl;
	mp.erase(it);
	// mp.print();
	print_cap(mp);
	print_content_iterator(mp);

	std::cout << "********** ERASE MP ELEMENTS 1 BY 1 **********" << std::endl;
	//mp.print();
	mp.erase("p");
	// mp.print();
	mp.erase("l");
	// mp.print();
	mp.erase("b");
	// mp.print();
	mp.erase("i");;
	// mp.print();
	mp.erase("i");
	// mp.print();
	mp.erase("o");
	// mp.print();
	print_cap(mp);
	print_content_iterator(mp);

	std::cout << "********** INSERT MP FROM MP2 BEGIN TO END **********" << std::endl;
	mp.insert(mp2.begin(), mp2.end());
	// mp.print();
	print_cap(mp);
	print_content_iterator(mp);

	std::cout << "********** MP CLEAR **********" << std::endl;
	mp.clear();
	// mp.print();
	print_cap(mp);
	print_content_iterator(mp);

	std::cout << "********** LOWER & UPPER BOUND **********" << std::endl;
	ft::map<std::string,int> mymap;
	ft::map<std::string,int>::iterator itlow,itup;
	mymap["a"] = 20;
	mymap["d"] = 80;
	mymap["e"] = 100;
	mymap["g"] = 111234;
	mymap["i"] = 67;
	mymap["r"] = 87;
	mymap["u"] = 32;

	print_content_iterator(mp);

	// mymap.print();
	itlow=mymap.lower_bound("b");
	std::cout << "itlow: " << itlow->first << std::endl;
	itup=mymap.upper_bound("s");
	std::cout << "yo 2" << std::endl;
	std::cout << "itup: " << itup->first << std::endl;
	mymap.erase(itlow,itup);
	std::cout << "erased" << std::endl;
	// mymap.print();
	print_cap(mymap);
	print_content_iterator(mymap);

/*	std::cout << "********** EQUAL RANGE **********" << std::endl;
	ft::map<char,int> mymap2;
	mymap2['a']=10;
	mymap2['b']=20;
	mymap2['c']=30;
	std::pair<ft::map<char,int>::iterator, ft::map<char,int>::iterator> ret2;
	ret2 = mymap2.equal_range('b');
	std::cout << "lower bound points to: ";
	std::cout << ret2.first->first << " => " << ret2.first->second << '\n';
	std::cout << "upper bound points to: ";
	std::cout << ret2.second->first << " => " << ret2.second->second << '\n';

	std::cout << "********** BEFORE SWAP **********" << std::endl;
	std::cout << "MYMAP\n";
	print_content_iterator(mymap);
	std::cout << "MYMAP2\n";
	print_content_iterator(mymap2);

	std::cout << "********** AFTER SWAP **********" << std::endl;
	mymap.swap(mymap2);

	std::cout << "MYMAP\n";
	print_content_iterator(mymap);
	std::cout << "MYMAP2\n";
	print_content_iterator(mymap2);*/

	/* RELATIONAL OPERATORS */

	std::cout << "\n\n\n******************** TESTS RELATIONAL OPERATORS ********************\n";

/*	ft::map<char,int> foo,bar;
	foo['a']=100;
	foo['b']=200;
	bar['a']=10;
	bar['z']=1000;
	if (foo==bar) std::cout << "foo and bar are equal\n";
	if (foo!=bar) std::cout << "foo and bar are not equal\n";
	if (foo< bar) std::cout << "foo is less than bar\n";
	if (foo> bar) std::cout << "foo is greater than bar\n";
	if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
	if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";*/

    return (0);
}
