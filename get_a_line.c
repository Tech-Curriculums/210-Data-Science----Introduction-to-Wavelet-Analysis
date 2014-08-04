#include <stdio.h>
#include <stdlib.h>


int main(void) {
  FILE *infile;
  char price[8];

  infile = fopen("./amzn_close.csv","r");

  while (fgets(price, sizeof(price), infile) !=0 ) {
    price[6]='\0';
    printf("%s,%f \n", price, atof(price));
  }
  return 0;
}
