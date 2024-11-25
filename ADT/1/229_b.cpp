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
    int n;
    cin>>n;
    vector<ll> a(n),b(n),ans(n);
    iota(ans.begin(),ans.end(),0);
    rep(i,n){
        cin>>a[i]>>b[i];
    }
    stable_sort(ans.begin(),ans.end(),[&](int i,int j){
        ll x = a[i]*(a[j]+b[j]);
        ll y = a[j]*(a[i]+b[i]);
        return x>y;
    });
    rep(i,n) cout<<ans[i]+1<<" ";
}