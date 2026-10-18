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
int ctoi(char c){return int(c-'0');} // e.g.) a -> 49, 1 -> 1
char itoc(int x){return x+'0';}

void solve(){
  string s; cin >> s;

  ll cnt = 0;
  for(int i = 1; i <= s.size(); i++){
    if(i == 1){
      cnt += s.size();
    }else if(i == 2){
      cnt += s.size() - 1;
    }else if(i == 3){
      cnt += s.size() - 2;
    }else{

      if(i%2 == 0){

        for(int j = i/2-1; j < s.size() - i/2; j++){
          // debug(j);
          int cur_cnt = 0;
          for(int k = 0; k < i/2; k++){
              // debug(j-k);
              // debug(s.at(j-k));
              // debug(j+k+1);
              // debug(s.at(j+k+1));
            if(s.at(j-k) != s.at(j+k+1)){
              cur_cnt++;
              if(cur_cnt > 1) break;
            }
          }
          if(cur_cnt <= 1) cnt++;
        }

      }else{

        for(int j = i/2; j < s.size() - i/2; j++){
          // debug(j);
          int cur_cnt = 0;
          for(int k = 0; k < i/2+1; k++){
              // debug(j-k);
              // debug(s.at(j-k));
              // debug(j+k);
              // debug(s.at(j+k));
            if(s.at(j-k) != s.at(j+k)){
              cur_cnt++;
              if(cur_cnt > 1) break;
            }
          }
          if(cur_cnt <= 1) cnt++;
        }

      }
    }
  }
  cout << cnt << endl;

}

int main() {

  solve();

  return 0;
}
