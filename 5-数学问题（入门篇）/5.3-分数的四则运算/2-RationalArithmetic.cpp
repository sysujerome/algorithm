#include <iostream>
#include <string>
#include <cmath>

using namespace std;

typedef struct Fraction {
	int up, down;
} Fraction;


void get_fraction(string str, Fraction& frac);
Fraction add(Fraction frac1, Fraction frac2);
Fraction sub(Fraction frac1, Fraction frac2);
Fraction mul(Fraction frac1, Fraction frac2);
Fraction dev(Fraction frac1, Fraction frac2);
Fraction reduction(Fraction frac);
int gcd(int num1, int num2);
string print(Fraction frac);

int main() {
	Fraction ans_add, ans_sub, ans_mul, ans_dev;
	string str1, str2;
	cin >> str1 >> str2;
	Fraction frac1, frac2;
	get_fraction(str1, frac1);
	get_fraction(str2, frac2);
	frac1 = reduction(frac1);
	frac2 = reduction(frac2);
	ans_add = add(frac1, frac2);
	ans_sub = sub(frac1, frac2);
	ans_mul = mul(frac1, frac2);
	ans_dev = dev(frac1, frac2);
	printf("%s + %s = %s\n", print(frac1).c_str(), print(frac2).c_str(), print(ans_add).c_str());
	printf("%s - %s = %s\n", print(frac1).c_str(), print(frac2).c_str(), print(ans_sub).c_str());
	printf("%s * %s = %s\n", print(frac1).c_str(), print(frac2).c_str(), print(ans_mul).c_str());
	printf("%s / %s = %s\n", print(frac1).c_str(), print(frac2).c_str(), print(ans_dev).c_str());
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

Fraction reduction(Fraction frac) {
	if (frac.up == 0 || frac.down == 0) return frac;
	int g = gcd(abs(frac.up), frac.down);
	frac.up = frac.up / g;
	frac.down = frac.down / g;
	return frac;
}

int gcd(int num1, int num2) {
	if (num1 % num2 == 0) return num2;
	else return gcd(num2, num1%num2);
}

Fraction add(Fraction frac1, Fraction frac2) {
	if (frac1.up == 0) return reduction(frac2);
	if (frac2.up == 0) return reduction(frac1);
	Fraction res;
	res.up = frac1.up*frac2.down + frac1.down*frac2.up;
	res.down = frac1.down * frac2.down;
	res = reduction(res);
	return res;
}

Fraction sub(Fraction frac1, Fraction frac2) {
	if (frac1.up == 0) {
		frac2.up = frac2.up * (-1);
		return reduction(frac2);
	}
	if (frac2.up == 0) return reduction(frac1);
	Fraction res;
	res.up = frac1.up*frac2.down - frac1.down*frac2.up;
	res.down = frac1.down * frac2.down;
	res = reduction(res);
	return res;
}

Fraction mul(Fraction frac1, Fraction frac2) {
	Fraction res;
	if (frac1.up == 0 || frac2.up == 0) {
		res.up = 0;
		res.down = 1;
	} else {
		res.up = frac1.up*frac2.up;
		res.down = frac1.down * frac2.down;
	}
	res = reduction(res);
	return res;
}

Fraction dev(Fraction frac1, Fraction frac2) {
	Fraction res;
	if (frac1.up == 0) {
		res.up = 0;
		res.down = 1;
	} else if (frac2.up == 0) {
		res.up = 0;
		res.down = 0;
	} else {
		res.up = frac1.up * frac2.down;
		res.down = frac1.down * frac2.up;
		if (res.up < 0 && res.down < 0) {
			res.up = abs(res.up);
			res.down = abs(res.down);
		} else if (res.up > 0 && res.down < 0) {
			res.up = res.up * (-1);
			res.down = abs(res.down);
		}
	}
	res = reduction(res);
	return res;
}


string print(Fraction frac) {
	string res = "";
	if (frac.up < 0) res += "(";
	if (frac.up == 0 && frac.down != 0) {
		res = "0";
		return res;
	} else if (frac.up == 0 && frac.down == 0) {
		res = "Inf";
		return res;
	} else {
		int a, b, c;
    	a = abs(frac.up / frac.down);
    	b = abs(frac.up) % frac.down;
    	c = frac.down;
    	if (frac.up < 0) res += "-";
    	if (a != 0) res += to_string(a);
    	if (b != 0) {
    		if (a != 0) res += " ";
    		res += to_string(b);
    		res += "/";
    		res += to_string(c);
    	}
	}
	if (frac.up < 0) res += ")";
	return res;	
}