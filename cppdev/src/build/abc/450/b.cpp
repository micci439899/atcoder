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

void solve(){
  int n; cin >> n;

  vector<vector<ll>> cost(n+1, vector<ll>(n+1, 0));

  for(int i = 1; i <= n; i++){
    for(int j = i+1; j <= n; j++){
      ll c_ij; cin >> c_ij;
      cost.at(i).at(j) = c_ij;      
      // debug(c_ij);
    }
  }

  // debug(cost);

  for(int i = 1; i <= n-2; i++){
    for(int j = i+1; j <= n-1; j++){
      for(int k = j+1; k <= n; k++){
        ll x = cost.at(i).at(j) + cost.at(j).at(k);
        ll y = cost.at(i).at(k);
        if(x < y){
          out_yn(true);
          return;
        }
      }
    }
  }
  out_yn(false);


  /*
  // vector<vector<int>> c(n-1, vector<int>(n-1, 0));
  // vector<int> c((n-1) * n / 2);

  // rep(i, c.size()){
  //   cin >> c.at(i);
  // }

  vector<vector<int>> c2(n-1, vector<int>(n-1, 0));
  for(int i = 0; i < n-1;i++){
    for(int j = i; j < n-1; j++){
      ll c_ij; cin >> c_ij;
      c2.at(i).at(j) = c_ij;
      // cout << i << "," << j << ", " << c_ij << endl;
    }
  }

  out_vec2d(c2);

  for(int i = 0; i < n-1; i++){
    debug(i);
    for(int j = i; j < n-1; j++){
      debug(j);
      for(int k = j+1; k < n-1; k++){
        debug(k);
        ll x = c2.at(i).at(j) + c2.at(j).at(k);
        ll y = c2.at(i).at(k);
        if(x < y){
          out_yn(true);
          return;
        }
      }
    }
  }

  out_yn(false);
  */


}

int main() {

  solve();

  return 0;
}


