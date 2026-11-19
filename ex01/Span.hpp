#pragma once
#include "vector"
#include "iostream"
class Span
{
	private:
		std::vector<int> _vector;
		unsigned int _size;
		unsigned int _pos;
		class	CantAddException : public std::exception
		{
			private:
				const char *what() const noexcept override;
		};
	public:
		Span();
		Span(const Span &src);
		Span &operator=(const Span &src);
		~Span();

		void addNumber(int number);
		unsigned int shortestSpan();
		unsigned int longestSpan();

		unsigned int getSize() const;

};