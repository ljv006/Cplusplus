/*问题陈述：简单字符串应用
*/
#include<iostream>
#include<string>

using namespace std;

int main() {
	int N;
	cin >> N;
	for (int i = 1; i <= N; ++i) {
		string s;
		int pos;
		cin >> pos >> s;
		cout << i << " ";
		for (int j = 0; j < s.length(); ++j) {
			if (j + 1 == pos) continue;
			cout << s[j];		
		}
		cout << endl;
	}
	return 0;
}
