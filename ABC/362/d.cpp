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

// 辺の情報
struct Edge
{
	// 行先
	int to;

	// コスト
	ll cost;
};

using Graph = vector<vector<Edge>>;

// { distance, from }
using Pair = pair<ll, int>;

// ダイクストラ法 (1.1 基本実装)
// distances は頂点数と同じサイズ, 全要素 INF で初期化しておく
void Dijkstra(const Graph& graph, vector<ll>& distances, int startIndex, vector<long long>& a)
{
	// 「現時点での最短距離, 頂点」の順に取り出す priority_queue
	// デフォルトの priority_queue は降順に取り出すため std::greater を使う
	priority_queue<Pair, vector<Pair>, greater<Pair>> q;
	q.emplace((distances[startIndex] = 0), startIndex);

	while (!q.empty())
	{
		const long long distance = q.top().first;
		const int from = q.top().second;
		q.pop();

		// 最短距離でなければ処理しない
		if (distances[from] < distance)
		{
			continue;
		}

		// 現在の頂点からの各辺について
		for (const auto& edge : graph[from])
		{
			// to までの新しい距離
			const long long d = (distances[from] + edge.cost + a[edge.to]);

			// d が現在の記録より小さければ更新
			if (d < distances[edge.to])
			{
				q.emplace((distances[edge.to] = d), edge.to);
			}
		}
	}
}

int main()
{
    ll n,m;
    cin>>n>>m;
    vector<ll> a(n),u(m),v(m),b(m);
    Graph g(n);
    rep(i,n){
        cin>>a[i];
    }
    rep1(i,m){
        int from,to,weight;
        cin>>from>>to>>weight;
        Edge e{to-1, weight},e2{from-1, weight};
        g[from-1].push_back(e);
        g[to-1].push_back(e2);
    }
    vector<ll> dist(n,INF);

    Dijkstra(g,dist,0,a);
    
    rep(i,n-1){
        cout<<dist[i+1]+a[0]<<" ";
    }
}