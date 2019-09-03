#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int n, x, k=-1;
bool insertion = true;
vector<int> seq, partial;

void print_vec(vector<int> vec) {
	for (int i=0; i<vec.size(); i++) {
		printf("%d%s", vec[i], i == vec.size()-1 ? "\n":" ");
	}
}

void insertion_sort(){
	for (int i=k; i>0; i--) {
		if (partial[i] < partial[i-1]) {
			int tmp = partial[i];
			partial[i] = partial[i-1];
			partial[i-1] = tmp;
		} else break;		
	}
	printf("Insertion Sort\n");
	print_vec(partial);
}

void merge(vector<int> &vec, int lstart, int lend, int rstart, int rend) {
	vector<int> tmp;
	int lid = lstart, rid = rstart;
	while (lid <= lend && rid <= rend) {
		if (vec[lid] < vec[rid]) tmp.push_back(vec[lid++]);
		else tmp.push_back(vec[rid++]);
	}
	while (lid <= lend) tmp.push_back(vec[lid++]);
	while (rid <= rend) tmp.push_back(vec[rid++]);
	for (int i=0; i<tmp.size(); i++) {
		vec[lstart+i] = tmp[i];
	}
}

void merge_sort() {
	bool flag = false;
	printf("Merge Sort\n");
	for (int k=1; k<n; k*=2) {
		int subcnt = n % k == 0 ? n/k : n/k+1;
		if (seq == partial) flag = true;
		for (int i=0; i<subcnt/2; i++) {
			merge(seq, 2*i*k, (2*i+1)*k-1, (2*i+1)*k, min((2*i+2)*k-1, n-1));
		}
		if (flag) break;
	}
	print_vec(seq);
}

int main () {
	scanf("%d", &n);
	for (int i=0; i<n; i++) {
		scanf("%d", &x);
		seq.push_back(x);
	}
	for (int i=0; i<n; i++) {
		scanf("%d", &x);
		partial.push_back(x);
		if (i>0 && k==-1 && partial[i] < partial[i-1])
			k = i;
		if (k!=-1 && partial[i] != seq[i])
			insertion = false;
	}
	if (insertion) insertion_sort();
	else merge_sort();
	return 0;
}
