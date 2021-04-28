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
	int		i;
	ft::RedBlackTree<int, int>	test_tree;

	for (i = 0; i < 12; i++)
	{
		int x = 12 - i;
		int y = i;
		test_tree.print_tree();
		std::cout << "Inserting " << x << " -> " << y << std::endl << std::endl;
		test_tree.insert(std::pair<int, int>(x, y));
	}
	test_tree.print_tree();
	return (0);
}
