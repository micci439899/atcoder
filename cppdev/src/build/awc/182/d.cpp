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

const ll INFL = 1LL<<60;

void solve(){
  int n, m; cin >> n >> m;

  vector<ll> a(n);
  rep(i, n) cin >> a.at(i);

  vector<ll> l(m), r(m), c(m), w(m);
  rep(i, m){
    ll li, ri, ci, wi; cin >> li >> ri >> ci >> wi;
    li--; ri--;
    l.at(i) = li;
    r.at(i) = ri;
    c.at(i) = ci;
    w.at(i) = wi;
  }

  ll ans = INFL;
  rep(bit, 1<<m){
    ll w_sm = 0;
    vector<ll> x = a;
    rep(i, m){
      if((bit>>i) & 1){
        w_sm += w.at(i);
        for(int j = l.at(i); j <= r.at(i); j++){
          x.at(j) -= c.at(i);
        }
      }
    }

    bool is_ok = true;
    rep(i, n){
      if(x.at(i) > 0){
        is_ok = false;
        break;
      }
    }
    if(is_ok){
      ans = min(ans, w_sm);
    }
  }

  if(ans == INFL){
    cout << -1 << endl;
  }else{
    cout << ans << endl;
  }

}

int main() {
  solve();
  return 0;
}
