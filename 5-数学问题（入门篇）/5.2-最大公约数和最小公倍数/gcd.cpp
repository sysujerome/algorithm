#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int gcd_factorization(int num1, int num2);    // 质因数分解法
int gcd_mutualDivision(int num1, int num2);   // 辗转相除法
int gcd_mutualSubtration(int num1, int num2); // 更相减损术

int main() {
	int num1, num2;
	while (scanf("%d %d", &num1, &num2) != EOF) {
		int ans = gcd_mutualSubtration(num1, num2);
		printf("%d\n", ans);
	}
}

int gcd_factorization(int num1, int num2) {
	vector<int> factors;
	int res = 1;
	while (num1 > 1) {
		for (int i = 2; i <= num1; i++) {
			if (num1 % i == 0) {
				factors.push_back(i);
				num1 /= i;
				break;
			}
		}
	}
	while (num2 > 1) {
		for (int i = 2; i <= num2; i++) {
			if (num2 % i == 0) { // &&  != factors.end()) {
				vector<int>::iterator iter = find(factors.begin(), factors.end(), i);
				if (iter != factors.end()) {
					res *= i;
					factors.erase(iter);
				}
				num2 /= i;
				break;
			}
		}
	}
	return res;
}


int gcd_mutualDivision(int num1, int num2) {
	// if (num1 < num2) {
	// 	int t = num1;
	// 	num1 = num2;
	// 	num2 = t;
	// } 不用比较这一步，因为当num1<num2时，num1%num2=num1, 下一个递归两者的顺序就相反了
	if (num1 % num2 == 0) return num2;
	return gcd_mutualDivision(num2, num1%num2);
}

int gcd_mutualSubtration(int num1, int num2) {
	if (num1 % 2 == 0 && num2 % 2 == 0) return 2*gcd_mutualSubtration(num1/2, num2/2);
	if (num1 < num2) {
		int t = num1;
		num1 = num2;
		num2 = t;
	}
	while (num1 && num2) {
		if (num1 - num2 == num2) return num2;
		else num1 = num1 - num2;
		if (num1 < num2) {
			int t = num1;
			num1 = num2;
			num2 = t;
		}
	}
	return 1; // 少了这一行，虽然在逻辑上没有问题，但是某些编译器过不了编译
}
// 参考：https://baike.baidu.com/item/%E6%9C%80%E5%A4%A7%E5%85%AC%E7%BA%A6%E6%95%B0#2_3