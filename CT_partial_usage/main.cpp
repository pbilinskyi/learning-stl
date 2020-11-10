#include <iostream>
#include "Stack.h"


int main(){
	Stack<int> st;
	st.push(1);
	st.push(2);
	std::cout << st;
	system("pause");
	return 0;
}