/*
 * 分别对距离和时间用两次dij得到两条路径再进行比较
 * 这里用了堆优化的dij
 */
#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#define MAXN 502
using namespace std;
struct Vertex {
	int x, dist;
	bool operator<(const Vertex&v)const {
		return dist > v.dist;
	}
};
int n, m, x, y, distmap[MAXN][MAXN], timemap[MAXN][MAXN];
// 最短距离，最小时间
int mindist, mintime;
// 最短距离路径，最小时间路径
vector<int> distroutes, timeroutes;
// 保存所有边
vector<vector<int> > edges;
void build_edge(int src, int dst, int dist, int time) {
	edges[src].push_back(dst);
	distmap[src][dst] = dist;
	timemap[src][dst] = time;
}
void dijkstra1(int src, int dst) {
	vector<bool> visits(n, false);
	vector<int> dist(n, INT_MAX), time(n, INT_MAX);
	vector<vector<int> > routes(n);
	// 用优先级队列来查找最短路径
	priority_queue<Vertex> pq;
	dist[src] = time[src] = 0;
	pq.push(Vertex{src, 0});
	while (!pq.empty()) {
		int cur = pq.top().x;
		pq.pop();
		if (visits[cur]) continue;
		visits[cur] = true;
		routes[cur].push_back(cur);
		if (cur == dst) break;
		for (int i=0; i<edges[cur].size(); i++) {
			int to = edges[cur][i];
			if (visits[to]) continue;
			// 有距离更小的路径或距离一样但时间更少的路径时更新
			if(dist[to] > dist[cur] + distmap[cur][to] ||
			   (dist[to] == dist[cur]+distmap[cur][to] && time[to] > time[cur]+timemap[cur][to])) {
				dist[to] = dist[cur] + distmap[cur][to];
				time[to] = time[cur] + timemap[cur][to];
				routes[to] = routes[cur];
				pq.push(Vertex{to, dist[to]});
			}
		}
	}
	mindist = dist[dst];
	distroutes = routes[dst];
}
void dijkstra2(int src, int dst) {
	vector<bool> visits(n, false);
	vector<int> time(n, INT_MAX);
	vector<vector<int> > routes(n);
	priority_queue<Vertex> pq;
	time[src] = 0;
	pq.push(Vertex{src, 0});
	while (!pq.empty()) {
		int cur = pq.top().x;
		pq.pop();
		if (visits[cur]) continue;
		visits[cur] = true;
		routes[cur].push_back(cur);
		if (cur == dst) break;
		for (int i=0; i<edges[cur].size(); i++) {
			int to = edges[cur][i];
			if (visits[to]) continue;
			// 有时间更少的路径或经过节点更少的路径时更新
			if (time[to] > time[cur] + timemap[cur][to] ||
				(time[to] == time[cur] + timemap[cur][to] && routes[to].size() > routes[cur].size())) {
				time[to] = time[cur] + timemap[cur][to];
				routes[to] = routes[cur];
				pq.push(Vertex{to, time[to]});
			}
		}
	}
	mintime = time[dst];
	timeroutes = routes[dst];
}
void print_path(vector<int> path) {
	for (int i=0; i<path.size(); i++) {
		printf(" %d%s", path[i], i == path.size()-1 ? "\n" : " ->");
	}
}
int main () {
	scanf("%d %d", &n, &m);
	edges.resize(n);
	for (int i=0; i<m; i++) {
		int o, d, t;
		scanf("%d%d%d%d%d", &x, &y, &o, &d, &t);
		build_edge(x, y, d, t);
		if (o != 1) build_edge(y, x, d, t);
	}
	scanf("%d %d", &x, &y);
	dijkstra1(x, y);
	dijkstra2(x, y);
	if (distroutes == timeroutes) {
		printf("Distance = %d; Time = %d:", mindist, mintime);
		print_path(distroutes);
	} else {
		printf("Distance = %d:", mindist);
		print_path(distroutes);
		printf("Time = %d:", mintime);
		print_path(timeroutes);
	}
	return 0;
}