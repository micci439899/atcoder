# include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep_ll(i, n) for (ll i = 0; i < (ll)(n); i++)

template<class T> void out_vec(vector<T> &v){for(int i=0;i<(int)v.size();i++){cout<<v.at(i)<<" ";}cout<<endl;}
template<class T> void out_vec2d(vector<vector<T>> &v){for(int i=0;i<(int)v.size();i++){for(int j=0;j<(int)v.at(i).size();j++){cout<<v.at(i).at(j)<<" ";}cout<<endl;}}
void out_yn(bool b){if(b){cout << "Yes" << endl;}else{cout << "No" << endl;}}

int main() {
  int s, a, b, x;
  cin >> s >> a >> b >> x;

  int total_time = 0;
  int total_move = 0;
  while(true) {
    //cout << "total_time:" << total_time << endl;
    //cout << "total_move:" << total_move << endl;
    //cout << endl;
    if(total_time + a > x){
      total_move += (x - total_time) * s;
      break;
    } else {
      total_time += a;
      total_move += a * s;
    }
    total_time += b;

    if(total_time > x) break;
  }

  cout << total_move << endl;


  return 0;
}
