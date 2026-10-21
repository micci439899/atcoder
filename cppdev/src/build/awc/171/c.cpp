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

  vector<ll> a(n);
  rep(i, n) cin >> a.at(i);

  // vector<ll> cum_a(n+1, 0);
  // rep(i, n) cum_a.at(i+1) = cum_a.at(i) + a.at(i);

  ll sm_all = accumulate(a.begin(), a.end(), 0LL);

  ll ans = 0;
  ll l_idx = 0;
  ll sm = 0;
  rep(i, n){
    sm += a.at(i);
    while(l_idx < n && l_idx <= (ll)i && sm > sm_all-k){
      sm -= a.at(l_idx);
      l_idx++;
    }


    if(sm == sm_all-k) ans++;
  }
  cout << ans << endl;

/*
  ll sm = accumulate(a.begin(), a.end(), 0LL);

  ll ans = 0;
  rep(i, n){
    auto it = lower_bound(cum_a.begin()+i, cum_a.end(), sm-k+cum_a.at(i));

    if(it != cum_a.end()){
      if(*it == sm - k + cum_a.at(i)){
        ans++;
      }
    }
  }
  cout << ans << endl;
*/
}

int main() {

  solve();

  return 0;
}
