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
  ll n, k; cin >> n >> k;

/*
  vector<ll> a(n);
  rep(i, n) cin >> a.at(i);

  ll ans = 0;
  for(int i = 0; i <= k; i++){
    ll sm = 0;
    for(int j = i; j < n; j+=(k+1)){
      sm += a.at(j);
      debug(a.at(j));
    }
    debug(sm);
    ans = max(ans, sm);
    cout << endl;
  }
  cout << ans << endl;
*/

  vector<ll> a(n);
  rep(i, n) cin >> a.at(i);
  vector<vector<ll>> dp(n, vector<ll>(2, 0));
  // rep(i, n) cin >> dp.at(i).at(1);
  dp.at(0).at(1) = a.at(0);
  if(n == 1){
    cout << a.back() << endl;
    return;
  }

  for(int i = 1; i < n; i++){
    ll ma = max(dp.at(i-1).at(0), dp.at(i-1).at(1));
    if(i-k-1 >= 0){
      dp.at(i).at(1) = max(dp.at(i-k-1).at(1) + a.at(i), ma);
      dp.at(i).at(0) = ma;
    }else{
      dp.at(i).at(1) = max(a.at(i), ma);
      dp.at(i).at(0) = ma;      
    }
  }

  ll ans = max(dp.at(n-1).at(0), dp.at(n-1).at(1));
  cout << ans << endl;


}

int main() {

  solve();

  return 0;
}
