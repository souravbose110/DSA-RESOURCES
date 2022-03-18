#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& a, int s, int e) {
    int mid = (s + e) / 2;
    vector<int> temp;
    int i = s, j = mid + 1;
    while (i <= mid and j <= e) {
        if (a[i] < a[j]) temp.push_back(a[i++]);
        else temp.push_back(a[j++]);
    }
    while (i <= mid) temp.push_back(a[i++]);
    
    while (j <= e) temp.push_back(a[j++]);
    
    int k = 0;
    for (i=s; i<=e; ++i) a[i] = temp[k++];
}

void mergesort(vector<int>& a, int s, int e) {
    if (s >= e) {
        return;
    }

    int mid = (s + e) / 2;
    mergesort(a, s, mid);
    mergesort(a, mid + 1, e);
    merge(a, s, e);
}

int main() {
	
    vector<int> a = {2, 4, 1, 5, 4, 9, 7, 6, 8};
    int s = 0, e = a.size() - 1;
    mergesort(a, s, e);
    for (int i : a) cout << i << ' ';
}
