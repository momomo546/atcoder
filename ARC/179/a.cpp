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
    ll n, k;
    cin>>n>>k;
    vector<ll> a(n);
    ll sum1=0,sum2=0;
    rep(i,n) {
        cin>>a[i];
        if(a[i]<0) sum2-=a[i];
        else sum1+=a[i];
    }
    
    if(k>0){
        sort(a.begin(),a.end());
        cout<<"Yes"<<"\n";
        rep(i,n){
            cout<<a[i]<<" ";
        }
    }
    else if(sum1-sum2>=k){
        sort(a.rbegin(),a.rend());
        cout<<"Yes"<<"\n";
        rep(i,n){
            cout<<a[i]<<" ";
        }
    }
    else cout<<"No";
}