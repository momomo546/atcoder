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

int cnt=0;
vector<pair<int,int>> p;

void MergeSort(vector<int> &a, int left, int right) {
    if (right - left == 1) return;
    int mid = left + (right - left) / 2;

    // 左半分 [left, mid) をソート
    MergeSort(a, left, mid);

    // 右半分 [mid, right) をソート
    MergeSort(a, mid, right);

    // 一旦「左」と「右」のソート結果をコピーしておく (右側は左右反転)
    vector<int> buf;
    for (int i = left; i < mid; ++i) buf.push_back(a[i]);
    for (int i = right-1; i >= mid; --i) buf.push_back(a[i]);

    // マージする
    int iterator_left = 0;                    // 左側のイテレータ
    int iterator_right = (int)buf.size() - 1; // 右側のイテレータ
    for (int i = left; i < right; ++i) {
        // 左側採用
        if (buf[iterator_left] <= buf[iterator_right]) {
            if(a[i] != buf[iterator_left]){
                cnt++;
                p.push_back(make_pair(a[i],buf[iterator_left]));
            }
            a[i] = buf[iterator_left++];
        }
        // 右側採用
        else {
            if(a[i] != buf[iterator_right]){
                cnt++;
                p.push_back(make_pair(a[i],buf[iterator_right]));
            }
            a[i] = buf[iterator_right--];
        }
    }
}

int main()
{
    int n;
    cin>>n;
    vector<int> a(n);
    rep(i,n){
        cin>>a[i];
    }
    MergeSort(a, 0, n);
    cout<<cnt<<"\n";
    for(const auto& e:p){
        cout<<e.first<<" "<<e.second<<"\n";
    }
}