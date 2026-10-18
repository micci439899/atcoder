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

const int INF = 1<<30;

vector<int> dx = {1, 0, -1, 0, 1, -1, -1, 1};
vector<int> dy = {0, 1, 0, -1, 1, 1, -1, -1};

struct Point {
  int x;
  int y;
  bool switched;
};

bool is_within(int x, int y, int w, int h){
  if(x < 0 || w-1 < x) return false;
  if(y < 0 || h-1 < y) return false;
  return true;
}

void solve(){
  int h, w; cin >> h >> w;

  vector<string> a(h);
  rep(i, h) cin >> a.at(i);

  int sx, sy, gx, gy;
  rep(y, h)rep(x, w){
    if(a.at(y).at(x) == 'S'){
      sy = y;
      sx = x;
    }
    if(a.at(y).at(x) == 'G'){
      gy = y;
      gx = x;
    }
  }

  vector<vector<vector<int>>> dist(2, vector(h, vector<int>(w, INF)));
  dist.at(0).at(sy).at(sx) = 0;

  queue<Point> que;
  que.push({sx, sy, false});

  while(!que.empty()){
    Point point = que.front(); que.pop();
    rep(k, 4){
      int ny = point.y + dy.at(k);
      int nx = point.x + dx.at(k);
      if(!is_within(nx, ny, w, h)) continue;
      if(a.at(ny).at(nx) == '#') continue;
      if(a.at(ny).at(nx) == 'o' && point.switched) continue;
      if(a.at(ny).at(nx) == 'x' && !point.switched) continue;
      bool nswitched = a.at(ny).at(nx) != '?' ? point.switched : !point.switched;
      if(dist.at(nswitched).at(ny).at(nx) != INF) continue;
      dist.at(nswitched).at(ny).at(nx) = dist.at(point.switched).at(point.y).at(point.x) + 1;
      que.push({nx, ny, nswitched});
    }
  }

  // rep(i, 2){
  //   out_vec2d(dist.at(i));
  // }

  int mi = min(dist.at(0).at(gy).at(gx), dist.at(1).at(gy).at(gx));
  if(mi == INF) mi = -1;
  cout << mi << endl;

}

int main() {

  solve();

  return 0;
}
