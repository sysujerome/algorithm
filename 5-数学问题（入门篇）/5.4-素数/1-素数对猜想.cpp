#include <iostream>
#include <cmath>
#define N 100000

using namespace std;
bool isPrimer[N];
void setPrime(bool* isPrimer, int num);
int getPrimePairs(bool* isPrimer, int num);

int main() {
	int num;
	scanf("%d", &num);
	setPrime(isPrimer, num);
	int ans = getPrimePairs(isPrimer, num);
	printf("%d\n", ans);
	return 0;
}

void setPrime(bool* isPrimer, int num) {
	for (int i = 0; i <= num; i++) isPrimer[i] = true;
	for (int i = 2; i <= num; i++) {
		if (!isPrimer[i]) continue;
		else {
			for (int j = 2; j <= num; j++) {
				if (i*j > num) break;
				isPrimer[i*j] = false;
			}
		}
	}
}
int getPrimePairs(bool* isPrimer, int num) {
	int res = 0;
	for (int i = 2; i <= num-2; i++) {
		if (isPrimer[i] && isPrimer[i+2]) res++;
	}
	return res;
}