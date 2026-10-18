# include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

template<class T> void out_vec(vector<T> &v){for(int i=0;i<(int)v.size();i++){cout<<v.at(i)<<" ";}cout<<endl;}
template<class T> void out_vec2d(vector<vector<T>> &v){for(int i=0;i<(int)v.size();i++){for(int j=0;j<(int)v.at(i).size();j++){cout<<v.at(i).at(j)<<" ";}cout<<endl;}}
void out_yn(bool b){if(b){cout << "Yes" << endl;}else{cout << "No" << endl;}}

int main() {
  int t;
  cin >> t;

  while(t--){
    int n;
    cin >> n;

    if(n == 2){
      int s_1, s_2;
      cin >> s_1 >> s_2;
      if(2 * s_1 >= s_2){
        cout << 2 << endl;
      }else{
        cout << -1 << endl;
      }
      continue;
    }

    int s_0;
    cin >> s_0;

    vector<int> s(n-2);
    rep(i, n-2) cin >> s.at(i);

    int s_n_1;
    cin >> s_n_1;

    sort(s.begin(), s.end());

    vector<int> t;
    t.push_back(s_0);

    int ans = -1;
    int idx = 0;
    size_t prev_pos = 0;
    while(true){
      int h = 2 * t.at(idx);
      if(h >= s_n_1){
        t.push_back(s_n_1);
        ans = t.size();
        break;
      }

      auto it = upper_bound(s.begin(), s.end(), h);
      it--;
      if(t.back() == *it){
        ans = -1;
        break;
      }
      t.push_back(*it);
      idx++;
    }

    cout << ans << endl;

  }





  return 0;  
}
