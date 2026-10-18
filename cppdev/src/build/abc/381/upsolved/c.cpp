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
  string s;
  cin >> s;

  int ans = 1;
  rep(i, n){
    if(s.at(i) == '/'){
      int l = i;
      int r = i;
      while(true){
        l--;
        r++;
        if(l < 0)break;
        if(r > n-1)break;
        if(s.at(l) != '1')break;
        if(s.at(r) != '2')break;
      }
      int mi = min(i-l-1, r-i-1);
      ans = max(ans, 2*mi + 1);
    }
  }

  cout << ans << endl;



  return 0;  
}
