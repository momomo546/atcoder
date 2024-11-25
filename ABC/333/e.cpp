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
    cin >> n;
    vector<int> t(n),x(n),p;
    rep(i,n) cin>>t[i]>>x[i];
    int ans=0,cnt=0;
    map<int,int> mp;
    repr(i,n){
        if(t[i]==2){
            cnt++;
            if(mp.find(x[i])==mp.end()) mp[x[i]]=1;
            else mp[x[i]]+=1;
            ans=max(ans,cnt);
        }
        else{
            if(mp.find(x[i])==mp.end()) p.push_back(0);
            else {
                p.push_back(1);
                if(mp[x[i]]>1) mp[x[i]]--;
                else mp.erase(x[i]);
                cnt--;
            }
        }
    }
    if(cnt>0) cout<<-1;
    else{
        cout<<ans<<"\n";
        repr(i,p.size()){
            cout<<p[i]<<" ";
        }
        cout<<endl;
    }
}