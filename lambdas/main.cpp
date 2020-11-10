#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <iterator>
#include <functional>


using namespace std;

template<typename Cont>
void print(Cont& v, char ending = '\n') {
	for (auto elem : v) {
		cout << elem << " ";
	}
	cout << ending;
}

bool pred(int first, int second) {
	return (first >= second);
}

void withSTL(vector<int>& coll) {
	cout << "First 5 elements get squared: " << endl;
	transform(coll.begin(), next(coll.begin(), 5), coll.begin(),
		[] (int elem) {
			return elem*elem;
		});

	
	for_each(coll.begin(), coll.end(), [](int elem) {
		cout << elem << " ";
	});
	cout << endl;
	//
	remove_if(coll.begin(), coll.end(), [] (int elem) {
		return (elem % 2 == 0);
	});
	cout << "All odd removed:" << endl;
	print(coll);
	//
	cout << "Copy into multiset with descending order: " << endl;
	auto my_greater = [](int first, int second) {
		return first > second;
	};

	set<int, decltype(my_greater) > coll2(my_greater);

	copy(coll.begin(), coll.end(), inserter(coll2, coll2.begin()));
	print(coll2);
	//
	using namespace std::placeholders;
	auto it = find_if(coll2.cbegin(), coll2.cend(), 
						bind(equal_to<int>(), _1, 11));
	cout << "11 preceedes to " << *next(it) << endl;
}

void simpleUsingOfLambda() {
	int x = 0, y = 0;
	auto l = [x, &y] {
		cout << x << " " << y << endl;
		//x = 1;	ERROR: x is captured by value so you are not allowed to modify it
		//			capture by value is default mode
		++y;
	};

	auto l_mutable = [x, &y]() mutable {
		cout << x << " " << y << endl;
		x += 1;			//OK because lambda is mutable. Note that it doesn't change outer x. 
						//While calling lambda at first time, the copy of outer x is created. 
						//With mutable lambda has a state.
	};

	l_mutable();
	l_mutable();
	l_mutable();
}

int main() {

	vector<int> coll(24);
	for (int i = 0; i < 24; ++i) {
		coll[i] = i;
	}
	withSTL(coll);
	
	system("pause");
	return 0;
}