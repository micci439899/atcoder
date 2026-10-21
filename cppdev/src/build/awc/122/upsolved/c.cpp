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

const int INF = 1<<30;

void solve(){
  int n, m, q; cin >> n >> m >> q;

  vector<vector<int>> g(n);
  rep(i, m){
    int u, v; cin >> u >> v; u--; v--;
    g.at(u).push_back(v);
  }

  // vector<vector<int>> dist(n, vector<int>(n, INF));
  // rep(i, n){
  //   dist.at(i).at(i) = 0;
  // }
  vector<int> max_dist(n, 0);

  rep(i, n){
    vector<int> dist(n, INF);
    dist.at(i) = 0;
    queue<pii> que;
    que.push({i, 0});

    while(!que.empty()){
      auto [u, d] = que.front(); que.pop();

      for(int v : g.at(u)){
        // if(chmin(dist.at(i).at(v), d+1)){
        if(chmin(dist.at(v), d+1)){
          que.push({v, d+1});
        }
      }
    }

    int ma = *max_element(dist.begin(), dist.end());
    max_dist.at(i) = ma;
  }

  // rep(i, n){
  //   int ma = 0;
  //   rep(j, n){
  //     chmax(ma, dist.at(j).at(i));
  //   }
  //   max_dist.at(i) = ma;
  // }
  // debug(dist);
  // debug(max_dist);

  sort(max_dist.begin(), max_dist.end());

  while(q--){
    int k; cin >> k;

    // ll ans = 0;
    // rep(i, n){
    //   ll idx = upper_bound(dist.at(i).begin(), dist.at(i).end(), k) - dist.at(i).begin();
    //   if(idx > n-1)ans++;
    // }
    int ans = upper_bound(max_dist.begin(), max_dist.end(), k) - max_dist.begin();
    cout << ans << endl;
  }
}



int main() {

  solve();

  return 0;
}
