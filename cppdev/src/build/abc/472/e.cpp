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


/*
vector<vector<pll>> g;
vector<bool> visited;
vector<bool> finished;
vector<pll> history;

ll dfs(pll v){
  visited.at(v) = true;
  history.push_back(v);
  for(pll p : g.at(v)){
    auto [from, to] = p;
    if(v == from) continue;
    if(finished.at(to)) continue;
    if(visited.at(to) && finished.at(to)){
      history.push_back(p);
      return to;
    }

    ll pos = dfs(to)
  }
}
*/


// https://drken1215.hatenablog.com/entry/2023/05/20/200517
// 辺を表す構造体
template<class T> struct Edge {
    int from, to;
    T val;
    Edge(int f = -1, int t = -1, T v = -1) : from(f), to(t), val(v) {}
};

// グラフを表す型
template<class T> using Graph = vector<vector<Edge<T>>>;

// サイクル検出ソルバー
template<class T> struct CycleDetection {
    // 入力されたグラフ
    Graph<T> G;
    
    // 探索の様子
    vector<bool> seen, finished;
    vector<Edge<T>> history;
    
    // コンストラクタ
    CycleDetection() { }
    CycleDetection(const Graph<T> &graph) { init(graph); }
    void init(const Graph<T> &graph) {
        G = graph;
        seen.assign(G.size(), false);
        finished.assign(G.size(), false);
    }
    
    // サイクル検出
    // return the vertex where cycle is detected
    int dfs(int v, const Edge<T> &e, bool is_prohibit_reverse = true) {
        seen[v] = true;    // 行きがけ時に true になる
        history.push_back(e);    // 履歴を残す
        for (const Edge<T> &e2 : G[v]) {
            // 逆流を禁止する場合は逆流を禁止する
            if (is_prohibit_reverse && e2.to == e.from) continue;
            
            // 頂点 v2 がすでに探索済みの場合はスキップ
            if (finished[e2.to]) continue;

            // サイクルが検出された
            if (seen[e2.to] && !finished[e2.to]) {
                history.push_back(e2);
                return e2.to;
            }

            // 頂点 v2 を再帰的に探索する
            int pos = dfs(e2.to, e2, is_prohibit_reverse);
            if (pos != -1) return pos;
        }
        finished[v] = true;    // 帰りがけ時に true になる
        history.pop_back();    // 探索が完全に終了した頂点 (赤色) は履歴から除去する
        return -1;
    }
    
    // 履歴からサイクルのみを抽出する関数 (pos：サイクルを検出した頂点)
    vector<Edge<T>> reconstruct(int pos) {
        vector<Edge<T>> cycle;
        
        // 履歴を遡ってサイクルを形作る
        while (!history.empty()) {
            const Edge<T> &e = history.back();
            cycle.push_back(e);
            history.pop_back();
            if (e.from == pos) break;
        }
        
        // サイクルの向きを正順にする
        reverse(cycle.begin(), cycle.end());
        return cycle;
    }
    
    // サイクルを返す関数 (is_prohibit_reverse は逆流を許さないかどうか)
    vector<Edge<T>> detect(bool is_prohibit_reverse = true) {
        int pos = -1;
        for (int v = 0; v < (int)G.size() && pos == -1; ++v) {
            if (seen[v]) continue;
            history.clear();
            pos = dfs(v, Edge<T>(), is_prohibit_reverse);
            // if (pos != -1) return reconstruct(pos);
            if (pos != -1){
              vector<Edge<T>> cycle = reconstruct(pos);
              if(cycle.size() >= 3 && cycle.size()%2==1){
                return cycle;
              }
            } 
        }
        return vector<Edge<T>>();
    }
};

void testcase(){
  int n, m; cin >> n >> m;

  Graph<int> g(n);

  rep(i, m){
    int a, b; cin >> a >> b;
    a--; b--;
    g.at(a).push_back({a, b, i});
    g.at(b).push_back({b, a, i});
  }

  CycleDetection<int> cd(g);
  const vector<Edge<int>> &res = cd.detect(true);

  if(res.empty()){
    cout << -1 << endl;
  }else{
    cout << res.size() << endl;
    int idx = 0;
    for(const Edge<int> &e : res){
      if(idx) cout << " ";
      cout << e.val + 1;
      idx++;
    }
    cout << endl;
  }

}

void solve(){
  int t; cin >> t;
  while(t--){
    testcase();
  }
}

int main() {

  solve();

  return 0;
}