# include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

template<class T> void out_vec(vector<T> &v){for(int i=0;i<(int)v.size();i++){cout<<v.at(i)<<" ";}cout<<endl;}
template<class T> void out_vec2d(vector<vector<T>> &v){for(int i=0;i<(int)v.size();i++){for(int j=0;j<(int)v.at(i).size();j++){cout<<v.at(i).at(j)<<" ";}cout<<endl;}}
void out_yn(bool b){if(b){cout << "Yes" << endl;}else{cout << "No" << endl;}}

vector<string> rotate(vector<string> &s, int num){
  vector<string> tmp_s = s;
  vector<string> res = s;
  int sz = res.size();

  rep(k, num){
    rep(i, sz)rep(j, sz){
      res.at(j).at(sz-1-i) = tmp_s.at(i).at(j);
    }
    tmp_s = res;
  }
  return res;
}


int main() {
  int n;
  cin >> n;

  vector<string> s(n);
  rep(i, n) cin >> s.at(i);

  vector<string> t(n);
  rep(i, n) cin >> t.at(i);

  int ans = INT_MAX;
  rep(k, 4){
    int cnt = 0;
    vector<string> rot_s = rotate(s, k);
    cnt += k;

    rep(i, n)rep(j, n){
      if(rot_s.at(i).at(j) != t.at(i).at(j)) cnt++;
    }

    ans = min(ans, cnt);
  }


  cout << ans << endl;




  return 0;
}


