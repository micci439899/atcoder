# include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep_ll(i, n) for (ll i = 0; i < (ll)(n); i++)

template<class T> void out_vec(vector<T> &v){for(int i=0;i<(int)v.size();i++){cout<<v.at(i)<<" ";}cout<<endl;}
template<class T> void out_vec2d(vector<vector<T>> &v){for(int i=0;i<(int)v.size();i++){for(int j=0;j<(int)v.at(i).size();j++){cout<<v.at(i).at(j)<<" ";}cout<<endl;}}
void out_yn(bool b){if(b){cout << "Yes" << endl;}else{cout << "No" << endl;}}


vector<string> find_part(vector<string> &s, int s_i, int s_j, int m){
  vector<string> s_part;
  for(int i = s_i; i < s_i+m; i++){
    s_part.push_back(s.at(i).substr(s_j, m));
  }
  return s_part;
}

int main() {
  int n, m;
  cin >> n >> m;

  vector<string> s(n);
  rep(i, n) cin >> s.at(i);

  set<vector<string>> s_st;
  for(int i = 0; i < n-m+1; i++){
    for(int j = 0; j < n-m+1; j++){
      vector<string> s_part = find_part(s, i, j, m);

      // cout << "i:" << i << " j:" << j << endl;
      // out_vec(s_part);
      s_st.insert(s_part);
    }
  }

  cout << s_st.size() << endl;

  return 0;
}


