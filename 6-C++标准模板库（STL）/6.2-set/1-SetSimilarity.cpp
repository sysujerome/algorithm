#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
	int setNum;
	vector<set<int> > sets;
	scanf("%d", &setNum);
	while (setNum--) {
		int setSize, setInt;
		set<int> mySet;
		scanf("%d", &setSize);
		while (setSize--) {
			scanf("%d", &setInt);
			mySet.insert(setInt);
		}
		sets.push_back(mySet);
	}
	cout << "-----------------------------" << endl;

	int testNum;
	scanf("%d", &testNum);
	while (testNum--) {
		int set1, set2;
		scanf("%d %d", &set1, &set2);
		int  Nt, Nc = 0;
		Nt = sets[set1-1].size() + sets[set2-1].size();
		set<int> testSet;
		// for (set<int>::iterator iter = sets[set2-1].begin(); iter != sets[set2-1].end(); iter++) testSet.insert(*iter);
		// for (set<int>::iterator iter = sets[set1-1].begin(); iter != sets[set1-1].end(); iter++) testSet.insert(*iter); 超时

		// for (set<int>::iterator iter = sets[set1-1].begin(); iter != sets[set1-1].end(); iter++)
		// 	if (sets[set2-1].find(*iter) != sets[set2-1].end())
		// 		Nc++;




		set<int>::iterator ia, ib;
    	ia = sets[set1-1].begin();
    	ib = sets[set2-1].begin();
    	while(1) {
    	    while(ia != sets[set1-1].end() && *ia < *ib)
    	        ia++;
    	    while(ib != sets[set2-1].end() && *ib < *ia)
    	        ib++;
    	    if(ia == sets[set1-1].end() || ib == sets[set2-1].end())
    	        break;
    	    if(*ib == *ia) {
    	        Nc++;
    	        ia++;
    	        ib++;
    	    }
    	}


	    float ans = (Nc*1.0)/(Nt-Nc);
		printf("%0.1f%%\n", ans*100);
	}
}

// 超时，重交，可！
// set本来在插入时已经有序