#include <iostream>
#include <vector>
#include <iterator>
#include <deque>
#include  <set>

using namespace std;

template<typename Cont>
void print(Cont& v, char ending = '\n') {
	for (auto elem : v) {
		cout << elem << " ";
	}
	cout << ending;
}

void initialisation() {
	//1. You can use initialising list for all of the containers
	vector<int> v1{ 1, 2, 3, 4, 5, 6, 7 };
	print(v1);

	//2. Initialize iof elements of another container.
	//Types of elements may differ, provided there must be an automatic conversion.
	vector<double> v2(v1.begin(), v1.begin() + 3);
	print(v2);

	//3. Move elements of one container to another
	vector<double> v3(make_move_iterator(v2.begin()), make_move_iterator(v2.end()));
	print(v3);

	//4. Use C-array for initialisation
	int carr[] = { 1, 2, 3, 4, 5, 6 };
	set<int> s1(begin(carr), end(carr));

	//5. Use stream iterator
	deque<int> d1{ istream_iterator<int>(cin), istream_iterator<int>() };

}

void moveAndAssign() {
	vector<int> v1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	vector<int> v2 = std::move(v1);
	//	print(v1); - v1 has undefined state afterward moving
	print(v2);

	v1 = std::move(v2);
	print(v1);
	//print(v2); - undefined state
}

int main(){
	moveAndAssign();
	system("pause");
	return 0;
}
