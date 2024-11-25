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
    ll n,k;
    cin >> n>>k;
    vector<int>a(k);
    rep(i,k) cin>>a[i];
    vector<ll>pre(k+1,0),suf(k+1,0);
    rep1(i,k){
        pre[i] = pre[i - 1];
        if (i % 2 == 0) pre[i]+=a[i-1]-a[i-2];
    }
    repr(i,k){
        suf[i] = suf[i + 1];
        if ((k-i) % 2 == 0) suf[i]+=a[i+1]-a[i];
    }
    ll ans = INF;
    for (int i = 0; i <= k; i += 2) {
        ans=min(ans,pre[i]+suf[i]);
    }
    cout<<ans;
}