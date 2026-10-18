# include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep_ll(i, n) for (ll i = 0; i < (ll)(n); i++)

template<class T> void out_vec(vector<T> &v){for(int i=0;i<(int)v.size();i++){cout<<v.at(i)<<" ";}cout<<endl;}
template<class T> void out_vec2d(vector<vector<T>> &v){for(int i=0;i<(int)v.size();i++){for(int j=0;j<(int)v.at(i).size();j++){cout<<v.at(i).at(j)<<" ";}cout<<endl;}}
void out_yn(bool b){if(b){cout << "Yes" << endl;}else{cout << "No" << endl;}}

vector<int> dx = {1, 0, -1, 0};
vector<int> dy = {0, 1, 0, -1};

bool is_within(int x, int y, int w, int h){
  if(x < 0 || w-1 < x) return false;
  if(y < 0 || h-1 < y) return false;
  return true;
}

int main() {
  int h, w, d;
  cin >> h >> w >> d;

  vector<string> s(h);
  rep(i, h) cin >> s.at(i);

  vector<vector<bool>> visited(h, vector<bool>(w, false));
  int ans = 0;
  queue<tuple<int, int, int>> q;

  rep(i, h)rep(j, w)if(s.at(i).at(j) == 'H'){
    auto tpl = make_tuple(i, j, d);
    q.push(tpl);
    visited.at(i).at(j) = true;
    ans++;
  }

  while(!q.empty()){
    int i, j, x;
    tie(i, j, x) = q.front();
    q.pop();

    if(x == 0) continue;

    rep(k, 4){
      int ny = i + dy.at(k);
      int nx = j + dx.at(k);

      if(!is_within(nx, ny, w, h)) continue;

      if(visited.at(ny).at(nx)) continue;

      if(s.at(ny).at(nx) == '#') continue;

      visited.at(ny).at(nx) = true;
      if(s.at(ny).at(nx) == '.') ans++;

      auto tpl = make_tuple(ny, nx, x-1);
      q.push(tpl);
    }
  }

  cout << ans << endl;




  return 0;  
}
