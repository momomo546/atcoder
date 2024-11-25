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
    int n, m;
    cin>>n>>m;
    vector<int> ans(n), a(m);
    rep(i,m) cin>>a[i];
    sort(a.begin(),a.end());
    int mi = a[0],ma = a[a.size()-1];
    if(mi==1||ma==n){
        cout<<-1;
        return 0;
    }
    
    int pre = mi,next = ma,cnt2 = 0;
    rep(i,pre-1)ans[i]=i+1;
    rep(j,m){
        int cnt = 0;
        next = ma;
        for (int k = cnt2; k < m ;k++){
            cnt2++;
            if(k==m-1)break;
            if(a[k]!=a[k+1]-1){
                next=a[k+1];
                break;
            }
            else cnt++;
        }
        for (int i = pre-1; i < pre + cnt ;i++) ans[i]=i+2;
        ans[pre + cnt]=pre;
        for (int i = pre + cnt+1; i < next-1;i++) ans[i]=i+1;
        pre = next;
        if(cnt2==m) break;
    }
    
    for (int i = ma+1; i < n;i++) ans[i]=i+1;
    rep(i,n){
        cout<<ans[i]<<" ";
    }
}