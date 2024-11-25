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
    string s,t;
    cin>>s>>t;
    bool flag=false;
    rep(i,s.size()/t.size()){
        if(s[i]==t[0]){
            if(i==s.size()-1){
                cout<<"No";
                return 0;
            }
            int cnt=0;
            rep(j,t.size()){
                if(s.size()>i+j*t.size()){
                    if(s[i+j*t.size()]==t[j])cnt++;
                    else break;
                }
            }
            if(cnt==t.size())flag=true;
            cnt=0;
            rep(j,t.size()){
                if(s.size()>i+j*(t.size()-1)){
                    if(s[i+j*(t.size()-1)]==t[j])cnt++;
                    else break;
                }
            }
            if(cnt==t.size())flag=true;
        }
    }
    if(flag)cout<<"Yes";
    else cout<<"No";
    return 0;
}