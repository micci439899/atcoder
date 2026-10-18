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

  vector<int> nm(m, 0);
  vector<int> sm(m, 0);

  rep(i, n){
    int a, b;
    cin >> a >> b;
    a--;
    nm.at(a)++;
    sm.at(a) += b;
  }

  cout << fixed << setprecision(8);
  rep(i, m){
    double ave = (double)sm.at(i) / (double)nm.at(i);
    cout << ave << endl;
  }




  return 0;
}


