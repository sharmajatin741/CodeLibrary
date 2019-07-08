struct FenwickTree2D {
    vector<vector<int>> bit;  // binary indexed tree
    int n,m;
    void init(int n,int m) {
        this->n = n;
        this->m = m;
        bit.assign(n, vector<int>(m,0));
    }
    int get(int r,int s) {
        int ret = 0;
        for (int i=r; i >= 0; i = (i & (i + 1)) - 1)
            for (int j=s; j >= 0; j = (j & (j + 1)) - 1)
                  ret += bit[i][j];
        return ret;
    }
    void add(int idx,int idy, int delta) {
        for (int i=idx; i < n; i = i | (i + 1))
              for (int j=idy; j < m; j = j | (j + 1))
                   bit[i][j] += delta;
    }
}fw;