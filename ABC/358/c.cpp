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
    int n,m;
    cin>>n>>m;
    vector<string> s(n);
    rep(i,n)cin>>s[i];
    int ans=100;
    for (int bit = 1; bit < (1<<n); ++bit) {
        vector<int> num;
        for (int i = 0; i < n; ++i) {
            if (bit & (1<<i)) { 
                num.push_back(i);
            }
        }
        vector<bool> b(m,false);
        for(const auto& e : num){
            rep(i,m){
                if(s[e][i]=='o')b[i]=true;
            }
        }
        bool flag=true;
        rep(i,m){
            if(b[i]==false)flag=false;
        }
        if(flag==true){
            int g=num.size();
            ans=min(ans,g);
        }
    }
    cout<<ans;
}