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

  vector<ll> a(n);
  rep(i, n) cin >> a.at(i);
  // vector<ll> a(n+1, -1);
  // rep(i, n) cin >> a.at(i+1);

  sort(a.begin(), a.end());

  ll prv_idx = 0;
  ll val = 0;
  while(q--){
    ll t; cin >> t;

    val = max(val, t);
    ll idx = lower_bound(a.begin(), a.end(), val) - a.begin();
    cout << idx - prv_idx << endl;
    prv_idx = idx;

/*
    auto it = upper_bound(a.begin(), a.end(), t-1);
    ll idx = it - a.begin();

    debug(t);
    debug(idx);
    debug(prv);

    ll ans = max(0LL, idx-prv+1);
    prv = idx;
    cout << ans << endl;
*/


/*
    auto it = lower_bound(a.begin(), a.end(), t);
    ll ucnt = a.end() - it + 1;

    ll ans = max(0LL, ucnt - prv);
    if(it != a.end()){
      prv = ucnt;
    }else{
      prv = n;
    }
    cout << ans << endl;
*/

/*
    auto it1 = lower_bound(a.begin(), a.end(), t-1);
    auto it2 = lower_bound(a.begin(), a.end(), prv-1);
    ll idx1 = it1 - a.begin();
    ll idx2 = it2 - a.begin();

    ll ans = max(0LL, idx1-idx2);
    cout << ans << endl;

    prv = *it1;
*/


/*
    // ll idx = lower_bound(a.begin(), a.end(), t) - a.begin();
    auto it1 = lower_bound(a.begin(), a.end(), t);
    auto it2 = lower_bound(a.begin(), a.end(), prv);


    ll idx1 = it1 - a.begin();
    ll idx2 = it2 - a.begin();
    // if(it1 != a.end() && *it1 == t)idx1--;

    ll ans = max(0LL, idx1-idx2);
    cout << ans << endl;
    if(it1 != a.end()){
      prv = *it1;
    }else{
      prv = a.back()+1;
    }
    // ll idx = it - a.begin();
    // if(*it == t)idx--;

    // ll ans = max(0LL, idx-prv);
    // cout << ans << endl;
    // prv = t;
*/

  }
}


int main() {

  solve();

  return 0;
}
