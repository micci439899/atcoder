# include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep_ll(i, n) for (ll i = 0; i < (ll)(n); i++)

template<class T> void out_vec(vector<T> &v){for(int i=0;i<(int)v.size();i++){cout<<v.at(i)<<" ";}cout<<endl;}
template<class T> void out_vec2d(vector<vector<T>> &v){for(int i=0;i<(int)v.size();i++){for(int j=0;j<(int)v.at(i).size();j++){cout<<v.at(i).at(j)<<" ";}cout<<endl;}}
void out_yn(bool b){if(b){cout << "Yes" << endl;}else{cout << "No" << endl;}}

int main() {
  int n, q;
  cin >> n >> q;

  // 各OSバージョンの台数
  vector<int> versions(n+1, 1);
  versions.at(0) = 0;

  // 1番小さいOSバージョン
  int min_version = 1;

  while(q--){
    int x, y;
    cin >> x >> y;

    int upgraded_num = 0;
    while(min_version <= x){
      int version_num = versions.at(min_version);
      upgraded_num += version_num;
      min_version++;
    }
    versions.at(y) += upgraded_num;

    cout << upgraded_num << endl;
  }



  return 0;  
}
