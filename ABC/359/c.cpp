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
    ll s1,s2;
    ll t1,t2;
    cin>>s1>>s2;
    cin>>t1>>t2;
    ll ans=0;
    ans+=abs(s2-t2);
    if(s1%2==0&&s2%2==0||s1%2==1&&s2%2==1){
        if(s1<t1){
            if(abs(s2-t2)<abs(s1-t1)+1){
                ans+=(abs(s1-t1)-abs(s2-t2))/2;
            }
        }
        else{
            if(abs(s2-t2)<abs(s1-t1)){
                ans+=(abs(s1-t1)-abs(s2-t2)+1)/2;
            }
        }
    }
    else{
        if(s1<t1){
            if(abs(s2-t2)<abs(s1-t1)){
                ans+=(abs(s1-t1)-abs(s2-t2)+1)/2;
            }
        }
        else{
            if(abs(s2-t2)<abs(s1-t1)+1){
                ans+=(abs(s1-t1)-abs(s2-t2))/2;
            }
        }
    }
    cout<<ans;
}