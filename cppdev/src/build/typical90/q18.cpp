# include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep_ll(i, n) for (ll i = 0; i < (ll)(n); i++)

template<class T> void out_vec(vector<T> &v){for(int i=0;i<(int)v.size();i++){cout<<v.at(i)<<" ";}cout<<endl;}
template<class T> void out_vec2d(vector<vector<T>> &v){for(int i=0;i<(int)v.size();i++){for(int j=0;j<(int)v.at(i).size();j++){cout<<v.at(i).at(j)<<" ";}cout<<endl;}}
void out_yn(bool b){if(b){cout << "Yes" << endl;}else{cout << "No" << endl;}}

const long double PI=3.141592653589793;

int main() {
  ll t, l, x, y;
  cin >> t >> l >> x >> y;

  int q;
  cin >> q;

  rep(i, q){
    ll e;
    cin >> e;

    long double theta = 2.0 * PI * e/t;
    //ll w2 = (x-0)*(x-0) + (y+sin(theta))*(y+sin(theta));
    long double w2 = (x-0)*(x-0) + (y+l/2.0*sin(theta))*(y+l/2.0*sin(theta));
    //long double h = (long double)l/2.0 - cos(theta);
    //long double h = (long double)l/2.0 * (1.0 - cos(theta));
    long double h = l/2.0  - l/2.0 * cos(theta);
    // cout << fixed << setprecision(12) << atan(h / sqrt(w2)) * 180.0 / PI << endl;
    // cout << fixed << setprecision(12) << "theta:" << theta << " w:" << sqrt(w2) << " h:" << h << endl;
    cout << fixed << setprecision(12) << atan2(h, sqrt(w2)) * 180.0 / PI << endl;
  }





  return 0;  
}
