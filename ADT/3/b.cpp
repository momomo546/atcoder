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
    cin >> n >> m;
    vector<vector<int>> a(m,vector<int>(n)),b(50,vector<int>(50));

    rep(i,m){
        rep(j,n){
            cin>>a[i][j];
        }
    }
    rep(i,m){
        rep(j,n){
            if(j>0)b[a[i][j]-1][a[i][j-1]-1]++;
            if(j<n-1)b[a[i][j]-1][a[i][j+1]-1]++;
        }
    }
    int cnt=0;
    rep(i,n){
        for(int j=i+1;j<n;j++){
            if(b[i][j]==0)cnt++;
        }
    }
    cout<<cnt;
}