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

vector<int> dx = {1, 0, -1, 0};
vector<int> dy = {0, 1, 0, -1};

bool is_within(int x, int y, int w, int h){
  if(x < 0 || w-1 < x) return false;
  if(y < 0 || h-1 < y) return false;
  return true;
}

void solve(){
  int h, w;
  cin >> h >> w;

  vector<string> s(h);

  rep(i, h) cin >> s.at(i);

  vector<vector<bool>> visited(h, vector<bool>(w, false));

  int cnt = 0;
  queue<pii> que;
  rep(i, h)rep(j, w){
    if(s.at(i).at(j) == '.'){
      if(visited.at(i).at(j)) continue;

      visited.at(i).at(j) = true;
      que.push({i, j});
      bool is_edge = false;
      if(i == 0 || i == h-1 || j == 0 || j == w-1) is_edge = true;
      while(!que.empty()){
        pii point = que.front(); que.pop();
        rep(k, 4){
          int ni = point.first + dy.at(k);
          int nj = point.second + dx.at(k);
          if(!is_within(nj, ni, w, h)) continue;
          if(s.at(ni).at(nj) == '#') continue;
          if(visited.at(ni).at(nj)) continue;
          visited.at(ni).at(nj) = true;
          que.push({ni, nj});
          if(ni == 0 || ni == h-1 || nj == 0 || nj == w-1) is_edge = true;
        }

      }
      if(!is_edge) cnt++;
    }
  }

  cout << cnt << endl;




}

int main() {

  solve();

  return 0;  
}
