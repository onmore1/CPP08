#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>

int main()
{
	std::vector<int> vInt(10, 0);
	for (int i = 0; i < 10; i++)
		vInt[i] = i * 2;
	try
	{
		std::cout << "Trying with vector\n";
		easyfind(vInt, 4);
	}
	catch (const std::exception &e)
	{
		std::cout << "Error: " << e.what() << "\n";
	}
	try
	{
		std::cout << "Trying with int list\n";
		std::list<int> lInt = {10, 20, 30, 40};
		easyfind(lInt, 30);
	}
	catch (const std::exception &e)
	{
		std::cout << "Error: " << e.what() << "\n";
	}
	try
	{
		std::cout << "Trying with deque\n";
		std::deque<int> dInt = {0, 0, 1, 10, 9999, 32};
		easyfind(dInt, 0);
		easyfind(dInt, -1);
	}
	catch (const std::exception &e)
	{
		std::cout << "Error: " << e.what() << "\n";
	}
	try
	{
		std::cout << "\nTrying with empty vector\n";
		std::vector<int> empty;
		easyfind(empty, 42);
	}
	catch (const std::exception &e)
	{
		std::cout << "Error: " << e.what() << "\n";
	}
	try
	{
		std::cout << "\nTrying first and last elements\n";
		std::vector<int> boundary = {10, 20, 30, 40, 50};
		easyfind(boundary, 10);
		easyfind(boundary, 50);
	}
	catch (const std::exception &e)
	{
		std::cout << "Error: " << e.what() << "\n";
	}
	try
	{
		std::cout << "\nTrying with duplicate values\n";
		std::vector<int> duplicates = {5, 5, 5, 10, 10, 20};
		easyfind(duplicates, 5);
		easyfind(duplicates, 10);
		easyfind(duplicates, 20);
		easyfind(duplicates, 99);
	}
	catch (const std::exception &e)
	{
		std::cout << "Error: " << e.what() << "\n";
	}
	try
	{
		std::cout << "\nTrying with negative numbers\n";
		std::list<int> negative = {-10, -5, -1, 0, 1, 5};
		easyfind(negative, -10);
		easyfind(negative, -1);
		easyfind(negative, -99);
	}
	catch (const std::exception &e)
	{
		std::cout << "Error: " << e.what() << "\n";
	}
	try
	{
		std::cout << "\nTrying with const vector\n";
		const std::vector<int> constVector = {1, 2, 3, 4, 5};
		easyfind(constVector, 3);
		easyfind(constVector, 99);
	}
	catch (const std::exception &e)
	{
		std::cout << "Error: " << e.what() << "\n";
	}

	return (0);
}
