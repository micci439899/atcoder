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

const ll INFL = 1LL<<40;

void solve(){
  int n; ll p; int k; cin >> n >> p >> k;

  vector<vector<ll>> a(n, vector<ll>(n));
  rep(i, n)rep(j, n) cin >> a.at(i).at(j);

  auto warshall_floyd = [&](ll x){
    vector<vector<ll>> dist(n, vector<ll>(n, INFL));
    rep(i, n)rep(j, n){
      if(a.at(i).at(j) >= 0){
        dist.at(i).at(j) = a.at(i).at(j);
      }else{
        dist.at(i).at(j) = x;
      }
    }
    rep(kk, n)rep(i, n)rep(j, n){
      chmin(dist.at(i).at(j), dist.at(i).at(kk) + dist.at(kk).at(j));
    }
    return dist;
  };

  auto f = [&](ll x){
    ll l = 0;
    ll r = INFL;
    ll mi = INFL;

    while(r - l > 1){
      ll mid = l + (r-l)/2;
      vector<vector<ll>> dist = warshall_floyd(mid);

      ll cnt = 0;
      rep(i, n)for(int j = i+1; j < n; j++){
        if(dist.at(i).at(j) <= p) cnt++;
      }
      if(cnt > x){
        l = mid;
      }else{
        r = mid;
        mi = min(mi, mid);
      }
    }
    return mi;
  };

  ll l = f(k);
  ll r = f(k-1);

  ll ans = r - l;
  if(ans >= INFL/2LL){
    cout << "Infinity" << endl;
  }else{
    cout << ans << endl;
  }
}

int main() {

  solve();

  return 0;
}
