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
    vector<pair<ll,ll>> a(n);
    rep(i,n){
        cin>>a[i].first;
    }
    rep(i,n){
        cin>>a[i].second;
    }
    sort(a.begin(),a.end());
    ll sum=0;
    ll ans=0;
    for(int i=0;i<n-1;i++){
        if(a[i].first==a[i+1].first){
            sum+=a[i].second;
        }
        else{
            if(sum>0){
                ans+=sum;
                sum=0;
            }
        }
    }
    if(sum>0){
        ans+=sum;
        sum=0;
    }
    cout<<ans;
}