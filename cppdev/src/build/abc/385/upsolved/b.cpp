# include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, a, b) for (int i = (int)(a); i < (int)(b); i++)


int main() {
  int h, w, x, y;
  cin >> h >> w >> x >> y;
  x--;
  y--;

  vector<string> s(h);
  rep(i, h){
    cin >> s.at(i);
  }

  string t;
  cin >> t;

  vector<vector<bool>> visited(h, vector<bool>(w, false));

  int ans = 0;
  rep(i, t.size()){
    int current_x = x;
    int current_y = y;
    char current_pos = s.at(x).at(y);
    if(t.at(i) == 'U'){
      if(x == 0) continue;

      int next_x = x-1;
      int next_y = y;

      if(s.at(next_x).at(next_y) == '.'){
        x = next_x;
      } else if(s.at(next_x).at(next_y) == '@'){
        x = next_x;
        if(!visited.at(next_x).at(next_y)){
          ans++;
          visited.at(next_x).at(next_y) = true;
        }
      }

    } else if(t.at(i) == 'D'){
      if(x == h-1) continue;

      int next_x = x+1;
      int next_y = y;

      if(s.at(next_x).at(next_y) == '.'){
        x = next_x;
      } else if(s.at(next_x).at(next_y) == '@'){
        x = next_x;
        if(!visited.at(next_x).at(next_y)){
          ans++;
          visited.at(next_x).at(next_y) = true;
        }
      }

    } else if(t.at(i) == 'L'){
      if(y==0) continue;

      int next_x = x;
      int next_y = y-1;

      if(s.at(next_x).at(next_y) == '.'){
        y = next_y;
      } else if(s.at(next_x).at(next_y) == '@'){
        y = next_y;
        if(!visited.at(next_x).at(next_y)){
          ans++;
          visited.at(next_x).at(next_y) = true;
        }
      }

    } else if(t.at(i) == 'R'){
      if(y==w-1) continue;

      int next_x = x;
      int next_y = y+1;

      if(s.at(next_x).at(next_y) == '.'){
        y = next_y;
      } else if(s.at(next_x).at(next_y) == '@'){
        y = next_y;
        if(!visited.at(next_x).at(next_y)){
          ans++;
          visited.at(next_x).at(next_y) = true;
        }
      }

    } else {
      // undefined
    }
  }


  cout << x+1 << " " << y+1 << " " << ans << endl;



  return 0;

}











