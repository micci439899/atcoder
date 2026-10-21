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

ll cross_product(const pair<long long, long long> &a, const pair<long long, long long> &b){
  return a.first * b.second - a.second * b.first;
}
ll cross_product(const pair<long long, long long> &o, const pair<long long, long long> &a, const pair<long long, long long> &b){
  return (o.first - a.first) * (o.second - b.second) - (o.second - a.second) * (o.first - b.first);
}


// 凸包アルゴリズム
// monotone chain
// 下記参考
// https://en.wikibooks.org/wiki/Algorithm_Implementation/Geometry/Convex_hull/Monotone_chain
vector<pair<long long, long long>> convex_hull(vector<pair<long long, long long>> p){
  int n = p.size();

  vector<pair<long long, long long>> res(2*n);

  sort(p.begin(), p.end());

  // lower hull
  int k = 0;
  for(int i = 0; i < n; i++){
    while(
      k >= 2
      && cross_product(res.at(k-2), res.at(k-1), p.at(i)) <= 0
    ){
      res.pop_back();
      k--;
    }
    res.at(k) = p.at(i);
    k++;
  }

  // upper hull
  int t = k + 1;
  for(int i = n-2; i >= 0; i--){
    while(
      k >= t
      && cross_product(res.at(k-2), res.at(k-1), p.at(i)) <= 0
    ){
      res.pop_back();
      k--;
    }
    res.at(k) = p.at(i);
    k++;
  }

  res.pop_back();
  k--;
  res.resize(k);
  return res;
}


void solve(){
  int n; cin >> n;

  vector<pll> xy(n);
  rep(i, n){
    ll x, y; cin >> x >> y;
    xy.at(i) = {x, y};
  }

  vector<pll> hull = convex_hull(xy);

  ll ans = 0;
  int k = hull.size();
  // debug(hull);
  rep(i, k){
    ans += cross_product({0LL, 0LL}, hull.at(i), hull.at((i+1)%k));
    // debug(ans);
  }
  cout << ans << endl;
}

int main() {

  solve();

  return 0;
}