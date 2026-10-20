# include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep_ll(i, n) for (ll i = 0; i < (ll)(n); i++)

template<class T> void print_vec(vector<T> &v){for(int i=0;i<(int)v.size();i++){cout<<v.at(i)<<" ";}cout<<endl;}
template<class T> void print_vec2d(vector<vector<T>> &v){for(int i=0;i<(int)v.size();i++){for(int j=0;j<(int)v.at(i).size();j++){cout<<v.at(i).at(j)<<" ";}cout<<endl;}}

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> g(n);
  rep(i, m){
    int a, b;
    cin >> a >> b;
    a--; b--;
    g.at(a).push_back(b);
    g.at(b).push_back(a);
  }

  int ans = 0;
  rep(i, n){
    vector<int> e = g.at(i);
    int e_num = 0;
    rep(j, e.size()){
      if(e.at(j)<i){
        e_num++;
      }
    }

    if(e_num == 1){
      ans++;
    }
  }

  cout << ans << endl;




  return 0;  
}
