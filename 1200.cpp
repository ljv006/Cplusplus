/*问题陈述：简单地匹配两个数，输入的N为需要匹配的数的总个数，N为奇数。
思路：可以将输入的数据进行排序，然后从低开始匹配，检查到前后两数不等就停止。
还可以使用multiset，count(i)返会i在multiset出现的次数。
最后还可以：两个相同的数做“异或运算”的结果是0； 0与任何数做“异或运算”得其本身，故最后剩余的长度就是运算的结果
			cin >> temp;  
            res ^= temp;  

*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;
/*
int main() {
	int n;
	cin >> n;
	while (n != 0) {
		vector<int> v;
		int tmp;
		for (int i = 0; i < n; ++i) {
			cin >> tmp;
			v.push_back(tmp);
		}
		sort(v.begin(), v.end());
		for (int j = 0; j < n;) {
			if (v[j] == v[j+1])
				j+=2;
			else {
				cout << v[j] << endl;
				break;
			}
		}
		cin >> n;	
	}
}
*/

int main() {
	int n;
	cin >> n;
	while (n != 0) {
		multiset<int> s;
		for (int i = 0; i < n; ++i) {
			int tmp;
			cin >> tmp;
			s.insert(tmp);
		}
		for (multiset<int>::iterator j = s.begin(); j != s.end(); ++j) {
			if (s.count(*j) == 1) {
				cout << *j << endl;				
				break;
			}
		}
		cin >> n;
	}
	return 0;
}
