#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

void readAndPrintWithoutDublicates(const char* filename) {
	vector<string> coll;
	//ifstream ifs(filename);
	copy(istream_iterator<string>(cin), 
		istream_iterator<string>(), back_inserter(coll));
	//ifs.close();

	ostream_iterator<string> osit(cout, " ");
	copy(coll.begin(), coll.end(), osit);
	
	sort(coll.begin(), coll.end());
	cout << endl;

	unique_copy(coll.begin(), coll.end(), osit);
}

int main() {
	readAndPrintWithoutDublicates("data.txt");
	system("pause");
	return 0;
}
