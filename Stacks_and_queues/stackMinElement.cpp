#include "stackMinElement.h"

/* CONSTRUCTORS AND COPY ASSIGNMENT OPERATORS */
template<class T>
Stack<T>::Stack(int size)
{
	m_cap = (size > 0 && size < 1000) ? size : 10;
	m_top = -1;
	m_min = T();
	m_vec_min.reserve(m_cap); // this forces to do push_back() operation in O(1) constant time
	m_arr = new T [m_cap];
}

template <typename T>
Stack<T>::Stack(const Stack<T>& src)
	: m_cap{ src.m_cap }, m_top{ src.m_top }, m_min{ src.m_min },
	m_vec_min{ src.m_vec_min }, m_arr{ new T[src.m_cap] }
{
	for (int i = 0; i <= m_top; ++i)
	{
		m_arr[i] = src.m_arr[i];
	}
}

template <typename T>
Stack<T>::Stack(Stack<T>&& src) noexcept
	: m_cap{ src.m_cap }, m_top { src.m_top }, m_arr { src.m_arr },
	  m_vec_min{ src.m_vec_min }, m_min { src.m_min }
{
	src.m_arr = nullptr;
	src.m_cap = src.m_top = 0;
}

template <typename T>
Stack<T>& Stack<T>::operator=(Stack<T> lhs)
{
	if (*this == &lhs) return *this;
	std::swap(std::move(*this), std::move(lhs));
	return *this;
}

template <typename T>
Stack<T>& Stack<T>::operator=(Stack<T>&& lhs) noexcept
{
	m_cap = lhs.m_cap;
	m_arr = lhs.m_arr;
	m_top = lhs.m_top;
	m_min = lhs.m_min;
	m_vec_min = lhs.m_vec_min;
	lhs.m_arr = nullptr;
	return *this;
}


/* GENERIC FUNCTIONS & PUBLIC INTERFACE */
template<class T>
void Stack<T>::push(const T& elem) 
{
	if (!isFull()) {
		if (isEmpty()) {
			m_min = elem;
			m_vec_min.push_back(m_min);
		}
		else if (m_min > elem) {
			m_min = elem;
			m_vec_min.push_back(m_min);
		}
		m_arr[++m_top] = elem;
	}
	else {
		std::cout << "Program terminated, stack is full." << std::endl;
		exit(0);
	}
	
}

template<typename T>
T Stack<T>::pop() noexcept
{
	if (!isEmpty()) { 
		if (m_min == m_arr[m_top]) {
			m_vec_min.pop_back();
			m_min = !m_vec_min.empty() ? m_vec_min.back() : T(); 
			// it's O(1) constant functions && we have nothrow guarantee for both
		}
		return m_arr[m_top--];
	}
	else {
		std::cout << "Program terminated, stack is empty." << std::endl;
		exit(0);
	}
}

template<class T>
const T Stack<T>::top() const{
	if (!isEmpty()) {
		return m_arr[m_top];
	} 
	return -1;
}

template<class T>
T Stack<T>::min() const
{
	return m_min;
}

