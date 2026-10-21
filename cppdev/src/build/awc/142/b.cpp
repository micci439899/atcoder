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
  ll n, m, k, q; cin >> n >> m >> k >> q;

  // vector<ll> v(n);
  // vector<ll> c(n);
  // rep(i, n){
  //   cin >> v.at(i) >> c.at(i);
  // }
  vector<pll> vc(n);
  rep(i, n) cin >> vc.at(i).first >> vc.at(i).second;

  vector<bool> can_used(m, false);

  vector<ll> s(q);
  rep(i, q){
    cin >> s.at(i);
    can_used.at(s.at(i)-1) = true;
  }

  sort(vc.rbegin(), vc.rend());

  ll kk = k;
  ll ans = 0;
  rep(i, n){
    if(can_used.at(vc.at(i).second-1)){
      ans += vc.at(i).first;
      kk--;
    }
    if(kk == 0) break;
  }
  cout << ans << endl;

/*
  map<ll, pll> mp;
  rep(i, n){
    if(mp.count(c.at(i))){
      pll p = mp[c.at(i)];
      mp[c.at(i)] = {p.first + v.at(i), p.second+1};

    }else{
      mp[c.at(i)] = {v.at(i), 1};
    }
  }
  ll kk = k;
  auto it = mp.end();
  while(true){
    it--;
  }
*/


}


int main() {

  solve();

  return 0;
}
