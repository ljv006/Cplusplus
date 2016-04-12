/*问题陈述：每个月一对成年兔子可以生产一对小兔子，小兔子经过m个月可以生育，问给定一个月份d，问当前有多少对兔子，初始状态只有一对兔子。要理解清楚num保存的是现有的兔子对数。
*/
#include<iostream>
#include<memory.h>

using namespace std;

//下标1记录月份，下标2记录一个高精度数的特定位数
int num[101][101];
int main() {
	int m, d;
	cin >> m >> d;
	while (m != 0 || d != 0) {
		memset(num, 0, sizeof(num));
		//初始状态只有一对兔子
		num[0][1] = 1;
		for (int i = 1; i <= d; ++i) {
			//前m-1个月每月只会产生一对兔子
			if (i < m) {
				num[i][1] = num[i-1][1] + 1;
				//处理进位问题
				if (num[i][1] >= 10) {
					num[i][2] += num[i][1] / 10;
					num[i][1] = num[i][1] % 10;
				}		
			} else {
				int carryin = 0;
				//高精度算法
				for (int j = 1; j < 101; ++j) {
					//递推式：当前月的兔子数=上一个月的兔子数+m个月前的出生的兔子数（要考虑进位）
					num[i][j] = num[i - 1][j] + num[i - m][j] + carryin;
					//进位使用后要置为0，然后进行算下一位
					carryin = 0;
					if (num[i][j] >= 10) {
						carryin = num[i][j] / 10;
						num[i][j] %= 10;					
					}
				}
			}
		}
		for (int i = 100; i >= 1; --i) {
			if (num[d][i] != 0) {
				for (i; i >= 1; --i) {
					cout << num[d][i];
				}		
			}
		}
		cout << endl;
		cin >> m >> d;
	}
	return 0;
}
