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
    vector<int> m(6);
    rep(i,6){
        cin>>m[i];
    }
    int n;
    cin>>n;
    rep(i,n){
        int x;
        cin>>x;
        while(x>=500&&m[5]>0){
                x-=500;
                m[5]--;
        }
        while(x>=100&&m[4]>0){
                x-=100;
                m[4]--;
        }
        while(x>=50&&m[3]>0){
                x-=50;
                m[3]--;
        }
        while(x>=10&&m[2]>0){
                x-=10;
                m[2]--;
        }
        while(x>=5&&m[1]>0){
                x-=5;
                m[1]--;
        }
        while(x>=1&&m[0]>0){
                x-=1;
                m[0]--;
        }
        if(x!=0){
            cout<<"No";
            return 0;
        }
    }
    cout<<"Yes";
}