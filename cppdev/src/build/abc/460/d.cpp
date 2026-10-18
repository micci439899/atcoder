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

bool is_within(int x, int y, int w, int h){
  if(x < 0 || w-1 < x) return false;
  if(y < 0 || h-1 < y) return false;
  return true;
}

struct Point {
  int x;
  int y;
  bool switched;
};

void solve(){
  int h, w; cin >> h >> w;

  vector<string> s(h);
  rep(i, h) cin >> s.at(i);

  rep(i, h)cout << s.at(i) << endl;


/*
  // vector<pii> black;
  // vector<pii> white;
  queue<pii> black;
  queue<pii> white;

  rep(i, h)rep(j, w){
    // if(s.at(i).at(j) == '.') white.push_back({i, j});
    // else black.push_back({i, j});
    if(s.at(i).at(j) == '.') white.push({i, j});
    else black.push({i, j});
  }

  vector<vector<bool>> changes(h, vector<bool>(w, false));

  bool is_changed = false;
  while(true){
    if(is_changed){
      vector<pii> nblack;
      while(!black.empty()){
        pii ij = white.front(); white.pop();
        rep(k, 8){
          int ni = ij.first + dy.at(k);
          int nj = ij.second + dx.at(k);
          if(!is_within(nj, ni, w, h)) continue;
          if(s.at(ni).at(nj) == '.') cnt++;
        }
        if(cnt > 0){
          nblack.push_back({ni, nj});
        }
      }
      if(nblack.size() == 0)break;
      rep(i, nblack.size()){
        white.push(nblack.at(i));
      }
    }else{
      vector<pii> nblack;
      // rep(i, white.size()){
      while(!white.empty()){
        pii ij = white.front(); white.pop();
        rep(k, 8){
          int ni = ij.first + dy.at(k);
          int nj = ij.second + dx.at(k);
          if(!is_within(nj, ni, w, h)) continue;
          if(s.at(ni).at(nj) == '#') cnt++;
        }
        if(cnt > 0){
          nblack.push_back({ni, nj});
        }
      }

      if(nblack.size() == 0)break;
      rep(i, nblack.size()){
        black.push(nblack.at(i));
        changes.at(i).at(j)
      }
    }
  }
*/




/*
  queue<pii> que;
  rep(i, h)rep(j, w){
    if(s.at(i).at(j) == '.') que.push({i, j});
  }

  bool is_changed = false;
  while(true){
    vector<pii> black;
    vector<pii> white;
    while(!que.empty()){
      pii ij = que.front(); que.pop();
      int cnt = 0;
      rep(k, 8){
        int ni = ij.first + dy.at(k);
        int nj = ij.second + dx.at(k);
        if(s.at(ni).at(nj) == '#') cnt++;
      }
      if(cnt > 0){
        black.push_back({ni, nj});
      }
    }

    rep(k, n){
      que.push(black.at(k));
      // pii ij = black.at(k);
      // s.at(ij.first).at(ij.second) = "#";
    }
    is_changed = !is_changed;
  }
*/



}

int main() {

  solve();

  return 0;
}
