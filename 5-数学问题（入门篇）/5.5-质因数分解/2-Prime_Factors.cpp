#include <iostream>
#include <cmath>
#include <map>
using namespace std;

bool isPrime(int n);

int main() {
	int n;
	scanf("%d", &n);
    if (n == 1) {
        printf("1=1\n");
        return 0;
    }
	map<int, int> factors;
    printf("%d=", n);
	for (int i = 2; i <= n; i++) {
		if (isPrime(n)) {
			factors.insert(pair<int, int>(n, 1));
			break;
		}
		while (n % i == 0) {
			if (factors.find(i) == factors.end()) {
				factors.insert(pair<int,int>(i, 1));
			} else {
				int num = factors.find(i)->second;
				num++;
				factors.erase(factors.find(i));
				factors.insert(pair<int,int>(i, num));
			}
			n /= i;
		}
	}
	bool begined = false;
	for (map<int, int>::iterator iter = factors.begin(); iter != factors.end(); iter++) {
		if (begined) printf("*");
		if (iter->second > 1) printf("%d^%d", iter->first, iter->second);
		else printf("%d", iter->first);
		if (!begined) begined = !begined;
	}
	printf("\n");
	return 0;
}

bool isPrime(int n) {
	//	printf("-------------------\n");
	int sqr = sqrt(n);
	for (int i = 2; i < sqr; i++) {
		if (n % i == 0) return false;
	}
	return true;
}


// 先判断n是否是素数，再进行循环，不然会因为n过大导致超时 --> int占4个字节，65536K是671008864个字节，即167 752 216个int
// 不能贸贸然开n个数组，不然会因为空间受限出错。