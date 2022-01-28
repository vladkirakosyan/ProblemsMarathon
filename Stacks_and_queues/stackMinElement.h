#ifndef STACK_H
#define STACK_H


#include <vector>
template <class T>
class Stack final {

public:
	explicit Stack(int size = 10);
	~Stack() { delete[] m_arr; }
	Stack(const Stack<T>& src);
	Stack(Stack<T>&& src) noexcept;
	Stack<T>&operator=(Stack<T> lhs);
	Stack<T>& operator=(Stack<T>&& lhs) noexcept;

public:
	void push(const T&);
	T pop() noexcept;
	T min() const;
	const T top() const;
	int size() const { return m_top + 1; }
	bool isEmpty() const { return m_top == -1; }
	bool isFull() const { return m_top == m_cap - 1; }
	friend std::ostream& operator<<(std::ostream& os, const Stack<T>& src)
	{
		os << "Stack size is " << src.size() << '\t';
		os << ",elements are : ";
		for (int i = 0; i < src.size(); ++i)
		{
			os << src.m_arr[i] << " ";
		}
		return os;
	}

private:
	int m_cap;
	int m_top;
	T m_min;
	T* m_arr;
	std::vector<T> m_vec_min;
	
};


#include "stackMinElement.cpp" 
#endif // STACK_H
