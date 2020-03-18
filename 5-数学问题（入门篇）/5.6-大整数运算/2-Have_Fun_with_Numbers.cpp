#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool check(string str, string& ans);

int main() {
	string input, ans;
	cin >> input;
	bool checked = check(input, ans);
	if (checked) cout << "Yes" << endl;
	else cout << "No" << endl;
	cout << ans << endl;
	return 0;
}

bool check(string str, string& ans) {
	int len = str.length();
	int carry = 0, c = 0;
	ans = "";
	for (int i = len-1; i >= 0; i--) {
		int num = carry + (str[i] - '0') * 2;
		c = num % 10;
		carry = num / 10;
		ans.push_back(c + '0');
	}
	if (carry > 0) ans.push_back(carry + '0');
	reverse(ans.begin(),ans.end());
	for (int i = 0; i < len; i++)
		if (find(ans.begin(), ans.end(), str[i]) == ans.end())
			return false;

	len = ans.length();
	for (int i = 0; i < len; i++)
		if (find(str.begin(), str.end(), ans[i]) == str.end())
			return false;
	return true;
}