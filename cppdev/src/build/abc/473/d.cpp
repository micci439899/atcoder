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

vector<vector<ll>> ans;
ll n, k;

void dfs(ll x, vector<ll> v, ll cur){
  v.push_back(x);
  // cur += x*v.size();
  cur += x*(n-v.size()+1);

  if(cur > k) return;

  if(v.size() == n){
    if(cur == k){
      reverse(v.begin(), v.end());
      ans.push_back(v);
    }
    return;
  }

  // for(ll i = 0; i <= k; i++){
  for(ll i = k-cur; i >= 0; i--){
    if(cur == k && v.size() < n && i != 0) continue;
    // ll nxt = cur + i*(v.size()+1);
    ll nxt = cur + i*(n-(v.size()+1)-1);
    if(nxt > k) continue;
    dfs(i, v, cur);
  }
}

void solve(){
  cin >> n >> k;

  // for(int i = 0; i <= k; i++){
  for(int i = k; i >= 0; i--){
    vector<ll> v;
    dfs(i, v, 0);
  }

  sort(ans.begin(), ans.end());
  rep(i, ans.size()){
    rep(j, ans.at(i).size()){
      if(j) cout << " ";
      cout << ans.at(i).at(j);
    }
    cout << endl;
  }
}

int main() {

  solve();

  return 0;
}
