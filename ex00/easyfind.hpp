#pragma once
#include <exception>
#include <algorithm>
#include <iostream>
#include <type_traits>

class NoResultFoundException : public std::exception
{
	public:
		const char *what() const noexcept override;
};

const char *NoResultFoundException::what() const noexcept
{
	return ("No result found");
}

template <typename T> void easyfind(T &container, int toFind)
{
	std::cout << "Trying to find: " << toFind << "\n";
	if (std::find(container.begin(), container.end(), toFind) == container.end())
		throw NoResultFoundException();
	else
		std::cout << "Value: " << toFind << ", was found!\n";
}