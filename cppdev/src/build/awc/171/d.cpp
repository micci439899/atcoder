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

const ll INFL = 1LL<<60;

vector<int> dx = {1, 0, -1, 0};
vector<int> dy = {0, 1, 0, -1};

void solve(){
  int h, w; cin >> h >> w;

  vector<vector<int>> a(h, vector<int>(w));
  rep(i, h)rep(j, w) cin >> a.at(i).at(j);

  vector<vector<ll>> dist(2, vector<ll>(h*w, INFL));
  dist.at(0).at(0) = 0;
  dist.at(1).at(0) = 0;

  queue<tuple<ll, bool, ll>> que;
  que.push({0, true, 0});
  que.push({0, false, 0});

  auto to_1d = [&](int i, int j){
    return i*w + j;
  };
  auto to_2d = [&](int x) -> pii {
    int i = x/w;
    int j = x%w;
    return {i, j};
  };
  auto is_within = [&](int i, int j){
    if(i < 0 || h-1 < i) return false;
    if(j < 0 || w-1 < j) return false;
    return true;
  };

  while(!que.empty()){
    auto [idx, is_h, d] = que.front(); que.pop();

    rep(k, 4){
      if(is_h && k%2==0) continue;
      if(!is_h && k%2!=0) continue;
      auto [i, j] = to_2d(idx);
      int ni = i + dy.at(k);
      int nj = j + dx.at(k);
      // debug(i);
      // debug(j);
      // debug(ni);
      // debug(nj);
      ll n_idx = to_1d(ni, nj);

      if(!is_within(ni, nj)) continue;
      if(a.at(ni).at(nj)) continue;
      if(chmin(dist.at(is_h).at(n_idx), d+1)){
        que.push({n_idx, !is_h, d+1});
      }
    }
  }

  // debug(dist);

  ll ans = min(dist.at(0).at(h*w-1), dist.at(1).at(h*w-1));
  if(ans == INFL){
    cout<< "NONE" << endl;
  }else{
    cout << ans << endl;
  }
/*
*/
}

int main() {

  solve();

  return 0;
}
