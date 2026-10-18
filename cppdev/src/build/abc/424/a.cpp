# include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep_ll(i, n) for (ll i = 0; i < (ll)(n); i++)

template<class T> void print_vec(vector<T> &v){for(int i=0;i<(int)v.size();i++){cout<<v.at(i)<<" ";}cout<<endl;}
template<class T> void print_vec2d(vector<vector<T>> &v){for(int i=0;i<(int)v.size();i++){for(int j=0;j<(int)v.at(i).size();j++){cout<<v.at(i).at(j)<<" ";}cout<<endl;}}

int main() {
  int n, m, k;
  cin >> n >> m >> k;

  vector<int> q(n);
  vector<int> ans;
  rep(i, k){
    int a, b;
    cin >> a >> b;
    a--;
    q.at(a)++;
    if(q.at(a) == m){
      ans.push_back(a+1);
    }
  }

  if(ans.size() > 0){
    print_vec(ans);
  }



  return 0;
}


