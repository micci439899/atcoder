# include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep_ll(i, n) for (ll i = 0; i < (ll)(n); i++)

template<class T> void out_vec(vector<T> &v){for(int i=0;i<(int)v.size();i++){cout<<v.at(i)<<" ";}cout<<endl;}
template<class T> void out_vec2d(vector<vector<T>> &v){for(int i=0;i<(int)v.size();i++){for(int j=0;j<(int)v.at(i).size();j++){cout<<v.at(i).at(j)<<" ";}cout<<endl;}}
void out_yn(bool b){if(b){cout << "Yes" << endl;}else{cout << "No" << endl;}}

int main() {
  int n, k;
  cin >> n >> k;

  string s;
  cin >> s;

  map<string, int> mp;
  //for(int i = 1; i <= n; i++) {
  for(int i = k; i <= k; i++) {
    for(int j = 0; j < n - i + 1; j++) {
      string sub_s = s.substr(j, i);
      mp[sub_s]++;
    }
  }


  int max_cnt = 0;
  for(auto [f, s] : mp) {
    //if(s == 1){
    //  continue;
    //}
    //max_size = max(max_size, (int)f.size());
    max_cnt = max(max_cnt, s);
    //cout << f << ":" << s << endl;
  }

  vector<string> ans;
  for(auto [f, s] : mp) {
    if(s == max_cnt) ans.push_back(f);
  }
  sort(ans.begin(), ans.end());

  cout << max_cnt << endl;
  out_vec(ans);



  return 0;
}


