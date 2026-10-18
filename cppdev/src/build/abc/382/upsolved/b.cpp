# include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep_ll(i, n) for (ll i = 0; i < (ll)(n); i++)

template<class T> void out_vec(vector<T> &v){for(int i=0;i<(int)v.size();i++){cout<<v.at(i)<<" ";}cout<<endl;}
template<class T> void out_vec2d(vector<vector<T>> &v){for(int i=0;i<(int)v.size();i++){for(int j=0;j<(int)v.at(i).size();j++){cout<<v.at(i).at(j)<<" ";}cout<<endl;}}
void out_yn(bool b){if(b){cout << "Yes" << endl;}else{cout << "No" << endl;}}


int main() {
  int n, d;
  cin >> n >> d;

  string s;
  cin >> s;

  int c_cnt = 0;
  string t;
  for(int i = s.size()-1; i >= 0; i--){
    if(d <= 0){
      t.push_back(s.at(i));
    }else{
      if(s.at(i) == '@'){
        t.push_back('.');
        d--;
      }else{
        t.push_back(s.at(i));
      }
    }
  }
  reverse(t.begin(), t.end());

  cout << t << endl;




  return 0;
}


