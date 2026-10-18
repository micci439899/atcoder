# include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep_ll(i, n) for (ll i = 0; i < (ll)(n); i++)

template<class T> void out_vec(vector<T> &v){for(int i=0;i<(int)v.size();i++){cout<<v.at(i)<<" ";}cout<<endl;}
template<class T> void out_vec2d(vector<vector<T>> &v){for(int i=0;i<(int)v.size();i++){for(int j=0;j<(int)v.at(i).size();j++){cout<<v.at(i).at(j)<<" ";}cout<<endl;}}
void out_yn(bool b){if(b){cout << "Yes" << endl;}else{cout << "No" << endl;}}

int main() {
  int x, n;
  cin >> x >> n;

  vector<int> w(n);
  rep(i, n) cin >> w.at(i);

  vector<bool> is_attached(n, false);

  int total = x;

  int q;
  cin >> q;
  while(q--){
    int p;
    cin >> p;
    p--;

    if(is_attached.at(p)){
      is_attached.at(p) = !is_attached.at(p);
      total -= w.at(p);
    }else{
      is_attached.at(p) = !is_attached.at(p);
      total += w.at(p);
    }

    cout << total << endl;
  }




  return 0;
}


