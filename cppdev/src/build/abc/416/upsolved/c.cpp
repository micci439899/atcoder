# include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep_ll(i, n) for (ll i = 0; i < (ll)(n); i++)

template<class T> void out_vec(vector<T> &v){for(int i=0;i<(int)v.size();i++){cout<<v.at(i)<<" ";}cout<<endl;}
template<class T> void out_vec2d(vector<vector<T>> &v){for(int i=0;i<(int)v.size();i++){for(int j=0;j<(int)v.at(i).size();j++){cout<<v.at(i).at(j)<<" ";}cout<<endl;}}
void out_yn(bool b){if(b){cout << "Yes" << endl;}else{cout << "No" << endl;}}

int n, k;
ll x;
vector<string> s;
vector<string> ans;

void dfs(string current_s, int depth){
  if(depth == k){
    ans.push_back(current_s);
    return;
  }

  for(int i = 0; i < s.size(); i++){
    dfs(current_s + s.at(i), depth+1);
  }
}

int main() {
  cin >> n >> k >> x;

  s.resize(n);
  rep(i, n) cin >> s.at(i);

  dfs("", 0);

  sort(ans.begin(), ans.end());
  cout << ans.at(x-1) << endl;



  return 0;  
}
