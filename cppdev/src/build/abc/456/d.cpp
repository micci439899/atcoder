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

const ll MOD = 998244353;

void solve(){
  string s;
  cin >> s;

  if(s.size() == 1){
    cout << 1 << endl;
    return;
  }

  vector<vector<ll>> dp(3, vector<ll>(s.size(), 0));

  if(s.front() == 'a'){
    dp.at(0).at(0) = 1;
  }else if(s.front() == 'b'){
    dp.at(1).at(0) = 1;
  }else{
    dp.at(2).at(0) = 1;
  }

  rep(i, s.size()-1){
    if(s.at(i+1) == 'a'){
      ll added = dp.at(1).at(i) + dp.at(2).at(i);
      // dp.at(0).at(i+1) = (dp.at(0).at(i) + added) % MOD;
      dp.at(0).at(i+1) = added % MOD;

      dp.at(1).at(i+1) = dp.at(1).at(i);
      dp.at(2).at(i+1) = dp.at(2).at(i);
      // dp.at(1).at(i+1) = (dp.at(1).at(i) + 1) % MOD;
      // dp.at(2).at(i+1) = (dp.at(2).at(i) + 1) % MOD;
    }else if(s.at(i+1) == 'b'){
      ll added = dp.at(0).at(i) + dp.at(2).at(i);
      // dp.at(1).at(i+1) = (dp.at(1).at(i) + added) % MOD;
      dp.at(1).at(i+1) = added % MOD;

      dp.at(0).at(i+1) = dp.at(0).at(i);
      dp.at(2).at(i+1) = dp.at(2).at(i);
      // dp.at(0).at(i+1) = (dp.at(0).at(i) + 1) % MOD;
      // dp.at(2).at(i+1) = (dp.at(2).at(i) + 1) % MOD;
    }else{
      ll added = dp.at(0).at(i) + dp.at(1).at(i);
      // dp.at(2).at(i+1) = (dp.at(2).at(i) + added) % MOD;
      dp.at(2).at(i+1) = added % MOD;

      dp.at(0).at(i+1) = dp.at(0).at(i);
      dp.at(1).at(i+1) = dp.at(1).at(i);
      // dp.at(0).at(i+1) = (dp.at(0).at(i) + 1) % MOD;
      // dp.at(1).at(i+1) = (dp.at(1).at(i) + 1) % MOD;
    }
  }

  out_vec2d(dp);

  ll sm = dp.at(0).back();
  sm = (sm + dp.at(1).back()) % MOD;
  sm = (sm + dp.at(2).back()) % MOD;

  cout << sm << endl;

}


int main() {

  solve();

  return 0;
}
