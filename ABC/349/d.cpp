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
    ll l,r;
    cin >> l >> r;
    ll cnt=0,tmp=r-l,two=2;
    bool flag=false;
    if(l==0||l==2)flag=true;
    while(tmp>two){
        cnt++;
        two*=2;
        if(l==two)flag=true;
    }
    vector<pair<ll,ll>> ans;

    ll tmp3=1;
    while(two!=0){
        ll tmp2=l+two-l%two;
        tmp3=(flag)?0:tmp2/two;
        if((tmp3+1)*two>r)two/=2;
        else {
            ans.push_back(make_pair(tmp3*two,(tmp3+1)*two));
            break;
        }
    }

    ll tmp_two=two;
    ll l2=tmp3+1;
    while(tmp_two!=0){
        tmp_two/=2;
        while(tmp_two!=0){
            l2*=2;
            if((l2+1)*tmp_two>r)tmp_two/=2;
            else {
                ans.push_back(make_pair(l2*tmp_two,(l2+1)*tmp_two));
                break;
            }
        }
        l2++;
    }

    tmp_two=two;
    ll r2=tmp3;
    while(tmp_two!=0){
        tmp_two/=2;
        while(tmp_two!=0){
            r2*=2;
            if((r2-1)*tmp_two<l)tmp_two/=2;
            else {
                ans.push_back(make_pair((r2-1)*tmp_two,r2*tmp_two));
                break;
            }
        }
        r2--;
    }
    sort(ans.begin(),ans.end(),[](auto i,auto j){return i.first<j.first;});
    cout << ans.size()<<"\n";
    rep(i,ans.size()){
        cout<<ans[i].first<<" "<<ans[i].second<<"\n";
    }
}