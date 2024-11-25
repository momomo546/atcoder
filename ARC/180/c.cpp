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
    vector<ll> a(n);
    rep(i,n){
        cin>>a[i];
    }
    set<ll> st;
    ll ans=1,cnt=0;
    st.insert(a[0]);
    for(int i=1; i<n;i++){
        set<ll> prev(st),now;
        now.insert(a[i]);
        for (auto x : prev) {
            st.insert(x+a[i]);
            now.insert(x+a[i]);
        }
        ans*=now.size();
        if(now.size()>2)cnt++;
        ans%=MOD2;
    }
    ans-=cnt;
    ans=(ans%MOD2+MOD2)%MOD2;
    cout<<ans;
}