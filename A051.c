#include <stdio.h>
#include <stdlib.h>
int s[1000][1000], dp[1001][1002];

int max(int a, int b, int c) {
  int max = a;
  if (b > max) max = b;
  if (c > max) max = c;
  return max;
}

int main() {
  int H, W;
  scanf("%d%d", &H, &W);
  for (int i = 1; i <= H; i++) {
    for (int j = 1; j <= W; j++) {
      scanf("%d", &s[i][j]);
    }
  }
  // dp[i][j]:(i,j)番目まで倒れた時の得点の最大値
  for (int i = 1; i <= H; i++) {
    dp[i][0] = 0;
    dp[i][W + 1] = 0;
  }
  for (int j = 0; j <= W + 1; j++) {
    dp[1][j] = 0;
    if (j >= 1 && j <= W) dp[1][j] = s[1][j];
  }
  for (int i = 2; i <= H; i++) {
    for (int j = 1; j <= W; j++) {
      dp[i][j] =
          s[i][j] + max(dp[i - 1][j - 1], dp[i - 1][j], dp[i - 1][j + 1]);
    }
  }
  int maximum = -1;
  for (int j = 1; j <= W; j++) {
    if (dp[H][j] > maximum) maximum = dp[H][j];
  }
  printf("%d\n", maximum);
  return 0;
}