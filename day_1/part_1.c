#include <stdio.h>
#include <stdlib.h>

int main() {
  int cnt = 0;  // The answer var.
  int pos = 50; // Current position.
  int num;      // The rotation number.
  /* Open the file */
  FILE *f = fopen("file.txt", "r");
  char line[256];

  while (fgets(line, sizeof(line), f)) {
    /* Read the number and direction */
    num = atoi(line + 1);
    if (line[0] == 'L') {
      pos -= num;
    } else {
      pos += num;
    }

    /* Count it */
    if (abs(pos) % 100 == 0) {
      cnt += 1;
    }
  }

  fclose(f);
  printf("%d\n", cnt);
  return 0;
}
