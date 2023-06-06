#include <stdio.h>

void fillSpiral(int n) {
  int x = 0;
  int y = 0;
  int dx = 0;
  int dy = -1;
  int maxX = 1;
  int maxY = 1;
  int steps = 0;

  for (int i = 0; i < n * n; i++) {
    if (-n / 2 <= x && x <= n / 2 && -n / 2 <= y && y <= n / 2) {
      printf("(%d, %d)\n", x, y);
      steps++;
    }

    if (x == y || (x < 0 && x == -y) || (x > 0 && x == 1 - y)) {
      int temp = dx;
      dx = -dy;
      dy = temp;
    }

    x += dx;
    y += dy;

    if (steps == maxX) {
      int temp = dx;
      dx = -dy;
      dy = temp;
      if (dy == 0) {
        maxX++;
      }
      steps = 0;
    } else if (steps == maxY) {
      int temp = dx;
      dx = -dy;
      dy = temp;
      maxY++;
      steps = 0;
    }
  }
}

int main() {
  int n;

  printf("Enter the number of squares (n): ");
  scanf("%d", &n);

  printf("Spiral pattern:\n");
  fillSpiral(n);

  return 0;
}
