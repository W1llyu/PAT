#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <limits.h>
#define MAX 200
using namespace std;

string cost_key(string a, string b) {
	return a += b;
}

int n, k, min_cost=INT_MAX, max_happiness=0, cnt=0, x=0;
int happiness_map[MAX] = {0}, cost_map[MAX][MAX] = {0};
string start;
vector<string> cities;
map<string, int> cityidx;
vector<int> path, best;
vector<bool> visits;

void set_value(int cost, int happiness) {
	min_cost = cost;
	max_happiness = happiness;
	best = path;
}

void dfs(int src, int dst, int cost, int happiness) {
	visits[src] = true;
	path.push_back(src);
	if (src == dst) {
		if (cost < min_cost) {
			cnt = 1;
			set_value(cost, happiness);
		} else if (cost == min_cost) {
			cnt++;
			if (happiness > max_happiness || (happiness == max_happiness && path.size() < best.size()))
				set_value(cost, happiness);
		}
	}
	if (cost >= min_cost) return;
	for (int i=0; i<n; i++) {
		if (!visits[i] && cost_map[src][i] != 0) {
			dfs(i, dst, cost+cost_map[src][i], happiness+happiness_map[i]);
			path.pop_back();
			visits[i] = false;
		}
	}
}

int main () {
	cin >> n >> k >> start;
	cities.resize(n);
	for (int i=0; i<n; i++) {
		string city;
		if (i > 0)
			cin >> city >> x;
		else 
			city = start;
		cities[i] = city;
		cityidx[city] = i;
		happiness_map[i] = x;
	}
	for (int i=0; i<k; i++) {
		string city1, city2;
		cin >> city1 >> city2 >> x;
		cost_map[cityidx[city1]][cityidx[city2]] = x;
		cost_map[cityidx[city2]][cityidx[city1]] = x;
	}
	visits.resize(n, false);
	dfs(0, cityidx["ROM"], 0, 0);
	printf("%d %d %d %d\n", cnt, min_cost, max_happiness, max_happiness/(best.size()-1));
	for (int i=0; i<best.size(); i++) {
		printf("%s%s", cities[best[i]].c_str(), i == best.size()-1 ? "\n":"->");
	}
	return 0;
}
