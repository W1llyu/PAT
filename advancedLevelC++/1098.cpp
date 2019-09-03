#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void swap_num(vector<int> &arr, int pos_a, int pos_b) {
	int tmp = arr[pos_a];
	arr[pos_a] = arr[pos_b];
	arr[pos_b] = tmp;
}

void adjust_heap(vector<int> &heap, int par, int limit) {
	if (par >= limit) return;
	int left = (par+1)*2-1, right = left+1;
	if (right < limit) {
		if (heap[left] < heap[right] && heap[par] < heap[right]) {
			swap_num(heap, par, right);
			adjust_heap(heap, right, limit);
		} else if (heap[left] > heap[right] && heap[par] < heap[left]) {
			swap_num(heap, par, left);
			adjust_heap(heap, left, limit);
		}
	} else if (right == limit) {
		if (heap[par] < heap[left]) {
			swap_num(heap, par, left);
			adjust_heap(heap, left, limit);
		}
	}
}

int n, k, x;
vector<int> seq, partial, heap;
bool is_insert = true;

void insertion_sort() {
	for (int i=k-1; i>=0; i--) {
		if (partial[i] > partial[i+1]) 
			swap_num(partial, i, i+1);
		else
			break;
	}
	printf("Insertion Sort\n");
	for (int i=0; i<n; i++) {
		printf("%d%s", partial[i], i < n-1 ? " " : "\n");
	}
}

void heap_sort() {
	int l_max = partial[0], s_sorted;
	for (int i=0; i<n; i++) {
		if (partial[i] < l_max) {
			s_sorted = i;
		}
	}
	swap_num(partial, 0, s_sorted);
	adjust_heap(partial, 0 , s_sorted);
	printf("Heap Sort\n");
	for (int i=0; i<n; i++) {
		printf("%d%s", partial[i], i < n-1 ? " " : "\n");
	}
}

int main () {
	scanf("%d", &n);
	for (int i=0; i<n; i++) {
		scanf("%d", &x);
		seq.push_back(x);
	}
	bool sorted = true;
	for (int i=0; i<n; i++) {
		scanf("%d", &x);
		partial.push_back(x);
		if (!sorted && partial[i] != seq[i])
			is_insert = false;
		if (i > 0 && sorted && partial[i] < partial[i-1]) {
			sorted = false;
			k = i;
		}
	}
	if (is_insert) insertion_sort();
	else heap_sort();
	return 0;
}
