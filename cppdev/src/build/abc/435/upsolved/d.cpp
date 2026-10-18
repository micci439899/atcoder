# include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

template<class T> void out_vec(vector<T> &v){for(int i=0;i<(int)v.size();i++){cout<<v.at(i)<<" ";}cout<<endl;}
template<class T> void out_vec2d(vector<vector<T>> &v){for(int i=0;i<(int)v.size();i++){for(int j=0;j<(int)v.at(i).size();j++){cout<<v.at(i).at(j)<<" ";}cout<<endl;}}
void out_yn(bool b){if(b){cout << "Yes" << endl;}else{cout << "No" << endl;}}

vector<vector<int>> g;
vector<bool> visited;

void dfs(vector<vector<int>> &g, int v){
  if(visited.at(v)) return;
  visited.at(v) = true;

  for(int vv : g.at(v)){
    dfs(g, vv);
  }
}

int main() {
  int n, m;
  cin >> n >> m;

  g.resize(n);
  visited.assign(n, false);

  rep(i, m){
    int x, y;
    cin >> x >> y;
    x--; y--;
    g.at(y).push_back(x);
  }

  int q;
  cin >> q;

  while(q--){
    int q_type, v;
    cin >> q_type >> v;
    v--;

    if(q_type == 1){
      dfs(g, v);
    }else{
      out_yn(visited.at(v));
    }
  }


  return 0;
}
