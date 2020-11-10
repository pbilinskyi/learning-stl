#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>


using namespace std;

template <typename T>
inline void PRINT_ELEMENTS(const T& coll, const char* optstr="") {
	cout << optstr;

	for (const auto& elem : coll) {
		cout << elem << " ";
	}
	cout << endl;

	/*equal to:
	typename T::const_iterator it = coll.begin();
	for (; it != coll.end(); ++it){
		cout << *it << " ";
	}
	cout << endl;
	*/
}

int main() {
	vector<string> v = { "I", "can't", "give", "you", "all", "my", "dreams" };
	PRINT_ELEMENTS(v, "Marianne Faithful: ");

	unordered_set<int> us = {4, 2, 9, 5, 1, 2, 2, 2};
	//cout << *--us.find(9) << endl;
	unordered_map<string, int> um = { {"favorite", 19}, {"favorite", 17}, {"the best", 20}};
	//cout << um.count("the best") << endl;
	PRINT_ELEMENTS(us, "unordered set contains:");
	system("pause");
	return 0;
}
