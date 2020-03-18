// 最小公倍数
#include <iostream>

using namespace std;

int gcd(int num1, int num2);
int lcm(int num1, int num2);

int main() {
	int num1, num2;
	while (scanf("%d %d", &num1, &num2) != EOF) {
		printf("%d\n", lcm(num1, num2));
	}
	return 0;
}

int gcd(int num1, int num2) {
	if (num1 % num2 == 0) return num2;
	return gcd(num2, num1%num2);
}

int lcm(int num1, int num2) {
	int factor = gcd(num1, num2);
	return num1/factor*num2; // 考虑到溢出的可能性，先除后乘
}