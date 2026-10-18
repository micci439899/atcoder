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

//https://qiita.com/tqk/items/7c4df1eeb5ebaedcf714
struct PairHash {
  inline size_t operator()(const pair<long long, long long> &p) const{
    const auto h1 = hash<long long>()(p.first);
    const auto h2 = hash<long long>()(p.second);
    return h1 ^ (h2 << 1);
  }
};

// 傾き（slope, gradient）
pll grad(pll p1, pll p2){
  ll dx = p1.first - p2.first;
  ll dy = p1.second - p2.second;

  if(dx == 0){
    dx = 0;
    dy = 1;
  }else if(dy == 0){
    dx = 1;
    dy = 0;
  }else{
    if(dx < 0){
      dx *= -1;
      dy *= -1;
    }
    ll g = gcd(abs(dx), abs(dy));
    dx /= g;
    dy /= g;
  }
  return {dx, dy};
}

void solve(){
  ll n; cin >> n;

  vector<pll> xy(n);
  rep(i, n){
    ll x, y; cin >> x >> y;
    xy.at(i) = {x, y};
  }

  unordered_map<pll, ll, PairHash> grad_mp;
  unordered_map<pll, ll, PairHash> center_mp;
  rep(i, n){
    for(int j = i+1; j < n; j++){
      pll g = grad(xy.at(i), xy.at(j));
      grad_mp[g]++;

      pll c = {xy.at(i).first + xy.at(j).first, xy.at(i).second + xy.at(j).second};
      center_mp[c]++;
    }
  }

  ll ans = 0;
  for(auto p : grad_mp) ans += p.second*(p.second-1)/2;
  for(auto p : center_mp) ans -= p.second*(p.second-1)/2;
  cout << ans << endl;
}

int main() {

  solve();

  return 0;
}