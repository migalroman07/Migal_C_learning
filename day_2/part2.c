#include <stdio.h>
#include <string.h>

long long is_repeated(long long number) {
  /* Function to check if the number matches conditions. */
  char str[20];
  sprintf(str, "%lld", number);
  int l = strlen(str);

  for (int pattern_len = 1; pattern_len <= l / 2; pattern_len++) { // We will check each pattern lenght possible.
    if (l % pattern_len != 0) continue;                            // If pattern can not fit in the number.

    int is_repeating = 1;
    for (int i = pattern_len; i < l; i += pattern_len) {
      if (strncmp(str, str + i, pattern_len) != 0) { // Compare each substring to the first one.
        is_repeating = 0;
        break;
      }
    }
    if (is_repeating == 1) return 1;
  }
  return 0;
}

int main() {
  /* Import and read the file */
  FILE *f = fopen("file2.txt", "r");
  char line[10000];
  long long cnt = 0;
  fgets(line, sizeof(line), f);

  char *token = strtok(line, ",\n"); // Get the first token feom the while string.

  while (token != NULL) {
    long long start, end;
    char str[20];
    sscanf(token, "%lld-%lld", &start, &end); // Get start and end values from the token.

    for (long long i = start; i <= end; ++i) {
      sprintf(str, "%lld", i); // Convert and
      int l = strlen(str);     // 	get lenght of the current number.

      if (is_repeated(i)) cnt += i;
    }

    token = strtok(NULL, ",\n"); // Get the next token.
  }

  fclose(f);
  printf("%lld\n", cnt);
  return 0;
}
