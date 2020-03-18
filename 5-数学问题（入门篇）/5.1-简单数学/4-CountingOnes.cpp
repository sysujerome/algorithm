#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int countingOnes(int num);

int main() {
	int num;
	while (scanf("%d", &num) != EOF) {
		int ans = countingOnes(num);
		printf("%d\n", ans);
	}
	return 0;
}

int countingOnes(int num) {
	string str = to_string(num);
	int len = str.length();
	int res = 0;
	for (int i = 0; i < len; i++) {
		int c = str[i] - '0';
		int a = num / (int)pow(10, len-i);
		int b = num % (int)pow(10, len-i-1);
		if (c > 1) res += (a+1) * pow(10, len-i-1);
		else if (c < 1) res += a * pow(10, len-i-1);
		else res += a * pow(10, len-i-1) + b + 1;
	}
	return res;
}


