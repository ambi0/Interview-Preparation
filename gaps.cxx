/*
 * Given a sorted list of integers in the range [0,99] with no duplicates,
 * print out the gaps in the list.
 *
 * Example: {0, 1, 2, 50, 52, 75}
 * 		output: 3-49,51,53-74,76-99
 *
 * Runtime: O(n)
 */

#include <iostream>
#include <vector>

using namespace std;

void printGaps(vector<int> const&);

int main(){
	vector<int> some_ints {0, 1, 2, 50, 52, 75};
	printGaps(some_ints);
}

void printGaps(vector<int> const& v){
	if(v.size() > 0) //ensure vector has elements inside before proceeding
	{
		//leftmost case
		if(*v.begin() != 0){
			if(*v.begin() == 1){
				cout << 0 << endl;
			}
			else{
				cout << 0 << '-' << *v.begin() - 1 << endl;
			}
		}

		//centre case
		for(vector<int>::const_iterator i = v.begin(); i != prev(v.end()); ++i){
			if(*i + 1 != *next(i)){
				if(*i + 1 == *next(i) - 1){
					cout << *i + 1 << endl;
				}
				else{
					cout << *i + 1 << '-' << *next(i) - 1 << endl;
				}
			}
		}

		//rightmost case
		if(*prev(v.end()) != 99){
			if(*prev(v.end()) == 98){
				cout << 99 << endl;
			}
			else{
				cout << *prev(v.end()) + 1 << '-' << 99 << endl;
			}
		}
	}
}