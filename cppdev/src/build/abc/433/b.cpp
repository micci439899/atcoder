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

  vector<int> a(n);
  rep(i, n) cin >> a.at(i);

  rep(i, n){
    if(i == 0){
      cout << -1 << endl;
      continue;
    }
    bool exist = false;
    for(int j = i-1; j >= 0; j--){
      if(a.at(j) > a.at(i)){
        cout << j+1 << endl;
        exist = true;
        break;
      }
    }
    if(!exist){
      cout << -1 << endl;
    }
  }



  return 0;
}


