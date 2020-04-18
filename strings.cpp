namespace strings{
	vector<int> prefix_function(string s)
	{
		int n = (int)s.length();
		vector<int> pi(n);
		for (int i = 1; i < n; i++) {
		   int j = pi[i-1];
		   while (j > 0 && s[i] != s[j])
		       j = pi[j-1];
		   if (s[i] == s[j])
		       j++;
		   pi[i] = j;
		}
		return pi;
	}
	pair<vector<int>,vector<int>> manacher(string s)
	{
		int n=s.length();
		vector<int> d1(n);
		for (int i = 0, l = 0, r = -1; i < n; i++) {
			int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
			while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) {
			   	k++;
			}
			d1[i] = k--;
			if (i + k > r) {
			   l = i - k;
			   r = i + k;
			}
		}
		vector<int> d2(n);
		for (int i = 0, l = 0, r = -1; i < n; i++) {
			int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
			while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k]) {
			   k++;
			}
			d2[i] = k--;
			if (i + k > r) {
			   l = i - k - 1;
			   r = i + k ;
			}
		}
		// d1-> odd palindromes
		// d2-> even palindromes
		return {d1,d2};
	}	
	struct hashs
	{
		string s;
		vector<int> hash,pw;
		int P,_MOD;
		hashs(string s,int P,int _MOD):P(P),_MOD(_MOD){
			int n=s.length();
			pw.resize(n+2,0);
			hash.resize(n+2,0);
			pw[0]=1;
			for(int i=n-1;i>=0;i--)
			{
				hash[i]=(1LL*hash[i+1]*P+(s[i]-'a'+1))%_MOD;
				pw[n-i]=(pw[n-i-1]*P)%_MOD;
			}
			pw[n]=(1LL*pw[n-1]*P)%_MOD;
		}
		int get(int l,int r)
		{
			return (hash[l]+MOD-(1LL*hash[r+1]*pw[r-l+1])%_MOD)%_MOD;
		}
	};
}
