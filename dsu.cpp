struct dsu{
	vector<int> par;
	vector<int> sz;
	void init(int n)
	{
		par.resize(n+2);
		sz.resize(n+2);
		for(int i=0;i<=n;i++)
		{
			par[i]=i;
			sz[i]=1;
		}
	}
	int find(int x)
	{
		return x==par[x]?x:par[x]=find(par[x]);
	}
	bool join(int x,int y)
	{
		x=find(x);
		y=find(y);
		if(x==y)
		{
			return false;
		}
		else{
			if(sz[x]<sz[y])
			{
				swap(x,y);
			}
			par[y]=x;
			sz[x]+=sz[y];
			return true;
		}
	}
	bool is_connected(int x,int y)
	{
		if(find(x)==find(y)) return true;
		else return false;
	}
}dsu;
