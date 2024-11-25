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

vector<int> dx={1,0,-1,0},dy={0,1,0,-1};

// { distance, from }
using Pair = pair<ll, pair<int,int>>;

// ダイクストラ法 (1.1 基本実装)
// distances は頂点数と同じサイズ, 全要素 INF で初期化しておく
void Dijkstra(const vector<string>& graph, vector<vector<ll>>& distances, pair<int,int> startIndex,string& color,int n)
{
	// 「現時点での最短距離, 頂点」の順に取り出す priority_queue
	// デフォルトの priority_queue は降順に取り出すため std::greater を使う
	priority_queue<Pair, vector<Pair>, greater<Pair>> q;
	q.emplace((distances[startIndex.first][startIndex.second] = 0), startIndex);

	while (!q.empty())
	{
		const ll distance = q.top().first;
		const pair<int,int> from = q.top().second;
		q.pop();

		// 最短距離でなければ処理しない
		if (distances[from.first][from.second] < distance)
		{
			continue;
		}

		// 現在の頂点からの各辺について
		for (int i = 0;i<4;i++)
		{
            int cost =0;
            int x = from.first+dx[i];
            int y = from.second+dy[i];
            if(x<0||y<0||x>=n||y>=n)continue;
            if(graph[x][y]==color[0]) cost++;
			// to までの新しい距離
			const long long d = (distances[from.first][from.second] + cost);

			// d が現在の記録より小さければ更新
			if (d < distances[x][y])
			{
				//q.emplace((distances[x][y] = d), {x,y});
                q.emplace(make_pair((distances[x][y] = d), make_pair(x,y)));
			}
		}
	}
}

int main()
{
    int n;
    cin>>n;
    vector<string> c(n);
    string b="B",r="R";
    rep(i,n){
        cin>>c[i];
    }
    vector<vector<ll>> dist1(n,vector<ll> (n,INF)),dist2(n,vector<ll> (n,INF));
    Dijkstra(c,dist1,{0,0},b,n);
    Dijkstra(c,dist2,{0,n-1},r,n);
    cout<<dist1[n-1][n-1]+dist2[n-1][0];
}