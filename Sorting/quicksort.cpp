#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int>& a, int s, int e) {
	int pivot = a[e];
    int i = s - 1, j = s;
    for (int j=s; j<e; ++j) {
        if (a[j] < pivot) {
            swap(a[++i], a[j]);
        }
    }
    swap(a[i+1], a[e]);
    
    return i+1;
}

void quicksort(vector<int>& a, int s, int e) {
	if (s >= e) {
		return;
	}
	int p = partition(a, s, e);
    quicksort(a, s, p-1);
    quicksort(a, p+1, e);
}

int main() {
	
    vector<int> a = {2, 4, 1, 5, 4, 9, 7, 6, 8};
    quicksort(a, 0, a.size() - 1);
    for (int i : a) cout << i << ' ';
}
