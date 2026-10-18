# include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

template<class T> void out_vec(vector<T> &v){for(int i=0;i<(int)v.size();i++){cout<<v.at(i)<<" ";}cout<<endl;}
template<class T> void out_vec2d(vector<vector<T>> &v){for(int i=0;i<(int)v.size();i++){for(int j=0;j<(int)v.at(i).size();j++){cout<<v.at(i).at(j)<<" ";}cout<<endl;}}
void out_yn(bool b){if(b){cout << "Yes" << endl;}else{cout << "No" << endl;}}


vector<int> dx = {1, 0, -1, 0, 1, -1, -1, 1};
vector<int> dy = {0, 1, 0, -1, 1, 1, -1, -1};

bool is_within(int x, int y, int w, int h){
  if(x < 0 || w-1 < x) return false;
  if(y < 0 || h-1 < y) return false;
  return true;
}


vector<set<int>> g2;
vector<bool> visited;
vector<ll> g3;

void dfs(int v){
  if(visited.at(v)) return;
  visited.at(v) = true;

  for(int vv : g2.at(v)){
    dfs(v);
  }
}

int main() {
  int h, w;
  cin >> h >> w;

  vector<string> g(h);
  rep(i, h){
    cin >> g.at(i);
  }

  map<char, vector<pair<int, int>>> mp;

  rep(i, h)rep(j, w){
    char ch = g.at(i).at(j);
    if('a' <= ch && ch <= 'z'){
      auto p = make_pair(i, j);
      mp[ch].push_back(p);
    }
  }

  // rep(i, h)rep(j, w){
  //   int idx = i*w+j;
  //   cout << idx << endl;
  // }

  //vector<vector<int>> g2(h, vector<int>(w));
  // vector<vector<int>> g2(h*w);
  // vector<set<int>> g2(h*w);
  g2.resize(h*w);
  visited.assign(h*w, false);
  g3.resize(h*w);



  rep(i, h)rep(j, w){
    int idx = i*w+j;
    // cout << "idx: " << idx << endl;
    char ch = g.at(i).at(j);
    if(ch != '#'){
      // cout << "surrounded" << endl;
      rep(k, 4){
        int nx = j + dx.at(k);
        int ny = i + dy.at(k);

        if(!is_within(nx, ny, w, h)) continue;

        if(g.at(ny).at(nx) != '#'){
          // cout << "nx: " << nx << " ny: " << ny << endl;
          int idx2 = ny*w+nx;
          // cout << "idx2: " << idx2 << endl;
          // g2.at(idx).push_back(idx2);
          // g2.at(idx2).push_back(idx);
          g2.at(idx).insert(idx2);
          g2.at(idx2).insert(idx);
        }
      }

      if('a' <= ch && ch <= 'z'){
        // cout << "it is alphabet " << endl;
        vector<pair<int, int>> v = mp.at(ch);
        for(auto p : v){
          if(i == p.first && j == p.second) continue;
          int idx2 = p.first*w+p.second;
          // cout << "idx2: " << idx2 << endl;
          // g2.at(idx).push_back(idx2);
          // g2.at(idx2).push_back(idx);
          g2.at(idx).insert(idx2);
          g2.at(idx2).insert(idx);
        }
      }
    }
  }

  // rep(i, g2.size()){
  //   cout << i << endl;
  //   for(int it : g2.at(i)){
  //     cout << it << " ";
  //   }
  //   cout << endl;
  // }

  dfs(0);

  ll ans = 0;
  if(!visited.at(h*w-1)){
    cout << -1 << endl;
  }else{
    cout << ans << endl;
  }

  // out_vec2d(g2);




  // for(auto [k,v] : mp){
  //   cout << k << endl;
  //   for(auto p : v){
  //     cout << p.first << ":" << p.second << endl;
  //   }
  // }




  


  return 0;
}
