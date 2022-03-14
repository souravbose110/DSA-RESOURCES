#include "bits/stdc++.h"

using namespace std;

#define int int64_t
#define nl '\n'
#define all(x) begin(x),end(x)
#define allr(x) rbegin(x), rend(x)
#define debug(x) cerr << #x<<" "; _print(x); cerr << endl;
#define ff first 
#define ss second
#define sz(x) (int)(x).size()
#define pb push_back
#define ppb pop_back
#define fast cin.tie(0)->sync_with_stdio(0)
#define lb lower_bound
#define ub upper_bound
#define minq priority_queue<int, vector<int>, greater<int>>
#define maxq priority_queue<int>

template <typename T>
void print(T &&t) {cout << t << '\n'; }

void bubble_sort(int a[], int n) {
	
	for (int i=1; i<=n-1; ++i) {
		for (int j=0; j<=n-1-i; ++j) {
			if (a[j] > a[j+1]) {
				swap(a[j], a[j+1]);
			}
		}
	}
}

void insertion_sort(int a[], int n) {
	
	for (int i=1; i<n; ++i) {
		int cur = a[i];
		int prv = i - 1;
		while (prv >= 0 and a[prv] > cur) {
			a[prv+1] = a[prv];
			--prv;
		}
		a[prv+1] = cur;
	}
}

void selection_sort(int a[], int n) {
	
	for (int i=0; i<n-1; ++i) {
		int pos = i;
		for (int j=i+1; j<n; ++j) {
			if (a[j] < a[pos]) {
				pos = j;
			}
		}
		swap(a[i], a[pos]);
	}
}

int32_t main() {
    fast;
    
 	int a[] = {5, 4, 3, 2, 1};
 	selection_sort(a, 5);
 	for (int i : a) cout << i << ' ';

    return 0;
}
