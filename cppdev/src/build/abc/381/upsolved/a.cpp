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

  if(n%2 == 0){
    cout << "No" << endl;
    return 0;
  }

  rep(i, n){
    if(i < n/2){
      if(s.at(i) != '1'){
        cout << "No" << endl;
        return 0;
      }
    }else if(i == n/2){
      if(s.at(i) != '/'){
        cout << "No" << endl;
        return 0;
      }
    }else{
      if(s.at(i) != '2'){
        cout << "No" << endl;
        return 0;
      }
    }
  }
  cout << "Yes" << endl;


  return 0;
}
