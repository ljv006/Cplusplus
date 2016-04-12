/*
问题陈述：给定一个进制m，输入两个m进制的数，进行除法和取模运算，输出m进制下的结果。
思路是先将m进制的数转换成十进制数，在完成运算后再换为m进制，通过查表进行转换。
*/
#include<iostream>
#include<string>
#include<math.h>
using namespace std;
const string s = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const int l = 37;
int findPos(char c) {
	int i;
	for (i = 0; i < l; ++i) {
		if (s[i] == c) {
			return i;		
		}
	}
}
int convert2Dec(int m, string num) {
	int len = num.length();
	int res = 0;
	for (int i = len - 1; i >= 0; --i) {
		res += findPos(num[i]) * pow(m, len - 1 - i);
	}
	return res;
}

string convert2M(int m, int num) {
	string res = "";
	if (num == 0) return "0";
	while (num) {
		int pos;
		pos = num % m;
		res.push_back(s[pos]);
		num /= m;
	}
	string s = string(res.rbegin(), res.rend());
	return s;
}

int main() {
	int T, m;
	cin >> T;
	while (T--) {
		cin >> m;
		string s1, s2;
		cin >> s1 >> s2;
		int num1, num2;
		num1 = convert2Dec(m, s1);
		num2 = convert2Dec(m, s2);
		cout << num1 << " " << num2 << endl;
		cout << convert2M(m, num1 / num2) << endl;
		cout << convert2M(m, num1 % num2) << endl;
	}
	return 0;
}
