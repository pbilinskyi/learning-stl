#include <iostream>

using namespace std;

/*
template<typename T1, typename T2>
auto max2(T a, T b) {
	cout << "template 2" ;
	return a > b ? a : b;
}

template<typename RT, typename T1, typename T2>
T max2(T a, T b) {
	cout << "template 3" ;
	return a > b ? a : b;
}

void f2() {
	cout << max2(1.0, 2.0) << endl;				//template 2 only matches

	cout << max2<long double>(1.0, 2) << endl;	//template 3 only matches

	cout << max2<int>(1.0, 2) << endl;			//ERROR, both matches
}
*/

int max(int a, int b) {
	std::cout << "non-template ";
	return a > b ? a : b;
}

template<typename T>
T max(T a, T b) {
	cout << "template 1";
	return a > b ? a : b;
}

int main() {
	cout << max(1, 2) << endl;		//NONTEMPLATE functions matches it perfectly
	//Nontemplate has more priority that template

	cout << max(1.0, 2.0) << endl;	//TEMPLATE <double>

	cout << max<>(1, 2) << endl;	//TEMPLATE <int>. That indicates that only templates may resolve a call,
	//but template parameters must be deduced from argument list

	cout << max<int>(1, 2) << endl;	//TEMPLATE <int>

	cout << max('$', 7.2) << endl;	//NONTEMPLATE 
	//Template version doesn't suit. Only the nontemplate functions allows nontrivial conversions.

	system("pause");
	return 0;
}