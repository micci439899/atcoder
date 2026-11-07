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

// https://qiita.com/sounansya/items/51b39e0d7bf5cc194081
// f(n, m, a, b) := \sum_{i=0}^{n-1} \floor{\frac{ai+b}{m}}
// 0 le n lt 2^32
// 1 le m lt 2^32
ll floor_sum(ll n, ll m, ll a, ll b){
  ll a1 = a / m;
  ll a2 = a % m;
  ll s = n * (n-1) / 2 * a1;
  ll b1 = b / m;
  ll b2 = b % m;
  if(a2 == 0) return s + b1 * n;

  ll k = (a2 * (n-1) + b2) / m;
  return s + n * (k + b1) - floor_sum(k, a2, m, m + a2 - b2 - 1);
}

void solve(){
  int t;
  cin >> t;

  while(t--){
    ll n, m, a, b; cin >> n >> m >> a >> b;
    cout << floor_sum(n, m, a, b) << endl;
  }


}

int main() {

  solve();

  return 0;
}
