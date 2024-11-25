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
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    map<string,int> mp;
    int cnt=0,all=0;
    sort(s.begin(),s.end());
    do {
        if(mp[s]==0)mp[s]++;
        else continue;
        all++;
        rep(i,n-k+1){
            bool flag=true;
            int a=k/2;
            rep(j,a){
                if(s[i+j]==s[k+i-j-1]) continue;
                else flag=false;
            }
            if(flag) {
                cnt++;
                break;
            }
        }
    } while (next_permutation(s.begin(), s.end()));
    cout<<all-cnt;
}