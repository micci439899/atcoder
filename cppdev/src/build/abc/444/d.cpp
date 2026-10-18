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

void solve(){
  ll n;
  cin >> n;

  map<ll, ll> mp;
  rep(i, n){
    ll a_i;
    cin >> a_i;
    mp[a_i]++;
  }


  vector<ll> digit(2*1e5);
  ll rem = n;
  rep(i, digit.size()){
    digit.at(i) = rem;
    if(mp.count(i+1)){
      rem -= mp[i+1];
      if(rem == 0) break;
    }
  }

  vector<ll> digit2(2*1e5);

  // rep(i, 12){
  //   debug(digit.at(i));
  // }


  // 下位
  vector<ll> x(2*1e5);
  // 上位
  vector<ll> y(2*1e5);

  rep(i, digit.size()){
    ll cnt = digit.at(i);
    ll idx = i;
    while(cnt){
      if(idx < x.size()){
        x.at(idx) += cnt%10;
        if(x.at(idx) > 10){
          ll rem2 = x.at(idx)%10;
          ll q = x.at(idx)/10;
          x.at(idx) = rem2;
          x.at(idx+1) += q;

        }
        if(idx > i) digit.at(idx) += cnt%10;
      }else{
        digit2.at(idx-x.size()) += cnt%10;
        // y.at(idx-x.size()) += cnt;
        if(idx > i) digit2.at(idx) += cnt%10;
      }
      cnt /= 10;
      idx++;
    }
  }

  // rep(i, 12){
  //   debug(x.at(i));
  // }



  // reverse(x.begin(), x.end());
  // bool b = true;
  // rep(i, x.size()){
  //   if(b && x.at(i) == 0)continue;
  //   b = false;
  //   cout << x.at(i);
  // }
  if(count(y.begin(), y.end(), 0) == y.size()){
    reverse(x.begin(), x.end());
    bool b = true;
    rep(i, x.size()){
      if(b && x.at(i) == 0)continue;
      b = false;
      cout << x.at(i);
    }
    cout << endl;
    return;
  }



  rep(i, digit2.size()){
    ll cnt = digit2.at(i);
    ll idx = i;
    while(cnt){
      // if(idx < x.size()){
        y.at(idx) += cnt%10;
      // }else{

      // }
      cnt /= 10;
      idx++;
    }
  }

  reverse(y.begin(), y.end());
  bool b2 = true;
  rep(i, y.size()){
    if(b2 && y.at(i) == 0)continue;
    b2 = false;
    cout << y.at(i);
  }

  reverse(x.begin(), x.end());
  bool b3 = true;
  rep(i, x.size()){
    if(b3 && x.at(i) == 0)continue;
    b3 = false;
    cout << x.at(i);
  }
  cout << endl;






}


int main() {

  solve();

  return 0;
}
