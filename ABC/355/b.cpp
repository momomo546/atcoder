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
    int n, m;
    cin>>n>>m;
    vector<int> a(n),b(m);
    set<int> st;
    rep(i,n){
        cin>>a[i];
    }
    rep(i,m){
        cin>>b[i];
        st.insert(b[i]);
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    
    rep(i,n-1){
        if(a[i+1]-a[i]!=1){
            bool flag = false;
            rep(i,a[i+1]-a[i]-1){
                if (st.find(a[i]+i+1) != st.end()) {
                    flag=true;
                    break;
                }
            }
            if(flag==false){
                cout<<"Yes";
                return 0;
            }
        }
        else {
            cout << "Yes";
            return 0;
        }
    }
    cout<<"No";
}