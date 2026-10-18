# include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

template<class T> void out_vec(vector<T> &v){for(int i=0;i<(int)v.size();i++){cout<<v.at(i)<<" ";}cout<<endl;}
template<class T> void out_vec2d(vector<vector<T>> &v){for(int i=0;i<(int)v.size();i++){for(int j=0;j<(int)v.at(i).size();j++){cout<<v.at(i).at(j)<<" ";}cout<<endl;}}
void out_yn(bool b){if(b){cout << "Yes" << endl;}else{cout << "No" << endl;}}

int main() {
  int n, m;
  cin >> n >> m;

  ll cnt = 0;
  set<pair<int, int>> st;
  rep(i, m){
    int u, v;
    cin >> u >> v;

    if(u == v){
      cnt++;
      continue;
    }

    if(u > v) swap(u, v);
    if(st.count({u, v})){
      cnt++;
      continue;
    }
    st.insert({u, v});
  }

  cout << cnt << endl;


  return 0;  
}
