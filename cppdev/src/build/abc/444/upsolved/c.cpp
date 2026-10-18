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

vector<ll> ans;

void f1(vector<ll> &a, ll n){
  // すべて分かれた
  if(n%2 != 0) return;
  ll l = a.at(0) + a.at(n-1);
  bool is_valid = true;
  rep(i, n/2){
    if(a.at(i) + a.at(n-1-i) != l){
      is_valid = false;
      break;
    }
  }
  if(is_valid) ans.push_back(l);
}

void f2(vector<ll> &a, ll n){
  // 分かれてないAtCoderりこがある
  ll l = a.at(n-1);

  int idx = n-1;
  while(true){
    if(a.at(idx) != l)break;
    idx--;
    if(idx < 0)break;
  }
  if(idx < 0){
    ans.push_back(l);
    return;
  }
  ll sz = idx+1;

  if(sz%2 != 0) return;
  bool is_valid = true;
  rep(i, sz/2){
    if(a.at(i) + a.at(sz-1-i) != l){
      is_valid = false;
      break;
    }
  }
  if(is_valid) ans.push_back(l);
}


void solve(){
  ll n;
  cin >> n;

  vector<ll> a(n);
  rep(i, n) cin >> a.at(i);
  sort(a.begin(), a.end());

  f1(a, n);
  f2(a, n);

  sort(ans.begin(), ans.end());
  out_vec(ans);



}

int main() {

  solve();

  return 0;  
}
