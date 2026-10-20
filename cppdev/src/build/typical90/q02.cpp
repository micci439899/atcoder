# include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep_ll(i, n) for (ll i = 0; i < (ll)(n); i++)

template<class T> void out_vec(vector<T> &v){for(int i=0;i<(int)v.size();i++){cout<<v.at(i)<<" ";}cout<<endl;}
template<class T> void out_vec2d(vector<vector<T>> &v){for(int i=0;i<(int)v.size();i++){for(int j=0;j<(int)v.at(i).size();j++){cout<<v.at(i).at(j)<<" ";}cout<<endl;}}
void out_yn(bool b){if(b){cout << "Yes" << endl;}else{cout << "No" << endl;}}

const int MAX_DIGIT = 20;

int main() {
  int n;
  cin >> n;

  vector<string> ans;
  for(int i = 0; i < 1<<n; i++){
    //cout << "i:" << i << endl;
    //bitset<n> b(i);
    bitset<MAX_DIGIT> b(i);

    //vector<char> s(n);
    string s;
    bool is_target = true;
    int l_num = 0;
    int r_num = 0;
    //for(int j = 0; j < n; j++){
    for(int j = MAX_DIGIT-n; j < MAX_DIGIT; j++){
      //cout << "j:" << j << endl;
      if(b.test(MAX_DIGIT - j - 1) == 0){
        l_num++;
        //s.at(i) = '(';
        s += '(';
      }else{
        r_num++;
        //s.at(i) = ')';
        s += ')';
      }
      if(r_num > l_num){
        is_target = false;
        break;
      }
    }
    if(!is_target) continue;

    if(l_num == r_num){
      ans.push_back(s);
    }
  }

  sort(ans.begin(), ans.end());


  rep(i, ans.size()){
    cout << ans.at(i) << endl;
  }
  //out_vec(ans);



  return 0;  
}
