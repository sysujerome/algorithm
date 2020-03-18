// #include <iostream>
// #include <vector>
// #include <string>
// #include <algorithm>
// #include <cstring>
// using namespace std;

// int main() {
// 	vector<vector<string> > courses;
// 	int n, k;
// 	scanf("%d %d", &n, &k);
// 	vector<string> v;
// 	for (int i = 0; i < k; i++) courses.push_back(v);
// 	for (int i = 0; i < k; i++) { // 输入课程
// 		int index, num;
// 		scanf("%d %d", &index, &num);
// 		vector<string> course_mem;
// 		for (int j = 0; j < num; j++) {
// 			char chars[100];
// 			scanf("%s", chars);
// 		    string str = chars;
// 			course_mem.push_back(str);
// 		}
// 		courses[index-1] = course_mem;
// 	}

// 	// printf("print: \n-------------------------\n");
//  //    for (int i = 0; i < k; i++) {
//  //    	for (int j = 0; j < courses[i].size(); j++) {
//  //    		printf("%s ", courses[i][j].c_str());
//  //    	}
//  //    	printf("\n");
//  //    }
// 	// printf("-------------------------\n");

// 	for (int i = 0; i < n; i++) {
// 		char chars[100];
// 		scanf("%s", chars);
// 		string str = chars;
// 		printf("%s ", str.c_str());
// 		vector<int> coursesId;
// 		for (int j = 0; j < k; j++) {
// 			if (find(courses[j].begin(), courses[j].end(), str) != courses[j].end())
// 				coursesId.push_back(j+1);
// 		}
// 		printf("%d", coursesId.size());
// 		for (int j = 0; j < coursesId.size(); j++) {
// 			printf(" %d", coursesId[j]);
// 		}
// 		printf("\n");
// 	}
// 	return 0;
// }

// 超时


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
#include <map>

using namespace std;

int main() {
	int n, k;
	map<string, vector<int> > myMap;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < k; i++) { // 输入课程
		int index, num;
		scanf("%d %d", &index, &num);
		vector<string> course_mem;
		vector<int> stu_course;
		for (int j = 0; j < num; j++) {
			char chars[100];
			scanf("%s", chars);
		    string str = chars;
		    map<string, vector<int> >::iterator iter = myMap.find(str);
		    //map的find和stl那个find函数不一样，map的find的复杂度只有log(n)，stl那个复杂度是O(n)。
		    if (iter == myMap.end()) {
		    	vector<int> coursesId;
		    	coursesId.push_back(index);
		    	myMap.insert(pair<string, vector<int> >(str, coursesId));
		    } else {
		    	// fault: 不能直接写 iter->second.insert(index);
		    	// 也不能写 iter->second();
		    	vector<int> coursesId = iter->second;
		    	myMap.erase(iter);
		    	coursesId.push_back(index);
		    	myMap.insert(pair<string, vector<int> >(str, coursesId));
		    	//cout << "Insert " << index << endl;
		    }
		}
	}

	for (int i = 0; i < n; i++) {
		char chars[100];
		scanf("%s", chars);
		string str = chars;
		printf("%s ", str.c_str());
		vector<int> coursesId;
    	map<string, vector<int> >::iterator iter = myMap.find(str);
		if (iter == myMap.end()) printf("0\n");
		else {
			coursesId = iter->second;
			sort(coursesId.begin(), coursesId.end());
			printf(" %d", coursesId.size());
			for (int i = 0; i < coursesId.size(); i++) {
				printf(" %d", coursesId[i]);
			}
			printf("\n");
		}
	}
	return 0;
}





// 	vector<vector<string> > courses;
// 	int n, k;
// 	scanf("%d %d", &n, &k);
// 	vector<string> v;
// 	for (int i = 0; i < k; i++) courses.push_back(v);
// 	for (int i = 0; i < k; i++) { // 输入课程
// 		int index, num;
// 		scanf("%d %d", &index, &num);
// 		vector<string> course_mem;
// 		for (int j = 0; j < num; j++) {
// 			char chars[100];
// 			scanf("%s", chars);
// 		    string str = chars;
// 			course_mem.push_back(str);
// 		}
// 		courses[index-1] = course_mem;
// 	}


