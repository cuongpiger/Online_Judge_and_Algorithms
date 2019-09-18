#pragma warning(disable:4996)
#include <iostream>
#include <cstdint>
#include <algorithm>
#include <functional>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <cmath>
#include <iomanip>
#include <sstream>
#include <unordered_set>
#include <unordered_map>
using namespace std;

//==========================================================================================================================
#define pw(a) ((a) * (a))
#define vit vector<int>::iterator
#define sit set<int>::iterator
#define dqit deque<int>::iterator
#define FILE_IO freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL), cout.tie(NULL)
#define sortRev greater<int>()
const double pi = 3.14159265359;
const long long mod = 1e9 + 7;
typedef uint64_t uit;
typedef long long ll;
typedef long long int lli;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<double, int> pdi;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<ll, ll> p2ll;
typedef pair<string, int> psi;
typedef pair<ld, ld> p2ld;
typedef pair<char, char> pcc;
typedef pair<ll, string> plls;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<string> vstr;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pdi> vpdi;
typedef vector<p2ll> vp2ll;
typedef vector<vector<int>> vvi;
typedef vector<vector<bool>> vvb;
typedef vector<vector<char>> vvc;
typedef vector<vector<long long>> vvll;
typedef vector<vector<pii>> vvpii;
typedef vector<vector<vector<int>>> vvvi;
typedef deque<int> dqi;
typedef queue<int> qi;
typedef queue<pii> qpii;
int GCD(int a, int b) { return !b ? a : GCD(b, a % b); }
inline double DIST(const pii& a, const pii& b) { return sqrt(pw((double)(a.first - b.first)) + pw((double)(a.second - b.second))); }
inline int DEC(char x) { return (int)(x - '0'); }
//==========================================================================================================================

//https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2968
/**
** Comment **
**/

#define x first
#define y second
#define post first
#define cost second

vvpii direct = { { {0, 1}, {1, 1}, {1, 0} } , { {0, 1}, {1, 1}, {1, 0}, {1, -1} },{ {1, 0}, {1, -1} } };
int mp[100010][3];

inline bool canGo(pii pos, int n) {
	if (pos.x < 0 || pos.x >= n || pos.y < 0 || pos.y >= 3) {
		return false;
	}
	return true;
}

inline int LCBFS(int n, pii src, pii des) {
	vvi cos(n, vi(3, 696969696));
	vvb vs(n, vb(3, false));
	queue<pair<pii, int>> q;

	cos[src.x][src.y] = mp[src.x][src.y];
	vs[src.x][src.y] = true;
	q.push({ src, mp[src.x][src.y] });

	while (!q.empty()) {
		pair<pii, int> u = q.front();
		q.pop();

		for (int i = 0; i < direct[u.post.y].size(); ++i) {
			pii next = { u.post.x + direct[u.post.y][i].x, u.post.y + direct[u.post.y][i].y };

			if (canGo(next, n)) {
				int neighborCost = mp[next.x][next.y];

				if (!vs[next.x][next.y] || cos[next.x][next.y] > cos[u.post.x][u.post.y] + neighborCost) {
					cos[next.x][next.y] = cos[u.post.x][u.post.y] + neighborCost;
					vs[next.x][next.y] = true;
					q.push({ next,  cos[next.x][next.y] });
				}
			}
		}
	}

	return cos[des.x][des.y];
}

int main() {
	FAST_IO;
	//freopen("output.txt", "w", stdout);

	int n, cs = 1;
	while (cin >> n && n) {
		for (int i = 0; i < n; ++i) {
			cin >> mp[i][0] >> mp[i][1] >> mp[i][2];
		}

		int res = LCBFS(n, { 0, 1 }, { n - 1, 1 });
		cout << cs++ << ". " << res << endl;
	}

	return 0;
}