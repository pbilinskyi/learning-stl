#pragma once
#include <vector>
#include <cassert>
#include <ostream>

template <typename T>
class Stack;

template <typename T>
std::ostream& operator<< (std::ostream&, Stack<T> const&);


template<typename T>
class Stack {
private:
	std::vector<T> elems; // elements
public:
	void push(T const& elem); // push element
	void pop(); // pop element
	T const& top() const; // return top element
	bool empty() const { // return whether the stack is empty
			return elems.empty();
	}

	template <>
	friend std::ostream& operator<< (std::ostream& os, Stack<T> const & st);
};

template<typename T>
std::ostream& operator<< (std::ostream& os, Stack<T> const & st) {
	for (auto it = st.elems.cbegin(); it != st.elems.end(); ++it) {
		os << *it << " ";
	}
	os << '\n';
	return os;
}

template<typename T>
void Stack<T>::push(T const& elem)
{
	elems.push_back(elem); // append copy of passed elem
}
	
template<typename T>
void Stack<T>::pop()
{
		assert(!elems.empty());
		elems.pop_back(); // remove last element
}

template<typename T>
T const& Stack<T>::top() const
{
	assert(!elems.empty());
	return elems.back(); // return copy of last element
}