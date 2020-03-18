#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

int main() {
	vector<vector<string> > courses;
	char c2str[5];
	int n, k;
	scanf("%d %d", &n, &k);
	vector<string> v;
	for (int i = 0; i < k; i++) courses.push_back(v);
	for (int i = 0; i < n; i++) { // 输入学生信息
		int num, coursesId;
		scanf("%s %d", c2str, &num);
		string name = c2str;
		vector<string> course_mem;
		for (int j = 0; j < num; j++) {
			scanf("%d", &coursesId);
			// fault: 漏写&，会导致程序崩溃
			courses[coursesId-1].push_back(name);
		}
	}

	//printf("print: \n-------------------------\n");
    for (int i = 0; i < k; i++) {
    	sort(courses[i].begin(), courses[i].end());
    	printf("%d %d\n", i+1, courses[i].size());
    	for (int j = 0; j < courses[i].size(); j++) {
    		printf("%s\n", courses[i][j].c_str());
    	}
    }
	//printf("-------------------------\n");

	return 0;
}
