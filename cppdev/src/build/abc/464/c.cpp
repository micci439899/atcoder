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
  ll n, m; cin >> n >> m;

  vector<map<ll, ll>> d_mp(m);
  map<ll, ll> mp;
  rep(i, n){
    ll a, d, b; cin >> a >> d >> b;
    a--; d--; b--;
    if(d == 0){
      mp[b]++;
    }else{
      mp[a]++;
      d_mp.at(d)[b]++;
      if(a != b){
        d_mp.at(d)[a]--;
      }
    }
  }

  ll cnt = mp.size();
  rep(i, d_mp.size()){
    // debug(i);
    for(auto p : d_mp.at(i)){
      // debug(p);
      ll prev = mp[p.first];
      mp[p.first] += p.second;
      if(mp[p.first] == 0) cnt--;
      if(prev == 0) cnt++;
    }
    cout << cnt << endl;
  }

/*
  // vector<vector<ll>> d_before(m);
  // vector<vector<ll>> d_after(m);
  vector<pll> d(m);
  map<ll, ll> mp;
  // map<ll, ll> mp_before;
  // map<ll, ll> mp_after;
  rep(i, n){
    ll a, d, b; cin >> a >> d >> b;
    a--; d--; b--;
    if(d == 0){
      mp[b]++;
    }else{
      mp[a]++;
      if(a != b){
        d.at(d).emplace_back(a, b);
        // d_before.at(d).push_back(a)
        // d_after.at(d).push_back(b);
      }
    }
  }

  ll cnt = mp.size();
  rep(i, ds){
    rep(j, ds.at(i)){
      auto [a, b] = d.at(i).at(j);
      mp[ds.at(i).at(j)]--;
      if(mp[ds.at(i).at(j)] == 0) cnt--;
    }
  }
*/

}



int main() {

  solve();

  return 0;
}
