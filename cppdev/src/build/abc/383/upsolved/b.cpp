# include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep_ll(i, n) for (ll i = 0; i < (ll)(n); i++)

template<class T> void out_vec(vector<T> &v){for(int i=0;i<(int)v.size();i++){cout<<v.at(i)<<" ";}cout<<endl;}
template<class T> void out_vec2d(vector<vector<T>> &v){for(int i=0;i<(int)v.size();i++){for(int j=0;j<(int)v.at(i).size();j++){cout<<v.at(i).at(j)<<" ";}cout<<endl;}}
void out_yn(bool b){if(b){cout << "Yes" << endl;}else{cout << "No" << endl;}}


bool is_within(int x, int y, int w, int h){
  if(x < 0 || w-1 < x) return false;
  if(y < 0 || h-1 < y) return false;
  return true;
}

set<pair<int, int>> find_humidified(vector<string> &s, int x, int y, int d, int w, int h){
  set<pair<int, int>> st;
  for(int i = -d; i <= d; i++){
    for(int j = -d; j <= d; j++){
      if(abs(i) + abs(j) > d) continue;

      int nx = x + j;
      int ny = y + i;

      if(!is_within(nx, ny, w, h)) continue;

      if(s.at(ny).at(nx) == '.') {
        pair<int, int> p = make_pair(ny, nx);
        st.insert(p);
      }
    }
  }
  return st;
}


int main() {
  int h, w, d;
  cin >> h >> w >> d;

  vector<string> s(h);
  rep(i, h) cin >> s.at(i);

  // 床の座標
  vector<pair<int, int>> floors;
  rep(i, h)rep(j, w){
    if(s.at(i).at(j) == '.'){
      floors.emplace_back(i, j);
    }
  }

  int max_humidified = 0;
  for(int i = 0; i < floors.size(); i++){
    auto [fj1, fi1] = floors.at(i);
    set<pair<int, int>> st1 = find_humidified(s, fi1, fj1, d, w, h);

    for(int j = i+1; j < floors.size(); j++){
      auto [fj2, fi2] = floors.at(j);
      set<pair<int, int>> st2 = find_humidified(s, fi2, fj2, d, w, h);

      // 加湿器2つを併合（同じ床の可能性あり）
      for(auto p : st1){
        st2.insert(p);
      }
      max_humidified = max(max_humidified, (int)st2.size());
    }
  }

  cout << max_humidified << endl;






  return 0;
}


