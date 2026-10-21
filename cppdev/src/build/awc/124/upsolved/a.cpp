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

template<typename T>
vector<pair<T, long long>> rle(vector<T> v){
  int n = v.size();
  vector<pair<T, long long>> res;
  if(n == 1){
    res.emplace_back(v.at(0), n);
    return res;
  }
  T t = v.at(0);
  long long cnt = 1;
  for(int i = 1; i < n; i++){
    if(v.at(i) != t){
      res.emplace_back(t, cnt);
      cnt = 1;
      t = v.at(i);
    }else{
      cnt++;
    }
    if(i == n-1) res.emplace_back(t, cnt);
  }
  return res;
}

void solve(){
  int n; cin >> n;
  string s; cin >> s;

  vector<char> cs;
  for(char c : s) cs.push_back(c);

  vector<pair<char, long long>> x = rle(cs);

  ll ans = 0;
  for(auto p : x){
    if(p.first == 'W') chmax(ans, p.second);
  }
  cout << ans << endl;
  
}

int main() {

  solve();

  return 0;
}
