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
  ll n, v, q; cin >> n >> v >> q;

  vector<ll> t(n+1);
  vector<ll> w(n+1);
  rep(i, n){
    cin >> t.at(i+1) >> w.at(i+1);
  }

  vector<ll> pos(n+1, 0);
  rep(i, n){
    if(i == 0) continue;
    ll dt = t.at(i+1) - t.at(i);
    ll vv = w.at(i) > 0 ? w.at(i)+v : w.at(i)-v;
    pos.at(i+1) = pos.at(i) + vv * dt;
    // pos.at(i+1) = pos.at(i) + (w.at(i) + v) * dt;
  }

  // debug(t);
  // debug(w);
  // debug(pos);

  while(q--){
    ll x; cin >> x;
    ll ans;
    auto it = lower_bound(t.begin(), t.end(), x);
    if(it == t.end()){
      ll dt = x - t.back();
      ll vv = w.back() > 0 ? w.back() + v : w.back() - v;
      // ans = pos.at(n) + (v + w.back()) * dt;
      ans = pos.at(n) + vv * dt;
    }else{
      if(it == t.begin()){
        ans = 0;
      }else{
        if(*it == x){
          ll idx = it - t.begin();
          ans = pos.at(idx);
        }else{
          it--;
          ll idx = it - t.begin();
          if(idx == 0){
            ans = 0;
          }else{
            ll dt = x - *it;
            ll vv = w.at(idx) > 0 ? w.at(idx)+v : w.at(idx)-v;
            // ans = pos.at(idx) + (w.at(idx)+v) * dt;
            ans = pos.at(idx) + vv * dt;
            
          }
        }
      }
    }
    cout << ans << endl;
  }
}

int main() {

  solve();

  return 0;
}
