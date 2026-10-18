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

  vector<vector<int>> b(1e6+1);
  rep(i, n){
    b.at(a.at(i)).push_back(i);
  }

  int ans = INT_MAX/2;
  rep(i, b.size()){
    vector<int> ids = b.at(i);
    if(ids.size() <= 1) continue;
    for(int j = 0; j < ids.size()-1; j++){
      int diff = ids.at(j+1) - ids.at(j) + 1;
      ans = min(diff, ans);
    }
  }

  if(ans == INT_MAX/2){
    cout << -1 << endl;
  }else{
    cout << ans << endl;
  }


  return 0;  
}
