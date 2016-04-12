#include<iostream>
#include<string>
#include<memory.h>

using namespace std;
int edge[1001][1001];
int count = 0;
string STR[1001];
int dis[1001];
bool visited[1001];

int toInt(string str) {
	for (int i = 0; i < count; ++i) {
		if (STR[i] == str) return i;	
	}
	STR[count] = str;
	count++;
	return count - 1;
}

int dijkstra(int s, int e) {
	for (int i = 0; i < count; ++i) {
		dis[i] = edge[s][i];	
	}
	visited[s] = true;
	dis[s] = 0;
	for (int i = 1; i < count; ++i) {
		int min_dist = 100001;
		int v = s;
		for (int j = 0; j < count; ++j) {
			if (!visited[j] && dis[j] < min_dist) {
				v = j;
				min_dist = dis[j];			
			}
		}
		visited[v] = true;
		for (int j = 0; j < count; ++j) {
			if (!visited[j] && edge[v][j] < 100001) {
				if (dis[j] > dis[v] + edge[v][j])
					dis[j] = dis[v] + edge[v][j];
			}		
		}
	}
	if (dis[e] > 100001) return -1;
	return dis[e];
}
int main() {
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		count = 0;
		memset(edge, 100001, sizeof(edge));
		memset(dis, 100001, sizeof(dis));
		memset(visited, false, sizeof(visited));
		for (int i = 0; i < n; ++i) {
			string s, t;
			int d;
			cin >> s >> t >> d;
			edge[toInt(s)][toInt(t)] = d;
			edge[toInt(t)][toInt(s)] = d;
		}
		string start, end;
		cin >> start >> end;
		cout << dijkstra(toInt(start), toInt(end)) << endl;
	}
	return 0;
}
