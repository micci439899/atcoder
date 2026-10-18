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

vector<char> arrows = {'<', '^', '>', 'v'};

bool is_within(int x, int y, int w, int h){
  if(x < 0 || w-1 < x) return false;
  if(y < 0 || h-1 < y) return false;
  return true;
}

int main() {
  int h, w;
  cin >> h >> w;

  vector<string> s(h);
  rep(i, h) cin >> s.at(i);

  queue<pair<int, int>> q;
  rep(i, h)rep(j, w)if(s.at(i).at(j) == 'E'){
    q.emplace(i, j);
  }

  vector<string> t = s;

  vector<vector<bool>> visited(h, vector<bool>(w, false));

  while(!q.empty()){
    auto [i, j] = q.front();
    q.pop();

    rep(k, 4){
      int ny = i + dy.at(k);
      int nx = j + dx.at(k);

      if(!is_within(nx, ny, w, h)) continue;

      if(s.at(ny).at(nx) != '.') continue;

      if(visited.at(ny).at(nx)) continue;

      visited.at(ny).at(nx) = true;

      t.at(ny).at(nx) = arrows.at(k);

      q.emplace(ny, nx);
    }
  }

  rep(i, h){
    cout << t.at(i) << endl;
  }


  return 0;  
}
