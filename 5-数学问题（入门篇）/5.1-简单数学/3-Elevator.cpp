#include <iostream>
#define N 102

using namespace std;

int floors[N];

int main() {
	int floorNum;
	while (scanf("%d", &floorNum) != EOF && floorNum) {
		for (int i = 0; i < floorNum; i++) {
			scanf("%d", &floors[i]);
		}
		int cur = 0, total = 0;
		for (int i = 0; i < floorNum; i++) {
			if (floors[i] > cur) total += (floors[i] - cur) * 6;
			else total += (cur - floors[i]) * 4;
			total += 5;
			cur = floors[i];
		}
		printf("%d\n", total);
	}
	return 0;
}