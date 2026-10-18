# include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep_ll(i, n) for (ll i = 0; i < (ll)(n); i++)

template<class T> void print_vec(vector<T> &v){for(int i=0;i<(int)v.size();i++){cout<<v.at(i)<<" ";}cout<<endl;}
template<class T> void print_vec2d(vector<vector<T>> &v){for(int i=0;i<(int)v.size();i++){for(int j=0;j<(int)v.at(i).size();j++){cout<<v.at(i).at(j)<<" ";}cout<<endl;}}

int main() {
  ll n;
  cin >> n;

  vector<vector<ll>> g(n+1);
  for(ll i = 1; i <= n; i++){
    ll a, b;
    cin >> a >> b;
    g.at(a).push_back(i);
    g.at(b).push_back(i);
  }

  queue<ll> q;
  q.push(0);

  vector<bool> visited(n+1, false);
  visited.at(0) = true;

  while(!q.empty()){
    ll v = q.front();
    q.pop();

    for(ll vv : g.at(v)){
      if(visited.at(vv)) continue;
      visited.at(vv) = true;
      q.push(vv);
    }
  }

  ll ans = 0;
  for(ll i = 1; i < n+1; i++){
    if(visited.at(i))ans++;
  }

  cout << ans << endl;

  return 0;
  
}
