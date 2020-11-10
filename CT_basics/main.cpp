#include <iostream>
#include "Stack.h"

using namespace std;
//Note 1. Code is instantiated only for member functions that are called

//Note 2. You may use instantiated class template's type just like other types.
//You may use it as a part of declaration of new class template.
//Or to create sysnonymous type via typedef, using.
//You can create aray of Stack<int>'s, for example, or create Stack< Stack<int> >.
//You are able to pass Stack<int>'s as reference, declare it const or volatile.
//DON'T FORGET! Stack<int> intarr[10] means arrayb of 10 Stack<int>'s

using IntStack = Stack<int>;

void CT_as_a_type(Stack<int> const & st) {
	IntStack arr[10];

}

int main() {
	Stack< int> intStack;			// stack of ints
	Stack<std::string> stringStack; // stack of strings
	// manipulate int stack
	intStack.push(7);
	cout << intStack.top() << "\n";
	// manipulate string stack
	stringStack.push("hello");

	cout << stringStack.top().c_str() << "\n";
	stringStack.pop();
	system("pause");
	return 0;
}