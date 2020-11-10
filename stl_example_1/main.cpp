#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <cstdlib>

using namespace std;

bool isPrime(int n) {
	if (n < 0) n = -n;
	if ((n == 0) || (n == 1)) return 1;
	int divisor;
	for (divisor = n / 2; n%divisor != 0 && divisor > 1; --divisor);
	return (divisor == 1);
}

void usePredicateFunction() {
	list<int> coll;
	for (int i = 24; i < 30; ++i) coll.push_back(i);

	auto pos = find_if(coll.begin(), coll.end(), isPrime);
	if (pos != coll.end()) cout << "first prime : " << *pos << endl;
	else cout << "no primes" << endl;
}

class Person {
public:
	bool operator()(int i) {

	}
};

int main() {
	
	system("pause");
	return 0;
}