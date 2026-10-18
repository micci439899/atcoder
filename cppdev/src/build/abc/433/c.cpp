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

  ll ans = 0LL;

  vector<int> idxs;
  for(int i = 1; i < (int)s.size(); i++){
    int cur = s.at(i) - '0';
    if(prev+1 == cur)idxs.push_back(i);
  }

  cout << ans << endl;


/*
  int idx1 = 0;
  int idx2 = -1;


  int prev = s.at(0) - '0';

  for(int i = 1; i < (int)s.size(); i++){
    int cur = s.at(i) - '0';
    if(prev == cur){
    }else if(prev+1 == cur){
      if(idx1 == -1){
        idx1 = i;
      }else if(idx1 == 0){
        idx2 = i;
        cout << "idx2: " << idx2 << endl;
      }else{
        cout << "ans3" << endl;
        int num1 = idx2 - idx1;
        int num2 = i - idx2;
        ll mi = min(num1, num2);
        ans += mi;



        idx2 = idx1;
        idx1 = i;



      }
    }else{
      cout << "ans1" << endl;
      int num1 = idx2 - idx1;
      int num2 = i - idx2;
      ll mi = min(num1, num2);
      ans += mi;

      idx1 = i;
      idx2 = -1;
    }
    prev = cur;
  }

  if(idx2 > 0){
      cout << "ans last" << endl;
    int num1 = idx2 - idx1;
    int num2 = s.size() - idx2;
    ll mi = min(num1, num2);
    cout << num1 << " " << num2 << endl;
    ans += mi;
  }

  cout << ans << endl;

*/
/*
  ll ans = 0;
  int prev = s.at(0) - '0';
  int pre_succ_num1 = 1;
  int post_succ_num1 = 1;
  int pre_succ_num2 = 1;
  int post_succ_num2 = 1;

  bool is_prev = true;
  bool is_processed = false;

  for(int i = 1; i < (int)s.size(); i++){
    int cur = (s.at(i) - '0');
    if(prev == cur){
      if(is_prev){
        pre_succ_num1++;
      }else{
        post_succ_num1++;
      }
      is_processed = true;
    }else if(prev+1 == cur){
      cout << "prev+1 = cur prev:" << prev << " cur:" << cur << endl;
      is_prev = false;
      is_processed = true;
    }else{
      if(is_processed && pre_succ_num1 > 0 && post_succ_num1 > 0){
        cout << "pre_succ_num1: " << pre_succ_num1 << " post_succ_num1: " << post_succ_num1 << endl;
        ll mi = min(pre_succ_num1, post_succ_num1);
        ans += mi;
      }
      pre_succ_num1 = 1;
      post_succ_num1 = 1;
      pre_succ_num2 = 1;
      post_succ_num2 = 1;
      is_prev = true;
      is_processed = false;
    }
    prev = cur;
  }

  if(is_processed && pre_succ_num1 > 0 && post_succ_num1 > 0){
    ll mi = min(pre_succ_num1, post_succ_num1);
    ans += mi;
  }

  cout << ans << endl;
*/

  return 0;  
}
