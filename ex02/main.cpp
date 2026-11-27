#include "MutantStack.hpp"

int main()
{
MutantStack<int> mstack;
mstack.push(5);
mstack.push(17);
std::cout << mstack.top() << std::endl;
mstack.pop();
std::cout << mstack.size() << std::endl;
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
//STRING
MutantStack<std::string> mstack_string;
mstack_string.push("Hello");
mstack_string.push("\n");
mstack_string.push("1 123 , 123");
mstack_string.push("..what.. . . . . ");
mstack_string.push("wolrd");
mstack_string.push("lol");
std::cout << mstack_string.size();
std::cout << "String Mutat stack start: " << *mstack_string.begin() << "\n";
std::cout << "String Mutat stack end: " << *mstack_string.end() << "\n";
for (MutantStack<std::string>::iterator stringStackBegin = mstack_string.begin(); stringStackBegin < mstack_string.end(); stringStackBegin++)
	std::cout << *stringStackBegin << "\n";
return 0;
}