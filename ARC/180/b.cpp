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

set<pair<int,int>> st;
vector<pair<int,int>> ans;
int k;

bool fcomp(const pair<int,int>& a, const pair<int,int>& b) {
    if(b.second-a.second<k)return false;
    if (st.find(make_pair(a.second,b.second)) != st.end()) {
        if(a.first<b.first){
            st.insert(make_pair(a.second,b.second));
            ans.push_back(make_pair(a.second,b.second));
            int tmp=a.second;
            a.second=b.second;
            b.second=tmp;
        }
        return a.first<b.first;
    }
    else return false;
}

int main()
{
    int n;
    cin>>n>>k;
    vector<pair<int,int>> p(n);
    
    rep(i,n) {
        cin>>p[i].first;
        p[i].second=i;
    }
    sort(p.begin(),p.end(),fcomp );
    cout<<ans.size()<<"\n";
    rep(i,ans.size()){
        cout<<ans[i].first<<" "<<ans[i].second<<"\n";
    }
}