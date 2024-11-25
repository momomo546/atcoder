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

string s1="###",s2="#.#",s3="...";

int main()
{
    int n;
    cin>>n;
    if(n==0){
        cout<<"#";
        return 0;
    }
    if(n==1){
        cout<<s1<<"\n";
        cout<<s2<<"\n";
        cout<<s1<<"\n";
        return 0;
    }
    int tmp=3;
    int num=static_cast<int>(pow(3, n));
    vector<string> s(num);
    string bra = s3;
    s[0]+=s1;
    s[1]+=s2;
    s[2]+=s1;
    vector<string> s_tmp(num/3);
    rep(i,n-1){
        
        rep(j,tmp)s_tmp[j]=s[j];
        rep(j,3){
            rep(k,3){
                if(j==0&&k==0)continue;
                if(j==1&&k==1){
                    rep(l,tmp){
                        s[l+tmp]+=bra;
                    }
                }
                else{
                    rep(l,tmp){
                        s[l+tmp*j]+=s_tmp[l];
                    }
                }
            }
        }
        tmp*=3;
        bra=bra+bra+bra;
    }
    
    rep(i,tmp){
        cout<<s[i]<<"\n";
    }
}