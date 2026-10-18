# include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep_ll(i, n) for (ll i = 0; i < (ll)(n); i++)

template<class T> void out_vec(vector<T> &v){for(int i=0;i<(int)v.size();i++){cout<<v.at(i)<<" ";}cout<<endl;}
template<class T> void out_vec2d(vector<vector<T>> &v){for(int i=0;i<(int)v.size();i++){for(int j=0;j<(int)v.at(i).size();j++){cout<<v.at(i).at(j)<<" ";}cout<<endl;}}
void out_yn(bool b){if(b){cout << "Yes" << endl;}else{cout << "No" << endl;}}

int main() {
  int k;
  string s, t;
  cin >> k >> s >> t;

  // 解説AC
  int s_sz = s.size();
  int t_sz = t.size();

  if(s_sz + 1 == t_sz){
    // insert
    int prefix_cnt = 0;
    int suffix_cnt = 0;

    while(prefix_cnt < s_sz){
      if(s.at(prefix_cnt) == t.at(prefix_cnt)){
        prefix_cnt++;
      }else{
        break;
      }
    }

    while(suffix_cnt < s_sz){
      int s_idx = s_sz - suffix_cnt - 1;
      int t_idx = t_sz - suffix_cnt - 1;
      if(s.at(s_idx) == t.at(t_idx)){
        suffix_cnt++;
      }else{
        break;
      }
    }

    out_yn(prefix_cnt + suffix_cnt >= s_sz);

  }else if(s_sz == t_sz + 1){
    // delete
    int prefix_cnt = 0;
    int suffix_cnt = 0;

    while(prefix_cnt < t_sz){
      if(s.at(prefix_cnt) == t.at(prefix_cnt)){
        prefix_cnt++;
      }else{
        break;
      }
    }

    while(suffix_cnt < t_sz){
      int s_idx = s_sz - suffix_cnt - 1;
      int t_idx = t_sz - suffix_cnt - 1;
      if(s.at(s_idx) == t.at(t_idx)){
        suffix_cnt++;
      }else{
        break;
      }
    }

    out_yn(prefix_cnt + suffix_cnt >= t_sz);

  }else if(s_sz == t_sz){
    // modify or is same
    int diff_num = 0;
    rep(i, s_sz){
      if(s.at(i) != t.at(i)) diff_num++;
    }
    out_yn(diff_num <= 1);
  }else{
    out_yn(false);
  }


  return 0;  
}
