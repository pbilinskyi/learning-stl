#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>

using namespace std;
using namespace std::placeholders;

template<typename Cont>
void print(Cont& v, char ending = '\n') {
	for (auto elem : v) {
		cout << elem << " ";
	}
	cout << ending;
}

void func(int a, int b, int c)
{
	cout << (a - b - c) << endl;
}

void usingBind1() {
	auto fn1 = bind(func, _1, 2, 3);
	auto fn2 = bind(func, 2, _1, 3);

	fn1(10);
	fn2(10);
}

void usingBind2() {
	// Second parameter to fn1() is assigned 
   // to 'a' in func(). 
   // 2 is assigned to 'b' in func 
   // First parameter to fn1() is assigned 
   // to 'c' in func(). 
	auto fn1 = bind(func, _2, 2, _1);

	// calling of function 
	cout << "The value of function is : ";
	fn1(1, 13);

	// First parameter to fn2() is assigned 
	// to 'a' in func(). 
	// 2 is assigned to 'b' in func
	// Second parameter to fn2() is assigned 
	// to 'c' in func(). 
	auto fn2 = bind(func, _1, 2, _2);

	// calling of same function 
	cout << "The value of function after changing"
		" placeholder position is : ";
	fn2(1, 13);
}

void bindersInStl() {
	//use binders to define more complicated functional objects
	vector<int> coll(24);
	for (int i = 0; i < 24; ++i) {
		coll[i] = i;
	}

	auto fn1 = bind(greater<int>(), _1, 20);
	auto fn2 = bind(less<int>(), _1, 10);
	auto fn3 = bind(logical_or<bool>(), fn1, fn2);

	cout << fn3(19) << endl;

	vector<int>::const_iterator new_end = remove_if(coll.begin(), coll.end(), fn3);
	coll.erase(new_end, coll.end());
	print(coll);
	cout << endl;
}

int main() {
	bindersInStl();
	system("pause");
	return 0;
}