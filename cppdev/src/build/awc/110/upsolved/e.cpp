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

// Trie木
// 文字種、基準値を与える
template <int char_size, int base>
struct Trie {
  struct Node {
    // baseを基準とした値（0-indexed）
    // e.g.) baseがAのとき、Cは2
    int char_idx;

    // この頂点を通る文字列の数（prefixが一致する数）
    int s_num;

    // 次のNode（のnode_id）
    // 要素数は文字種の数になる
    // 各文字なければ-1となる
    vector<int> next;

    // この文字が終端となる文字列（のword_id）
    vector<int> accept;

    Node(int n_) : char_idx(n_), s_num(0) {
      next.assign(char_size, -1);
    }

    // debug用
    void out() {
      cout << "{ char_idx:" << char_idx << ", s_num:" << s_num << ", next: [";
      for(int i = 0; i < (int)next.size(); i++){
        if(i) cout << " ";
        cout << next.at(i);
      }
      cout << "]";
      cout << ", accept: [";
      for(int i = 0; i < (int)accept.size(); i++){
        if(i) cout << " ";
        cout << accept.at(i);
      }
      cout << "]}";
    }
  };

  // Trie木本体
  vector<Node> nodes;

  int root;
  Trie() : root(0) {
    nodes.push_back(Node(root));
  }

  // 単語挿入
  // word_idは各単語を識別するための番号付け（0-indexed）
  void insert(const string &s, int word_id) {
    // node_idは各Nodeを識別するための番号付け（0-indexed）
    int node_id = 0;
    for(int i = 0; i < (int)s.size(); i++) {
      int c = (int)(s.at(i) - base);

      int &next_id = nodes.at(node_id).next.at(c);

      if(next_id == -1) {
        next_id = nodes.size();
        nodes.push_back(Node(c));
      }
      nodes.at(node_id).s_num++;
      node_id = next_id;
    }
    nodes.at(node_id).s_num++;
    nodes.at(node_id).accept.push_back(word_id);
  }
  void insert(const string &s) {
    insert(s, nodes.at(0).s_num);
  }

  // 検索
  int search(const string &s, bool prefix) {
    int node_id = 0;
    for(int i = 0; i < (int)s.size(); i++) {
      int c = s.at(i) - base;
      int &next_id = nodes.at(node_id).next.at(c);
      if(next_id == -1) {
        return 0;
      }
      node_id = next_id;
    }
    return prefix ? nodes.at(node_id).s_num : nodes.at(node_id).accept.size();
  }

  // 単語そのものを検索
  // あるとき、挿入した個数を返す
  int search_all(const string &s) {
    return search(s, false);
  }
  // sがprefixとなる単語があるか検索
  // あるとき、該当する単語の数を返す
  int search_prefix(const string &s) {
    return search(s, true);
  }
  int search_unique_min_prefix(const string &s) {
    int node_id = 0;
    for(int i = 0; i < (int)s.size(); i++) {
      int c = s.at(i) - base;
      int &next_id = nodes.at(node_id).next.at(c);
      if(next_id == -1) { return -1; }
      if(nodes.at(next_id).s_num == 1) { return i; };
      node_id = next_id;
    }
    return nodes.at(node_id).s_num > 1 ? -1 : s.size();
  }
  int count() {
    return nodes.at(0).s_num;
  }
  int size() {
    return nodes.size();
  }
  // debug用
  void out(){
    cout << "Nodes: [";
    for(int i = 0; i < (int)nodes.size(); i++){
      if(i) cout << " ";
      nodes.at(i).out();
      if(i<(int)nodes.size()-1) cout << ", ";
    }
    cout << "]" << endl;
  }
};


void solve(){
  ll n; cin >> n;

  vector<string> s(n);
  rep(i, n) cin >> s.at(i);

  Trie<26, 'a'> trie;
  rep(i, n){
    trie.insert(s.at(i));
  }

  int ans = 0;
  rep(i, n){
    int num = trie.search_unique_min_prefix(s.at(i));
    if(num == -1){
      cout << -1 << endl;
      return;
    }
    ans += (num+1);
    // string t = "";
    // int prefix_num = -1;
    /*
    rep(j, s.at(i).size()){
      t.push_back(s.at(i).at(j));
      prefix_num = trie.search_prefix(t);
      if(prefix_num == 1) break;
    }
    if(t.size() == s.at(i).size() && prefix_num > 1){
      cout << -1 << endl;
      return;
    }
    ans += t.size();
    */
  }
  cout << ans << endl;

}

int main() {

  solve();

  return 0;
}
