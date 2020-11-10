#include <iostream>

using namespace std;

//	Easiest way
template<typename T1, typename T2> 
auto max1(const T1& a, const T2& b) {
	return a > b ? a : b;
}

template<typename RT, typename T1, typename T2> 
RT max2(const T1& a, const T2& b) {
	return a > b ? a : b;
}

//we use decay over decltype(expr) because result may be reference 
//decay<> removes cv-qualifiers, reference, and do other conversions: https://ru.cppreference.com/w/cpp/types/decay 
//result is stored in decay::type
template<typename T1, typename T2> 
auto max2(T1 a, T2 b) -> typename decay<decltype(a > b ? a : b)>::type{
	return a > b ? a : b;
}


//! note that commot_type decays
//equivalent to typename common_type<T1, T2>::type
template<typename T1, typename T2> 
common_type_t<T1, T2> max3(const T1& a, const T2& b) {
	return a > b ? a : b;
}

//demonstrating default template parameters
template <typename T1, typename T2, typename RT = common_type_t<T1, T2> >
RT max(T1 a, T1 b) {
	return a > b ? a : b;
}

int main() {
	cout << ::max1<int, int>(4, 7.2) << endl;
	cout << ::max1(4, 7.2) << endl;
	const char* i = "1234";
	const char* j = i+2;
	cout << max2(i, j) << endl;
	cout << max3(4, 7.2) << endl;
	system("pause");
	return 0;
}