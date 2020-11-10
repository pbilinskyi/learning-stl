#include <iostream>
#include <deque>
#include <vector>
#include <string>
#include <algorithm>
#include <chrono>
#include <ctime>
#include <functional>

using namespace std;

template<typename Cont>
void print(Cont& v, char ending = '\n') {
	for (auto elem : v) {
		cout << elem << " ";
	}
	cout << ending;
}


class Person {
	string firstname, lastname;
public:
	Person(string fn, string ln): firstname(fn), lastname(ln) {}
	string getFirstname() const { return firstname; }
	string getLastname() const { return lastname; }
};

bool personSortCriterion(const Person& p1, const Person& p2 ) {
	return (p1.getLastname() < p2.getLastname()) ||
		((p1.getLastname() == p2.getLastname()) && p1.getFirstname() < p2.getFirstname());
}

void f1() {
	deque<Person> coll = { {"Paul", "Bilinskyi"}, {"Carl", "Berg"} };
	sort(coll.begin(), coll.end(), personSortCriterion);
}


void f2() {
	deque<int> coll = { 1, 2, 19, 5, 7, 3, 1, 0, 3, 6, 9, 3, 1, 9, 4 };
	int x = 5;
	int y = 12;
	clock_t  b1 = clock();
	auto pos = find_if(coll.begin(), coll.end(), [=](int i) {
		return (i > x) && (i < y);
	});
	//cout << *pos << endl;
	clock_t e1 = clock();
	cout << "First: " << e1 - b1 << endl;

	b1 = clock();
	for (pos = coll.begin(); pos != coll.end(); ++pos) {
		if ((*pos > x) && (*pos < y)) {
			break;
		}
	}
	e1 = clock();
	cout << "First: " << e1 - b1 << endl;
}

void f3() {
	deque<Person> coll;
	sort(coll.begin(), coll.end(), [](const Person& p1, const Person& p2) {
		return (p1.getLastname() < p2.getLastname()) ||
			((p1.getLastname() == p2.getLastname()) && p1.getFirstname() < p2.getFirstname());
	});
}

class Pred {
	int x, y;
public:
	Pred(int xx, int yy) : x(xx), y(yy) {};
	bool operator()(int i) const {
		return (i > x) && (i < y);
	}
};

void f4() {
	deque<int> coll = {1, 2, 3, 5, 1, 8, 3, 6, 1, 0, 19};
	print(coll);
	Pred fobj(2, 6);
	auto pred = bind(logical_not<bool>(), bind(fobj, placeholders::_1));
	coll.erase(remove_if(coll.begin(), coll.end(), pred), 
			   coll.end());
	print(coll);
}

int main() {
	f4();

	system("pause");
	return 0;
}