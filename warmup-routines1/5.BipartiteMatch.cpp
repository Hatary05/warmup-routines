#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define rep(i, n) for(int i = 0; i < n; i++)
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define compress(x) (x).erase(unique(all(x)), x.end())
#define fr first
#define sc second

int n, m;
const int MAXN = 101010;
int A[MAXN], B[MAXN];
vector<int> adj[MAXN];
bool visited[MAXN];
bool dfs(int a){
    visited[a] = true;
    for(auto b : adj[a]){
        if(B[b] == -1 || (!visited[B[b]] && dfs(B[b]))){
            A[a] = b; B[b] = a;
            return true;
        }
    }
    return false;
}
int match(){
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        memset(visited, 0, sizeof(visited));
        if(dfs(i)) cnt++;
    }
    return cnt;
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        int q; cin >> q;
        while(q--){
            int x; cin >> x;
            adj[i].push_back(x);
        }
    }
    memset(A, -1, sizeof(A));
    memset(B, -1, sizeof(B));
    cout << match();
}