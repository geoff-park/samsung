// Gravity
// Solution 2: O(n^2)
// 가장 높은 상자만 낙차 계산

#include <bits/stdc++.h>

#define EMPTY 0
#define BOX 1

using namespace std;

int i, j, k;
int testCase;
int T;
int room[100][100];
int roomWidth, roomHeight;
int boxHeight;
int maxFallen;
int countEmptySpace;

// 추가
int boxTop[100];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> testCase;

  for (int T = 1; T <= testCase; ++T) {
    cin >> roomWidth;
    roomHeight = 100;

    // init
    maxFallen = 0;
    for (int i = 0; i < roomWidth; ++i) {
      for (int j = 0; j < roomWidth; ++j) {
        room[i][j] = EMPTY;
      }
    }

    for (int i = 0; i < roomWidth; ++i) {
      cin >> boxTop[i];
      for (int j = 0; j < boxTop[i]; ++j) {
        room[i][j] = BOX;
      }
    }

    for (int i = 0; i < roomWidth; ++i) {
      if (boxTop[i] > 0) {
        countEmptySpace = 0;
        for (int j = i + 1; j < roomWidth; ++j) {
          if (room[j][boxTop[i] - 1] == EMPTY) countEmptySpace++;
        }

        if (countEmptySpace > maxFallen) maxFallen = countEmptySpace;
      }
    }

    cout << "#" << T << ' ';
    cout << maxFallen << '\n';
  }

  return 0;
}
