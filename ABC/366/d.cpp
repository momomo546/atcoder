#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repr(i, n) for (int i = (int)(n)-1; i >= 0; i--)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)

constexpr ll INF = 1LL << 60;
constexpr ll MOD = 998244353;

ll gcd(ll a, ll b) { return a ? gcd(b % a, a) : b; } // b > a
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

const vector<int> dx = {1, 0, -1, 0};
const vector<int> dy = {0, 1, 0, -1};

int main()
{
    ll n;
    cin>>n;
	vector<vector<vector<int>>> a(n, vector<vector<int>>(n,vector<int> (n)));
	vector<vector<vector<int>>> sum(n, vector<vector<int>>(n,vector<int> (n)));
	rep(i,n){
		rep(j,n){
			rep(k,n){
				cin>>a[i][j][k];
			}
		}
	}
	rep(i,n){
		rep(j,n){
			sum[i][j][0]=a[i][j][0];
			rep(k,n-1){
				sum[i][j][k+1]=sum[i][j][k]+a[i][j][k+1];
			}
		}
	}
	rep(i,n){
		rep(j,n){
			rep(k,n-1){
				sum[i][k+1][j]+=sum[i][k][j];
			}
		}
	}
	rep(i,n){
		rep(j,n){
			rep(k,n-1){
				sum[k+1][j][i]+=sum[k][j][i];
			}
		}
	}
	ll q;
	cin>>q;
	rep(i,q){
		int lx,rx,ly,ry,lz,rz;
		cin>>lx>>rx>>ly>>ry>>lz>>rz;
		ll ans=sum[rx-1][ry-1][rz-1];
		if(lz-2>=0)ans-=sum[rx-1][ry-1][lz-2];
		if(ly-2>=0)ans-=sum[rx-1][ly-2][rz-1];
		if(lx-2>=0)ans-=sum[lx-2][ry-1][rz-1];
		if(lz-2>=0&&ly-2>=0)ans+=sum[rx-1][ly-2][lz-2];
		if(lx-2>=0&&ly-2>=0)ans+=sum[lx-2][ly-2][rz-1];
		if(lz-2>=0&&lx-2>=0)ans+=sum[lx-2][ry-1][lz-2];
		if(lz-2>=0&&ly-2>=0&&lx-2>=0)ans-=sum[lx-2][ly-2][lz-2];
		cout<<ans<<"\n";
	}
}