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

int main()
{
    ll n;
    cin >> n;
    map<int,int> mp;
    rep(i,n){
        int a,c;
        cin>>a>>c;
        if(mp.find(c)!=mp.end()) mp[c]=min(mp[c],a);
        else mp[c]=a;
    }
    int ans=0;
    for(const auto& e:mp){
        if(e.second>=ans) ans=e.second;
    }
    cout<<ans;
}