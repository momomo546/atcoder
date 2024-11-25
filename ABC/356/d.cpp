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
    ll n,m;
    cin>>n>>m;
    ll cnt2=0;
    ll two=2;
    vector<ll> a(60);
    while(m!=0){
        cnt2++;
        if(m%2==1){
            a[cnt2-1]=1;
        }
        m/=2;
    }
    ll ans=0,tmp;
    rep(i,60){
        if(a[i]==1){
            tmp=n/two;
            tmp*=two/2;
            tmp%=MOD;
            ans+=tmp;
            if(n%two>=two/2){
                ans+=(n%two)-(two/2)+1;
                ans%=MOD;
            }
        }
        two*=2;
    }
    ans%=MOD;
    cout<<ans;
}