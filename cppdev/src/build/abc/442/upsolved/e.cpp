# include <bits/stdc++.h>
using namespace std;
using ll = long long;
using uint = unsigned;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<long long, long long>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define debug(x) cerr << #x << " " << x << " " << endl;

template<class T>using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;
template<class T>bool chmax(T&a, T b){if(a<b){a=b;return true;}return false;}
template<class T>bool chmin(T&a, T b){if(b<a){a=b;return true;}return false;}

template<class T, class U>ostream&operator<<(ostream&os, pair<T,U>p){os<<"("<<p.first << "," << p.second<<")";return os;}
template<class T>ostream&operator<<(ostream&os, const vector<T>&v){os<<"[";for(int i = 0; i < v.size(); i++){cout << v.at(i);if(i != v.size()-1){cout << ",";}}os<<"]";return os;}
template<class T>ostream&operator<<(ostream&os, const set<T>&st){os<<"{";int idx=0;for(auto &e : st){cout << e;if(idx != st.size()-1){cout << ",";}idx++;}os<<"}";return os;}
template<class T, class U>ostream&operator<<(ostream&os, map<T,U>mp){os<<"{";int idx=0;for(auto p : mp){cout << p;if(idx != mp.size()-1){cout << ",";}idx++;}os<<"}";return os;}

template<class T> void out_vec(vector<T> &v){for(int i=0;i<(int)v.size();i++){cout<<v.at(i)<<" ";}cout<<endl;}
template<class T> void out_vec2d(vector<vector<T>> &v){for(int i=0;i<(int)v.size();i++){for(int j=0;j<(int)v.at(i).size();j++){cout<<v.at(i).at(j)<<" ";}cout<<endl;}}
void out_yn(bool b){if(b){cout << "Yes" << endl;}else{cout << "No" << endl;}}
int ctoi(char c){return int(c-'0');}
char itoc(int x){return x+'0';}

ll gcd(ll a, ll b){
  return b == 0 ? a : gcd(b, a%b);
}

// クロス積（外積）
// 2次元座標平面におけるベクトル同士のクロス積におけるz座標相当
ll cross_product(const pll &a, const pll &b){
  return a.first * b.second - b.first * a.second;
}

bool cmp(const pll &a, const pll &b){
  // 下半平面にいるか
  // より具体的には、y座標が0未満もしくはx軸上でx座標が負
  // （x軸上からの反時計回りでの角度を考えたとき、半開区間）
  bool is_low_a = a.second < 0 || (a.second == 0 && a.first < 0);
  bool is_low_b = b.second < 0 || (b.second == 0 && b.first < 0);

  // どちらかが上でどちらかが下
  // aが上ならaの方が角度が小さい
  if(is_low_a != is_low_b) return !is_low_a;

  // 同じ半平面ならクロス積（のz座標）が大きいときaの方が角度が小さい
  return cross_product(a, b) > 0;
}

void solve(){
  ll n, q;
  cin >> n >> q;

  // key: モンスター、value: 角度
  map<ll, pll> mons_angle;

  // key: 角度、value: モンスターの数
  // map<pll, vector<ll>> angle_mons;
  map<pll, ll> angle_mons;

  // 規約分数の角度（の集合）
  set<pll> st;

  rep(i, n){
    ll x, y;
    cin >> x >> y;

    if(x == 0){
      y = y > 0 ? 1 : -1;
    }else if(y == 0){
      x = x > 0 ? 1 : -1;
    }else{
      ll g = gcd(abs(x), abs(y));
      x /= g;
      y /= g;
    }

    mons_angle[i] = {x, y};
    // angle_mons[{x, y}].push_back(i);
    angle_mons[{x, y}]++;
    st.insert({x, y});
  }


  // 角度でソート（小さい順）
  vector<pll> points{st.begin(), st.end()};
  // sort(points.rbegin(), points.rend(), cmp);
  sort(points.begin(), points.end(), cmp);

  // 累積和
  points.insert(points.end(), points.begin(), points.end());
  vector<ll> cum_p(points.size()+1, 0);

  // key: 角度、value: （角度リストの）添字
  map<pll, ll> p2idx;

  rep(i, points.size()){
    pll xy = points.at(i);
    if(i < points.size()/2) p2idx[xy] = i;
    ll cnt = angle_mons[xy];
    cum_p.at(i+1) = cum_p.at(i) + cnt;
  }

  while(q--){
    ll a, b;
    cin >> a >> b;
    a--; b--;

    pll a_xy = mons_angle[a];
    pll b_xy = mons_angle[b];


    if(a_xy == b_xy){
      cout << angle_mons[a_xy] << endl;
      continue;
    }

    ll a_idx = p2idx[a_xy];
    ll b_idx = p2idx[b_xy];

    if(a_idx < b_idx){
      a_idx += points.size()/2;
      cout << cum_p.at(a_idx+1) - cum_p.at(b_idx) << endl;
    }else{
      cout << cum_p.at(a_idx+1) - cum_p.at(b_idx) << endl;
    }

  }




}

int main() {

  solve();

  return 0;  
}









