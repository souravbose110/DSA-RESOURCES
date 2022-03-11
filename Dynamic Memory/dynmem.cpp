#include "bits/stdc++.h"

using namespace std;

#define int int128_t
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
template <typename T, typename... Args>
void print(T &&t, Args &&...args) {
	cout << t << " ";
	print(forward<Args>(args)...);
}

int32_t main() {
    fast;
    
 	// 1D Dynamic Array
 	int n; cin >> n;
 	int* arr = new int[n];   
 	
 	// 2D Dynamic Array
 	int r, c; cin >> r >> c;
 	int** arr = new int*[r];
 	
 	for (int i=0; i<r; ++i) {
 		arr[i] = new int[c];
 	}
 	

    return 0;
}
