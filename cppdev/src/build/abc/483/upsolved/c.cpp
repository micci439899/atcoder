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
  ll n, m; cin >> n >> m;

  vector<ll> a(m), b(m);

  // 第一候補をAiにしている人が選んでいる第二候補Bi
  vector<vector<ll>> v(n);
  rep(i, m){
    cin >> a.at(i) >> b.at(i);
    a.at(i)--; b.at(i)--;
    v.at(a.at(i)).push_back(b.at(i));
  }

  // 第一候補だけを考えたときの獲得数
  vector<ll> cand(n);
  rep(i, m) cand.at(a.at(i))++;

  // 各候補者の得票数
  set<pll> st;
  rep(i, n) st.insert({cand.at(i), -i});

  rep(i, n){
    for(ll j : v.at(i)){
      st.erase({cand.at(i), -i});
      cand.at(i)--;
      st.insert({cand.at(i), -i});

      st.erase({cand.at(j), -j});
      cand.at(j)++;
      st.insert({cand.at(j), -j});
    }

    pll ans = *st.rbegin();
    cout << -ans.second+1 << endl;

    for(ll j :v.at(i)){
      st.erase({cand.at(i), -i});
      cand.at(i)++;
      st.insert({cand.at(i), -i});

      st.erase({cand.at(j), -j});
      cand.at(j)--;
      st.insert({cand.at(j), -j});
    }
  }
}

int main() {
  solve();
  return 0;
}
