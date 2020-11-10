#include <iostream>
#include <unordered_set>
#include <unordered_map>

using namespace std;

template<typename Cont>
void print(Cont& v, char ending = '\n') {
	for (auto elem : v) {
		cout << elem << " ";
	}
	cout << ending;
}

template<typename Map>
void printMap(Map& v, char ending = '\n') {
	for (auto elem : v) {
		cout << elem.second << " ";
	}
	cout << ending;
}

void serch_erase_insert_map() {
	
	unordered_multimap<const char*,  int> coll = { {"first", 1}, {"second", 2}, {"second", 2 } };
	//cout <<"Elements with key \"second\": " << coll.count("second") << endl;
	//cout <<"Element sith key \"first\" has value " << coll.find("first")->second << endl;

	coll.erase("second");
	//cout << "erase(\"second\")" << endl;
	//cout << "Elements with key \"second\": " << coll.count("second") << endl;

	coll.insert({"third", 3});
	

	unordered_map<string, int> coll2 = { {"A", 1}, {"B", 2}, {"C", 3} };
	cout << coll2["A"] << endl;
	cout << coll2.at("B") << endl;

	coll2["D"] = 4;
	coll2["A"] = 100;
	printMap(coll2);
}

void search_erase_set() {
	
	unordered_set<int> coll = {1, -2, 3, -4, 5, -6, 7};
	print(coll);
	
	for (auto it = coll.begin(); it != coll.end(); ) {
		if (*it < 0) {
			it = coll.erase(it);
		}
		else ++it;
	}

	print(coll);
}


int main() {
	search_erase_set();
	system("pause");
	return 0;
}