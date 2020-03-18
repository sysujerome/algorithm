// #include <iostream>
// #include <cmath>
// #include <cstring>
// #include <string>

// using namespace std;

// string sort_up(string str);
// string sort_down(string str);
// void count(string str);


// int main() {
// 	string input;
// 	while (cin >> input && input.length() != 0) {
// 		count(input);
// 	}
// 	return 0;
// }

// string sort_up(string str) {
// 	if (str.length() != 4) cout << "???????????" << endl;
// 	char nums[4];
// 	strcpy(nums, str.c_str());
// 	for (int i = 3; i >= 0; i--) {
// 		for (int j = 0; j <= i-1; j++) {  // fault2
// 			if (nums[j] > nums[j+1]) {
// 				char tmp = nums[j];
// 				nums[j] = nums[j+1];
// 				nums[j+1] = tmp;
// 			}
// 		}
// 	}
// 	string res = nums;
// 	return res;
// }

// string sort_down(string str) {
// 	if (str.length() != 4) cout << "???????????" << endl;
// 	char nums[4];
// 	strcpy(nums, str.c_str());
// 	for (int i = 3; i >= 0; i--) {
// 		for (int j = 0; j <= i-1; j++) {
// 			if (nums[j] < nums[j+1]) {
// 				char tmp = nums[j];
// 				nums[j] = nums[j+1];
// 				nums[j+1] = tmp;
// 			}
// 		}
// 	}
// 	string res = nums;
// 	//cout << "--------------- down = " << res << endl;
// 	return res;
// }


// void count(string str) {
// 	while (str.length() < 4) str = "0" + str;
// 	string up = sort_up(str);
// 	//cout << "--------------- up = " << up << endl;
// 	string down = sort_down(str);
// 	int int_up = 0, int_down = 0;
// 	for (int i = 0; i < 4; ++i)
// 	{
// 		int_up = int_up * 10 + (up[i]-'0'); // fault1
// 		int_down = int_down * 10 + (down[i]-'0');
// 	}
// 	int num = int_down - int_up;
// 	string diff = "";
// 	while (num != 0) {
// 		int c = num % 10;
// 		diff.push_back(c+'0');
// 		num = num / 10;
// 	}
// 	while (diff.length() < 4) {
// 		diff.push_back('0');
// 	}
// 	string res = "";
// 	for (int i = 3; i >= 0; i--) {
// 		res.push_back(diff[i]);
// 	}
// 	cout << down << " - " << up << " = " << res << endl;
// 	if (res == "6174" || res == "0000") return;
// 	count(res);
// 	return;
// }



// #include <iostream>
// #include <algorithm>
// #include <cstring>
// #include <string>

// using namespace std;

// void count(string str);
// string sub(string str1, string str2);
// string sort_down(string str);
// string sort_up(string str);
// bool decrease(char i,char j) {
//     return i > j;
// }


// int main() {
// 	string input;
// 	while (cin >> input) {
// 		count(input);
// 	}
// 	return 0;
// }

// void count(string str) {
// 	while (str.length() < 4) str.push_back('0');
// 	//cout << "------------------str = " << str << endl;
// 	//string up = sort_up(str);
// 	//string down = sort_down(str);
// 	string up = str;
// 	string down = str;
// 	sort(up.begin(), up.end());
// 	sort(down.begin(), down.end());
// 	reverse(down.begin(), down.end());
// 	//cout << "------------------up = " << up << endl;
// 	//cout << "------------------down = " << down << endl;
// 	string res = sub(down, up);
// 	//cout << "------------------res = " << res << endl;
// 	cout << down << " - " << up << " = " << res << endl;
// 	if (res == "6174" || res == "0000") return;
// 	else count(res);
// }

// string sub(string str1, string str2) {
// 	int num1 = 0, num2 = 0;
// 	for (int i = 0; i < 4; i++) {
// 		num1 = num1 * 10 + str1[i] - '0';
// 		num2 = num2 * 10 + str2[i] - '0';
// 	}
// 	int diff = num1 - num2;
// 	string res = "";
// 	while (diff != 0) {
// 		char c = diff % 10 + '0';
// 		res = c + res;
// 		diff = diff / 10;
// 	}
// 	while (res.length() < 4) res = "0" + res;
// 	return res;
// }

// string sort_up(string str) {
// 	char chars[4];
// 	strcpy(chars, str.c_str());
// 	sort(chars, chars+4);
// 	string res = chars;
// 	return res;
// }

// string sort_down(string str) {
// 	char chars[4];
// 	strcpy(chars, str.c_str());
// 	sort(chars, chars+4, decrease);
// 	string res = chars;
// 	return res;
// }



#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;

void count(string str);
string sub(string str1, string str2);

int main() {
	string input;
	while (cin >> input) {
		count(input);
	}
	return 0;
}

void count(string str) {
	while (str.length() < 4) str.push_back('0');
	string up = str;
	sort(up.begin(), up.end());
	string down = up;
	reverse(down.begin(), down.end());
	string res = sub(down, up);
	//cout << "str = " << str << ", up = " << up << ", down = " << down << ", sub = " << res << endl;
	cout << down << " - " << up << " = " << res << endl;
	if (res == "6174" || res == "0000") return;
	count(res);
}

string sub(string str1, string str2) {
	int a = stoi(str1), b = stoi(str2);
	string res = to_string(a-b);
	while (res.length() < 4) res = "0" + res;
	return res;
}