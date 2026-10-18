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
  ll n, k, m; cin >> n >> k >> m;

  vector<pll> vc(n);
  rep(i, n){
    ll c, v; cin >> c >> v;
    vc.at(i) = {v, c};
  }
  sort(vc.rbegin(), vc.rend());

  ll ans = 0;
  vector<bool> cnt(n, false);
  set<ll> c_st;
  c_st.insert(vc.at(0).second);
  cnt.at(0) = true;
  ans += vc.at(0).first;

  rep(i, n){
    if(c_st.count(vc.at(i).second) == 0){
      c_st.insert(vc.at(i).second);
      cnt.at(i) = true;
      ans += vc.at(i).first;
    }
    if(c_st.size() >= m) break;
  }

  // debug(c_st);
  // debug(cnt);

  ll all_cnt = m;

  // debug(all_cnt);
  rep(i, n){
    if(all_cnt >= k) break;
    if(!cnt.at(i)){
      ans += vc.at(i).first;
      all_cnt++;
    }
  }
  cout << ans << endl;






/*
  map<ll, vector<ll>> mp;
  rep(i, n){
    ll c, v; cin >> c >> v;
    mp[c].push_back(v);
  }

  map<ll, ll> cnt_mp;
  ll ans = 0;
  ll mm = 0;
  ll cnt = 0;
  for(auto p : mp){
    sort(p.second.rbegin(), p.second.rend());
    if(mm <= k){
      ans += p.second.at(0);
      cnt_mp[p.first] = 1;
      mm++;
      cnt++;
    }else{
      cnt_mp[p.first] = 0;
    }
  }

  debug(cnt_mp);
  debug(cnt);
  debug(mm);

  auto it = mp.end();
  it--;
  while(cnt < k){
    pair<ll, vector<ll>> pv = *it;
    vector<ll> v = pv.second;
    bool b = false;
    for(int i = cnt_mp[pv.first]; i < v.size(); i++){
      ans += v.at(i);
      cnt++;
      if(cnt < k){
        b = true;
        break;
      }
      // kk++;
    }
    if(b)break;
    it--;
    if(it == mp.begin()) break;
  }

  cout << ans << endl;
*/
}



int main() {

  solve();

  return 0;
}
