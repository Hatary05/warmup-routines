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

struct Trie{
    struct node{
        bool end = false;
        unordered_map<char, node*> nxt;
    };
    node *st = new node;
    void insert(const string &s){
        node *cur = st;
        for(auto c : s){
            if(!cur->nxt.count(c)) cur->nxt[c] = new node;
            cur = cur->nxt[c];
        }
        cur->end = true;
    }
    bool find(const string &s){
        node *cur = st;
        for(auto c : s){
            if(!cur->nxt.count(c)) return false;
            cur = cur->nxt[c];
        }
        return cur->end;
    }
    void clear(node *cur){
        for(auto &[_, nxt] : cur->nxt) clear(nxt);
        delete cur;
    }
    ~Trie(){clear(st);}
};
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    Trie trie;
    int n, q; cin >> n >> q;
    rep(_, n){
        string s; cin >> s;
        trie.insert(s);
    }
    rep(_, q){
        string s; cin >> s;
        cout << (trie.find(s) ? "Find\n" : "Not Find\n");
    }
}