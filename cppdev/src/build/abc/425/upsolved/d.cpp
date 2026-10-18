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

bool is_target(int x, int y, int w, int h, vector<string> &s){
  if(s.at(y).at(x) == '#') return false;

  int cnt = 0;
  rep(k, 4){
    int ni = y + dy.at(k);
    int nj = x + dx.at(k);

    if(!is_within(nj, ni, w, h)) continue;

    if(s.at(ni).at(nj) == '#') cnt++;
  }

  return cnt == 1;
}

void out_graph(vector<string> &s){
  rep(i, s.size()){
    cout << s.at(i) << endl;
  }
}

void solve(){
  int h, w;
  cin >> h >> w;

  vector<string> s(h);
  rep(i, h) cin >> s.at(i);

  vector<pii> targets;

  // 回数はh*w回で十分（この考察が一番ムズいと思う...）
  rep(i, h*w){
    if(i==0){
      rep(i, h)rep(j, w)if(is_target(j, i, w, h, s)) targets.emplace_back(i, j);
    }else{
      vector<pii> next_targets;
      rep(x, targets.size()){
        int i = targets.at(x).first;
        int j = targets.at(x).second;
        rep(k, 4){
          int ni = i + dy.at(k);
          int nj = j + dx.at(k);

          if(!is_within(nj, ni, w, h)) continue;

          if(is_target(nj, ni, w, h, s)){
            next_targets.emplace_back(ni, nj);
          }
        }
      }
      targets = next_targets;
    }

    rep(x, targets.size()){
      int i = targets.at(x).first;
      int j = targets.at(x).second;
      s.at(i).at(j) = '#';
    }
  }


/*
  queue<pii> q;
  rep(i, h)rep(j, w)if(s.at(i).at(j) == '#') q.emplace(i, j);

  while(!q.empty()){
    pii m = q.front(); q.pop();

    debug(m);
    out_graph(s);

    vector<pii> upd;

    rep(k, 4){
      int ni = m.first + dy.at(k);
      int nj = m.second + dx.at(k);

      if(!is_within(nj, ni, w, h)) continue;

      if(is_target(nj, ni, w, h, s)){
        //s.at(ni).at(nj) = '#';
        q.emplace(ni, nj);
        upd.emplace_back(ni, nj);
      }
    }
    // 都度更新だと他に影響が出る...
    rep(k, upd.size()){
      int ni = upd.at(k).first;
      int nj = upd.at(k).second;

      s.at(ni).at(nj) = '#';
    }
  }
*/


  int cnt = 0;
  rep(i, h)rep(j, w)if(s.at(i).at(j) == '#') cnt++;

  cout << cnt << endl;
}


int main() {

  solve();

  return 0;
}
