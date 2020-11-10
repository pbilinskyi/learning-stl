#include <iostream>
#include <vector>
#include <iterator>
#include <set>

using namespace std;

template<typename Cont>
void print(Cont& v, char ending = '\n') {
	for (auto elem : v) {
		cout << elem << " ";
	}
	cout << ending;
}

void printWithIterator() {
	vector<int> v = { 10, 6, 2, 9, 1, 0, 8 };

	/*for (vector<int>::const_iterator it = v.begin(); it != v.cend(); ++it) {
		cout << *it << " ";
	}
	cout << endl;
	
	//in reverse order
	for (vector<int>::const_reverse_iterator it = v.crbegin(); it != v.crend(); ++it) {
		cout << *it << " ";
	}

	for (int elem : v) {
		cout << elem << endl;
	}
*/
	auto it = v.rend();
	cout << *--it << endl;
	cout << endl;
}

void auxilaryFunctions() {
	vector<int> coll(24);
	for (int i = 0; i < 24; ++i) {
		coll[i] = i;
	}
	
	//advance()
	vector<int>::iterator it = coll.begin();
	advance(it, 2);
	cout << *it <<endl;

	//next()
	cout <<  "next(it)->" << *next(it) << "\nit -> " << *it << endl;
	
	//distance()
	it = prev(coll.end(), 20);
	cout << distance(coll.begin(), it) << endl;
}

int main() {


	auxilaryFunctions();
	system("pause");
	return 0;
}