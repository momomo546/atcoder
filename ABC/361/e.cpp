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

struct Edge
{
	int from;
	int to;
	int cost;
};

// ベルマンフォード法 (1.3 最短経路を再構築する)
// 負の閉路が存在する場合 true を返し, 負閉路の影響を受ける頂点は -INF にセットされる
// 頂点 targetIndex が負閉路の影響を受けない場合, 頂点 startIndex からの最短経路を path に格納する
// distances は頂点数と同じサイズ, 全要素 INF で初期化しておく
bool BellmanFord(const std::vector<Edge>& edges, std::vector<long long>& distances, int startIndex, int targetIndex, std::vector<int>& path)
{
	distances[startIndex] = 0;
	// 直前の頂点を記録する配列
	std::vector<int> p(distances.size(), -1);
	bool changed = false;

	for (size_t i = 0; i < distances.size(); ++i)
	{
		changed = false;
		// 各辺について
		for (const auto& edge : edges)
		{
			// (INF + cost) は INF なので処理しない
			if (distances[edge.from] == INF)
			{
				continue;
			}
			// to までの新しい距離
			const long long d = (distances[edge.from] + edge.cost);
			// d が現在の記録より小さければ更新
			if (d < distances[edge.to])
			{
				distances[edge.to] = d;
				// 直前の頂点を記録
				p[edge.to] = edge.from;
				changed = true;
			}
		}
		// どの頂点も更新されなかったら終了
		if (!changed)
		{
			break;
		}
	}

	if (changed) // 負閉路あり
	{
		// 頂点数分だけさらに繰り返し, 負閉路の影響を受ける頂点に -INF を伝播
		for (size_t i = 0; i < distances.size(); ++i)
		{
			for (const auto& edge : edges)
			{
				if (distances[edge.from] == INF)
				{
					continue;
				}

				const long long d = (distances[edge.from] + edge.cost);

				if (d < distances[edge.to])
				{
					// 負閉路の影響を受ける頂点を -INF に
					distances[edge.to] = -INF;
				}
			}
		}
	}

	if ((distances[targetIndex] != INF)
		&& (distances[targetIndex] != -INF)) // 頂点 targetIndex に到達不可または負閉路が影響する場合は最短経路無し
	{
		// 経路を再構築
		for (int i = targetIndex; i != -1; i = p[i])
		{
			path.push_back(i);
		}

		std::reverse(path.begin(), path.end());
	}

	return changed;
}

int main()
{
    ll n;
    cin>>n;
    vector<Edge> e;
    vector<int>path;
    vector<ll> dist(n);
    rep(i,n-1){
        Edge edge;
        cin>>edge.from>>edge.to>>edge.cost;
        e.push_back(edge);
    }
    BellmanFord(e,dist,e[0].from,e[0].to,path);

    ll ans=0;
    rep(i,n){
        ans+=dist[i];
    }
    cout<<ans;
}