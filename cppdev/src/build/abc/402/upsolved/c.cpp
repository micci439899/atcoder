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

  // 食材がどの料理に使われているか
  vector<vector<int>> idx(n);

  // 料理毎の苦手な食材の数
  vector<int> cnt(m);

  rep(i, m){
    int k;
    cin >> k;

    cnt.at(i) = k;

    rep(j, k){
      int a_ij;
      cin >> a_ij;
      a_ij--;

      idx.at(a_ij).push_back(i);
    }
  }

  int ans = 0;
  rep(i, n){
    int b_i;
    cin >> b_i;
    b_i--;

    // 克服した食材が使われた料理
    for(int j : idx.at(b_i)){
      cnt.at(j)--;
      if(cnt.at(j) == 0) ans++;
    }

    cout << ans << endl;
  }




  return 0;  
}
