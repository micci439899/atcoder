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
vector<char> directions = {'R', 'D', 'L', 'U'};

bool is_within(int x, int y, int w, int h){
  if(x < 0 || w-1 < x) return false;
  if(y < 0 || h-1 < y) return false;
  return true;
}

struct Point {
  int x;
  int y;
  // int ope_cnt;
  // string ope;
  vector<pair<char, ll>> ope;
};

void solve(){
  int h, w;
  cin >> h >> w;

  vector<string> s(h);
  rep(i, h) cin >> s.at(i);

  int sx, sy;
  rep(i, h)rep(j, w){
    if(s.at(i).at(j) == 'S'){
      sx = j;
      sy = i;
    }
  }

  queue<Point> que;
  // que.push({sx, sy, 0, ""});
  // que.push({sx, sy, ""});
  vector<pair<char, ll>> v;
  que.push({sx, sy, v});

  ll cnt = 0;
  while(!que.empty()){
    Point p = que.front(); que.pop();
    // cout << "x: " << p.x << ", y: " << p.y;
    // if(p.ope_cnt > 5 * 1e6) continue;
    if(cnt > 5 * 1e6) break;

    char prev = s.at(p.y).at(p.x);

    rep(k, 4){
      int nx = p.x + dx.at(k);
      int ny = p.y + dy.at(k);

      if(!is_within(nx, ny, w, h)) continue;
      if(s.at(ny).at(nx) == '#') continue;
      // if(prev == 'o' && directions.at(k) != p.ope.back()) continue;
      // if(prev == 'x' && directions.at(k) == p.ope.back()) continue;
      if(prev == 'o' && directions.at(k) != p.ope.back().first) continue;
      if(prev == 'x' && directions.at(k) == p.ope.back().first) continue;

      if(s.at(ny).at(nx) == 'G'){
        out_yn(true);
        // cout << p.ope + directions.at(k) << endl;
        rep(i, p.ope.size()){
          rep(j, p.ope.at(i).second){
            cout << p.ope.at(i).first;
          }
        }
        cout << directions.at(k) << endl;
        return;
      }
      // Point nxt_p = {nx, ny, p.ope_cnt+1, p.ope + directions.at(k)};
      // Point nxt_p = {nx, ny, p.ope + directions.at(k)};
      vector<pair<char, ll>> nxt_ope;
      if(p.ope.size() == 0){
        nxt_ope.push_back({directions.at(k), 1});
      }else{
        nxt_ope = p.ope;
        if(nxt_ope.back().first == directions.at(k)){
          nxt_ope.back().second++;
        }else{
          nxt_ope.push_back({directions.at(k), 1});
        }
      }
      Point nxt_p = {nx, ny, nxt_ope};

      que.push(nxt_p);
      cnt++;
    }
  }

  out_yn(false);





}


int main() {

  solve();

  return 0;
}
