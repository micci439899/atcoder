# include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

template<class T> void out_vec(vector<T> &v){for(int i=0;i<(int)v.size();i++){cout<<v.at(i)<<" ";}cout<<endl;}
template<class T> void out_vec2d(vector<vector<T>> &v){for(int i=0;i<(int)v.size();i++){for(int j=0;j<(int)v.at(i).size();j++){cout<<v.at(i).at(j)<<" ";}cout<<endl;}}
void out_yn(bool b){if(b){cout << "Yes" << endl;}else{cout << "No" << endl;}}

vector<vector<int>> g;
vector<bool> visited;

void dfs(int v){
  //if(visited.a(v)) return;
  visited.at(v) = true;

  for(auto u : g.at(v)){
    if(visited.at(u)) continue;
    dfs(u);
  }
}

int main() {
  int n, m;
  cin >> n >> m;

  g.resize(n);
  visited.assign(n, false);
  rep(i, m){
    int a, b;
    cin >> a >> b;
    a--; b--;
    g.at(a).push_back(b);
    g.at(b).push_back(a);
  }

  rep(i, n){
    if(g.at(i).size() != 2){
      out_yn(false);
      return 0;
    }
  }

  dfs(0);

  rep(i, n){
    if(!visited.at(i)){
      out_yn(false);
      return 0;
    }
  }

  out_yn(true);










  return 0;  
}
