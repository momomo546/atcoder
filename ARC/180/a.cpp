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
constexpr ll MOD2 = 1000000000 + 7;

ll gcd(ll a, ll b) { return a ? gcd(b % a, a) : b; } // b > a
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

int main()
{
    ll n;
    cin>>n;
    string s;
    cin>>s;
    ll cnt=0,ans=1;
    rep(i,s.size()-1){
        if(s[i]!=s[i+1]){
            cnt++;
        }
        else{
            ans*=cnt/2+1;
            ans%=MOD2;
            cnt=0;
        }
    }
    if(cnt/2+1!=0) ans*=cnt/2+1;
    ans%=MOD2;
    cout<<ans;
}