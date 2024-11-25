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
    vector<int> x(4),y(4),z(4),all(12);
    rep(i,4){
        cin>>x[i]>>y[i]>>z[i];
    }
    rep(i,4){
        all[i]=x[i];
        all[i+4]=y[i];
        all[i+8]=z[i];
    }
    sort(x.begin(),x.end());
    sort(y.begin(),y.end());
    sort(z.begin(),z.end());
    if(x[0]==all[0]||x[0]==all[1]){
        if(x[1]==all[0]||x[1]==all[1]){
            cout<<"No";
            return 0;
        }
    }
    else{
        if(x[1]==all[2]||x[1]==all[3]){
            cout<<"No";
            return 0;
        }
    }
    if(y[0]==all[4]||y[0]==all[5]){
        if(y[1]==all[4]||y[1]==all[5]){
            cout<<"No";
            return 0;
        }
    }
    else{
        if(y[1]==all[6]||y[1]==all[7]){
            cout<<"No";
            return 0;
        }
    }
    if(z[0]==all[8]||z[0]==all[9]){
        if(z[1]==all[8]||z[1]==all[9]){
            cout<<"No";
            return 0;
        }
    }
    else{
        if(z[1]==all[10]||z[1]==all[11]){
            cout<<"No";
            return 0;
        }
    }
    cout<<"Yes";
}