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

void solve(){
  int n, m, q; cin >> n >> m >> q;

  vector<vector<int>> g(n);
  rep(i, m){
    int u, v; cin >> u >> v; u--; v--;
    g.at(u).push_back(v);
  }

  while(q--){
    int k; cin >> k;

    int ans = 0;

    // 最初の生徒
    rep(i, n){
      // vector<bool> visited(n, false);
      // visited.at(i) = true;
      set<int> visited;
      visited.insert(i);

      set<int> cur_step;
      cur_step.insert(i);

      set<int> nxt_step;

      int kk = k;

      while(kk--){
        for(auto v : cur_step){
          for(auto u : g.at(v)){
            nxt_step.insert(u);
            // visited.at(v) = true;
            visited.insert(u);
          }
        }
        // debug(cur_step);
        // debug(nxt_step);
        if(visited.size() == n) break;
        cur_step = nxt_step;
        nxt_step.clear();
      }
      if(visited.size() == n) ans++;
    }

    cout << ans << endl;
  }


}



int main() {

  solve();

  return 0;
}
