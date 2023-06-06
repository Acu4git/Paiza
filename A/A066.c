#include <stdio.h>
#define N_MAX 10000
#define DAY_LEHGTH_MAX 100000

void memo(int[], int[], int[], int);
int solve(int[], int, int);

int main() {
  int N, min_a, max_b, a[N_MAX], b[N_MAX], day[DAY_LEHGTH_MAX + 1];
  scanf("%d", &N);
  min_a = DAY_LEHGTH_MAX;
  max_b = 0;
  for (int i = 0; i < N; i++) {
    scanf("%d%d", a + i, b + i);
    if (a[i] < min_a) min_a = a[i];
    if (b[i] > max_b) max_b = b[i];
  }
  for (int i = 0; i <= DAY_LEHGTH_MAX; i++) day[i] = 0;

  memo(day, a, b, N);
  printf("%d\n", solve(day, min_a, max_b));
  return 0;
}

void memo(int z[], int x[], int y[], int arr_size) {
  int i, j;
  for (i = 0; i < arr_size; i++) {
    for (j = x[i]; j <= y[i]; j++) {
      z[j] = 1;
    }
  }
}

int solve(int z[], int min, int max) {
  int ans, left, right;

  ans = 0;
  for (left = min; left <= max; left = right + 1) {
    int cnt = 0;
    right = left;

    while (right <= max && z[right] == 1) {
      cnt++;
      right++;
    }

    if (ans < cnt) ans = cnt;
  }

  return ans;
}