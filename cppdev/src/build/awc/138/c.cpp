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
  int n; cin >> n;
  ll k; cin >> k;

  vector<ll> a(n);
  vector<ll> b(n);
  rep(i, n) cin >> a.at(i) >> b.at(i);

  // vector<ll> cum_a(n+1, 0);
  // vector<ll> cum_b(n+1, 0);
  // rep(i, n){
  //   cum_a.at(i+1) = cum_a.at(i) + a.at(i);
  //   cum_b.at(i+1) = cum_b.at(i) + b.at(i);
  // }

  ll ans = 0;
  ll l = 0;
  ll a_sm = 0;
  ll b_sm = 0;
  rep(r, n){
  // rep(l, n){
    b_sm += b.at(r);
    a_sm += a.at(r);
    while(b_sm > k){
      b_sm -= b.at(l);
      a_sm -= a.at(l);
      l++;
    }
    chmax(ans, a_sm);
  }
  cout << ans << endl;

  // ll r = 0;
  // rep(l, n){
/*
    while(true){
      debug(l);
      debug(r);
      ll b_sm = cum_a.at(r+1) - cum_a.at(l);
      if(b_sm <= k){
        r++;
        cout << "if" << endl;
        if(r == n-1) break;
      }else{
        cout << "else" << endl;
        r--;
        b_sm -= b.at(r);
        break;
      }
    }
    ll a_sm = cum_a.at(r+1) - cum_a.at(l);
    chmax(ans, a_sm);
  }
  cout << ans << endl;
*/
}



int main() {

  solve();

  return 0;
}
