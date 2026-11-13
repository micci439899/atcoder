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
  // 解けず
  // sort後n/k個に分けるのを前からと後ろからやってみたが
  // 方針自体違いそう


  ll n, k; cin >> n >> k;

  vector<ll> a(n);
  rep(i, n) cin >> a.at(i);
  vector<ll> b = a;
  sort(a.begin(), a.end());
  sort(b.rbegin(), b.rend());

  if(n < k){
    cout << -1 << endl;
    return;
  }

  ll c = n/k;

  vector<vector<ll>> team1(c);
  rep(i, n){
    ll x = i/k;
    if(x == c)x--;

    team1.at(x).push_back(a.at(i));
  }

  vector<vector<ll>> team2(c);
  rep(i, n){
    ll x = i/k;
    if(x == c)x--;

    team2.at(x).push_back(b.at(i));
  }

  debug(team1);
  debug(team2);


  ll ans1 = 0;
  rep(i, c){

    ll ma = *max_element(team1.at(i).begin(), team1.at(i).end());
    ll mi = *min_element(team1.at(i).begin(), team1.at(i).end());
    ans1 += (ma-mi);
  }

  ll ans2 = 0;
  rep(i, c){

    ll ma = *max_element(team2.at(i).begin(), team2.at(i).end());
    ll mi = *min_element(team2.at(i).begin(), team2.at(i).end());
    ans2 += (ma-mi);
  }

  ll ans = min(ans1, ans2);
  cout << ans << endl;


}

int main() {
  solve();
  return 0;
}
