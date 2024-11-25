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

bool fcomp(const int& a, const int& b) {
    cout<<"? "<<a<<" "<<b<<"\n";;
    int t;
    cin>>t;
    if(t==1) return true;
    else return false; 
}

int main()
{
    ll n;
    cin>>n;
    int ntmp=n;
    int cnt = 1,a;
    while(ntmp!=1){
        vector<int> v;
        rep(i,ntmp) {
            v.push_back(cnt);
            cnt++;
        }
        sort(v.begin(), v.end(), fcomp);
        rep(i,ntmp/2) {
            cout<<"+ "<<v[i]<<" "<<v[ntmp-i-1]<<"\n";
        }
        ntmp=n/2+ntmp%2;
    }
    cout<<"!"<<"\n";
}