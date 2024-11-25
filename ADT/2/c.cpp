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
    ll n,m;
    cin >> n >> m;
    vector<ll> sum(n),ans(n);
    vector<pair<ll,ll>> a(m);
    vector<string> s(n);
    rep(i,m){
        cin>>a[i].first;
        a[i].second=i;
    }
    
    iota(sum.begin(),sum.end(),1);
    rep(i,n){
        cin>>s[i];
        rep(j,m) if(s[i][j]=='o') sum[i]+=a[j].first;
    }
    ll tmp=0;
    rep(i,n) tmp=max(tmp,sum[i]);

    auto f=[](auto i,auto j){return i.first>j.first;};
    sort(a.begin(),a.end(),f);

    rep(i,n){
        int cnt=0;
        if(sum[i]<tmp){
            rep(j,m){
                if(s[i][a[j].second]=='x'){
                    sum[i]+=a[j].first;
                    cnt++;
                    if(sum[i]>tmp)break;
                }
            }
        }
        cout<<cnt<<"\n";
    }
}