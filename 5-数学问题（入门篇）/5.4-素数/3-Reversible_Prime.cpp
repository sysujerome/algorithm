#include <iostream>
#include <cmath>
#define N 100
using namespace std;

int get_reversre(int num, int r);
bool isPrime(int num);

int main() {
	int num = 0, radix;
	while (scanf("%d", &num) && num >= 0) {
		scanf("%d", &radix);
		if (!isPrime(num)) {
			printf("No\n");
			continue;
		}
		int Rnum = get_reversre(num, radix);
		if (isPrime(Rnum)) printf("Yes\n");
		else printf("No\n");
	}
}

int get_reversre(int num, int r) {
	int res = 0, c = 0;
	while (num != 0) {
		c = num % r;
		num /= r;
		res = res * r + c;
	}
	return res;
}

bool isPrime(int num) {
	if (num == 1) return false;
	int sqr = (int)sqrt(num * 1.0);
	for (int i = 2; i <= sqr; i++)
		if (num % i == 0)
		    return false;
	return true;
}
