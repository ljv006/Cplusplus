/*问题描述：圆的定义
*/
#include<iostream>
#include<math.h>
using namespace std;

int main() {
	int T, N;
	cin >> T;
	while (T--) {
		cin >> N;
		int point = 0;
		for (int i = 0; i < N; ++i) {
			int x, y;
			cin >> x >> y;
			if ((x - 30) * (x - 30) + (y - 30) * (y - 30) < 400) point += 1;
			if ((x - 100) * (x - 100) + (y - 30) * (y - 30) < 100) point += 2;
			if ((x - 170) * (x - 170) + (y - 30) * (y - 30) < 25) point += 3;
		}
		cout << point << endl;
	}
	return 0;
}
