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

const int SIGMA = 256;

int quickSearch(std::string const& p, std::string const& t) {
    const int n = t.size();
    const int m = p.size();
	int cnt=0;

    if (n == 0 || m == 0) {
        return -1;
    }

    int i;

    // Preprocessing phase
    int shift[SIGMA];
    for (i = 0; i < SIGMA; ++i) shift[i] = m + 1;
    for (i = 0; i < m; ++i) shift[p[i]] = m - i;

    // Searching phase
    i = 0;
    while (i <= n - m) {
        int j = 0;
        while (j < m && p[j] == t[i + j]) ++j;
        if (j == m) {
            cnt++;
        }
        i += shift[t[i + m]];
    }
	return cnt;
}

int main()
{
    string s;
    cin>>s;
    int q;
	cin>>q;
	map<string,int> mp;
	rep(i,q){
		string tmp;
		cin>>tmp;
		if(mp[tmp]==0){
			int o=quickSearch(tmp,s);
			cout<<o<<"\n";
			mp[tmp]=o;
		}
		else{
			cout<<mp[tmp]<<"\n";
		}
	}
}