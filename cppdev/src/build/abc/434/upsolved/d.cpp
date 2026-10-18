# include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

template<class T> void out_vec(vector<T> &v){for(int i=0;i<(int)v.size();i++){cout<<v.at(i)<<" ";}cout<<endl;}
template<class T> void out_vec2d(vector<vector<T>> &v){for(int i=0;i<(int)v.size();i++){for(int j=0;j<(int)v.at(i).size();j++){cout<<v.at(i).at(j)<<" ";}cout<<endl;}}
void out_yn(bool b){if(b){cout << "Yes" << endl;}else{cout << "No" << endl;}}

const int WIDTH = 2000;
const int HEIGHT = 2000;

int main() {
  ll n;
  cin >> n;

  // 雲全体の累積和（各マス目が何個の雲で覆われているか）
  vector<vector<ll>> cum_cloud(HEIGHT+1, vector<ll>(WIDTH+1, 0));

  // 各雲1~nが覆っている部分
  // 複数の雲に覆われてる場合、各雲の番号が加算されている
  vector<vector<ll>> cloud(HEIGHT+1, vector<ll>(WIDTH+1, 0));
  rep(i, n){
    ll u, d, l, r;
    cin >> u >> d >> l >> r;
    u--; d--; l--; r--;

    cum_cloud.at(u).at(l)++;
    cum_cloud.at(u).at(r+1)--;
    cum_cloud.at(d+1).at(l)--;
    cum_cloud.at(d+1).at(r+1)++;

    cloud.at(u).at(l) += i;
    cloud.at(u).at(r+1) -= i;
    cloud.at(d+1).at(l) -= i;
    cloud.at(d+1).at(r+1) += i;
  }

  rep(i, HEIGHT+1)rep(j, WIDTH){
    cum_cloud.at(i).at(j+1) += cum_cloud.at(i).at(j);
    cloud.at(i).at(j+1) += cloud.at(i).at(j);
  }
  rep(i, HEIGHT)rep(j, WIDTH+1){
    cum_cloud.at(i+1).at(j) += cum_cloud.at(i).at(j);
    cloud.at(i+1).at(j) += cloud.at(i).at(j);
  }

  // 元々雲に覆われていないマス目の数
  ll cnt = 0;

  // 各雲だけで覆われているマス目の数
  vector<ll> cloud_cnt(n, 0);

  rep(i, HEIGHT)rep(j, WIDTH){
    if(cum_cloud.at(i).at(j) == 0){
      cnt++;
    }else if(cum_cloud.at(i).at(j) == 1){
      // 1個なら各雲の番号
      ll cloud_idx = cloud.at(i).at(j);
      cloud_cnt.at(cloud_idx)++;
    }
  }

  rep(i, n){
    cout << cnt + cloud_cnt.at(i) << endl;
  }




  return 0;
}
