class dsu {
private:
    vector<int> par, size;
    int cnt;
    int n;
public:
    dsu (int _n) : n(_n), cnt(_n) {
        par.resize(n + 1);
        size.assign(n + 1, 1);
        iota(par.begin(), par.end(), 0);
    }
    
    inline int get(int x) {
        return (par[x] == x ? x : par[x] = get(par[x]));
    }
    
    inline void unite(int x, int y) {
        x = get(x);
        y = get(y);
        
        if (x != y) {
            if (size[x] > size[y]) {
                swap(x, y);
            }
            par[y] = x;
            size[x] += size[y];
            --cnt;
        }
    }
    
    inline int getCount() {
        return cnt;
    }
};
