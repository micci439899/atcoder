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

  if(a.at(0) == 1){
    cout << 1 << endl;
    return 0;
  }

  int l_idx = 0;
  int r_idx = l_idx + a.at(0);

  while(l_idx < r_idx){
    r_idx = max(r_idx, l_idx + a.at(l_idx));

    // cout << "l_idx: " << l_idx << " r_idx: " << r_idx << endl;

    if(r_idx > n) break;

    l_idx++;

    if(l_idx >= n){
      cout << n << endl;
      return 0;
    }
  }

  int ans = r_idx > n ? n : r_idx;
  cout << ans << endl;


  return 0;  
}
