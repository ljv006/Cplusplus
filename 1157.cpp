/*问题陈述：简单排序
*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	while (n != 0) {
		vector<int> v;
		for	(int i = 0; i < n; ++i) {
			int tmp;
			cin >> tmp;
			v.push_back(tmp);		
		}
		sort(v.begin(), v.end());
		cout << v[v.size() - 1] << endl;
		cin >> n;
	}
	return 0;
}
