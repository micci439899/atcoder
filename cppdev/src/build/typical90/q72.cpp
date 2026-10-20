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

int h, w;

vector<int> dx = {1, 0, -1, 0};
vector<int> dy = {0, 1, 0, -1};

int to_1d(int i, int j){
  return i*w + j;
}

bool is_within(int i, int j){
  if(i < 0 || h-1 < i) return false;
  if(j < 0 || w-1 < j) return false;
  return true;
}

int dfs(int i, int j, int si, int sj, vector<string> &s, vector<vector<bool>> &visited, int depth){
  if(i == si && j == sj && visited.at(to_1d(si, sj)).at(to_1d(i, j))) return depth;
  visited.at(to_1d(si, sj)).at(to_1d(i, j)) = true;

  int res = -1;
  rep(k, 4){
    int ni = i + dy.at(k);
    int nj = j + dx.at(k);
    if(!is_within(ni, nj)) continue;
    if(s.at(ni).at(nj) == '#') continue;
    if((ni != si || nj != sj) && visited.at(to_1d(si, sj)).at(to_1d(ni, nj))) continue;
    int v = dfs(ni, nj, si, sj, s, visited, depth+1);
    res = max(res, v);
  }
  visited.at(to_1d(si, sj)).at(to_1d(i, j)) = false;
  return res;
}

void solve(){
  cin >> h >> w;

  vector<string> s(h);
  rep(i, h) cin >> s.at(i);

  vector<vector<bool>> visited(h*w, vector<bool>(h*w, false));
  int ans = 0;
  rep(i, h)rep(j, w){
    if(s.at(i).at(j) == '#') continue;
    int v = dfs(i, j, i, j, s, visited, 0);
    ans = max(ans, v);
  }
  if(ans <= 2){
    cout << -1 << endl;
  }else{
    cout << ans << endl;
  }
}

int main() {

  solve();

  return 0;
}
