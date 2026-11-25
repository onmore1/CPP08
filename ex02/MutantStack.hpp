
#pragma once
#include <stack>

template <typename T> class MutantStack : public std::stack<T>
{
	public:
		MutantStack() : stack()
		{
			std::cout << "Default constructor for MutantStack was called\n";
		}
		MutantStack(const MutantStack &src) : stack(src)
		{
			std::cout << "Custom constructor for MutantStack was called\n";
		}
		~MutantStack()
		{
			std::cout << "Deconstructor for MutantStack was called\n";
		}
		stack &operator=(const MutantStack &src)
		{
			if (*this != src)
				*this = src;
			return (*this);
		}
		//
		typedef typename std::deque<T>::iterator dIterator;
		typedef typename std::deque<t>::iterator constDIterator;

		dIterator begin()
		{
			return (stack::c.begin());
		}
		dIterator end()
		{
			return (stack::c.end());
		}
		constDIterator begin() const
		{
			return (stack::c.begin());
		}
		constDIterator end() const
		{
			return (stack::c.end());
		}
};