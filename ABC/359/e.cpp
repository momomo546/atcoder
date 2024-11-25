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
    ll ans=1,cnt=0,cnt2=0;
    vector<ll> h2(n);
    stack<ll> st;
    rep(i,n){
        ll h;
        cin>>h;
        h2[i]=h;
        bool flag=false;
        if(!st.empty()){
            while(st.top()<h){
                flag=true;
                ans+=h-st.top();
                st.pop();
                cnt++;
                if(st.empty()) break;
            }
        }
        if(flag){
            ans+=cnt2*(h-h2[i-cnt]);
            cnt2=cnt;
        }
        st.push(h);
        ans+=h;
        cout<<ans<<" ";
    }
}