
#pragma once
#include <stack>
#include <iostream>

template <typename T> class MutantStack : public std::stack<T>
{
	public:
		MutantStack()
		{
			std::cout << "Default constructor for MutantStack was called\n";
		}
		MutantStack(const MutantStack &src)
		{
			*this = src;
			std::cout << "Custom constructor for MutantStack was called\n";
		}
		~MutantStack()
		{
			std::cout << "Deconstructor for MutantStack was called\n";
		}
		MutantStack &operator=(const MutantStack &src)
		{
			this->c = src.c;
			return *this;
		}
		//

		typedef typename std::stack<T> stack;
		typedef typename std::deque<T>::iterator iterator;
		iterator begin()
		{
			return (this->c.begin());
		}
		iterator end()
		{
			return (this->c.end());
		}
		//

		void push(const T &value)
		{
			std::cout << "Pushing: " << value << "\n";
			stack::push(value);
		}
		T top()
		{
			std::cout << "Top: ";
			return (stack::top());
		}
		void pop()
		{
			std::cout << "Popping: " << stack::top() << "\n";
			stack::pop();
		}
		T size()
		{
			std::cout << "Size: ";
			return (stack::size());
		}
};