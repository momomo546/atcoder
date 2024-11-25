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
    ll n,t;
    cin>>n>>t;
    vector<ll> v(2*n+2);
    rep(i,t){
        ll a;
        cin>>a;
        ll yoko=a%n;
        if(yoko==0) yoko=n;
        yoko--;
        ll tate=(a-1)/n;
        v[yoko]++;
        v[tate+n]++;
        if(tate==yoko) v[2*n]++;
        if(tate+yoko==n-1) v[2*n+1]++;
        rep(j,2*n+2){
            if(v[j]==n){
                cout<<i+1;
                return 0;
            }
        }
    }
    cout<<-1;
}