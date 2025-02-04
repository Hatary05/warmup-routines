#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define compress(x) (x).erase(unique(all(x)), x.end())
#define fr first
#define sc second

const int MAXN = 101010;
vector<int> adj[MAXN];
int id = 0, d[MAXN], sid[MAXN];
bool done[MAXN];
stack<int> st;
vector<vector<int>> SCC;
vector<int> g[MAXN];
int dfs(int cur){
    int par = d[cur] = ++id;
    st.push(cur);
    for(auto nxt : adj[cur]){
        if(d[nxt] == 0) par = min(par, dfs(nxt));
        else if(!done[nxt]) par = min(par, d[nxt]);
    }
    if(par == d[cur]){
        vector<int> scc;
        while(true){
            int t = st.top(); st.pop();
            scc.push_back(t);
            sid[t] = sz(SCC);
            done[t] = true;
            if(t == cur) break;
        }
        sort(all(scc));
        SCC.push_back(scc);
    }
    return par;
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int v, e; cin >> v >> e;
    rep(_, e){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
    }
    for(int i = 1; i <= v; i++){
        if(d[i] == 0) dfs(i);
    }

    set<pii> ved; //visited edge
    for(int i = 1; i <= v; i++){
        for(auto nxt : adj[i]){
            int u = sid[i], v = sid[nxt];
            if(u == v || ved.count({u, v})) continue;
            g[u].push_back(v);
            ved.insert({u, v});
        }
    }
    
    int n = sz(SCC);
    cout << n << '\n';
    rep(i, n){
        cout << i << " : ";
        for(auto op : g[i]) cout << op << ' ';
        cout << '\n';
    }
    return 0;
}