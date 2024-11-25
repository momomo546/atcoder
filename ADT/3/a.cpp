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
    string s;
    cin >> s;
    if(s[0]=='1') {
        cout<<"No";
        return 0;
    }
    vector<bool> f(7,false);
    if(s[6]=='0')f[0]=true;
    if(s[3]=='0')f[1]=true;
    if(s[1]=='0'&&s[7]=='0')f[2]=true;
    if(s[4]=='0')f[3]=true;
    if(s[2]=='0'&&s[8]=='0')f[4]=true;
    if(s[5]=='0')f[5]=true;
    if(s[9]=='0')f[6]=true;
    rep1(i,5){
        if(f[i]==true){
            rep(j,i){
                if(f[j]==false){
                    for(int k=i+1;k<7;k++){
                        if(f[k]==false){
                            cout<<"Yes";
                            return 0;
                        }
                    }
                }
            }
        }
    }
    cout<<"No";
}