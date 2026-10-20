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

vector<int> bg;

void dfs(int u, int color, vector<vector<int>> &g){
  bg.at(u) = color;
  color = color == 0 ? 1 : 0;
  for(int v : g.at(u)){
    if(bg.at(v) >= 0) continue;
    dfs(v, color, g);
  }
}

void out(vector<int> &v, int n){
  rep(i, n/2){
    cout << v.at(i);
    if(i != n/2-1) cout << " ";
  }
  cout << endl;
}

void solve(){
  int n;
  cin >> n;

  vector<vector<int>> g(n);
  rep(i, n-1){
    int a, b;
    cin >> a >> b;
    a--; b--;

    g.at(a).push_back(b);
    g.at(b).push_back(a);
  }

  bg.assign(n, -1);
  dfs(0, 0, g);

  vector<int> g1;
  vector<int> g2;
  rep(i, n){
    if(bg.at(i) == 0) g1.push_back(i+1);
    if(bg.at(i) == 1) g2.push_back(i+1);
  }

  if(g1.size() > g2.size()){
    out(g1, n);
  }else{
    out(g2, n);
  }


}

int main() {

  solve();

  return 0;  
}
