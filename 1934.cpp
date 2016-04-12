/*

note:find是algorithm的函数，find_if*/
#include<iostream>
#include<list>
#include<stdio.h>
#include<algorithm>
#include<memory.h>
using namespace std;
/*直接使用STL实现的版本，超时
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		list<int> l;
		for (int i = 1; i <= n; ++i) {
			l.push_back(i);
		}
		for (int i = 1; i <= m; ++i) {
			int cmd, pos1, pos2;
			cin >> cmd >> pos1 >> pos2;
			if (cmd == 1) {
				list<int>::iterator i1, i2;
				i1 = find(l.begin(), l.end(), pos1);
				i2 = find(l.begin(), l.end(), pos2);
				int tmp = *i1;
				l.erase(i1);
				l.insert(i2, tmp);
					
			} else {
				list<int>::iterator i1, i2;
				i1 = find(l.begin(), l.end(), pos1);
				i2 = find(l.begin(), l.end(), pos2);
				int tmp = *i1;
				l.erase(i1);
				i2++;
				l.insert(i2, tmp);
			}		
		}
		for (list<int>::iterator i = l.begin(); i != l.end(); ++i) {
			cout << *i << " ";			
		}
		cout << endl;
	}
	return 0;
}
直接使用数组，超时
int main() {
	int num[500001];
	int T, n, m;
	cin >> T;
	while (T--) {
		scanf("%d %d", &n, &m);  
		for (int i = 0; i < n; ++i) {
			num[i] = i + 1;		
		}
		for (int j = 0; j < m; ++j) {
			int cmd, num1, num2, pos1, pos2;
			scanf("%d %d %d", &cmd, &num1, &num2);
			for (int i = 0; i < n; ++i) {
				if (num[i] == num1) pos1 = i;
				if (num[i] == num2) pos2 = i;
			}
			if (cmd == 1) {
				if (pos1 < pos2) {
				for (int i = pos1; i < pos2 - 1; ++i) {
					num[i] = num[i + 1];
				}
				num[pos2 - 1] = num1;
				} else {
				for (int i = pos2; i < pos1; ++i) {
					num[i] = num[i + 1];
				}
				num[pos1] = num2;
				}
			} else {
				if (pos1 < pos2) {
				for (int i = pos1; i < pos2 - 1; ++i) {
					num[i] = num[i + 1];
				}
				num[pos2 - 1] = num2;
				num[pos2] = num1;
				} else {
				for (int i = pos2; i < pos1; ++i) {
					num[i] = num[i + 1];
				}
				num[pos1] = num2;
				num[pos1 - 1] = num1;
				}
			}		
		}
		for (int i = 0; i < n; ++i) {
			printf("%d ", num[i]);
		}
		printf("\n");
	}
	return 0;
}
*/
/*问题陈述：按照要求移动小球的位置，主要问题在于时间限制。
思路：使用数组模拟双向链表。1.搞清楚如何删除和插入，1和2的情况不一样。2.找到开始的位置，进行遍历。
*/
int main() {
	int prev[500001],next[500001];
	int t, n, m;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		for (int j = 1; j <= n + 1; ++j) {
			prev[j] = j - 1;
			next[j - 1] = j;
		}
		for (int i = 0; i < m; ++i) {
			int cmd, num1, num2;
			cin >> cmd >> num1 >> num2;
			if (cmd == 1) {
				prev[next[num1]] = prev[num1];
				next[prev[num1]] = next[num1];
				next[prev[num2]] = num1;
				prev[num1] = prev[num2];
				next[num1] = num2;
				prev[num2] = num1;		
			}
			else {
				prev[next[num1]] = prev[num1];
				next[prev[num1]] = next[num1];
				prev[next[num2]] = num1;
				next[num1] = next[num2];
				prev[num1] = num2;
				next[num2] = num1;
				
			}
			
		}
		int pos;
		for (pos = 1; pos <= n; ++pos) {
			if (prev[pos] == 0)  break;
		}
		while (pos != n + 1) {
			cout << pos << " ";
			pos = next[pos];		
		}
		cout << endl;
	}
	return 0;
}
