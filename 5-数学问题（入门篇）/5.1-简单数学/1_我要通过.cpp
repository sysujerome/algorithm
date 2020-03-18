#include <iostream>
#include <string>

using namespace std;

bool isCorrect(string str);

int main() {
	string str;
	int testNum;
	scanf("%d", &testNum);
	while (testNum--) {
		cin >> str;
		if (isCorrect(str)) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}

bool isCorrect(string str) {
	//cout << str << "---------------\n";
	if (str == "PAT") return true;
	if (str.length() <= 3 && str != "PAT") return false;
	int len = str.length();
	int count_p = 0, count_a = 0, count_t = 0;
	for (int i = 0; i < len; i++) {
		if (str[i] == 'P') count_p++;
		else if (str[i] == 'A') count_a++;
		else if (str[i] == 'T') count_t++;
		else return false;                                               // (1)
	}                          
	if (count_p != 1 || count_t != 1) return false;
	// int i = 0, j = len-1;

	// while (i <= j-2 && str[i] == 'A' && str[j] == 'A') {              // (2) fault: str[i] == str[j] == 'A'
	// 	i++;
	// 	j--;
	// 	//cout << str.substr(i, 3);
	// 	if (j-i <= 2) {
	// 		return isCorrect(str.substr(i, 3));
	// 	}
	// }
	int a = 0, b = 0, c = 0;
	bool beforeP = true, betweenPT = false, afterT = false;
	for (int i = 0; i < len; i++) {
		if (beforeP && str[i] == 'A') a++;
		else if (betweenPT && str[i] == 'A') b++;
		else if (afterT && str[i] == 'A') c++;
		else if (str[i] == 'P') {
			beforeP = false;
			betweenPT = true;
			afterT = false;
		} else if (str[i] == 'T') {
			beforeP = false;
			betweenPT = false;
			afterT = true;
		} else {
			return false;
		}
	}
	if (a == c && b == 1) return true;                                 // (2)
	else if (c == a*b) return true;                                    // (3)
	else return false;
	// string str3 = "";											   // (3)
	// i = 0;
	// j = len-1;
	// if (str[i] == 'P' && str[j] == 'T') return true;
	// while (str[i] == 'A' && str[j] == 'A') {                       // fault: str[i] == str[j] == 'A'
	// 	i++;
	// 	j--;
	// }
	// for (i = 0; i <= j; i++) {
	// 	if (i+1 <= j && str[i+1] == 'T' && str[i] == 'A') continue;
	// 	str3.push_back(str[i]);
	// }
	// return isCorrect(str3);
}

// 数学问题如果用递归实现，会可能造成超过限制的内存的错误（第三个要求）