#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define fr first
#define sc second

const int MAXN = 101010;
const int LOG = 18;
vector<int> v[MAXN];
int p[MAXN][LOG], dep[MAXN];
void bfs() {
    queue<int> q; q.push(1);
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (auto nxt : v[cur]) {
            if (nxt == p[cur][0]) continue;

            p[nxt][0] = cur; q.push(nxt);
            dep[nxt] = dep[cur] + 1;
            for (int i = 1; i < LOG; i++) {
                p[nxt][i] = p[p[nxt][i - 1]][i - 1];
                if (p[nxt][i] == 0) break;
            }
        }
    }
}
int lca(int x, int y) {
    if (dep[x] > dep[y]) swap(x, y);
    int dif = dep[y] - dep[x];
    for (int i = LOG - 1; i >= 0; i--) {
        if (dif & (1 << i)) y = p[y][i];
    }
    if (x == y) return x;

    for (int i = LOG - 1; i >= 0; i--) {
        if (p[x][i] != p[y][i]) {
            x = p[x][i];
            y = p[y][i];
        }
    }
    return p[x][0];
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, q; cin >> n >> q;
    rep(_, n - 1) {
        int a, b; cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    bfs();
    while (q--) {
        int a, b; cin >> a >> b;
        cout << lca(a, b) << '\n';
    }
}
