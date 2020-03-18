#include <iostream>
#include <string>

using namespace std;

void dev(string a, int b, string& quo, int& remain);


int main() {
	string str;
	int b;
	cin >> str >> b;
	string quo;
	int remain;
	dev(str, b, quo, remain);
	cout << quo << " " << remain << endl;
	return 0;
}


void dev(string a, int b, string& quo, int& remain) {
	int len = a.length();
	int carry = 0, c = 0;
	for (int i = 0; i < len; i++) {
		if (i == 0 && (a[i]-'0') < b) carry = a[i] - '0';
		else {
			int num = carry * 10 + a[i] - '0';
			c = num / b;
			carry = num % b;
			quo.push_back(c+'0');
		}
	}
	remain = carry;
}