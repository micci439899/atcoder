# include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep_ll(i, n) for (ll i = 0; i < (ll)(n); i++)

template<class T> void out_vec(vector<T> &v){for(int i=0;i<(int)v.size();i++){cout<<v.at(i)<<" ";}cout<<endl;}
template<class T> void out_vec2d(vector<vector<T>> &v){for(int i=0;i<(int)v.size();i++){for(int j=0;j<(int)v.at(i).size();j++){cout<<v.at(i).at(j)<<" ";}cout<<endl;}}
void out_yn(bool b){if(b){cout << "Yes" << endl;}else{cout << "No" << endl;}}


int main() {
  int a, b, c, d, e;
  cin >> a >> b >> c >> d >> e;

  vector<int> points = { a, b ,c, d, e };

  string alpha = "ABCDE";

  vector<pair<int, string>> ans;

  for(int i = 1; i < 1<<5; i++) {
    string s = "";
    int point = 0;
    for(int j = 0; j < 5; j++) {
      if(i>>j & 1){
        s.push_back(alpha.at(j));
        point += points.at(j);
      }
    }
    pair<int, string> p = make_pair(point, s);
    ans.push_back(p);
  }

  auto cmp = [&](pair<int, string> p1, pair<int, string> p2) {
    if(p1.first > p2.first){
      return true;
    } else if(p1.first == p2.first) {
      return p1.second < p2.second;
    } else {
      return false;
    }
  };

  sort(ans.begin(), ans.end(), cmp);

  for(auto [f, s] : ans) {
    cout << s << endl;
  }


  return 0;  
}
