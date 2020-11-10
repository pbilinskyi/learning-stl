#include <iostream>
#include <vector>
#include <list>
#include <unordered_set>
#include <set>
#include <iterator>
#include <algorithm>

using namespace std;

template<typename Cont>
void print(Cont& v, char ending = '\n') {
	for (auto elem : v) {
		cout << elem << " ";
	}
	cout << ending;
}

void remove1() {
	/*
	The code shows remove() changes containers size and provide correct and intuiteve removing.
	The only disadvatege of using remove() is that unordered containers don't 
	work with external modificating algorithms, especially with remove().
	Use erase(element) for removing elements from unordered containers.
	It returns count of erased elements.
	
	*/



	list<int> coll;
	for (int i = 1; i <= 6; ++i) {
		coll.push_back(i);
		coll.push_front(i);
	}

	ostream_iterator<int> osit(cout, " ");
	cout << "pre: ";
	copy(coll.begin(), coll.end(), osit);
	cout << endl;
	cout << coll.size() << endl;


	coll.remove(3);

	cout << "post: ";
	copy(coll.begin(), coll.end(), osit);
	cout << endl;
	cout << coll.size() << endl;
}

void removeFromAssociative() {
	multiset<int> coll = { 4, 8, 3, 0,  3, 5, 2, 8 };
	
	//remove(coll.begin(), coll.end(), 3);	ERROR 

}

void f() {
	set<int> coll = { 1, 2, 3, 4, 5, 6, 7 };

	for_each(coll.begin(), coll.end(), [] (int elem) {
		return elem * elem;
	});

	vector<int> v(coll.size());
	transform(coll.begin(), coll.end(), v.begin(), [] (int elem) {
		return elem * elem;
		});
	print(v);
}

int main() {
	//remove1();
	f();
	//int count = coll.erase();
	//cout << count << endl;
	system("pause");
	return 0;
}