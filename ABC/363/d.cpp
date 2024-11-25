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
	ll sum=0,prev=0,tmp=1; 
	rep(i,60){
		if(i==0)sum+=10;
		else{
		ll cnt=1;
		rep(j,(i+1)/2+(i+1)%2){
			if(j==0) cnt*=9;
			else cnt*=10;
		}
		sum+=cnt;
		}
		if(sum>n)break;
		prev=sum;
		tmp++;
	}
	ll tmp2 = n-prev-1;
	vector<int> ans(tmp);
	ll a=tmp/2+tmp%2;
	if(tmp%2==1){
		rep(i,a){
			ll b=tmp2%10;
			tmp2/=10;
			ans[a-i-1]=b;
			ans[a+i-1]=b;
			if(i==a-1&&tmp>1){
				ans[a-i-1]++;
				ans[a+i-1]++;
			}
		}
	}
	else{
		rep(i,a){
			ll b=tmp2%10;
			tmp2/=10;
			ans[a-i-1]=b;
			ans[a+i]=b;
			if(i==a-1){
				ans[a-i-1]++;
				ans[a+i]++;
			}
		}
	}
	rep(i,tmp) cout<<ans[i];
	
}