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
  s = "s" + s + "e";

  int cnt = 0;
  rep(i, s.size()-1){
    if(s.at(i) == 's' && s.at(i+1) == 'o'){
      cnt++;
    }else if(s.at(i) == 'i' && s.at(i+1) == 'e'){
      cnt++;
    }else if(s.at(i) == 'i' && s.at(i+1) == 'i'){
      cnt++;
    }else if(s.at(i) == 'o' && s.at(i+1) == 'o'){
      cnt++;
    }
  }

  cout << cnt << endl;



  return 0;
}


