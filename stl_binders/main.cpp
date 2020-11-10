#include <functional>
#include <algorithm>
#include <vector>
#include <algorithm>
#include <iostream>


using namespace std;

void binder1() {

}

int main() {
	typedef vector<int>::iterator iterator;
	int arr[4] = {1, 2, 3, 4};
	//initialize with subarrray from [0 element to 4)
	vector<int> v1(arr + 0, arr + 4);

	binder1st<equal_to<int> > equal_to_3 = bind1st(equal_to<int>(), 3);
	iterator it1 = find_if(v1.begin(), v1.end(), equal_to_3);
	iterator it2 = find_if(v1.begin(), v1.end(), bind1st(equal_to<int>(), 3));
	iterator it3 = find_if(v1.begin(), v1.end(), bind2nd(equal_to<int>(), 3));
	cout << *it1 << " " << *it2 << " " << *it3 << endl;


	system("pause");
	return 0;
}