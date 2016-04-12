/*问题陈述：给定一个n，如果n为奇数，则n=3n+1;如果n为偶数，则n=n/2。重复这个过程直到n=1。在这个过程中涉及的数字个数称为n的链长（链长既包括n也包括1）
题目给定的输入i，j分别为一个区间的上下界，找出这个区间中的数对应的最大的链长。
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int cal(int num) {
	int count = 1;
	 while (num != 1) {
		if (num % 2 == 0) {
			num /= 2;
			count++;
		}
		else {
			num = num * 3 + 1;
			count++;
		}	
	}
	return count;
}
int main() {
	int a, b;
	cin >> a >> b;
	vector<int> v;
	for (int i = a; i <= b; ++i) {
		v.push_back(cal(i));
	}
	sort(v.begin(), v.end());
	cout << v[v.size() - 1] << endl;
	return 0;
}
