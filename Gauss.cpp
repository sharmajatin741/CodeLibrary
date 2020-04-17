struct Gauss
{
	vector<int> base;
	int LOG_A;
	int sz;
	void init(int LOG_A)
	{
		this->LOG_A=LOG_A;
		sz=0;
		base.resize(LOG_A,0);
	}
	void add(int mask)
	{
		for (int i = 0; i < LOG_A; i++)
		{
			if ((mask & 1LL << i) == 0) continue;	 
			if (!base[i]) {
				sz++;
				base[i] = mask;
				return;
			}
			mask ^= base[i];
		}
	}
	bool check(int mask)
	{
		for (int i = 0; i < LOG_A; i++) {
			if ((mask & 1LL << i) == 0LL) continue;
			if (!base[i]) return false;
			mask ^= base[i];
		}
		return true;
	}
	int getbest()
	{
		int x=0;
		for(int i=LOG_A-1;i>=0;i--)
		{
			x=max(x,x^base[i]);
		}
		return x;
	}

};
