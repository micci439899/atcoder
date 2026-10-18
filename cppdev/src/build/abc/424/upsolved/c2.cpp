# include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep_ll(i, n) for (ll i = 0; i < (ll)(n); i++)

template<class T> void print_vec(vector<T> &v){for(int i=0;i<(int)v.size();i++){cout<<v.at(i)<<" ";}cout<<endl;}
template<class T> void print_vec2d(vector<vector<T>> &v){for(int i=0;i<(int)v.size();i++){for(int j=0;j<(int)v.at(i).size();j++){cout<<v.at(i).at(j)<<" ";}cout<<endl;}}

vector<vector<ll>> g;
vector<bool> visited;
void dfs(ll v){
  visited.at(v) = true;
  for(auto vv : g.at(v)){
    if(!visited.at(vv)){
      dfs(vv);
    }
  }
}

int main() {
  ll n;
  cin >> n;
  g.resize(n+1);
  visited.assign(n+1, false);
  

  for(ll i = 1; i <= n; i++){
    ll a, b;
    cin >> a >> b;
    g.at(a).push_back(i);
    g.at(b).push_back(i);
  }

  visited.at(0) = true;
  dfs(0);

  ll ans = 0;
  for(ll i = 1; i < n+1; i++){
    if(visited.at(i))ans++;
  }

  cout << ans << endl;

  return 0;
  
}
