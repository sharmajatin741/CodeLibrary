namespace numb{
	vector<bool> isprime;
	vector<int> fac,rfac,phi;
	vector<vector<int>> prime_factors;
	int add(int a,int b)
	{
	      a+=b;
	      if(a>=MOD) a-=MOD;
	      return a;
	}
	int sub(int a,int b)
	{
	      a-=b;
	      if(a<0) a+=MOD;
	      return a;
	}
	int mul(int a,int b)
	{     
	      return ((long long)a*b)%MOD;
	}
	int mpow(int a,int b)
	{
		int res=1;
		while(b>0){
			if(b&1)
				res=mul(res,a);
			a=mul(a,a);
			b=b>>1LL;
		}
		return res;
	}
	int rev(int a)
	{
		return mpow(a,MOD-2);
	}
	
	void seive(int n)
	{
		isprime.resize(n+2,true);
		isprime[0]=isprime[1]=false;
		for(int i=2;i*i<=n;i++)
		{
			if(isprime[i])
			{
				for(int j=i*i;j<=n;j+=i)
				{
					isprime[j]=false;
				}
			}
		}
	}
	void fact(int n)
	{
		fac.resize(n+2,0LL);
		rfac.resize(n+2,0LL);
		fac[0]=1;
		for(int i=1;i<=n;i++)
		{
			fac[i]=mul(fac[i-1],i);
		}
		rfac[n]=rev(fac[n]);
		for(int i=n-1;i>=0;i--)
		{
			rfac[i]=mul(rfac[i+1],i+1);
		}
	}
	
	int ncr(int n,int r)
	{
		if(r>n) return 0;
		int ans=mul(fac[n],mul(rfac[r],rfac[n-r]));
		return ans;
	}
	int phii(int n) {
		int result = n;
		for (int i = 2; i * i <= n; i++) {
		   if (n % i == 0) {
		       while (n % i == 0)
		           n /= i;
		       result -= result / i;
		   }
		}
		if (n > 1)
		   result -= result / n;
		return result;
	}
	void pre_phi(int n) {
		phi.resize(n+2,0);
		phi[0] = 0;
		phi[1] = 1;
		for (int i = 2; i <= n; i++)
		   phi[i] = i - 1;

		for (int i = 2; i <= n; i++)
		   for (int j = 2 * i; j <= n; j += i)
		         phi[j] -= phi[i];
	}
	int gcd(int a,int b)
	{
		return b?gcd(b,a%b):a;
	}
	int gcd(int a, int b, int & x, int & y) {
		if (a == 0) {
		   x = 0;
		   y = 1;
		   return b;
		}
		int x1, y1;
		int d = gcd(b % a, a, x1, y1);
		x = y1 - (b / a) * x1;
		y = x1;
		return d;
	}
	bool find_any_solution(int a, int b, int c, int &x0, int &y0, int &g) {
		g = gcd(abs(a), abs(b), x0, y0);
		if (c % g) {
		   return false;
		}
		x0 *= c / g;
		y0 *= c / g;
		if (a < 0) x0 = -x0;
		if (b < 0) y0 = -y0;
		return true;
	}
	void prime_fact(int n)
	{
		prime_factors.resize(n+2);
		for(int i=2;i<=n;i++)
		{
			if(isprime[i])
			{
				for(int j=i;j<=n;j+=i)
				{
					prime_factors[j].pb(i);
				}
			}
		}
	}
}
using namespace numb;
