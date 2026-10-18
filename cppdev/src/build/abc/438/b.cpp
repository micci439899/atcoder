# include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

template<class T> void out_vec(vector<T> &v){for(int i=0;i<(int)v.size();i++){cout<<v.at(i)<<" ";}cout<<endl;}
template<class T> void out_vec2d(vector<vector<T>> &v){for(int i=0;i<(int)v.size();i++){for(int j=0;j<(int)v.at(i).size();j++){cout<<v.at(i).at(j)<<" ";}cout<<endl;}}
void out_yn(bool b){if(b){cout << "Yes" << endl;}else{cout << "No" << endl;}}

int main() {
  int n, m;
  cin >> n >> m;

  string s, t;
  cin >> s >> t;

  int ans = INT_MAX/2;
  for(int i = 0; i < s.size()-t.size()+1; i++){
    // cout << i << endl;
    int res = 0;
    string ss = s.substr(i, t.size());
    string tt = t;

    int cnt = 0;
    for(int j = 0; j < t.size(); j++){
      int tj = int(tt.at(j) - '0');
      int sj = int(ss.at(j) - '0');
      if(tj <= sj){
        cnt += sj - tj;
      }else{
        sj += 10;
        cnt += sj - tj;
      }

      // cout << "tj: " << tj << endl;

      // for(int k = 0; k < 9; k++){
      //   tj++;
      //   if(tj == 10)tj=0;

      //   cnt++;

      //   tt.at(j) = tj+'0';

      //   cout << "tt:" << tt << endl;
      //   if(ss == tt){
      //     ans = min(ans, cnt);
      //     break;
      //   }
      // }
    }
      ans = min(ans, cnt);
  }


  cout << ans << endl;





  return 0;
}


