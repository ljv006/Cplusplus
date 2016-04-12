/*问题陈述：如何生成质数表；质数的定义：只有1和它本身两个约数的数；合数：能够被分解成若干个质数的乘积。
思路：一边生成质数表，一边进行判断。
*/
#include<iostream>

using namespace std;

int main() {
	int prime[10001];
	prime[0] = 2;
	bool flag;
	int n;
	cin >> n;
	int k = 1;
	for (int i = 3; i < 100000000; ++i) {
		flag = false;
		for (int j = 0; j < k; ++j) {
			if (i % prime[j] == 0) {
				flag = true;
				break;	
			}
		}
		if (!flag) {
			prime[k] = i;
			k++;			
		}
		if (k >= n) {
			cout << prime[n - 1] << endl;
			break;
		}
	}
	
	return 0;
}
