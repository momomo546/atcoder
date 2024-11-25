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
    ll n;
    cin>>n;
    ll cnt = 1,tmp=n;
    while(tmp>0){
        cnt*=10;
        tmp/=10;
    }
    ll cnt2=1,ans=n;
    vector<ll> ans_tmp;
    ans_tmp.push_back(n);
    ll two=1;
    while(cnt2!=n){
                ans=ans*cnt+n;
                ans%=MOD;
                cnt2++;
            
        
    }
    cout<<ans;
}