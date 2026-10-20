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
  int n;
  cin >> n;

  vector<vector<int>> a(1001, vector<int>(1001, 0));
  rep(i, n){
    int lx, ly, rx, ry;
    cin >> lx >> ly >> rx >> ry;
    //lx--; ly--; rx--; ry--;

    a.at(ly).at(lx)++;
    a.at(ly).at(rx)--;
    a.at(ry).at(lx)--;
    a.at(ry).at(rx)++;
  }



  rep(i, 1000)rep(j, 1000){
    a.at(j).at(i+1) += a.at(j).at(i);
  }
  rep(i, 1000)rep(j, 1000){
    a.at(j+1).at(i) += a.at(j).at(i);
  }

  vector<int> cnt(n+1, 0);
  rep(i, 1000)rep(j, 1000){
    if(a.at(j).at(i) > 0) cnt.at(a.at(j).at(i))++; 
  }

  for(int i = 1; i <= n; i++){
    cout << cnt.at(i) << endl;
  }
}

int main() {

  solve();

  return 0;  
}
