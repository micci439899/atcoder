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
  ll n, q; cin >> n >> q;

  vector<string> s(n);
  rep(i, n) cin >> s.at(i);

  map<string, vector<ll>> mp;
  map<string, vector<ll>> mp_rev;
  rep(i, n){
    mp[s.at(i)].push_back(i);
    mp_rev[s.at(i)].push_back(-i);
  }
  for(auto &p : mp_rev){
    reverse(p.second.begin(), p.second.end());
  }

  while(q--){
    ll l, r; cin >> l >> r; l--; r--;
    string t; cin >> t;

    if(!mp.count(t)){
      cout << 0 << endl;
    }else{
      ll idx1 = lower_bound(mp[t].begin(), mp[t].end(), l) - mp[t].begin();
      ll idx2 = lower_bound(mp_rev[t].begin(), mp_rev[t].end(), -r) - mp_rev[t].begin();
      idx2 = mp[t].size() - idx2 - 1;

      cout << idx2 - idx1 + 1 << endl;
/*
      ll idx1 = lower_bound(mp[t].begin(), mp[t].end(), l) - mp[t].begin();
      auto it2 = lower_bound(mp[t].begin(), mp[t].end(), r);
      if(it2 == mp[t].end()){
        it2--;
      }
      if(*it2 == r){
        ll idx2 = it2 - mp[t].begin();
        cout << idx2 - idx1 + 1 << endl;
      }else{
        it2--;
        ll idx2 = it2 - mp[t].begin();
        cout << idx2 - idx1 + 1 << endl;
      }
*/
    }
  }
}


int main() {

  solve();

  return 0;
}
