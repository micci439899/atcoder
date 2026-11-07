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

  vector<ll> a(m);
  vector<ll> b(m);
  rep(i, m) cin >> a.at(i) >> b.at(i);
  rep(i, m) a.at(i)--;
  rep(i, m) b.at(i)--;

  vector<ll> cand1(n, 0);
  vector<ll> cand2(n, 0);

  vector<unordered_map<ll, ll>> v_mp(n);

  rep(i, m){
    cand1.at(a.at(i))++;
    cand2.at(b.at(i))++;

    v_mp.at(a.at(i))[b.at(i)]++;
  }

  vector<ll> cand = cand1;
  ll idx = -1;
  ll ma = -1;
  rep(i, n){
    if(chmax(ma, cand.at(i)))idx = i;
  }

  rep(i, n){
    ll ans = idx;
    ll ma2 = ma;
    cand = cand1;
    cand.at(i) = 0;
    if(ans == i){
      ans = -1;
      ma2 = -1;
    }
    unordered_map mp = v_mp.at(i);

    for(auto p : mp){
      cand.at(p.first) += p.second;
      if(ma2 < cand.at(p.first)){
        ans = p.first;
      }
    }
    cout << ans+1 << endl;
  }

}

int main() {
  solve();
  return 0;
}
