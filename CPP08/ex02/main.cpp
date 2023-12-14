#include "MutantStack.hpp"
#include <iostream>
#include <list>
#include <vector>

int main()
{
	{
		std::cout << "-----STACK-----" << std::endl;
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;//17
		mstack.pop();
		std::cout << mstack.size() << std::endl;//1
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}
	{
		std::cout << "-----LIST-----" << std::endl;
		std::list<int> list;
		list.push_front(5);
		list.push_front(17);
		std::cout << list.front() << std::endl;
		list.pop_front();
		std::cout << list.size() << std::endl;
		list.push_back(3);
		list.push_back(5);
		list.push_back(737);
		//[...]
		list.push_back(0);
		std::list<int>::iterator it2 = list.begin();
		std::list<int>::iterator ite2 = list.end();
		++it2;
		--it2;
		while (it2 != ite2)
		{
			std::cout << *it2 << std::endl;
			++it2;
		}
		std::list<int> s(list);
	}
	{
		std::cout << "-----VECTOR-----" << std::endl;
		std::vector<int> vect;
		vect.insert(vect.begin(), 5);
		vect.insert(vect.begin(), 17);
		std::cout << vect.front() << std::endl;
		vect.erase(vect.begin());
		std::cout << vect.size() << std::endl;
		vect.push_back(3);
		vect.push_back(5);
		vect.push_back(737);
		//[...]
		vect.push_back(0);
		std::vector<int>::iterator it2 = vect.begin();
		std::vector<int>::iterator ite2 = vect.end();
		++it2;
		--it2;
		while (it2 != ite2)
		{
			std::cout << *it2 << std::endl;
			++it2;
		}
		std::vector<int> s(vect);
	}
}
