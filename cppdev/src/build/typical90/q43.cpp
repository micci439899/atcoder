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

int INF = INT_MAX/2;

vector<int> dx = {1, 0, -1, 0};
vector<int> dy = {0, 1, 0, -1};

struct State {
  int x, y, dir;
};

bool is_within(int x, int y, int w, int h){
  if(x < 0 || w-1 < x) return false;
  if(y < 0 || h-1 < y) return false;
  return true;
}

void solve(){
  int h, w;
  cin >> h >> w;

  int rs, cs, rt, ct;
  cin >> rs >> cs >> rt >> ct;
  rs--; cs--; rt--; ct--;

  vector<string> s(h);
  rep(i, h) cin >> s.at(i);

  vector<vector<vector<int>>> dist(h, vector<vector<int>>(w, vector<int>(4, INF)));

  deque<State> deq;
  rep(i, 4){
    dist.at(rs).at(cs).at(i) = 0;
    deq.push_back({cs, rs, i});
  }

  while(!deq.empty()){
    State u = deq.front(); deq.pop_front();
    rep(k, 4){
      int nx = u.x + dx.at(k);
      int ny = u.y + dy.at(k);
      if(!is_within(nx, ny, w, h)) continue;
      if(s.at(ny).at(nx) == '#') continue;

      int extra_cost = u.dir != k ? 1 : 0;
      int cost = dist.at(u.y).at(u.x).at(u.dir) + extra_cost;

      if(dist.at(ny).at(nx).at(k) > cost){
        dist.at(ny).at(nx).at(k) = cost;
        if(u.dir != k){
          deq.push_back({nx, ny, k});
        }else{
          deq.push_front({nx, ny, k});
        }
      }
    }
  }

  int ans = INF;
  rep(k, 4){
    ans = min(ans, dist.at(rt).at(ct).at(k));
  }

  cout << ans << endl;
}

int main() {

  solve();

  return 0;  
}
