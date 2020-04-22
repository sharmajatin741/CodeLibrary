#include <bits/stdc++.h> 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using namespace chrono;
#define int long long
#define ld double
#define fi first
#define se second
#define pb push_back
#define pii pair<int,int>
#define sz(x) ((long long)x.size())
#define all(x) (x).begin(), (x).end()
#define popcount(x) __builtin_popcountll(x)
const int MOD =1e9+7;

mt19937_64 rng(high_resolution_clock::now().time_since_epoch().count());
template<typename T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T> istream& operator >> (istream &in,vector<T> &A){ for(auto &x:A) in>>x; return in; };
template<typename T> ostream& operator << (ostream &out,vector<T> &A){ for(auto &x:A) out<<x<<" "; return out; };
template<typename T,typename W> istream& operator >> (istream &in,pair<T,W> &A){ in>>A.fi>>A.se; return in; };
const int N = 15;


void solve()
{	

}

int32_t main(){
	cin.tie(0)->sync_with_stdio(0);
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	#endif
	int t=1;
	// cin>>t;
	for(int _t=1;_t<=t;_t++){
		// cout<<"Case #"<<_t<<": ";
		solve();
	}
} 