#include "Span.hpp"
#include <algorithm>
Span::Span():_size(0), _pos(0)
{
	std::cout << "Default Span constructor called\n";
}

Span::Span(const Span &src):_size(src._size), _pos(src._pos)
{
	std::cout << "Span copy constructor called\n";
	*this = src;
}

Span &Span::operator=(const Span &src)
{
	std::cout << "Span '=' operator called\n";
	unsigned int srcSize = src.getSize();
	this->_vector.reserve(srcSize);
	this->_vector.insert(this->_vector.begin(), src._vector.begin(), src._vector.end());
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
	if (this->_pos == this->_size)
		throw CantAddException();
	else
	{
		this->_vector.push_back(number);
		this->_pos++;
	}
}

unsigned int Span::longestSpan()
{
	std::pair<std::vector<int>::iterator, std::vector<int>::iterator> result; // iterator - smart pointer, pair - 2 elemts storage
	result = std::minmax_element(this->_vector.begin(), this->_vector.end());
	return (*result.first - *result.second);
}

