#pragma once
#include <exception>
#include <vector>
#include <ctime>


typedef enum vectorType{
	SORTED, ORIGINAL
}vectorType;

class Span
{
	private:

		std::vector<int>	_vector;
		std::vector<int>	_vectorSorted;
		unsigned int		_size;
		unsigned int		_pos;
		bool				_sorted;
		class	CantAddException : public std::exception
		{
			private:
				const char *what() const noexcept override;
		};
	public:
		Span();
		Span(unsigned int n);
		Span(const Span &src);
		Span &operator=(const Span &src);
		~Span();

		void addNumber(int number);
		void addNumberAuto(unsigned int toAddCount, unsigned int maxVal);
		unsigned int shortestSpan();
		unsigned int longestSpan();

		unsigned int getSize() const;
		int getNum(int pos, vectorType mode);
	};