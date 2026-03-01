#include <stdio.h>
#include <stdlib.h>

/* Define the max funtion really quick */
int max(int a, int b) { return a > b ? a : b; }

int main() {
  int cnt = 0;
  int pos = 50;
  int num;
  int prev; // Contains previous position.

  FILE *f = fopen("file.txt", "r");
  char line[100];

  while (fgets(line, sizeof(line), f)) {
    prev = pos;
    num = atoi(line + 1); // Get the number from string (convert).
    if (line[0] == 'L') {
      pos -= num;
    } else {
      pos += num;
    }

    if ((pos / 100 != prev / 100) || (pos > 0 && prev < 0) || (pos < 0 && prev > 0)) { // Different condition...
      cnt += max(1,
        abs(prev / 100 - pos / 100)); // Increase the cnt by the number of 100's crossed.
    }
  }

  fclose(f);
  printf("%d\n", cnt);
  return 0;
}
