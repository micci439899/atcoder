# include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep_ll(i, n) for (ll i = 0; i < (ll)(n); i++)

template<class T> void out_vec(vector<T> &v){for(int i=0;i<(int)v.size();i++){cout<<v.at(i)<<" ";}cout<<endl;}
template<class T> void out_vec2d(vector<vector<T>> &v){for(int i=0;i<(int)v.size();i++){for(int j=0;j<(int)v.at(i).size();j++){cout<<v.at(i).at(j)<<" ";}cout<<endl;}}
void out_yn(bool b){if(b){cout << "Yes" << endl;}else{cout << "No" << endl;}}

int main() {
  string s;
  cin >> s;

  if(s.size()%2 != 0){
    cout << "No" << endl;
    return 0;
  }

  map<char, int> mp;
  for(int i = 0; 2*i <= s.size()-2; i++){
    if(s.at(2*i) != s.at(2*i+1)){
      cout << "No" << endl;
      return 0;
    }
    mp[s.at(2*i)]++;
  }

  for(auto [k, v] : mp){
    if(v != 1){
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;


  return 0;
}


