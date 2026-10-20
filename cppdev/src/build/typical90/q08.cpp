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
int ctoi(char c){return int(c-'0');}
char itoc(int x){return x+'0';}

const ll MOD = 1e9+7;

void solve(){
  int n;
  cin >> n;

  string s;
  cin >> s;

  vector<vector<ll>> dp(n+1, vector<ll>(8, 0));
  dp.at(0).at(0) = 1;

  rep(i, n){
    rep(j, 8){
      dp.at(i+1).at(j) += dp.at(i).at(j);

      if(s.at(i) == 'a' && j == 0) dp.at(i+1).at(j+1) += dp.at(i).at(j);
      if(s.at(i) == 't' && j == 1) dp.at(i+1).at(j+1) += dp.at(i).at(j);
      if(s.at(i) == 'c' && j == 2) dp.at(i+1).at(j+1) += dp.at(i).at(j);
      if(s.at(i) == 'o' && j == 3) dp.at(i+1).at(j+1) += dp.at(i).at(j);
      if(s.at(i) == 'd' && j == 4) dp.at(i+1).at(j+1) += dp.at(i).at(j);
      if(s.at(i) == 'e' && j == 5) dp.at(i+1).at(j+1) += dp.at(i).at(j);
      if(s.at(i) == 'r' && j == 6) dp.at(i+1).at(j+1) += dp.at(i).at(j);
    }
    rep(j, 8){
      dp.at(i+1).at(j) %= MOD;
    }
  }

  cout << dp.back().back() << endl;
}

int main() {

  solve();

  return 0;  
}
