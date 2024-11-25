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
    vector<ll> a(9);
    vactor<bool> b(9,true);
    rep(i,9)cin >> a[i];
    rep(i,9){
        for(int j=i+1,9){
            for(int k=j+1,9){
                for(int l=k+1,9){
                    b[i]=false;
                    b[j]=false;
                    b[k]=false;
                    b[l]=false;
                    if(b[0]==b[1]&&b[1]==b[2])continue;
                    if(b[3]==b[4]&&b[4]==b[5])continue;
                    if(b[6]==b[7]&&b[7]==b[8])continue;
                    if(b[0]==b[3]&&b[3]==b[6])continue;
                    if(b[1]==b[4]&&b[4]==b[7])continue;
                    if(b[2]==b[5]&&b[5]==b[8])continue;
                    if(b[0]==b[4]&&b[4]==b[8])continue;
                    if(b[2]==b[4]&&b[4]==b[6])continue;
                    ll suma=0,sumb=0;
                    rep(m,9){
                        if(b[m])suma+=
                    }
                }
            }
        }
    }
}