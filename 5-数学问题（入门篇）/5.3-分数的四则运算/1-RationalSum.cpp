#include <iostream>
#include <string>
#include <cmath>

using namespace std;

typedef struct Fraction {
	int up, down;
} Fraction;


void get_fraction(string str, Fraction& frac);
Fraction add(Fraction frac1, Fraction frac2);
Fraction reduction(Fraction frac);
int gcd(int num1, int num2);

int main() {
	int num;
	Fraction ans;
	ans.up = 0;
	ans.down = 1;
	string str;
	scanf("%d", &num);
	while (num--) {
		cin >> str;
		Fraction t_frac;
		get_fraction(str, t_frac);
		ans = add(ans, t_frac);
	}
	if (ans.up == 0) {
		printf("0\n");
		return 0;
	}
	int a, b, c;
	a = abs(ans.up / ans.down);
	b = abs(ans.up) % ans.down;
	c = ans.down;
	if (ans.up < 0) printf("-");
	if (a != 0) printf("%d", a);
	if (b == 0) {
		printf("\n");
	} else {
		if (a != 0) printf(" ");
		printf("%d/%d\n", b, c);
	}
	return 0;
}


void get_fraction(string str, Fraction& frac) {
	int up = 0, down = 0;
	bool isUp = true, isNeg = false;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '-') {
			isNeg = true;
			continue;
		} else if (str[i] == '/') {
			isUp = false;
			continue;
		} else {
			if (isUp) up = up * 10 + str[i] - '0';
			else down = down * 10 + str[i] - '0';
		}
	}
	up = isNeg ? -up : up;
	frac.up = up;
	frac.down = down;
	return;
}
Fraction add(Fraction frac1, Fraction frac2) {
	if (frac1.up == 0) return frac2;
	if (frac2.up == 0) return frac1;
	Fraction res;
	res.up = frac1.up*frac2.down + frac1.down*frac2.up;
	res.down = frac1.down * frac2.down;
	res = reduction(res);
	return res;
}

Fraction reduction(Fraction frac) {
	int g = gcd(abs(frac.up), frac.down);
	frac.up = frac.up / g;
	frac.down = frac.down / g;
	return frac;
}


int gcd(int num1, int num2) {
	if (num1 % num2 == 0) return num2;
	else return gcd(num2, num1%num2);
}