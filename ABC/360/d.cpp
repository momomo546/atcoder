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

#define ALL(a)  (a).begin(),(a).end()

int main()
{
    ll n,t;
    cin>>n>>t;
    string s;
    cin>>s;
    vector<ll> x(n),x2(n,0),num(n+1);
    rep(i,n)cin>>x[i];
    rep(i,n-1)x2[i+1]=x2[i]+(x[i+1]-x[i]);
    rep1(i,n+1){
        if(s[i]=='1')num[i+1]=num[i]+1;
        else num[i+1]=num[i];
    }
    ll ans=0;
    rep(i,s.size()){
        if(s[i]=='1'){
            ll tmp = t*2+x2[i]+1;
            auto iter = lower_bound(x2.begin()+1,x2.end(), t*2+x2[i]+1);
            ll tmp2 = iter-x2.begin();
            ans+=num[tmp2]-num[i];
        }
    }
    cout<<ans;
}