# include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

template<class T> void out_vec(vector<T> &v){for(int i=0;i<(int)v.size();i++){cout<<v.at(i)<<" ";}cout<<endl;}
template<class T> void out_vec2d(vector<vector<T>> &v){for(int i=0;i<(int)v.size();i++){for(int j=0;j<(int)v.at(i).size();j++){cout<<v.at(i).at(j)<<" ";}cout<<endl;}}
void out_yn(bool b){if(b){cout << "Yes" << endl;}else{cout << "No" << endl;}}


// vector<ll> dx = {0, 1, 0, 1};
// vector<ll> dy = {0, 0, 1, 1};
vector<int> dx = {0, 1, 0, -1, 0, 1, -1, -1, 1};
vector<int> dy = {0, 0, 1, 0, -1, 1, 1, -1, -1};


bool is_within(int x, int y, int w, int h){
  if(x < 0 || w-1 < x) return false;
  if(y < 0 || h-1 < y) return false;
  return true;
}

int main() {
  ll n, m;
  cin >> n >> m;

  set<pair<ll, ll>> st;
  ll ans = 0;

  rep(i, m){
    ll r, c;
    cin >> r >> c;
    r--; c--;

    bool is_ok = true;

    rep(j, 9){
      ll nr = r + dy.at(j);
      ll nc = c + dx.at(j);

      auto it = st.find(make_pair(nr, nc));
      if(it != st.end()){
        // cout << "ng" << endl;
        // cout << "nr: " << nr << " nc: " << nc << endl;
        is_ok = false;
        break;
      }
    }
    if(is_ok){
      auto p = make_pair(r, c);
      st.insert(p);
      ans++;
    }
  }

/*
  vector<vector<bool>> g(n, vector<bool>(n));

  ll ans = 0;
  rep(i, m){
    ll r, c;
    cin >> r >> c;
    r--; c--;

    cout << "r:" << r << " c:" << c << endl;


    bool is_ok = true;
    rep(j, 4){
      ll nr = r + dy.at(j);
      ll nc = c + dx.at(j);

      if(g.at(nr).at(nc)){
        cout << "ng" << endl;
        cout << "nr: " << nr << " nc: " << nc << endl;
        is_ok = false;
        break;
      }
    }
    if(is_ok){
      rep(j, 4){
        ll nr = r + dy.at(j);
        ll nc = c + dx.at(j);

        g.at(nr).at(nc) = true;
      }
      ans++;
    }
  }
*/

  cout << ans << endl;


  return 0;  
}
