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

int main()
{
    int h,w,y;
    cin>>h>>w>>y;
    vector<vector<int>> a(h ,vector<int> (w))
    rep(i,h) rep(j,w) cin>>a[i][j];
    set<int> st;
    queue<int> que;
    vector<int>
    rep(i,h-2){
        que.push(a[i+1][0]);
        que.push(a[i+1][w-1]);
    }
    rep(i,w-2){
        que.push(a[0][i+1]);
        que.push(a[h-1][i+1]);
    }
    que.push(a[0][0]);
    que.push(a[h-1][0]);
    que.push(a[h-1][w-1]);
    que.push(a[0][w-1]);

    while(!que.empty()){
        int tmp
    }

}