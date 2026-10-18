# include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep_ll(i, n) for (ll i = 0; i < (ll)(n); i++)

template<class T> void out_vec(vector<T> &v){for(int i=0;i<(int)v.size();i++){cout<<v.at(i)<<" ";}cout<<endl;}
template<class T> void out_vec2d(vector<vector<T>> &v){for(int i=0;i<(int)v.size();i++){for(int j=0;j<(int)v.at(i).size();j++){cout<<v.at(i).at(j)<<" ";}cout<<endl;}}
void out_yn(bool b){if(b){cout << "Yes" << endl;}else{cout << "No" << endl;}}

int main() {
  int n, q;
  cin >> n >> q;

  // 鳩がいる巣
  vector<int> p(n);
  iota(p.begin(), p.end(), 0);

  // 巣にいる鳩の数
  vector<int> h(n, 1);

  // 複数の鳩がいる巣の数
  int nest_num = 0;

  while(q--){
    int q_type;
    cin >> q_type;

    if(q_type == 1) {
      int p_i, h_i;
      cin >> p_i >> h_i;
      p_i--; h_i--;

      // 今の巣の番号、次に行く巣の番号
      int current_nest = p.at(p_i);
      int next_nest = h_i;

      // 今の巣の鳩の数、次に行く巣の鳩の数
      int current_pidgeon_num = h.at(current_nest);
      int next_pidgeon_num = h.at(next_nest);


      // 鳩のいる巣、鳩の数を更新
      h.at(current_nest)--;
      p.at(p_i) = next_nest;
      h.at(next_nest)++;

      // 2 -> 1のときのみ減る
      if(current_pidgeon_num == 2) nest_num--;

      // 1 -> 2のときのみ増える
      if(next_pidgeon_num == 1) nest_num++;
    } else {
      cout << nest_num << endl;
    }
  }



  return 0;  
}
