#include <iostream>
#include <cmath>
#define N 10010
using namespace std;

int hasingMap[N];
bool isPrime(int num);
int hasing(int num, int size);

int main() {
	int MSize, n, num;
	scanf("%d %d", &MSize, &n);
	while (!isPrime(MSize)) MSize++;
	for (int i = 0; i < MSize; i++) hasingMap[i] = -1;
	for (int i = 0; i < n; i++) {
		scanf("%d", &num);
		int pos = hasing(num, MSize);
		if (pos != -1) printf("%d", pos);
		else printf("-");
		if (i != n-1) printf(" ");
		else printf("\n");
	}
	return 0;
}

bool isPrime(int num) {
	if (num == 1) return false;
    if (num == 2) return true;
	int sqr = (int)sqrt(num*1.0);
	for (int i = 2; i <= sqr; i++) 
		if (num % i == 0)
			return false;
	return true;
}

int hasing(int num, int size) {
	int pos = num % size;
	int add = 1;
	while (hasingMap[pos] != -1) {
        if (add >= size) return -1;
		pos = ((int)pow(add, 2.0) + num )% size;
		add++;
	}
    if (pos >= size) return -1;
	hasingMap[pos] = num;
	return pos;
}

//坑点：二次探测结束的边界是i^2中的i>=size,而不是简单的key+i^2>=size