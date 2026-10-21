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
template<class T, class U>ostream&operator<<(ostream&os, map<T,U>mp){os<<"{";int idx=0;for(auto p : mp){cout << p;if(idx != mp.size()-1){cout << ",";}idx++;}os<<"}";return os;}

template<class T> void out_vec(vector<T> &v){for(int i=0;i<(int)v.size();i++){cout<<v.at(i)<<" ";}cout<<endl;}
template<class T> void out_vec2d(vector<vector<T>> &v){for(int i=0;i<(int)v.size();i++){for(int j=0;j<(int)v.at(i).size();j++){cout<<v.at(i).at(j)<<" ";}cout<<endl;}}
void out_yn(bool b){if(b){cout << "Yes" << endl;}else{cout << "No" << endl;}}
int ctoi(char c){return int(c-'0');} // e.g.) a -> 49, 1 -> 1
char itoc(int x){return x+'0';}

void solve(){
  ll n, m, k; cin >> n >> m >> k;

  vector<ll> a(n);
  rep(i, n) cin >> a.at(i);

  vector<ll> b(m);
  rep(i, m) cin >> b.at(i);

  sort(a.begin(), a.end());


/*
  ll ans = 1;
  ll rem = k;
  // ll t_num = *it;
  ll t_num = *max_element(a.begin(), a.end());
  if(k == 0){
    t_num = *a.rbegin();
  }

  rep(i, m){
    if(i == 0) continue;
    if(t_num < b.at(i)){
      // if(rem == 0){
      //   break;
      // }
      // auto it = lower_bound(a.begin(), a.end(), b.at(i));
      // if(it == a.end()){
      //   break;
      // }
      // t_num = *it;
      // rem--;
      break;
    }
    ans++;
  }
  cout << ans << endl;
*/

/*
  if(m == 1){
    ll ma = *max_element(a.begin(), a.end());
    if(ma >= b.at(0)){
      cout << 1 << endl;
    }else{
      cout << 0 << endl;
    }
    return;
  }

  if(m == 2){
    ll ma = *max_element(a.begin(), a.end());
    if(ma < b.at(0)){
      cout << 0 << endl;
      return;
    }
    if(ma < b.at(1)){
      cout << 1 << endl;
      return;
    }
    cout << 2 << endl;
    return;
  }

  vector<ll> peak;
  for(int i = m-2; i >= 1; i--){
    if(b.at(i-1) < b.at(i) && b.at(i) > b.at(i+1)) peak.push_back(i);
  }

  debug(peak);
*/

  // 1番結果が良かった（WAが1個のやつ）のコメントアウトを解除してcommitしておく...
  auto it = lower_bound(a.begin(), a.end(), b.at(0));
  if(it == a.end()){
    cout << 0 << endl;
    return;
  }

  ll ans = 1;
  ll rem = k;
  ll t_num = *it;
  if(k == 0){
    t_num = *a.rbegin();
  }

  rep(i, m){
    if(i == 0) continue;
    if(t_num < b.at(i)){
      if(rem == 0){
        break;
      }
      auto it = lower_bound(a.begin(), a.end(), b.at(i));
      if(it == a.end()){
        break;
      }
      t_num = *it;
      rem--;
    }
    ans++;
  }
  cout << ans << endl;


}

int main() {
  solve();
  return 0;
}
