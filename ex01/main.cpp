#include "Span.hpp"
#include <iostream>

int main()
{
	Span span(3);
	span.addNumber(78);
	span.addNumber(0);
	span.addNumber(77);
	for (unsigned int i = 0; i < span.getSize(); i++)
	{
		span.getNum(i, ORIGINAL);
		std::cout << span.getNum(i, ORIGINAL) << "\n";
	}
	std::cout << "--------------------\n";
	std::cout << "Shortest span is " << span.shortestSpan() << "\n";
	std::cout << "\n";
	for (int i =0; i< 3;i++)
		std::cout << span.getNum(i, SORTED) << "\n";
	std::cout << "--------------------\n";
	std::cout << span.longestSpan() << "\n";
	std::cout << "--------------------\n";
	try
	{
		std::cout << "TRYING COPY ASSIGNMENT OPERATOR\n";
		Span copy;
		copy = span;
		for(unsigned int i = 0 ; i < copy.getSize(); i++)
			std::cout  << copy.getNum(i, ORIGINAL) << "\n";
	}
	catch(std::exception &e)
	{
		std::cout << "Error: " << e.what() << "\n";
	}
	std::cout << "--------------------\n";
	try
	{
		std::cout << "TESTING COPY CONSTRUCTOR\n";
		Span copy(span);
		for(unsigned int i = 0 ; i < copy.getSize(); i++)
			std::cout << copy.getNum(i, ORIGINAL) << "\n";
	}
	catch(const std::exception& e)
	{
		std::cout << "Error: " << e.what() << '\n';
	}
	std::cout << "--------------------\n";
	try
	{
		Span weirdSpan(5);
		weirdSpan.addNumberAuto(5, 15);
		for (unsigned int i = 0; i < weirdSpan.getSize(); i++)
			std::cout << weirdSpan.getNum(i, ORIGINAL) << "\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << "--------------------\n";
}