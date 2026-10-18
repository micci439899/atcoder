# include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

template<class T> void out_vec(vector<T> &v){for(int i=0;i<(int)v.size();i++){cout<<v.at(i)<<" ";}cout<<endl;}
template<class T> void out_vec2d(vector<vector<T>> &v){for(int i=0;i<(int)v.size();i++){for(int j=0;j<(int)v.at(i).size();j++){cout<<v.at(i).at(j)<<" ";}cout<<endl;}}
void out_yn(bool b){if(b){cout << "Yes" << endl;}else{cout << "No" << endl;}}

int main() {
  int n;
  cin >> n;

  vector<vector<int>> g(n, vector<int>(n));

  int r = 0;
  int c = n/2;
  int k = 1;
  g.at(r).at(c) = k;


  rep(i, n*n-1){
    int rr = (r-1)%n;
    int cc = (c+1)%n;
    if(rr < 0) rr += n;

    if(g.at(rr).at(cc) == 0){
      g.at(rr).at(cc) = k+1;
      r = rr;
      c = cc;
      k++;
    }else{
      int rrr = (r+1)%n;
      int ccc = c;
      g.at(rrr).at(ccc) = k+1;
      r = rrr;
      c = ccc;
      k++;
    }
  }


  out_vec2d(g);


  return 0;
}


