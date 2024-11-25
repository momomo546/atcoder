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
    int h,w;
    cin>>h>>w;
    vector<string> s(h);
    bool flag;
    rep(i,h){
        cin>>s[i];
    }
    rep(i,h){
        rep(j,w){
            if(s[i][j]=='#'){
                rep(k,4){
                    int x2 = i + dx[k];
                    int y2 = j + dy[k];
                    if(x2<0||x2>=h||y2<0||y2>=w) continue;
                    else if(s[x2][y2]=='.'){
                        s[x2][y2]='x';
                        flag=true;
                    }
                }
            }
        }
    }
    int ans=0,tmp=0;
    queue<pair<int,int>> que;
    vector<vector<int>> dist(h, vector<int>(w, -1));
    rep(i,h){
        rep(j,w){
            if(s[i][j]=='.'){
                que.push(make_pair(i,j));
                dist[i][j] = 0;
                tmp=0;
                while(!que.empty()){
                    pair<int,int> p=que.front();
                    que.pop();
                    tmp++;

                    if(s[p.first][p.second]!='x'){
                    rep(k,4){
                        int x2 = p.first + dx[k];
                        int y2 = p.second + dy[k];

                        if(x2<0||x2>=h||y2<0||y2>=w) continue;
                        if(s[x2][y2]=='#') continue;
                        if (dist[x2][y2] != -1) continue;

                        que.push(make_pair(x2,y2));
                        dist[x2][y2]=0;
                    }}
                    s[p.first][p.second]='#';
                    
                }
                ans=max(ans,tmp);
            }
        }
    }
    if(flag&&ans==0)cout<<1;
    else cout<<ans;
}