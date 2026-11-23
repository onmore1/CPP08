#include "Span.hpp"
#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <algorithm>


Span::Span():_size(0), _pos(0), _sorted(false)
{
	std::cout << "Default Span constructor called\n";
}

Span::Span(unsigned int n):_size(n), _pos(0), _sorted(false)
{
	std::cout << "Span constructor with size '" << n << "' was called\n";
}

Span::Span(const Span &src):_vector(src._vector), _vectorSorted(src._vectorSorted), _size(src._size), _pos(src._pos), _sorted(src._sorted)
{
	std::cout << "Span copy constructor called\n";
}

Span &Span::operator=(const Span &src)
{
	std::cout << "Span '=' operator called\n";
	if (this != &src)
	{
		this->_size = src._size;
		this->_pos = src._pos;
		this->_sorted = src._sorted;
		this->_vector = src._vector;
		this->_vectorSorted = src._vectorSorted;
	}
	return *this;
}

Span::~Span()
{
	std::cout << "Span deconstructor was called\n";
}

const char *Span::CantAddException::what() const noexcept
{
	return ("Can not add a number");
}

void Span::addNumber(int number)
{
	if (this->_vector.size() >= this->_size)
		throw CantAddException();
	this->_vector.push_back(number);
	this->_sorted = false;
}

void Span::addNumberAuto(unsigned int toAddCount, unsigned int maxVal)
{
	std::srand(std::time(NULL));
	for (; toAddCount > 0; toAddCount--)
	{
		unsigned int num = static_cast<unsigned int>(std::rand())
			% (static_cast<unsigned long>(maxVal) + 1);
		try
		{
			this->addNumber(static_cast<int>(num));
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << '\n';
			return;
		}
	}
}

unsigned int Span::longestSpan()
{
	if (this->_vector.size() < 2)
		throw std::out_of_range("Not enough numbers to calculate a span");
	int smallest = *std::min_element(this->_vector.begin(), this->_vector.end());
	int largest = *std::max_element(this->_vector.begin(), this->_vector.end());
	return static_cast<unsigned int>(largest) - static_cast<unsigned int>(smallest);
}

unsigned int Span::shortestSpan()
{
	if (this->_vector.size() < 2)
		throw std::out_of_range("Not enough numbers to calculate a span");
	if (!this->_sorted)
	{
		this->_vectorSorted = this->_vector;
		std::sort(this->_vectorSorted.begin(), this->_vectorSorted.end());
		this->_sorted = true;
	}
	unsigned int shortest = static_cast<unsigned int>(-1);
	for (std::vector<int>::size_type i = 1; i < this->_vectorSorted.size(); i++)
	{
		unsigned int difference =
			static_cast<unsigned int>(this->_vectorSorted[i]) -
			static_cast<unsigned int>(this->_vectorSorted[i - 1]);
		if (difference < shortest)
			shortest = difference;
	}
	return shortest;
}

unsigned int Span::getSize() const
{
	return (this->_size);
}

int Span::getNum(int pos, vectorType mode)
{
	if (pos < 0 || static_cast<unsigned int>(pos) >= this->_vector.size())
		throw std::out_of_range("No number at this position");
	if (mode == vectorType::ORIGINAL)
		return (this->_vector[pos]);
	if (!this->_sorted)
	{
		this->_vectorSorted = this->_vector;
		std::sort(this->_vectorSorted.begin(), this->_vectorSorted.end());
		this->_sorted = true;
	}
	return (this->_vectorSorted[pos]);
}