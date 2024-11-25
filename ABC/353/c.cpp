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
    cin>>n;
    ll ans=0;
    ll mod=100000000;
    vector<ll> a(n);
    rep(i,n){
        cin>>a[i];
        ans+=2*a[i];
    }
    sort(a.begin(),a.end());
    int cnt=0;
    rep(i,n-1){
        auto iter_lower = lower_bound(a.begin()+i, a.end(), mod-a[i+1]);
        cnt+=(n-i)-*iter_lower;
    }
    ans-=cnt*mod;
    cout<<ans;
}