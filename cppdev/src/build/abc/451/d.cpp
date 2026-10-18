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

// 桁数毎の2冪
vector<vector<ll>> pows(10);
void initialize(){
  ll a = 1;
  rep(i, 30){
    pows.at(to_string(a).size()).push_back(a);
    a*=2;
  }
}

vector<vector<int>> digit_vec(10);
void dfs(vector<int> digits, int digit_sm){
  debug(digit_sm);
  debug(digits);
  ll sm = 0;
  rep(i, digits.size()) sm += digits.at(i);
  if(sm == digit_sm){
    digit_vec.at(digit_sm) = digits;
    cout << "sum of digits is equals to digit_sm, so end" << endl;
    return;
  }

  for(int i = 1; i <= digit_sm; i++){
    vector<int> digits2;
    digits2.push_back(i);
    // cout << "push" << i << endl;

    dfs(digits2, digit_sm);
  }
}


// vector<vector<int>> z;
vector<int> dfs2(vector<int> ds, int d){
  int sm=0;
  rep(i, ds.size()) sm += ds.at(i);
  if(sm == d) return ds;

  vector<int> ans;
  for(int i = 1; i <= d; i++){
    vector<int> ds2 = ds;
    ds2.push_back(i);
    vector<int> res = dfs2(ds, d);
    rep(i, res.size()) ans.push_back(res.at(i));
  }
  return ans;
}


vector<vector<vector<int>>> a(10);
void dfs3(vector<int> ds, int d){
  int sm = 0;
  rep(i, ds.size()) sm += ds.at(i);
  if(sm >= d){
    if(sm == d){
      a.at(d).push_back(ds);
    }
    return;
  }
  // for(int i = 1; i <= d; i++){
  for(int i = d; i >= 1; i--){
    ds.push_back(i);
    dfs3(ds, d);
  }
}

void execute(int d){
  for(int i = d; i >= 1; i--){
    vector<int> vec;
    vec.push_back(i);
    dfs3(vec, i);
  }
}


void solve(){
  int n;
  cin >> n;

  initialize();

  // out_vec2d(pows);

  for(int i = 1; i <= 9; i++){
    vector<int> vec;
    dfs3(vec, i);
  }

  // rep(i, a.size()){
  //   debug(i);
  //   out_vec2d(a.at(i));
  // }



  // vector<ll> ans;
  // for(int i = 1; i <= 9; i++){
  //   vector<int> vec;
  //   dfs(vec, i);
  // }
  // out_vec2d(digit_vec);



}


int main() {

  solve();

  return 0;
}
