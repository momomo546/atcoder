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
	string s;
	cin>>s;
	vector<vector<int>> dp(3,vector<int>(s.size()+1));
	rep(i,s.size()){
		if(s[i]=='R'){
			dp[0][i+1]=max(dp[1][i],dp[2][i]);
			dp[1][i+1]=0;
			dp[2][i+1]=max(dp[0][i]+1,dp[1][i]+1);
		}
		else if(s[i]=='S'){
			dp[0][i+1]=max(dp[1][i]+1,dp[2][i]+1);
			dp[1][i+1]=max(dp[0][i],dp[2][i]);
			dp[2][i+1]=0;
		}
		else{
			dp[0][i+1]=0;
			dp[1][i+1]=max(dp[0][i]+1,dp[2][i]+1);
			dp[2][i+1]=max(dp[0][i],dp[1][i]);
		}
	}
	int ans=max(dp[0][s.size()],dp[1][s.size()]);
	ans=max(ans,dp[2][s.size()]);
	cout<<ans;
}