#include "RedBlackTree.hpp"

int		compare_int(int x, int y)
{
	if (x < y)
		return -1;
	else if (x > y)
		return 1;
	else
		return 0;
}

int		main()
{
	ft::RedBlackTree<int, int>	test_tree;

	/*for (int i = 0; i < 12; i++)
	{
		int x = 12 - i;
		int y = i;
		test_tree.print_tree();
		std::cout << "Inserting " << x << " -> " << y << std::endl << std::endl;
		test_tree.insert(std::pair<int, int>(x, y));
	}
	test_tree.print_tree();
	ft::RBT_node<std::pair<const int, int>>	*to_delete = test_tree.search_node(1);
	test_tree.delete_node(to_delete);
	test_tree.print_tree();*/

	/* exemple tree of https://www.youtube.com/watch?v=eO3GzpCCUSg&t=971s*/

	/* example 1 2 3 4 7 8 10: */
/*
	test_tree.insert(std::pair<int, int>(1, 0));
	test_tree.insert(std::pair<int, int>(8, 0));
	test_tree.insert(std::pair<int, int>(11, 0));
	test_tree.insert(std::pair<int, int>(13, 0));
	test_tree.insert(std::pair<int, int>(17, 0));
	test_tree.insert(std::pair<int, int>(15, 0));
	test_tree.insert(std::pair<int, int>(6, 0));
	test_tree.insert(std::pair<int, int>(25, 0));
	test_tree.insert(std::pair<int, int>(22, 0));
	test_tree.insert(std::pair<int, int>(27, 0));
	test_tree.insert(std::pair<int, int>(16, 0));

	ft::RBT_node<std::pair<const int, int>>	*to_delete = test_tree.search_node(6); //ex1
	//ft::RBT_node<std::pair<const int, int>>	*to_delete = test_tree.search_node(1); //ex2
	//ft::RBT_node<std::pair<const int, int>>	*to_delete = test_tree.search_node(17); //ex3
	//ft::RBT_node<std::pair<const int, int>>	*to_delete = test_tree.search_node(25); //ex4
	//ft::RBT_node<std::pair<const int, int>>	*to_delete = test_tree.search_node(13); //ex7
	//ft::RBT_node<std::pair<const int, int>>	*to_delete = test_tree.search_node(8); //ex8
	//ft::RBT_node<std::pair<const int, int>>	*to_delete = test_tree.search_node(11); //ex10
*/
	/* example 5 9: */
/*
	test_tree.insert(std::pair<int, int>(7, 0));
	test_tree.insert(std::pair<int, int>(3, 0));
	test_tree.insert(std::pair<int, int>(18, 0));
	test_tree.insert(std::pair<int, int>(10, 0));
	test_tree.insert(std::pair<int, int>(22, 0));
	test_tree.insert(std::pair<int, int>(8, 0));
	test_tree.insert(std::pair<int, int>(11, 0));
	test_tree.insert(std::pair<int, int>(26, 0));
*/
	//ft::RBT_node<std::pair<const int, int>>	*to_delete = test_tree.search_node(18); //ex5
	//ft::RBT_node<std::pair<const int, int>>	*to_delete = test_tree.search_node(3); //ex9

	/* example 6: */

	test_tree.insert(std::pair<int, int>(5, 0));
	test_tree.insert(std::pair<int, int>(2, 0));
	test_tree.insert(std::pair<int, int>(8, 0));
	test_tree.insert(std::pair<int, int>(1, 0));
	test_tree.insert(std::pair<int, int>(4, 0));
	test_tree.insert(std::pair<int, int>(7, 0));
	test_tree.insert(std::pair<int, int>(9, 0));

	ft::RBT_node<std::pair<const int, int> >	*to_delete = test_tree.search_node(1); //ex6.

	test_tree.print_tree();
	std::cout << "_________________________________________________________\n" << std::endl;
	test_tree.delete_node(to_delete);
	test_tree.print_tree();

	ft::RedBlackTree<int, int>::iterator it = test_tree.begin();
	//ft::RedBlackTree<int, int>::iterator it = test_tree.begin();
	for (; it != test_tree.end(); it++)
		std::cout << " | " << (*it).first << " | " << std::endl;
	return (0);
}
