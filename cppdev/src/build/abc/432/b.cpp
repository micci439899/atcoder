# include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep_ll(i, n) for (ll i = 0; i < (ll)(n); i++)

template<class T> void out_vec(vector<T> &v){for(int i=0;i<(int)v.size();i++){cout<<v.at(i)<<" ";}cout<<endl;}
template<class T> void out_vec2d(vector<vector<T>> &v){for(int i=0;i<(int)v.size();i++){for(int j=0;j<(int)v.at(i).size();j++){cout<<v.at(i).at(j)<<" ";}cout<<endl;}}
void out_yn(bool b){if(b){cout << "Yes" << endl;}else{cout << "No" << endl;}}

int main() {
  int x;
  cin >> x;

  string xs = to_string(x);
  reverse(xs.begin(), xs.end());

  vector<int> ans;
  do{

    int base = 1;
    int idx = 0;
    int res = 0;
    bool is_valid = true;
    for(auto c : xs){
      if(idx == xs.size()-1 && c == '0'){
        is_valid = false;
        break;
      }
      res += int(c - '0') * base;
      base *= 10;
      idx++;
    }

    if(is_valid){
      ans.push_back(res);
    }

  }while(next_permutation(xs.begin(), xs.end()));

  sort(ans.begin(), ans.end());

  cout << ans.at(0) << endl;



  return 0;
}


