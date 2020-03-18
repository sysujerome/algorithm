// #include <iostream>
// #include <cmath>
// #define N 1000000
// using namespace std;

// bool isPrime(int num);

// int main() {
// 	int n, m, count = 0;
// 	scanf("%d %d", &m, &n);
// 	for (int i = 1; i <= N; i++) {
// 		if (!isPrime(i)) {
// 			count++;
// 			if (count > n) {
// 				printf("%d\n", i);
// 				break;
// 			}
// 			if (count > m && (count-m) % 10 == 0) {
// 				printf("%d\n", i);
// 			} else if (count > m && (count-m) % 10 != 0) {
// 				printf("%d ", i);
// 			}
// 		}
// 	}
// 	return 0;
// }

// bool isPrime(int num) {
// 	int sqr = (int)sqrt(num*1.0);
// 	for (int i = 2; i <= sqr; i++) {
// 		if (num % i == 0) {
// 			return true;
// 		}
// 	}
// 	return false;
// }



#include <iostream>
#define N 1000000
using namespace std;

void setPrime(bool* isPrime, int n);
void getPrime(int m, int n, bool* isPrime, int len);

int main() {
	int n, m, count = 0;
	bool isPrime[N];
	scanf("%d %d", &m, &n);
	setPrime(isPrime, N);
	getPrime(m, n, isPrime, N);
	return 0;
}

void setPrime(bool* isPrime, int n) {
	for (int i = 0; i < n; i++) isPrime[i] = true;
	for (int i = 2; i <= n; i++) {
		if (!isPrime[i]) continue;
		else {
			for (int j = 2; j < n; j++) {
				if (i*j >= n) break;
				isPrime[i*j] = false;
			}
		}
	}
}

void getPrime(int m, int n, bool* isPrime, int len) {
	int count = 0;
	int board = m % 10 - 1;
	for (int i = 2; i < len; i++) {
		if (isPrime[i]) {
			count++;
			if (count >= m) {
				printf("%d", i);
				if (count == n) {
					printf("\n");
					return;
				}
				if ((count - board) % 10 != 0) printf(" ");
				else printf("\n");
			}
		}
	}
	return;
}