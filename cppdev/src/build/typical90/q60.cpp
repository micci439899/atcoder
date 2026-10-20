#include <bits/stdc++.h>
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
template<class T>ostream&operator<<(ostream&os, const multiset<T>&st){os<<"{";int idx=0;for(auto &e : st){cout << e;if(idx != st.size()-1){cout << ",";}idx++;}os<<"}";return os;}
template<class T, class U>ostream&operator<<(ostream&os, map<T,U>mp){os<<"{";int idx=0;for(auto p : mp){cout << p;if(idx != mp.size()-1){cout << ",";}idx++;}os<<"}";return os;}

template<class T> void out_vec(vector<T> &v){for(int i=0;i<(int)v.size();i++){cout<<v.at(i)<<" ";}cout<<endl;}
template<class T> void out_vec2d(vector<vector<T>> &v){for(int i=0;i<(int)v.size();i++){for(int j=0;j<(int)v.at(i).size();j++){cout<<v.at(i).at(j)<<" ";}cout<<endl;}}
void out_yn(bool b){if(b){cout << "Yes" << endl;}else{cout << "No" << endl;}}
int ctoi(char c){return int(c-'0');} // e.g.) a -> 49, 1 -> 1
char itoc(int x){return x+'0';}

const ll INFL = 1LL<<60;

void solve(){
  int n; cin >> n;

  vector<ll> a(n);
  rep(i, n) cin >> a.at(i);

  vector<ll> dp_l(n, INFL);
  vector<ll> pos_l(n, -1);
  rep(i, n){
    int idx = lower_bound(dp_l.begin(), dp_l.end(), a.at(i)) - dp_l.begin();
    dp_l.at(idx) = a.at(i);
    pos_l.at(i) = idx+1;
  }

  vector<ll> rev_a = a;
  reverse(rev_a.begin(), rev_a.end());

  vector<ll> dp_r(n, INFL);
  vector<ll> pos_r(n, -1);
  rep(i, n){
    int idx = lower_bound(dp_r.begin(), dp_r.end(), rev_a.at(i)) - dp_r.begin();
    dp_r.at(idx) = rev_a.at(i);
    pos_r.at(i) = idx+1;
  }

  reverse(pos_r.begin(), pos_r.end());

  ll ans = 0;
  rep(i, n){
    ans = max(ans, pos_l.at(i)+pos_r.at(i)-1);
  }
  cout << ans << endl;
}

int main() {

  solve();

  return 0;
}
