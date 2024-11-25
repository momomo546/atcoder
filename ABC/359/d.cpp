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

long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

int main()
{
    ll n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    ll ans=0;
    rep(i,n-k){
        bool flag=false;
        ll cnt=0;
        rep(j,k-1){
            if(s[i+j]!=s[i+k-j]){
                flag=true;
                break;
            }
            else{
                if(s[i+j]=='?'&&s[i+k-j]=='?') cnt++;
            }
        }
        if(flag)continue;
        else{
            if(s[i+k]=='?')cnt++;
            ll num = modpow(2,cnt,MOD);
            ans+=num;
            ans%=MOD;
        }
    }
    ll tmp=0;
    rep(i,n){
        if(s[i]=='?')tmp++;
    }
    ll sum = modpow(2,tmp,MOD);
    ans=((sum-ans)%MOD+MOD)%MOD;
    cout<<ans;
}