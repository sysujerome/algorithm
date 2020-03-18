#include <iostream>
#include <map>

using namespace std;

int main() {
	int m, n, num;
	scanf("%d %d", &m, &n);
	map<int, int> myMap;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &num);
			if (myMap.find(num) == myMap.end()) {
				myMap.insert(pair<int, int>(num, 1));
			} else {
				myMap[num] += 1;
			}
		}
	}
	for (map<int, int>::iterator iter = myMap.begin(); iter != myMap.end(); iter++) {
		int flag = n*m/2;
		if (iter->second > flag) {
			printf("%d\n", iter->first);
			break;
		}
	}
	return 0;
}



// #include <iostream>
// #include <map>
// #include <cmath>
// using namespace std;


// int main() {
// 	int m = 0, n = 0, num, size = (int)pow(2,17)+1;
// 	scanf("%d %d", &m, &n);
// 	int* nums = new int[size];
// 	for (int i = 0; i < size; i++) nums[i] = 0;
// 	for (int i = 0; i < n; i++) {
// 		for (int j = 0; j < m; j++) {
// 			scanf("%d", &num);
// 			nums[num]++;
// 		}
// 	}
// 	for (int i = 0; i < size; i++) {
// 		if (nums[i] >= (n*m/2)) {
// 			printf("%d\n", i);
// 			break;
// 		}
// 	}
// 	return 0;
// }

// 经实验，65536k指的是2^26Byte,对应的int数组就是2^24，因为int占4个byte