#include <stdio.h>
#include <string.h>

int main() {
  /* Import and read the file */
  FILE *f = fopen("file2.txt", "r");
  char line[10000];
  long long cnt = 0;
  fgets(line, sizeof(line), f);

  char *token =
      strtok(line, ",\n"); // Get the first token feom the while string.

  while (token != NULL) {
    long long start, end;
    char str[20];
    sscanf(token, "%lld-%lld", &start,
           &end); // Get start and end values from the token.

    for (long long i = start; i <= end; ++i) {
      sprintf(str, "%lld", i); // Convert and
      int l = strlen(str);     // 	get lenght of the current number.

      if (l % 2 == 0 &&
          !strncmp(str, str + l / 2,
                   l / 2)) { // Check the number and add it to the cnt.
        cnt += i;
      }
    }

    token = strtok(NULL, ",\n"); // Get the next token.
  }

  fclose(f);
  printf("%lld\n", cnt);
  return 0;
}
