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

struct point{
    int x, y;
    bool operator<(const point& rhs) const{
        return (x ^ rhs.x) ? x < rhs.x : y < rhs.y;
    }
};
ll ccw(point a, point b, point c){
    ll ret = (b.x - a.x) * (c.y - a.y);
    ret -= (b.y - a.y) * (c.x - a.x);
    return ret;
}

int n;
vector<point> p;
vector<int> uh, dh;
void chain(){
    sort(all(p));
    dh.push_back(0); dh.push_back(1);
    for(int c = 2; c < n; c++){
        while(sz(dh) >= 2){
            int b = dh.back(); dh.pop_back();
            int a = dh.back();
            if(ccw(p[a], p[b], p[c]) > 0){
                dh.push_back(b); break;
            }
        }
        dh.push_back(c);
    }

    uh.push_back(n - 1); uh.push_back(n - 2);
    for(int c = n - 3; c >= 0; c--){
        while(sz(uh) >= 2){
            int b = uh.back(); uh.pop_back();
            int a = uh.back();
            if(ccw(p[a], p[b], p[c]) > 0){
                uh.push_back(b); break;
            }
        }
        dh.push_back(c);
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n;
    rep(_, n){
        int x, y; cin >> x >> y;
        p.push_back({x, y});
    }
    chain();
    cout << sz(uh) + sz(dh) -2;
}