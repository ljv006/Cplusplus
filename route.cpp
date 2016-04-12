#include <time.h>
#include "route.h"
#include "lib_record.h"
#include <stdio.h>
#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <memory.h>

using namespace std;
#define infinity 100000
//全局变量声明
int route[601][601];
int tee[601];
int count_case = 0;
int count_begin = 0;
int count_end = 0;
int begin_now;
int end_now;
int including[51];//存放必经节点
bool visited[601];//深搜的时候使用
bool v[601];//Dijkstra的时候使用
int d[601][601];
int count_pos = 0;
int numOfNode = 0, numOfEdge , numOfIncludingNode;//节点、边、必经节点的数量

struct node{
    node() {
        num = 0;
        length = infinity;
    }
    int num;
    int length;
};

node edge[601][601];

void searchPath(int *prev,int begin, int end)
{
    
    int que[500];
    int tot = 0;
    que[tot] = end;
    tot++;
    int tmp = prev[end];
    while(tmp != begin)
    {
        que[tot] = tmp;
        tot++;
        tmp = prev[tmp];
    }
    que[tot] = begin;

    for(int i=tot; i >= 0; --i) {
       v[que[i]] = true;
       route[count_case][count_pos] = que[i];
       if (que[i] == begin_now) count_begin++;
       if (que[i] == end_now) count_begin++;
       count_pos = count_pos + 1;
    }
}
//单源最短路算法
//不能重复
int Dijkstra(int begin, int end, int n) {
    bool s[601]; // 判断是否已存入该点到S集合中
    int dist[601];  // 表示当前点到源点的最短路径长度
    int prev[601];   // 记录当前点的前一个结点
    for(int i=0; i<n; ++i)
    {
        dist[i] = edge[begin][i].length;
        s[i] = 0;     // 初始都未用过该点
        if(dist[i] == infinity)
            prev[i] = -1;
        else prev[i] = begin;
    }

    dist[begin] = 0;
    s[begin] = 1;
    // 依次将未放入S集合的结点中，取dist[]最小值的结点，放入结合S中
    // 一旦S包含了所有V中顶点，dist就记录了从源点到所有其他顶点之间的最短路径长度

    for(int i=1; i<n; ++i)
    {
        int tmp = infinity;
        int u = begin;
        // 找出当前未使用的点j的dist[j]最小值
        for(int j=0; j<n; ++j)
            if((!s[j]) && dist[j]<tmp && (!v[j] || (j == begin && count_begin <= 1) || (j == end && count_end <= 1)))
            {   u = j;              // u保存当前邻接点中距离最小的点的号码
                tmp = dist[j];
            }
        s[u] = 1;    // 表示u点已存入S集合中

        // 更新dist
        for(int j=0; j<n; ++j)
            if((!s[j]) && edge[u][j].length<infinity && (!v[j] || (j == begin && count_begin <= 1) || (j == end && count_end <= 1)))
            {
                int newdist = dist[u] + edge[u][j].length;
                if(newdist < dist[j])
                {
                    dist[j] = newdist;
                    prev[j] = u;
                }
            }
    }

    //将最短路径经过的节点设置为已遍历
    if (dist[end] == infinity) {
        return -1;
    } else {

        searchPath(prev, begin, end);
        return dist[end];
    }
}
int PathMidNode(int including_perm[], int n, int d[601][601]) {
        
        int dist = 0;
        for (int j = 0; j < n - 1; j++) {
            //节点重复
            if (edge[including_perm[j]][including_perm[j + 1]].length != infinity && (!v[including_perm[j]] || (j == 0 && count_begin <= 1))) {
                    d[including_perm[j]][including_perm[j + 1]] = edge[including_perm[j]][including_perm[j + 1]].length;
                    route[count_case][count_pos] = including_perm[j];
                    v[including_perm[j]] = true;
                    if (j == 0) count_begin++;
                    count_pos = count_pos + 1;
            } else {
                     d[including_perm[j]][including_perm[j + 1]] = Dijkstra(including_perm[j], including_perm[j + 1], numOfNode);
            }
            if (d[including_perm[j]][including_perm[j + 1]] == -1) {
                return -1;
            }
            dist +=  d[including_perm[j]][including_perm[j + 1]];
        }
        return dist;
}
void dfs(int pos, int n) {
    visited[pos] = true;
    for (int i = 0; i < n; i++) {
        if (!visited[i] && edge[pos][i].length != infinity)
            dfs(i, n);
    }
}
bool isConnected(int including[], int numOfIncludingNode, int numOfNode) {
    memset(visited, false, sizeof(visited));
    dfs(including[0], numOfNode);
    for (int i = 0; i < numOfIncludingNode; i++) {
        if (!visited[including[i]]) return false;
    }
    return true;
}
//你要完成的功能总入口
void search_route(char *topo[5000], int edge_num, char *demand)
{
    numOfEdge = edge_num;
    int s, e;
    int pos_ed = 0;
    int pos_c = 0;
    int ed[4];
    char c[4];
    memset(route, -1, sizeof(route));
    for (unsigned int i = 0; i < (unsigned int)edge_num; i++) {
        pos_ed = 0;
        memset(ed, 0, sizeof(ed));
        for (unsigned int j = 0; j < strlen(topo[i]); j++) {
               if (topo[i][j] == ',') {
                    pos_c = 0;
                    ed[pos_ed] = atoi(c);
                    memset(c, 0, sizeof(c));
                    pos_ed++;
                } else if (topo[i][j] == '\n' || topo[i][j] == '\0' || topo[i][j] == '\r') {
                    pos_c = 0;
                    ed[pos_ed] = atoi(c);
                    memset(c, 0, sizeof(c));
                    pos_ed++;
                    break;
                } else {
                    c[pos_c] = topo[i][j];
                    pos_c++;
                }
        }
        if (edge[ed[1]][ed[2]].length > ed[3]) {
            edge[ed[1]][ed[2]].length = ed[3];
            edge[ed[1]][ed[2]].num = ed[0];
            //cout << ed[0] << " " << ed[1] << " " << ed[2] << " " << ed[3] << endl;
            if (ed[1] > numOfNode) numOfNode = ed[1];
            if (ed[2] > numOfNode) numOfNode = ed[2];
        }

    }
    numOfNode += 1;
    int count = 0;
    pos_c  = 0;
    pos_ed = 0;
    for (unsigned int i = 0; i < strlen(demand); i++) {
               if (demand[i] == ',') {
                    pos_c  = 0;
                    if (count == 0) {
                        s = atoi(c);
                        count++;
                    } else {
                        e = atoi(c);
                    }
                    memset(c, 0, sizeof(c));
               } else if (demand[i] == '|') {
                    pos_c = 0;
                    including[pos_ed] = atoi(c);
                    memset(c, 0, sizeof(c));
                    pos_ed++;
               } else if (i == strlen(demand) - 1) {
                    c[pos_c] = demand[i];
                    including[pos_ed] = atoi(c);
                    memset(c, 0, sizeof(c));
                    pos_ed++;
               }else {
                    c[pos_c] = demand[i];
                    pos_c++;
               }
    }
    numOfIncludingNode = pos_ed;
    if (!isConnected(including, numOfIncludingNode, numOfNode))
        return;
    int path = infinity;
    int path_num = 0;
    sort(including, including + numOfIncludingNode);
    time_t start, stop;
    start = time(NULL);
   do {
        begin_now = including[0];
        end_now = including[numOfIncludingNode - 1];
        stop = time(NULL);
        if (stop - start >= 9) break;
        memset(v, false, sizeof(v));
        memset(d, 0, sizeof(d));
        count_pos = 0;
        count_begin = 0;
        count_end = 0;
        int part1 = Dijkstra(s, including[0], numOfNode);
        if (part1 == -1) {
            count_case++;
            continue;
        }

        int midPath = PathMidNode(including, numOfIncludingNode, d);
        if (midPath == -1) {
            count_case++;
            continue;
        }
        int part2 = Dijkstra(including[numOfIncludingNode - 1], e, numOfNode);
        if (part2 == -1) {
            count_case++;
            continue;
        }
        int tmp = part1 + midPath + part2;
        if (tmp < path) {
            path = tmp;
            path_num = count_case;
        }
        count_case++;
    } while (next_permutation(including, including + numOfIncludingNode));
 
   for (int i = 0; route[path_num][i + 1] != -1; i++) {
        //cout << route[path_num][i] << "->";
        int cur = route[path_num][i], nxt = route[path_num][i + 1];
        if (cur != nxt) {
            record_result(edge[cur][nxt].num);
        }
   }
}
