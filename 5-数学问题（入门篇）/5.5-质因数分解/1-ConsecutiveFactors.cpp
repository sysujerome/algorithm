#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int num, count = 0, ans = 0, pos = 0;
	scanf("%d", &num);
	int sqr = (int)sqrt(num * 1.0);
	int i = 2;
	while (i <= sqr) {
		count = 0;
		int tmp = num, t = i;
		while (tmp % t == 0) {
			//printf("num == %d\n", num);
			//cout << "i == " << i << "  count == " << count << endl;
			tmp /= t;
			t++;
			count++;
		}
		if (count > ans) {
			pos = t - count;
			ans = count;
		}
		i++;
	}
	if (ans == 0) {
		printf("%d\n%d\n", 1, num);
		return 0;
	}
	printf("%d\n", ans);
	for (int i = 0; i < ans; i++) {
		printf("%d", i+pos);
		if (i < ans-1) printf("*");
		else printf("\n");
	}
	return 0;
}