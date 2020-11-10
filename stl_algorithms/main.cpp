#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

template <typename T>
inline void PRINT_ELEMENTS(const T& coll, const char* optstr = "") {
	cout << optstr;

	for (const auto& elem : coll) {
		cout << elem << " ";
	}
	cout << endl;
}

void sortTest() {
	//can sort only containers with random-access iterators. For example, vectors.
	vector<int> v = { 10, 6, 2, 9, 1, 0, 8 };
	for (auto elem : v) {
		cout << elem << " ";
	}
	cout << endl;
	
	//ERROR: don't pass const iterators as diapason to modificating algorithm
	//sort(v.cbegin(), v.cend());

	sort(begin(v), end(v), greater<int>());
	for (auto elem : v) {
		cout << elem << " ";
	}
	cout << endl;
}

void removeDoesntResize() {
	vector<int> v = { 1, 2, 4, 5, 7, 3, 6, 5, 6, 5};
	PRINT_ELEMENTS(v);
	auto newEnd = remove(v.begin(), v.end(), 1);

	PRINT_ELEMENTS(v, "factically: ");
	cout << "logically: ";
	for (auto it = v.begin(); it != newEnd; ++it) {
		cout << *it << " ";
	}
}

void removeAndResize() {
	vector<int> coll = { 1, 2, 4, 5, 7, 3, 6, 5, 6, 5 };
	PRINT_ELEMENTS(coll);
	auto newEnd = remove(coll.begin(), coll.end(), 1);
	newEnd = coll.erase(newEnd, coll.end());

	PRINT_ELEMENTS(coll, "factically: ");
	cout << "logically: ";
	for (auto it = coll.begin(); it != newEnd; ++it) {
		cout << *it << " ";
	}
}


int main() {
	//sortTest();
	//removeDoesntResize();
	removeAndResize();
	system("pause");
	return 0;
}