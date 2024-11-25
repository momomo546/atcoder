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

int factorial(int n)
{
    int x = 1;
    for (int i = n; i > 0; i--)
    {
        x *= i;
    }
    return x;
}
int H(int n, int r)
{
    if (n <= 0 || r < 0)
    {
        return 0;
    }
    if (n == 1 || r == 0)
    {
        return 1;
    }
    return H(n, r - 1) + H(n - 1, r);
}
def div(a, b, p)
    inv = pow(a, p-2, p)    # a^(p-2) を pで割った余り
    return (a * inv) mod p

int main()
{
    int k;
    cin>>k;
    vector<int> c(26);
    rep(i,26)cin>>c[i];
    ll up=1,down=1,ans=0;
    ll tmp;
    rep(i,26){
      if(i>0&&c[i]>=i+1)ans++;
      up*=26-i;
      down*=i+1;
      tmp=up/down;
      tmp%=MOD;
      ans+=tmp;
      ans%=MOD;
    }
    cout<<ans;
}