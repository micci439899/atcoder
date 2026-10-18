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
  ll n, q; cin >> n >> q;

  vector<pair<ll, char>> qs(q);
  char last_color = 'a';
  vector<bool> has_tile(n, false);

  rep(i, q){
    int type; cin >> type;
    if(type == 1){
      ll x; cin >> x;
      x--;
      qs.at(i) = {x, 'A'};
      has_tile.at(x) = !has_tile.at(x);
    }else{
      char c; cin >> c;
      qs.at(i) = {-1LL, c};
      last_color = c;
    }
  }

  debug(has_tile);

  string ans = "";
  rep(i, n) ans.push_back('a');


  char cur = last_color;
  vector<bool> fixed(n, false);
  for(int i = q-1; i >= 0; i--){
    auto [x, c] = qs.at(i);

    if(x >= 0){
      // if(has_tile.at(x) && !fixed.at(x)){
      //   ans.at(x) = last_color;
      //   fixed.at(x) = true;
      // }else if(!has_tile.at(x) && !fixed.at(x)){
      //   ans.at(x) = last_color;
      //   fixed.at(x) = true;
      // }
      if(!fixed.at(x)){
        ans.at(x) = cur;
        fixed.at(x) = true;
      }
      has_tile.at(x) = !has_tile.at(x);
    }else{
      cur = c;
    }
  }

  rep(i, n)if(!fixed.at(i)) ans.at(i) = last_color;

  cout << ans << endl;





/*
  vector<bool> has_tile(n, false);
  // vector<pair<ll, char>> color_idx(n);

  vector<pair<ll, char>> qs;

  rep(i, q){
    int type; cin >> type;
    if(type == 1){
      ll x; cin >> x;
      x--;
      has_tile.at(x) = !has_tile.at(x);
      qs.push_back({x, 'A'});
    }else{
      char c; cin >> c;

      qs.push_back({-1LL, c});
    }
  }
  debug(has_tile);

  string ans = "";
  rep(i, n) ans.push_back('a');

  vector<bool> fixed(n, false);
  bool is_last_color = true;
  char last_color = 'a';
  for(int i = q-1; i >= 0; i--){
    auto [x, c] = qs.at(i);

    if('a' <= c && c <= 'z'){
      if(is_last_color){
        last_color = c;
        is_last_color = false;
      }
    }


    if(x >= 0){
      if(fixed.at(x)) continue;
      ans.at(x) = last_color;
      fixed.at(x) = true;
      // if(has_tile.at(x) && !fixed){
      //   fixed.at(x) = true;
      // }
    }
  }
  rep(i, n)if(!fixed.at(i))ans.at(i) = last_color;
  cout << ans << endl;
*/
}

int main() {

  solve();

  return 0;
}
