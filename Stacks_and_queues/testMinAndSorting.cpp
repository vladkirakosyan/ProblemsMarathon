/*
* Design and implement a stack which, in addition to push and pop,
* has a function min which returns the minimum element.
* Push, pop and min should all operate in 0(1) time.
*/

/*
* Write a program to sort a stack such that the smallest items are on the top.
* You can use an additional temporary stack, but you may not copy the elements
* into any other data structure (such as an array). The stack supports the following
* operations: push, pop, peek, and isEmpty.
*/

#include <iostream> 
#include "stackMinElement.h"

template <typename T>
void sorting(Stack<T>& src) noexcept
{
	Stack<T> tmpStack;

	while (!src.isEmpty())
	{
		T elem = src.pop();
		while (!tmpStack.isEmpty() && tmpStack.top() > elem)
		{
			src.push(tmpStack.pop());
		}
		tmpStack.push(elem);
	}
	std::swap(src, tmpStack);
}
int main(){
	
	Stack<char> a(40);
	a.push('t');
	a.push('f');
	a.push('l');
	a.push('a');

	Stack<int> b;
	b.push(4);
	b.push(3);
	b.push(-5);
	b.push(8);
	b.push(-10);

	sorting(b);
	std::cout << b;
	

	/*std::cout << "size_is_ " << a.size() << std::endl;
	std::cout << a.pop() << " ";
	std::cout << a.pop() << " ";
	std::cout << a.top() << " ";*/
	
	
	//std::cout << a.pop() << std::endl;
	//std::cout << a.top(); 
	return 0;
}
