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

int flag = 1;
struct Seg{
    vector<ll> t;
    void build(int n){
        for(; flag < n; flag <<= 1);
        t.resize(flag << 1);
        rep(i, n) cin >> t[i + flag];
        for(int i = flag - 1; i >= 1; i--){
            t[i] = t[i << 1] + t[i << 1 | 1];
        }
    }
    void update(int p, ll value){
        t[p += flag - 1] = value;
        for(; p > 1; p >>= 1) t[p >> 1] = t[p] + t[p ^ 1];
    }
    ll query(int l, int r, int n = 1, int nl = 1, int nr = flag){
        if(nr < l || r < nl) return 0;
        if(l <= nl && nr <= r) return t[n];
        int mid = (nl + nr) / 2;
        return query(l, r, n << 1, nl, mid) + query(l, r, n << 1 | 1, mid + 1, nr);
    }
};
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, q; cin >> n >> q;
    Seg seg; seg.build(n);
    while(q--){
        int tp; cin >> tp;
        if(tp == 1){
            ll a, b; cin >> a >> b;
            seg.update(a, b);
        }
        else if(tp == 2){
            int a, b; cin >> a >> b;
            cout << seg.query(a, b) << '\n';
        }
    }
}