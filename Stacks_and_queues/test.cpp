#include <iostream>
#include "Stack3h.h"

namespace constants
{
	std::initializer_list<char> letters{ 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h' };
	std::initializer_list<int> numbers{ 3, 6, 34, 1, 54, -23, 53, -22, 88, 101, 0 };
}

int main()
{
	Stack<int> arr(8);

	arr.push1(4);
	arr.push1(14);
	arr.push3(3);
	arr.push3(-1);
	arr.push3(12);
	arr.push3(90);
	std::cout << arr.pop3(); std::cout << " " << arr.pop3() << "  " << arr.pop3() << " ";
	

	std::cout << arr._cap << '\n';
	std::cout << arr._size1 << '\t';
	std::cout << arr._size2 << '\t';
	std::cout << arr._size3 << '\n';
	std::cout << arr._top1 << '\t';
	std::cout << arr._top2 << '\t';
	std::cout << arr._top3 << '\n';

	std::cout << arr.topOf1() << " " << arr.topOf2() << " " << arr.topOf3() << "\n";

	return 0;
}
