#include <bits/stdc++.h>

using namespace std;

int N;
using Board = vector<vector<int>>;
int ans = 0;

int getMax(const Board& b) {
  int mx = 0;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      mx = max(mx, b[i][j]);
    }
  }
  return mx;
}

// 길이 N인 한 줄 v에 대해, 왼쪽으로 민 결과를 반환
vector<int> compress_merge(vector<int> v) {
  // 1) 0 제거
  vector<int> t;
  for (int x : v)
    if (x != 0) t.push_back(x);

  // 2) 인접 동일 수 1회 병합
  vector<int> res;
  for (int i = 0; i < t.size();) {
    if (i + 1 < t.size() && t[i] == t[i + 1]) {
      res.push_back(t[i] * 2);
      i += 2;
    } else {
      res.push_back(t[i]);
      i += 1;
    }
  }

  // 3) 뒤로 0 채우기
  while (res.size() < N) res.push_back(0);

  return res;
}

// dir: 0=LEFT, 1=RIGHT, 2=UP, 3=DOWN
Board tilt(const Board& b, int dir) {
  Board nb = b;

  if (dir == 0) {  // LEFT
    for (int r = 0; r < N; ++r) {
      nb[r] = compress_merge(nb[r]);
    }
  } else if (dir == 1) {  // RIGHT
    for (int r = 0; r < N; ++r) {
      vector<int> v = nb[r];
      reverse(v.begin(), v.end());
      v = compress_merge(v);
      reverse(v.begin(), v.end());
      nb[r] = v;
    }
  } else if (dir == 2) {  // UP
    for (int c = 0; c < N; ++c) {
      vector<int> v;
      for (int r = 0; r < N; ++r) v.push_back(nb[r][c]);
      v = compress_merge(v);
      for (int r = 0; r < N; ++r) nb[r][c] = v[r];
    }
  } else if (dir == 3) {  // DOWN
    for (int c = 0; c < N; ++c) {
      vector<int> v;
      for (int r = 0; r < N; ++r) v.push_back(nb[r][c]);
      reverse(v.begin(), v.end());
      v = compress_merge(v);
      reverse(v.begin(), v.end());
      for (int r = 0; r < N; ++r) nb[r][c] = v[r];
    }
  }

  return nb;
}

void dfs(const Board& b, int depth) {
  if (depth == 5) {
    ans = max(ans, getMax(b));
    return;
  }
  for (int d = 0; d < 4; ++d) {
    Board nb = tilt(b, d);
    dfs(nb, depth + 1);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  // input
  cin >> N;
  Board b(N, vector<int>(N));
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      cin >> b[i][j];
    }
  }

  dfs(b, 0);

  // output
  cout << ans;

  return 0;
}
