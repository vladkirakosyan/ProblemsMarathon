#include "queue.h"

template <typename T>
Queue<T>::Queue(int cap)
	: _def(cap), _tmp(cap)
{
	_cap = cap > 0 && cap < constants::maxSize ? cap : constants::maxSize;
	std::cout << _def._cap << " _def._cap\n";
	std::cout << _tmp._cap << " _tmp._cap\n";
}

template <typename T>
Queue<T>::Queue(const Queue<T>& src)
	: _cap{ src._cap }, _def(src._def), _tmp(src._tmp)
{
}

template<class T>
Queue<T>& Queue<T>::operator=(Queue<T>& rhs)
{
	if (*this == &rhs) return *this;
	std::swap(*this, rhs);
	return *this;
}

template<class T>
bool Queue<T>::isFull1() const
{
	return _def.isFull3();
}

template <typename T>
bool Queue<T>::isFull2() const
{
	return _tmp.isFull1() && _tmp.isFull2() && _tmp.isFull3();
}

template <typename T>
bool Queue<T>::isEmpty1() const
{
	return _def.isEmpty1() && _def.isEmpty2() && _def.isEmpty3();
}
template <typename T>
bool Queue<T>::isEmpty2() const
{
	return _tmp.isEmpty1() && _tmp.isEmpty2() && _tmp.isEmpty3();
}

