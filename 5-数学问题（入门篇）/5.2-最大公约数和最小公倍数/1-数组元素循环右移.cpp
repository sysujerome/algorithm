// 修改数组，按数组顺序输出
#include <iostream>
#include <algorithm>
#define N 1000

using namespace std;

int nums[N];

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	m = m % n;
	for (int i = 0; i < n; i++) scanf("%d", &nums[i]);
	reverse(nums, nums+n);
	reverse(nums, nums+m);
	reverse(nums+m, nums+n);
	for (int i = 0; i < n; i++) {
		if (i == n-1) printf("%d\n", nums[n-1]);
		else printf("%d ", nums[i]);
	}
	return 0;
}


// 不修改数组，直接输出
#include <iostream>
#include <algorithm>
#define N 1000

using namespace std;

int nums[N];

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	m = m % n;
	for (int i = 0; i < n; i++) scanf("%d", &nums[i]);
	for (int i = 0; i < m; i++) {
		if (i == n-1) printf("%d\n", nums[i+n-m]);
		else printf("%d ", nums[i+n-m]);
	}
	for (int i = m; i < n; i++) {
		if (i == n-1) printf("%d\n", nums[i-m]);
		else printf("%d ", nums[i-m]);
	}
	
	return 0;
}