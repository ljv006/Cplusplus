/*问题描述：找规律，枚举几种情况，得出对2取模的结论。由于解空间太大，不能直接搜索*/
#include<iostream>
#include<memory.h>

using namespace std;
/*
int search(int n, bool visited[10001][10001], int x, int y) {
	if (x - 1 >= 0 && visited[x - 1][y]) search
	if (x + 1 < n && visited[x + 1][y])
	if (y - 1 >= 0)
	if (y+1<n) 
	
}
int main() {
	bool visited[10001][10001];
	int n;
	cin >> n;
	while (n != 0) {
		int res;
		memset(visited, false, sizeof(visited));
		res = search(n, visited, 0, 0);
		if (res % 2) cout << "Alice" << endl;
		else cout << "Bob" << endl;
		cin >> n;		
	}
	return 0;
}
*/

int main() {
	int N;
	cin >> N;
	while (N != 0) {
		if (N % 2) cout << "Bob" << endl;
		else cout << "Alice" << endl;
		cin >> N;	
	}
	return 0;
}
