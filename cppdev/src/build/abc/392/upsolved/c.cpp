# include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep_ll(i, n) for (ll i = 0; i < (ll)(n); i++)

template<class T> void out_vec(vector<T> &v){for(int i=0;i<(int)v.size();i++){cout<<v.at(i)<<" ";}cout<<endl;}
template<class T> void out_vec2d(vector<vector<T>> &v){for(int i=0;i<(int)v.size();i++){for(int j=0;j<(int)v.at(i).size();j++){cout<<v.at(i).at(j)<<" ";}cout<<endl;}}
void out_yn(bool b){if(b){cout << "Yes" << endl;}else{cout << "No" << endl;}}

int main() {
  int n;
  cin >> n;

  // key: ゼッケン、value: ゼッケンを着けている人
  map<int, int> z2p;

  // key: ゼッケンを着けている人、value: ゼッケン
  map<int, int> p2z;

  // key: 見つめている人、value: 見つめられてる人
  map<int, int> p2p;

  rep(i, n){
    int p;
    cin >> p;
    p2p[i+1] = p;
  }

  rep(i, n){
    int q;
    cin >> q;
    z2p[q] = i+1;
    p2z[i+1] = q;
  }

  vector<int> ans;
  for(auto [z, p] : z2p){
    // 見つめられている人
    int p2 = p2p[p];

    // 見つめられている人のゼッケン
    int z2 = p2z[p2];

    ans.push_back(z2);
  }

  out_vec(ans);





  return 0;  
}
