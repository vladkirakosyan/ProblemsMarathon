#pragma once
#include "Stack3h.h"

/* CONSTRUCTURES */
template <typename T>
Stack<T>::Stack(size_t cap)
{
	_cap = (cap > 0 and cap <= constants::maxSize) ? cap : constants::maxSize;
	_arr = new T[_cap];

	_top1 = _min = 0;
	_top2 = _size2 = _size1 = _cap / 3;
	_size3 = _cap - 2 * _size1;
	_top3 = _size1 * 2;
}
template<typename T>
Stack<T>::Stack(const Stack<T>& src)
	: _cap{ src._cap } , _top1{ src._top1 }, _top2{ src._top2 },
	_top3{ src._top3 }, _size1{ src._size1 }, _size2 { src._size2 },
	_size3 { src._size3 }, _min{ src._min }
{
	_arr = new T[_cap];
	for (int i = 0; i < _cap; ++i)
	{
		_arr[i] = src._arr[i];
	}
}

template<typename T>
Stack<T>::Stack(Stack<T>&& src) noexcept
	: _cap{ src._cap }, _top1{ src._top1 }, _top2{ src._top2 },
	_top3{ src._top3 }, _size1{ src._size1 }, _size2{ src._size2 },
	_size3{ src._size3 }, _arr{ src._arr }, _min { src._min }
{
	src._arr = { nullptr };
}

template<typename T>
Stack<T>& Stack<T>::operator=(Stack<T> lhs)
{
	if (*this == &lhs) return *this;
	std::swap(*this, lhs);
	return *this;
}

template<typename T>
Stack<T>& Stack<T>::operator=(Stack<T>&& lhs) noexcept
{
	if (*this == &lhs) return *this;
	delete[] _arr;
	_arr = { lhs._arr };
	_cap = { lhs._cap };
	_min = { lhs._min };
	_top1 = { lhs._top1 }; _top2 = { lhs._top2 }; _top3 = { lhs._top3 };
	_size1 = { lhs._size1 }; _size2 = { lhs._size2 }; _size3 = { lhs._size3 };
	return *this;
}

/* TOP_OF DEFINITON FOR ALL PARTS OF ARRAY */
template<typename T>
const T& Stack<T>::topOf1()
{
	if (!isEmpty1()) {
		return _arr[_top1 - 1];
	}
	return T();
}
template<typename T>
const T& Stack<T>::topOf2()
{
	if (!isEmpty2()) {
		return _arr[_top2 - 1];
	}
	return T();
}
template<typename T>
const T& Stack<T>::topOf3()
{
	if (!isEmpty3()) {
		return _arr[_top3 - 1];
	}
	return T();
}

/* ISEMPTY(), ISFULL() DEFINITION FOR 3 PARTS */
template<typename T>
bool Stack<T>::isEmpty1() const
{
	return _top1 == 0;
}

template<typename T>
bool Stack<T>::isEmpty2() const
{
	return _top2 == _cap / 3;
}

template<typename T>
bool Stack<T>::isEmpty3() const
{
	return _top3 == _size1 * 2;
}

template<typename T>
bool Stack<T>::isFull1() const
{
	return _top1 == _cap / 3;
}

template<typename T>
bool Stack<T>::isFull2() const
{
	return _top2 == _size1 * 2;
}

template<typename T>
bool Stack<T>::isFull3() const
{
	return _top3 == _cap;
}

/* PUSH OPERATIONS */
template<typename T>
void Stack<T>::push1(const T& elem)
{
	if (!isFull1()) {
		if (_min > elem) { _min = elem; }
		_arr[_top1++] = elem;
	}
	else {
		std::cout << "Program terminated, stack1 is full.\n";
		throw - 1;
	}
}
template<typename T>
void Stack<T>::push2(const T& elem)
{
	if (!isFull2()) {
		if (_min > elem) { _min = elem; }
		_arr[_top2++] = elem;
	}
	else {
		std::cout << "Program terminated, stack2 is full.\n";
		throw - 1;
	}
}
template<typename T>
void Stack<T>::push3(const T& elem)
{
	if (!isFull3()) {
		if (_min > elem) { _min = elem; }
		_arr[_top3++] = elem;
	}
	else {
		std::cout << "Program terminated, stack3 is full.\n";
		throw - 1;
	}
}

template<typename T>
T Stack<T>::pop1() noexcept
{
	if (!isEmpty1()) {
		return _arr[--_top1];
	}
	else {
		std::cout << "Program terminated, stack1 is empty." << std::endl;
		throw - 1;
	}
}
template<typename T>
T Stack<T>::pop2() noexcept
{
	if (!isEmpty2()) {
		return _arr[--_top2];
	}
	else {
		std::cout << "Program terminated, stack2 is empty." << std::endl;
		throw - 1;
	}
}
template<typename T>
T Stack<T>::pop3() noexcept
{
	if (!isEmpty3()) {
		return _arr[--_top3];
	}
	else {
		std::cout << "Program terminated, stack3 is empty." << std::endl;
		throw - 1;
	}
}

