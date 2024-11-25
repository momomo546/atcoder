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
    vector<ll> l(n),r(n);
    ll lsum=0,rsum=0;
    rep(i,n){
        cin>>l[i]>>r[i];
        lsum+=l[i];
        rsum+=r[i];
    }
    if(lsum<=0&&rsum>=0){
        cout<<"Yes"<<"\n";
        ll sum=0-lsum;
        rep(i,n){
            if(sum>0){
                ll tmp=r[i]-l[i];
                if(tmp<=sum){
                    cout<<l[i]+tmp;
                    sum-=tmp;
                }
                else{
                    cout<<l[i]+sum;
                    sum=0;
                }
            }
            else cout<<l[i];
            cout<<" ";
        }
    }
    else cout<<"No";
}