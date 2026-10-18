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
  ll n, s, l; cin >> n >> s >> l;
  s--;

  vector<ll> a(n-1);
  rep(i, n-1) cin >> a.at(i);

  vector<ll> cum_a(n);
  rep(i, n-1) cum_a.at(i+1) = cum_a.at(i) + a.at(i);

  int ans = 0;
  for(int i = 0; i <= s; i++)for(int j = s; j < n; j++){
    ll d1 = cum_a.at(s) - cum_a.at(i);
    ll d2 = cum_a.at(j) - cum_a.at(s);
    if(d1*2 + d2 <= l || d1+d2*2 <= l){
      // if(j-i+1 == 7){
      // debug(i);
      // debug(j);
      // debug(d1);
      // debug(d2);
      // debug(ans);
      // debug(j-i+1);
      // }
      ans = max(ans, j-i+1);
    }
  }
  cout << ans << endl;


/*
  vector<ll> cum_a(n);
  rep(i, n-1) cum_a.at(i+1) = cum_a.at(i) + a.at(i);

  ll ans = 0;
  rep(i, n){
    if(i <= s){
      ll d = cum_a.at(s) - cum_a.at(i);
      if(d <= l){
        ans = max(ans, s-i+1);
      }
    }else{
      ll d2 = cum_a.at(i) - cum_a.at(s+1);
      if(d2 <= l){
        d2 -= l;

        idx = i;
        while(true){
          d2 -= a.at(idx);
          idx--;
        }
      }
    }
  }
*/
}

int main() {

  solve();

  return 0;
}
