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
    int n, q;
    cin>>n>>q;
    vector<bool> ans(n,true);
    rep(i,q){
        int t;
        cin>>t;
        if(ans[t-1]==false){
            ans[t-1]=true;
        }
        else{
            ans[t-1]=false;
        }
    }
    int tmp=0;
    rep(i,n){
        if(ans[i]==true)tmp++;
    }
    cout<<tmp;
}