#include <iostream>

using namespace std;

// maximum of two values of any type (call-by-reference)
template<typename T>
T const& max(T const& a, T const& b)
{
	cout << "by reference 2" << endl;
	return b < a ? a : b;
}


// maximum of two C-strings (call - by - value)
char const* max(char const* a, char const* b)
{
	cout << "by value 2" << endl;
	return std::strcmp(b, a) < 0 ? a : b;
}

// maximum of three values of any type (call-by-reference)
template<typename T>
T const& max(T const& a, T const& b, T const& c)
{
	return max(max(a, b), c); // error if max(a,b) uses call - by - value
} 

int main(){
		//auto m1 = ::max(7, 42, 68); // OK
		char const* s1 = "frederic";
		char const* s2 = "anica";
		char const* s3 = "lucas";
		auto m2 = ::max(s1, s2, s3); //run-time ERROR
		cout << m2 << endl;
		system("pause");
		return 0;

}