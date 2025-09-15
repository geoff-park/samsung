// Gravity
// Solution 1: O(n^3)

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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> testCase;

  for (int T = 1; T <= testCase; ++T) {
    cin >> roomWidth;
    roomHeight = 100;

    // init
    maxFallen = 0;
    for (int i = 0; i < roomWidth; ++i) {     // 90도 회전하기 때문에 roomWidth를 세로로 생각
      for (int j = 0; j < roomHeight; ++j) {  // 마찬가지로 roomHeight를 가로로 생각
        room[i][j] = EMPTY;
      }
    }

    for (int i = 0; i < roomWidth; ++i) {
      cin >> boxHeight;
      for (int j = 0; j < boxHeight; ++j) {
        room[i][j] = BOX;
      }
    }

    // 각 상자의 낙차를 구한다: O(n^3)
    for (int i = 0; i < roomWidth; ++i) {
      for (int j = 0; j < roomHeight; ++j) {
        // room[i][j]가 박스일 때 빈칸의 개수를 셈으로써 낙차를 구한다.
        if (room[i][j] == BOX) {
          countEmptySpace = 0;
          for (int k = i + 1; k < roomWidth; ++k) {
            if (room[k][j] == EMPTY) countEmptySpace++;
          }

          // 이전에 구한 낙차보다 현재 낙차가 크다면 업데이트한다.
          if (countEmptySpace > maxFallen) maxFallen = countEmptySpace;
        }
      }
    }

    cout << "#" << T << ' ';
    cout << maxFallen << '\n';
  }

  return 0;
}
