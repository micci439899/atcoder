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

const ll INFL = LONG_LONG_MAX / 2;

void solve(){
  string s;
  cin >> s;

  vector<ll> a_ids;
  vector<ll> b_ids;
  vector<ll> c_ids;

  vector<ll> cum_a(s.size()+1, 0);
  vector<ll> cum_c(s.size()+1, 0);

  rep(i, s.size()){
    if(s.at(i) == 'A'){
      a_ids.push_back(i);
      cum_a.at(i+1) = cum_a.at(i) + 1;
      cum_c.at(i+1) = cum_c.at(i);
    }else if(s.at(i) == 'B'){
      b_ids.push_back(i);
      cum_a.at(i+1) = cum_a.at(i);
      cum_c.at(i+1) = cum_c.at(i);
    }else{
      c_ids.push_back(i);
      cum_a.at(i+1) = cum_a.at(i);
      cum_c.at(i+1) = cum_c.at(i) + 1;
    }
  }

  if(b_ids.size() == 0){
    cout << 0 << endl;
    return;
  }

  ll target_b_id = -1;
  ll diff = INFL;
  ll a_cnt = 0;
  ll c_cnt = 0;
  //for(ll b_id : b_ids){
  rep(i, b_ids.size()){
    ll b_id = b_ids.at(i);
    ll cur_a_cnt = cum_a.at(b_id);
    ll cur_c_cnt = cum_c.at(s.size()) - cum_c.at(b_id);

    if(cur_a_cnt > 0 && cur_c_cnt > 0){
      if(abs(cur_a_cnt - cur_c_cnt) < diff){
        // target_b_id = b_id;
        target_b_id = i;
        diff = abs(cur_a_cnt - cur_c_cnt);
      }else if(abs(cur_a_cnt - cur_c_cnt) == diff){
        if(cur_a_cnt > a_cnt){
          // target_b_id = b_id;
          target_b_id = i;
          diff = abs(cur_a_cnt - cur_c_cnt);
        }
      }
    }
    a_cnt = cur_a_cnt;
    c_cnt = cur_c_cnt;
  }

  debug(target_b_id);
  debug(diff);

  if(target_b_id < 0){
    cout << 0 << endl;
    return;
  }


  ll ans = 0;
  while(true){
    ll id = b_ids.at(target_b_id);
    ans++;
    auto it_a = lower_bound(a_ids.begin(), a_ids.end(), id);
    it_a--;
    auto it_c = lower_bound(c_ids.begin(), c_ids.end(), id);

    ll next_b_id = 0;

    if(target_b_id == 0){
      next_b_id = b_ids.at(target_b_id+1);
    }else if(target_b_id == b_ids.size()-1){
      next_b_id = b_ids.at(target_b_id-1);
    }else{
      l_b_id = b_ids.at(target_b_id-1);
      r_b_id = b_ids.at(target_b_id+1);
      
    }

  }




  // out_vec(a_ids);
  // out_vec(b_ids);
  // out_vec(c_ids);
  // out_vec(cum_a);
  // out_vec(cum_c);



}


int main() {

  solve();

  return 0;
}
