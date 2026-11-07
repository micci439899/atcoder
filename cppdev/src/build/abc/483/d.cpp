// The template file is below
// https://github.com/micci439899/atcoder

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
template<class T, class U>ostream&operator<<(ostream&os, map<T,U>mp){os<<"{";int idx=0;for(auto p : mp){cout << p.first<<":"<<p.second;if(idx != mp.size()-1){cout << ",";}idx++;}os<<"}";return os;}
template<class T, class U>ostream&operator<<(ostream&os, unordered_map<T,U>mp){os<<"{";int idx=0;for(auto p : mp){cout << p.first<<":"<<p.second;if(idx != mp.size()-1){cout << ",";}idx++;}os<<"}";return os;}

template<class T> void out_vec(vector<T> &v){for(int i=0;i<(int)v.size();i++){cout<<v.at(i)<<" ";}cout<<endl;}
template<class T> void out_vec2d(vector<vector<T>> &v){for(int i=0;i<(int)v.size();i++){for(int j=0;j<(int)v.at(i).size();j++){cout<<v.at(i).at(j)<<" ";}cout<<endl;}}
void out_yn(bool b){if(b){cout << "Yes" << endl;}else{cout << "No" << endl;}}
int ctoi(char c){return int(c-'0');} // e.g.) a -> 49, 1 -> 1
char itoc(int x){return x+'0';}

void solve(){
  ll n; cin >> n;

  vector<ll> a(n);
  rep(i, n) cin >> a.at(i);
  // a.insert(a.begin(), 0);

  ll l = 0;
  ll l_idx = -1;
  ll r = 0;
  ll r_idx = -1;
  ll pre = 0;

  vector<ll> pos(n);
  // 何も変えない
  rep(i, n){
    ll cur = pre + a.at(i);
    pos.at(i) = cur;
    if(cur < pre){
      if(chmin(l, cur)){
        l_idx = i;
      }
    }else{
      if(chmax(r, cur)){
        r_idx = i;
      }
    }
    pre = cur;
  }

  // debug(pos);
  // debug(l_idx);
  // debug(r_idx);
  // debug(l);
  // debug(r);

  ll nl = l;
  ll nr = r;
  rep(i, n-1){
    if(a.at(i)*a.at(i+1) < 0){
      ll pos1 = pos.at(i) - a.at(i+1);
      // debug(pos1);
      if(a.at(i) < 0){
        chmin(nl, pos1);
        if(i <= l_idx){
          nr -= a.at(i);
        }
      }else{
        chmax(nr, pos1);
        if(i <= r_idx){
          nl += a.at(i);
        }
      }
      // debug(nl);
      // debug(nr);
    }
  }
  // debug(nl);
  // debug(nr);
  cout << nr - nl + 1 << endl;


  // debug(l);
  // debug(r);



}

int main() {
  solve();
  return 0;
}
