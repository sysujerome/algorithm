#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string getPalindrominc(string num);
string add(string str1, string str2);

int main() {
	string num;
	int k;
	cin >> num >> k;
	string Pnum = getPalindrominc(num);
	int count = 0;
	while (Pnum != num && count < k) {
		num =  add(getPalindrominc(num), num);
		Pnum = getPalindrominc(num);
		count++;
	}
	cout << num << endl << count << endl;
	return 0;
}

string getPalindrominc(string num) {
	int len = num.length();
	string res = "";
	for (int i = len-1; i >= 0; i--)
	    res.push_back(num[i]);
	return res;
}

string add(string str1, string str2) {
	int carry = 0, c = 0, num = 0;
	string res = "";
	reverse(str1.begin(), str1.end());
	reverse(str2.begin(), str2.end());
	int len1 = str1.length();
	int len2 = str2.length();
	for (int i = 0; i < len1 || i < len2; i++) {
		if (i >= len1) num = str2[i] - '0' + carry;
		else if (i >= len2) num = str1[i] - '0' + carry;
		else num = str1[i] + str2[i] - '0'*2 + carry;
		carry = num / 10;
		c = num % 10;
		res.push_back(c+'0');
	}
	if (carry) res.push_back(carry+'0');
	reverse(res.begin(), res.end());
	return res;
}
//坑点：即使输入的数字在int的范围内，但在处理过程中，数字也可能会超出int的取值范围，所以在不断乘的情况下，要采用string类型存储数字