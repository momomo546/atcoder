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
    int n;
    cin>>n;
    vector<int> a(n),tmp(n);
    rep(i,n)cin>>a[i];
    int tmp2=a[0];
    ll sum=0;
    rep(i,n-1){
        tmp2=tmp2^a[i+1];
        sum+=tmp2;
        tmp[i]=tmp2;
    }
    ll cnt=0;
    for (int i = n-2; i > 0; i--){
        for (int j = 0; j < i; j++){
            int x=j+1+cnt;
            tmp2=tmp[j+1+cnt]^a[cnt];
            sum+=tmp2;
            tmp[j+1+cnt]=tmp2;
        }
        cnt++;
    }
    cout<<sum;

}