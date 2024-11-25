#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)

constexpr ll INF = 1LL << 60;
constexpr ll MOD = 998244353;

ll gcd(ll a, ll b) { return a ? gcd(b % a, a) : b; } // b > a
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

int main()
{
    ll n;
    cin >> n;
    map<ll, ll> map;
    ll count = 0;
    rep(i, n)
    {
        ll a;
        cin >> a;
        if (a == 0) count++;
        else{
            for (ll j = 2; j * j <= a; j++){
                while (a % (j * j) == 0) a /= (j * j);
            }
            if (map.find(a) != map.end()) map[a] = map[a] + 1;
            else map[a] = 1;
        }
    }
    ll ans = 0;
    for (const auto &e : map){
        if(e.second > 1) ans += e.second * (e.second - 1) / 2;
    }
    if(count!=0) {
        ans+=count*(n-1);
        ans-=count*(count-1)/2;
    }
    cout<<ans<<endl;
}
