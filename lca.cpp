struct TREE{
	vector<vector<int>> a;
	vector<vector<int>> up;
	vector<int> in,out;
	vector<int> depth;
	vector<int> seq;
	vector<int> rseq;
	int n,m,now,nows;
	void init(int n,int m)
	{
		this->n = n;
		this->m = m;
		now=0;
		nows=0;
		a.resize(n+2);
		up.resize(n+2,vector<int>(m,0));
		in.resize(n+2,0);
		out.resize(n+2,0);
		seq.resize(n+2,0);
		rseq.resize(n+2,0);
		depth.resize(n+2,0);
	}
	void add(int x,int y)
	{
		a[x].pb(y);
		a[y].pb(x);
	}
	void dfs(int u,int p,int level=0)
	{
		in[u]=++now;
		depth[u]=level;
		rseq[nows]=u;
		seq[u]=nows++;
		up[u][0]=p;
		for(int i=1;i<m;i++) up[u][i]=up[up[u][i-1]][i-1];
		for(auto v:a[u])
		{
			if(v!=p)
			{
				dfs(v,u,level+1);
			}
		}
		out[u]=++now;
	}
	bool is_ancestor(int u, int v)
	{
	    return in[u] <= in[v] && out[u] >= out[v];
	}
	int lca(int u,int v)
	{
		if (is_ancestor(u, v))
		   return u;
		if (is_ancestor(v, u))
		   return v;
		for (int i = m-1; i >= 0; --i) {
		   if (!is_ancestor(up[u][i], v))
		       u = up[u][i];
		}
		return up[u][0];
	}
	int dis(int u,int v)
	{
		return depth[u]+depth[v]-2*depth[lca(u,v)];
	}
}tr;
