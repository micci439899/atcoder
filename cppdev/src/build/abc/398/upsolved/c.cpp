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

  vector<pair<int, int>> pairs;
  rep(i, n) {
    int a;
    cin >> a;
    pairs.emplace_back(a, i+1);
  }

  sort(pairs.rbegin(), pairs.rend());

  if(pairs.size() == 1) {
    cout << 1 << endl;
    return 0;
  }

  //cout << "pairs" << endl;
  //rep(i, n){
  //  cout << i << ": (" << pairs.at(i).first << ", " << pairs.at(i).second << ")" << endl;
  //}

  int duplicate_num = -1;
  rep(i, n-1){
    int current_num = pairs.at(i).first;
    if(duplicate_num == current_num) continue;

    if(current_num != pairs.at(i+1).first){
      cout << pairs.at(i).second << endl;
      return 0;
    }else{
      duplicate_num = current_num;
    }
  }

  if(pairs.at(pairs.size()-2).first != pairs.at(pairs.size()-1).first){
    cout << pairs.at(pairs.size()-1).second << endl;
    return 0;
  }

  cout << -1 << endl;

  return 0;  
}
