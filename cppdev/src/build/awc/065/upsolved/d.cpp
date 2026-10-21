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

const ll RC_MAX = 2001;

// 45度回転後の範囲を非負に
const ll offset = 1000;

void solve(){
  ll n, m; cin >> n >> m;

  vector<vector<ll>> grid(RC_MAX, vector<ll>(RC_MAX, 0));
  rep(i, n){
    ll x, y, c; cin >> x >> y >> c;
    ll u = x + y;
    ll v = x - y + offset;
    grid.at(u).at(v) += c;
  }

/*
  cout << "converted" << endl;
  // for(int i = 0 + offset; i < 5 + offset; i++){
  for(int i = 0; i < 5; i++){
    for(int j = 0 + offset; j < 5 + offset; j++){
      if(j) cout << " ";
      cout << grid.at(i).at(j);
    }
    cout << endl;
  }
  cout << endl;
*/
  
  vector<vector<ll>> cum_grid(RC_MAX+1, vector<ll>(RC_MAX+1, 0));
  // cum_grid.at(1).at(0) = grid.at(0).at(0);
  // cum_grid.at(0).at(1) = grid.at(0).at(0);
  rep(i, RC_MAX)rep(j, RC_MAX){
    // if(i == 1001 && j == 1001){
    // if(grid.at(i).at(j) == 10){
    //   debug(i);
    //   debug(j);
    //   debug(cum_grid.at(i+1).at(j));
    //   debug(cum_grid.at(i).at(j+1));
    //   debug(cum_grid.at(i).at(j));
    //   debug(grid.at(i).at(j));
    // }
    cum_grid.at(i+1).at(j+1) = cum_grid.at(i+1).at(j) + cum_grid.at(i).at(j+1) - cum_grid.at(i).at(j) + grid.at(i).at(j);
  }

/*
  cout << "cum" << endl;
  for(int i = 0; i < 6; i++){
    for(int j = -1 + offset; j < 6 + offset; j++){
      if(j) cout << " ";
      cout << cum_grid.at(i).at(j);
    }
    cout << endl;
  }
  cout << endl;
*/

  rep(i, m){
    ll p, q, k; cin >> p >> q >> k;
    ll u = p + q;
    ll v = p - q + offset;

    ll lx = max(0LL, u-k);
    ll rx = min(2000LL, u+k);
    ll ly = max(0LL, v-k);
    ll ry = min(2000LL, v+k);

    ll ans = cum_grid.at(rx+1).at(ry+1) - cum_grid.at(lx).at(ry+1) - cum_grid.at(rx+1).at(ly) + cum_grid.at(lx).at(ly);
    cout << ans << endl;
  }


}

int main() {

  solve();

  return 0;
}
