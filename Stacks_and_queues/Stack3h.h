#ifndef STACK_3_PARTS
#define STACK_3_PARTS
namespace constants
{
	const size_t maxSize = 1000;
}

template <typename T>
class Stack
{
public:
	explicit Stack(size_t cap = 1000);
	Stack(const Stack<T>& src);
	Stack(Stack<T>&& src);
	Stack& operator=(Stack<T> lhs);
	~Stack() { delete[] _arr; }

public:
	/* PUSHES AN ELEMENT IF GIVEN PART ISN't FULL */
	void push1(const T&);
	void push2(const T&);
	void push3(const T&);
	/* POPS AN ELEMENT FROM ONE OF PARTS AND RETURNS IT IF GIVEN PART IS NOT EMPTY */
	T pop1() noexcept;
	T pop2() noexcept;
	T pop3() noexcept;
	/* RETURNS TOP OF STACKS 1st, 2nd, or 3rd PART's LAST ELEMENT */
	const T& topOf1();
	const T& topOf2();
	const T& topOf3();
	/* CHECKS IF STACK IS EMPTY */
	bool isEmpty1() const;
	bool isEmpty2() const;
	bool isEmpty3() const;
	/* CHECKS IF STACK IS FULL */
	bool isFull1() const;
	bool isFull2() const;
	bool isFull3() const;

//private:
	T* _arr;

	size_t _cap; 
	size_t _size1;
	size_t _size2;
	size_t _size3;

	size_t _top1;
	size_t _top2;
	size_t _top3;
};

#include "Stack3h.hpp"
#endif // STACK_3_PARTS
