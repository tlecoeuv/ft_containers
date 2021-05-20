#include "Map.hpp"

int		main()
{
	ft::map<char,int> mymap;
	ft::map<char,int>::iterator itlow,itup;
	mymap['a']=20;
	mymap['d']=80;
	mymap['e']=100;
	mymap['g']=111234;
	mymap['i']=67;
	mymap['r']=87;
	mymap['u']=32;

	mymap.print();
	itlow = mymap.begin();
	itlow++;
	std::cout << "yo" << std::endl;
	// mymap.print();
	itlow=mymap.lower_bound ('b');
	std::cout << "itlow: " << itlow->first << std::endl;
	itup=mymap.upper_bound ('s');
	itup--;
	std::cout << "yo 2" << std::endl;
	mymap.erase(itlow,itup);
	std::cout << "erased" << std::endl;
}
