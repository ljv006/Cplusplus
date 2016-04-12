/*问题陈述：创建类、比较函数、if结构
*/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

struct student{
	int number;
	string name;
	int finalScore;
	int classScore;
	char isGanbu;
	char isWest;
	int paper;
	int money;
};

bool compare(student a, student b) {
	if (a.money < b.money) return true;
	if (a.money == b.money && a.number > b.number) return true;
	return false;
}

int cal(student s) {
	int res = 0;
	if (s.finalScore > 80 && s.paper > 0) res += 8000;
	if (s.finalScore > 85 && s.classScore > 80) res += 4000;
	if (s.finalScore > 90) res += 2000;
	if (s.isWest == 'Y' && s.finalScore > 85) res += 1000;
	if (s.isGanbu == 'Y' && s.classScore > 80) res += 850;
	return res;
}

int main() {
	int N;
	int total = 0;
	cin >> N;
	vector<student> v;
	for (int i = 0; i < N; ++i) {
		student tmp;
		cin >> tmp.name >> tmp.finalScore >> tmp.classScore;
		cin >> tmp.isGanbu >> tmp.isWest >> tmp.paper;
		tmp.number = i;
		tmp.money = cal(tmp);
		total += tmp.money;
		v.push_back(tmp);
	}
	sort(v.begin(), v.end(), compare);
	student res = v[v.size() - 1];
	cout << res.name << endl;
	cout << res.money << endl;
	cout << total << endl;
	return 0;
}
