#include <string>
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void solve(int size, float num1, float num2);

int main() {
	float num1, num2;
	int size;
	scanf("%d%f%f", &size, &num1, &num2);
	solve(size, num1, num2);
	return 0;
}


void solve(int size, float num1, float num2) {
	if (num1 == 0 && 0 == num2) {
		printf("YES \n");
		float num = num1 / pow(10, size);
		cout << setprecision(size) << num;
		printf("*10^%d\n", 0);
		return;
	}
	string str1 = to_string(num1);
	string str2 = to_string(num2);
	//cout << "str1 : " << str1 << endl;
	//cout << "str2 : " << str2 << endl;
	int point1 = 0, point2 = 0;
	for (int i = 0; i < str1.size(); i++) {
		if (str1[i] == '.') {
			str1.erase(i, 1);
			point1 = i;
			break;
		}
	}
	for (int i = 0; i < str2.size(); i++) {
		if (str2[i] == '.') {
			str1.erase(i, 1);
			point2 = i;
			break;
		}
	}
	point1 = point1==0 ? str1.size() : point1;
	point2 = point2==0 ? str2.size() : point2;
	if (point1 != point2) {
		printf("NO\n");
		return;
	}
	for (int i = 0; i < size; i++) {
		if (i >= str1.size() || i >= str2.size()) {
			if (str1.size() == str2.size()) {
				printf("YES ");
				float num = num1 / pow(10, point1);
				cout << setprecision(point1) << num;
				printf("*10^%d\n", point1);
			} else {
				printf("NO\n");
			}
			return;
		}
		if (str1[i] != str2[i]) {
			printf("NO\n");
			return;
		}
	}
	printf("YES \n");
	float num = num1 / pow(10, point1);
	cout << setprecision(point1) << num;
	printf("*10^%d\n", point1);
	return;
}