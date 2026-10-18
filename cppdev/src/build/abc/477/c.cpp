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
  ll q; cin >> q;
  string s, t; cin >> s >> t;

  vector<ll> ids;

  rep(i, s.size()){
    if(s.at(i) == t.at(0)){
      bool is_ok = true;
      rep(j, t.size()){
        if(i+j >= (int)s.size()){
          is_ok = false;
          break;
        }
        if(s.at(i+j) != t.at(j)){
          is_ok = false;
          break;
        }
      }
      if(is_ok){
        ids.push_back(i);
      }
    }
  }

  while(q--){
    ll l, r; cin >> l >> r;
    l--; r--;
    bool is_yes = false;
    auto it = lower_bound(ids.begin(), ids.end(), l);
    if(it != ids.end()){
      ll l2 = *it;
      ll r2 = *it+t.size()-1;
      if(l <= l2 && r2 <= r){
        is_yes = true;
      }
    }
    out_yn(is_yes);
  }
}

int main() {

  solve();

  return 0;
}
