# include <bits/stdc++.h>
using namespace std;
using ll = long long;
using uint = unsigned;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<long long, long long>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define debug(x) cerr << #x << " " << x << " " << endl;

template<class T>using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;
template<class T>bool chmax(T&a, T b){if(a<b){a=b;return true;}return false;}
template<class T>bool chmin(T&a, T b){if(b<a){a=b;return true;}return false;}

template<class T, class U>ostream&operator<<(ostream&os, pair<T,U>p){os<<"("<<p.first << "," << p.second<<")";return os;}
template<class T>ostream&operator<<(ostream&os, const vector<T>&v){os<<"[";for(int i = 0; i < v.size(); i++){cout << v.at(i);if(i != v.size()-1){cout << ",";}}os<<"]";return os;}
template<class T>ostream&operator<<(ostream&os, const set<T>&st){os<<"{";int idx=0;for(auto &e : st){cout << e;if(idx != st.size()-1){cout << ",";}idx++;}os<<"}";return os;}
template<class T, class U>ostream&operator<<(ostream&os, map<T,U>mp){os<<"{";int idx=0;for(auto p : mp){cout << p;if(idx != mp.size()-1){cout << ",";}idx++;}os<<"}";return os;}

template<class T> void out_vec(vector<T> &v){for(int i=0;i<(int)v.size();i++){cout<<v.at(i)<<" ";}cout<<endl;}
template<class T> void out_vec2d(vector<vector<T>> &v){for(int i=0;i<(int)v.size();i++){for(int j=0;j<(int)v.at(i).size();j++){cout<<v.at(i).at(j)<<" ";}cout<<endl;}}
void out_yn(bool b){if(b){cout << "Yes" << endl;}else{cout << "No" << endl;}}
int ctoi(char c){return int(c-'0');} // e.g.) a -> 49, 1 -> 1
char itoc(int x){return x+'0';}

// 素集合データ構造（Union-Find）
struct DisjointSetUnion {
  vector<int> parents;
  vector<int> sizes;

  // 初期化子リスト
  DisjointSetUnion(int n) : parents(n, -1), sizes(n, 1) {}

  // xが属しているグループの代表（根）を取得
  int find(int x) {
    if(parents.at(x) == -1) return x;

    // 経路圧縮
    parents.at(x) = find(parents.at(x));
    return parents.at(x);
  }

  // xとyが同じグループに属しているかどうか
  bool is_same(int x, int y) {
    return find(x) == find(y);
  }

  // xが属しているグループとyが属しているグループを併合する
  // xとyが既に同じグループに属しているときfalse、そうでないときtrueを返す
  bool unite(int x, int y) {
    int x_r = find(x);
    int y_r = find(y);

    if(x_r == y_r) return false;

    // union by size（木の深さをなるべく小さくする）
    if(sizes.at(x_r) < sizes.at(y_r)) swap(x_r, y_r);

    parents.at(y_r) = x_r;
    sizes.at(x_r) += sizes.at(y_r);
    return true;
  }

  // xが属しているグループの要素数を返す
  int size(int x) {
    return sizes.at(find(x));
  }
};


void solve(){
  int n, m; cin >> n >> m;

  DisjointSetUnion dsu(n);

  vector<int> flag(n, -1);

  rep(i, m){
    int u, v, c; cin >> u >> v >> c;
    u--; v--;

    if(!dsu.is_same(u, v)){
      dsu.unite(u, v);
    }
    int x = dsu.find(u);
    flag.at(x) = c;
    if(u != x) flag.at(u) = -1;
    if(v != x) flag.at(v) = -1;
    // debug(flag.at(x));
  }

  set<int> st;
  rep(i, n){
    if(dsu.size(i) == 1) continue;
    int x = dsu.find(i);
    // debug(i);
    // debug(x);
    // debug(dsu.size(i));
    // debug(flag.at(x));
    if(flag.at(x) > 0) st.insert(flag.at(x));
  }

  // debug(st);

  cout << st.size() << endl;
}

int main() {

  solve();

  return 0;
}
