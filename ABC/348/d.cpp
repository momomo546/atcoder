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
    int dp[201][201];
    memset(dp, 0, sizeof(dp));

    int h,w;
    cin >> h >> w;
    vector<string> a(h);
    rep(i,h) cin>>a[i];
    int n;
    cin>>n;
    map<pair<int,int>,int> mp;
    rep(i,n){
        int r,c,e;
        cin>>r>>c>>e;
        mp[make_pair(r-1,c-1)]=e;
    }
    pair<int,int> s,t;
    rep(i,h){
        rep(j,w){
            if(a[i][j]=='S') {
                s = make_pair(i,j);
                a[i][j]='.';
            }
            else if(a[i][j]=='T') {
                t = make_pair(i,j);
                a[i][j]='.';
            }
        }
    }

    int cnt=0;
    if(mp.find(s)!=mp.end()) cnt=mp[s];
    dp[s.first][s.second]=cnt;

    queue<pair<int,int>> que;
    que.push(s);

    vector<int>dx={1,0,-1,0},dy={0,1,0,-1};
    while(!que.empty() && dp[t.first][t.second]==0){
        pair<int,int> tmp=que.front();
        int x = tmp.first, y = tmp.second;
        que.pop();
        cnt=dp[x][y]-1;
        rep(i,4){
            int x2 = x+dx[i],y2 = y+dy[i];

            if(x2 < 0 || x2 >= h || y2 < 0 || y2>= w) continue;
            if(a[x2][y2]=='#') continue;
            if(cnt<=0) continue;

            pair<int,int> tmp2=make_pair(x2,y2);
            que.push(tmp2);
            if(mp.find(tmp2)!=mp.end()) {
                cnt=mp[tmp2];
                mp.erase(tmp2);
            }
            dp[x2][y2]=max(dp[x2][y2],cnt);
        }
    }
    if(dp[t.first][t.second]!=0) cout<<"Yes";
    else cout<<"No";
}//mi