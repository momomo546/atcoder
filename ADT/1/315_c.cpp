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

ll f(ll a,ll b){
    return a*a*a+a*a*b+a*b*b+b*b*b;
}

int main()
{
    ll n;
    cin>>n;
    ll ans=INF;
    ll i=0,j=1e6;
    while(i<=j){
        ll tmp=f(i,j);
        if(tmp>=n){
            ans=min(ans,tmp);
            j--;
        }
        else i++;
    }
    cout<<ans;
}