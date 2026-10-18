# include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep_ll(i, n) for (ll i = 0; i < (ll)(n); i++)

template<class T> void out_vec(vector<T> &v){for(int i=0;i<(int)v.size();i++){cout<<v.at(i)<<" ";}cout<<endl;}
template<class T> void out_vec2d(vector<vector<T>> &v){for(int i=0;i<(int)v.size();i++){for(int j=0;j<(int)v.at(i).size();j++){cout<<v.at(i).at(j)<<" ";}cout<<endl;}}
void out_yn(bool b){if(b){cout << "Yes" << endl;}else{cout << "No" << endl;}}

int main() {
  int n, m;
  cin >> n >> m;

  vector<pair<int ,int>> edges;
  rep(i, m){
    int u, v;
    cin >> u >> v;
    u--; v--;
    edges.emplace_back(u, v);
  }

  int ans = INT_MAX/2;
  for(int i = 0; i < 1<<n; i++){
    int cnt = 0;
    for(auto [u, v] : edges){
      bool u_shift = (i>>u) & 1;
      bool v_shift = (i>>v) & 1;
      if(u_shift == v_shift) cnt++;
    }
    ans = min(ans, cnt);
  }

  cout << ans << endl;


  return 0;  
}
