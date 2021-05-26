/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_vector_og.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofernan <rofernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 12:02:24 by rofernan          #+#    #+#             */
/*   Updated: 2020/12/16 14:44:45 by rofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>

template <class T>
void	print_cap(std::vector<T> &vec)
{
	std::cout << "vec.size():\t" << vec.size() << std::endl;
	std::cout << "vec.max_size():\t" << vec.max_size() << std::endl;
	std::cout << "vec.capacity():\t" << vec.capacity() << std::endl;
	std::cout << "vec.empty():\t" << vec.empty() << std::endl;
	std::cout << std::endl;
}

template <class T>
void	print_content(std::vector<T> vec)
{
	std::cout << "print content with operator[]:\n";
	for (size_t i = 0; i < vec.size(); i++)
		std::cout << "vec[" << i << "]: " << vec[i] << std::endl;
	std::cout << std::endl;
}

template <class T>
void	print_content_at(std::vector<T> vec)
{
	std::cout << "print content with vec.at():\n";
	for (size_t i = 0; i < vec.size(); i++)
		std::cout << "vec.at(" << i << "): " << vec.at(i) << std::endl;
	std::cout << std::endl;
}

template <class T>
void	print_content_iterator(std::vector<T> vec)
{
	std::cout << "print content with iterarors:\n";
	for (typename std::vector<T>::iterator it = vec.begin(); it != vec.end(); it++)
		std::cout << "*it:\t" << *it << std::endl;
	std::cout << std::endl;
}

template <class T>
void	print_reverse_iterator(std::vector<T> vec)
{
	std::cout << "print content with reverse iterarors:\n";
	for (typename std::vector<T>::reverse_iterator it = vec.rbegin(); it != vec.rend(); it++)
		std::cout << "*it:\t" << *it << std::endl;
	std::cout << std::endl;
}

template <class T>
void	print_access(std::vector<T> vec)
{
	std::cout << "vec.front():\t" << vec.front() << std::endl;
	std::cout << "vec.back():\t" << vec.back() << std::endl;
	std::cout << std::endl;
}

int main(void)
{
	std::cout << "################# TESTS ORIGINAL VECTOR #################" << std::endl;
	std::vector<int>	vec;
	std::vector<int>	vec2;

	std::cout << "********** VEC **********\n";
	print_cap(vec);
	vec.insert(vec.begin(), 4);
	print_content(vec);

	std::cout << "********** VEC2 **********\n";
	print_cap(vec2);

	std::cout << "********** VEC - push_back values **********\n";
	vec.push_back(5);
	vec.push_back(2);
	vec.push_back(4);
	vec.push_back(10);
	vec.push_back(15);
	vec.push_back(7);
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(90);

	print_cap(vec);
	print_content(vec);
	print_content_at(vec);
	print_content_iterator(vec);
	print_reverse_iterator(vec);
	print_access(vec);

	try {
		std::cout << vec.at(1) << std::endl;
		std::cout << vec.at(10) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "********** TEST INSERT 1 VEC **********\n";
	std::cout << "ret iterator insert: " << *vec.insert(vec.begin() + 2, 42) << "\n\n";
	print_cap(vec);
	print_content(vec);
	print_access(vec);

	std::cout << "********** TEST INSERT 2 VEC **********\n";
	vec.insert(vec.begin() + 3, 7, 5555);
	print_cap(vec);
	print_content(vec);
	print_access(vec);

	std::vector<int>	vec3(4, 42);
	std::cout << "********** VEC3 **********\n";
	print_cap(vec3);
	print_content(vec3);
	print_content_iterator(vec3);
	print_access(vec3);

	std::cout << "********** TEST INSERT 2 VEC3 **********\n";
	vec3.insert(vec3.begin() + 2, vec.begin(), vec.end());
	print_cap(vec3);
	print_content(vec3);
	print_access(vec3);

	std::cout << "********** TEST RESIZE n < cap VEC3 **********\n";
	vec3.resize(9);
	print_cap(vec3);
	print_content(vec3);
	print_access(vec3);

	std::cout << "********** TEST RESIZE n > cap VEC3 **********\n";
	vec3.resize(19, 1111);
	print_cap(vec3);
	print_content(vec3);
	print_access(vec3);

	std::vector<int>	vec4(vec.begin() + 1, vec.begin() + 5);
	std::cout << "********** VEC4 **********\n";
	print_cap(vec4);
	print_content(vec4);
	print_access(vec4);

	std::cout << "********** VEC **********\n";
	vec.assign(7, 100);
	print_cap(vec);
	print_content(vec);
	print_content_iterator(vec);
	print_access(vec);

	vec.clear();

	std::cout << "********** VEC5 = VEC4 **********\n";
	std::vector<int>	vec5;
	vec5 = vec4;
	print_cap(vec5);
	print_content(vec5);
	print_content_iterator(vec5);
	print_access(vec5);

	std::cout << "********** VEC5 = VEC3 **********\n";
	vec5 = vec3;
	print_cap(vec5);
	print_content(vec5);

	std::cout << "********** VEC5 = VEC **********\n";
	vec5 = vec;
	print_cap(vec5);
	print_content(vec5);
	print_content_iterator(vec5);

	std::cout << "********** VEC6 **********\n";
	std::vector<int> vec6(9, 7777);
	print_cap(vec6);
	print_content(vec6);
	print_content_iterator(vec6);
	print_access(vec6);

	std::cout << "********** SWAP VEC6 - VEC3 **********\n";
	vec6.swap(vec3);
	std::cout << "********** VEC3 **********\n";
	print_cap(vec3);
	print_content(vec3);
	print_access(vec3);
	std::cout << "********** VEC6 **********\n";
	print_cap(vec6);
	print_content(vec6);
	print_access(vec6);

	std::cout << "********** TEST ERASE 6th to 16th VALUES VEC6 **********\n";
	std::cout << "return value erase: " << *vec6.erase(vec6.begin() + 6, vec6.begin() + 16) << std::endl;
	print_cap(vec6);
	print_content(vec6);
	print_access(vec6);

	std::cout << "********** TEST ERASE VALUES VEC6 **********\n";
	std::cout << "return value erase: " << *vec6.erase(vec6.begin() + 6) << std::endl;
	print_cap(vec6);
	print_content(vec6);
	print_access(vec6);

	std::cout << "return value erase: " << *vec6.erase(vec6.begin() + 5) << std::endl;
	print_cap(vec6);
	print_content(vec6);
	print_access(vec6);

	std::cout << "return value erase: " << *vec6.erase(vec6.begin() + 2) << std::endl;
	print_cap(vec6);
	print_content(vec6);
	print_access(vec6);

	/* RELATIONAL OPERATORS */

	std::cout << "\n\n\n******************** TESTS RELATIONAL OPERATORS ********************\n";

	std::vector<int> foo (3,100);
	std::vector<int> bar (2,200);

	if (foo == bar) std::cout << "foo and bar are equal\n";
	if (foo != bar) std::cout << "foo and bar are not equal\n";
	if (foo < bar) std::cout << "foo is less than bar\n";
	if (foo > bar) std::cout << "foo is greater than bar\n";
	if (foo <= bar) std::cout << "foo is less than or equal to bar\n";
	if (foo >= bar) std::cout << "foo is greater than or equal to bar\n";

	std::cout << std::endl;

	std::vector<int> a;
	a.push_back(10);
	a.push_back(20);
	a.push_back(30);
  	std::vector<int> b;
	b.push_back(10);
	b.push_back(20);
	b.push_back(30);
  	std::vector<int> c;
	c.push_back(30);
	c.push_back(20);
	c.push_back(10);
	std::vector<int> d;
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


	std::cout << "\n********** TEST STRING VECTOR **********\n";
	std::vector<std::string>	vecst;
	vecst.push_back("hello");
	vecst.push_back("world");
	vecst.push_back("lala");
	vecst.push_back("popo");
	vecst.push_back("lolo");
	vecst.push_back("papapapa");
	vecst.push_back("nonononono");
	vecst.push_back("hehehe");
	print_cap(vecst);
	print_content_iterator(vecst);
	print_access(vecst);

	std::cout << "\n********** ERASE STRING VECTOR **********\n";
	std::cout << "return value erase: " << *vecst.erase(vecst.begin() + 1, vecst.begin() + 4) << std::endl;
	print_cap(vecst);
	print_content_iterator(vecst);
	print_access(vecst);

	std::cout << "\n********** ERASE 1 ELEM STRING VECTOR **********\n";
	std::cout << "return value erase: " << *vecst.erase(vecst.begin() + 2) << std::endl;
	print_cap(vecst);
	print_content_iterator(vecst);
	print_access(vecst);

	std::cout << "\n********** ERASE LAST ELEM STRING VECTOR **********\n";
	std::cout << "return value erase: " << *vecst.erase(vecst.end() - 1) << std::endl;
	print_cap(vecst);
	print_content_iterator(vecst);
	print_access(vecst);
	
	std::cout << "********** INSERT STRING VECTOR **********\n";
	std::cout << "return value insert: " << *vecst.insert(vecst.begin() + 1, "world") << std::endl;
	print_cap(vecst);
	print_content(vecst);
	print_access(vecst);

	std::cout << "********** CREATE STRING VECTOR 2 **********\n";
	std::vector<std::string> vecst2(5, "rom");
	print_cap(vecst2);
	print_content(vecst2);
	print_access(vecst2);

	std::cout << "********** INSERT STRING VECTOR 2 **********\n";
	vecst2.insert(vecst2.begin() + 3, vecst.begin(), vecst.end());
	print_cap(vecst2);
	print_content(vecst2);
	print_access(vecst2);

	std::cout << "********** INSERT STRING VECTOR 3 **********\n";
	vecst2.insert(vecst2.begin() + 5, 4, "chop chop");
	print_cap(vecst2);
	print_content(vecst2);
	print_access(vecst2);

	std::cout << "********** RESIZE n < size STRING VECTOR **********\n";
	vecst.resize(1);
	print_cap(vecst);
	print_content(vecst);
	print_access(vecst);

	std::cout << "********** RESIZE n > size STRING VECTOR **********\n";
	vecst.resize(6, "lili");
	print_cap(vecst);
	print_content(vecst);
	print_access(vecst);

	// std::cout << vec[0] << std::endl;
	// std::cout << vec[1] << std::endl;
	// std::cout << vec[2] << std::endl;

	// vec2 = vec;
	// for (size_t i = 0; i < vec.size(); i++)
	// 	std::cout << "vec[" << i << "]:" << vec[i] << "\t\t" << "vec2[" << i << "]:" << vec2[i] << std::endl;
	// vec.pop_back();
	// vec.push_back(100);
	// std::cout << std::endl;
	// for (size_t i = 0; i < vec.size(); i++)
	// 	std::cout << "vec[" << i << "]:" << vec[i] << "\t\t" << "vec2[" << i << "]:" << vec2[i] << std::endl;
	// std::cout << std::endl;
	// std::cout << *vec.erase(vec.begin()+1, vec.begin()+4) << std::endl;
	// for (size_t i = 0; i < vec.size(); i++)
	// 	std::cout << "vec[" << i << "]:" << vec[i] << std::endl;
	// std::cout << "vec.size(): " << vec.size() << std::endl;
	// // swap(vec, vec2);
	// // vec = vec2;
	// vec.swap(vec2);
	// std::cout << std::endl;
	// for (size_t i = 0; i < vec.size(); i++)
	// 	std::cout << "vec[" << i << "]:" << vec[i] << "\t\t" << "vec2[" << i << "]:" << vec2[i] << std::endl;
	// std::cout << std::endl;
	// vec2.clear();
	// vec2.push_back(455);
	// vec2.push_back(234);
	// vec2.push_back(1024);
	// vec2.push_back(5000);
	// for (size_t i = 0; i < vec.size(); i++)
	// 	std::cout << "vec[" << i << "]:" << vec[i] << "\t\t" << "vec2[" << i << "]:" << vec2[i] << std::endl;
	// std::cout << std::endl;
	// vec.swap(vec2);
	// for (size_t i = 0; i < vec.size(); i++)
	// 	std::cout << "vec[" << i << "]:" << vec[i] << "\t\t" << "vec2[" << i << "]:" << vec2[i] << std::endl;
	// std::cout << std::endl;
	// vec.pop_back();
	// for (size_t i = 0; i < vec.size(); i++)
	// 	std::cout << "vec[" << i << "]:" << vec[i] << "\t\t" << "vec2[" << i << "]:" << vec2[i] << std::endl;
	// ft::swap(vec, vec2);
	// std::cout << std::endl;
	// for (size_t i = 0; i < vec.size(); i++)
	// 	std::cout << "vec[" << i << "]:" << vec[i] << "\t\t" << "vec2[" << i << "]:" << vec2[i] << std::endl;
	// print_cap(vec);
	// print_access(vec);
	// print_content(vec);
	return (0);
}
