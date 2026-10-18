# include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

template<class T> void out_vec(vector<T> &v){for(int i=0;i<(int)v.size();i++){cout<<v.at(i)<<" ";}cout<<endl;}
template<class T> void out_vec2d(vector<vector<T>> &v){for(int i=0;i<(int)v.size();i++){for(int j=0;j<(int)v.at(i).size();j++){cout<<v.at(i).at(j)<<" ";}cout<<endl;}}
void out_yn(bool b){if(b){cout << "Yes" << endl;}else{cout << "No" << endl;}}

int main() {
  int n;
  cin >> n;

  vector<int> a(n);
  rep(i, n) cin >> a.at(i);

  int ans = 0;
  rep(i, n){
    // int sm = 0;
    // for(int j = i; j < n; j++){
    //   sm += a.at(j);
    // }
    int sm = 0;
    for(int j = i; j < n; j++){
      sm += a.at(j);
      bool is_ok = true;
      for(int k = i; k <= j;k++){
        // cout << "i:" << i << " j:" << j << " k:" << k << endl;
        if(sm % a.at(k) == 0) {
          is_ok = false;
          // cout << sm << " cannot be divided by " << a.at(k) << endl;
          // ans++;
        }
      }
      if(is_ok) ans++;
    }
  }

  cout << ans << endl;




  return 0;
}


