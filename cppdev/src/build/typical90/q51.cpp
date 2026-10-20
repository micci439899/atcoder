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

void solve(){
  int n, k; cin >> n >> k;
  ll p; cin >> p;

  vector<ll> a(n);
  rep(i, n) cin >> a.at(i);

  int mid = n/2;
  vector<vector<ll>> x(mid+1);
  vector<vector<ll>> y(n-mid+1);

  rep(bit, 1<<mid){
    ll cnt = 0;
    ll sm = 0;
    rep(i, mid){
      if(bit>>i & 1){
        sm += a.at(i);
        cnt++;
      }
    }
    x.at(cnt).push_back(sm);
  }

  rep(bit, 1<<(n-mid)){
    ll cnt = 0;
    ll sm = 0;
    rep(i, n-mid){
      if(bit>>i & 1){
        sm += a.at(i+mid);
        cnt++;
      }
    }
    y.at(cnt).push_back(sm);
  }

  for(auto & xi : x){
    sort(xi.begin(), xi.end());
  }
  for(auto & yi : y){
    sort(yi.begin(), yi.end());
  }

  ll ans = 0;
  for(int i = 0; i <= k; i++){
    if((int)x.size() <= i) continue;
    rep(j, x.at(i).size()){
      ll rem = p - x.at(i).at(j) + 1;
      if((int)y.size() <= k-i) continue;
      ll idx = lower_bound(y.at(k-i).begin(), y.at(k-i).end(), rem) - y.at(k-i).begin();
      ans += idx;
    }
  }
  cout << ans << endl;
}

int main() {

  solve();

  return 0;
}
