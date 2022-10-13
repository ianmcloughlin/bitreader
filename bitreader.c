// Standard read/print functions.
#include <stdio.h>
// Fixed size types.
#include <stdint.h>


int main(int argc, char *argv[]) {

  // Check we got exactly one command line argument.
  if (argc != 2) {
    // Print usage statement.
    printf("Usage: %s <filename>\n", argv[0]);
    // Exit with error.
    return 1;
  }

  // Open file indicated by first command line argument.
  FILE *f = fopen(argv[1], "rb");
  // Check if file opened.
  if (f == NULL) {
    // Print error.
    perror(argv[1]);
    // Exit with error.
    return 1;
  }

  // For reading a single byte.
  uint8_t x;
  // For iterating.
  int i = 0;

  // While we keep getting bytes from f.
  while (fread(&x, 1, 1, f) == 1) {
    // Print the HEX of the byte with leading zeros.
    printf("%02X", x);
    // Increment bytes read.
    i++;
  }

  // Print number of bytes read.
  printf("\n%d bytes\n", i);

  // Reset file pointer to start of file.
  fseek(f, 0, SEEK_SET);

  // While we keep getting bytes from f.
  while (fread(&x, 1, 1, f) == 1) {
    // Loop through the bits of the current byte.
    for (i = 7; i >= 0; i--)
      // Print a 1 if it's a 1, 0 otherwise.
      printf("%d", (x >> i) & 0x01 ? 1 : 0);
  }

  // Complete the line.
  printf("\n");


  // Exit without error.
  return 0;

}

