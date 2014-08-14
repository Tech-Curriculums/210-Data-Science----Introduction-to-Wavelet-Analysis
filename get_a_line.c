#include <stdio.h>
#include <stdlib.h>

int get_length_of_file();

int main(void) {


  //BEGIN VARIABLES

  //the start position of the file
  int init_pos;

  float positive_sum=0;
  float negative_sum=0;


  //THIS PART OF THE CODE SIMPLY GETS THE FILE INTO AN ARRAY
  FILE *infile;  //input file with data
  char price[8]; //takes input data from input file
  int lines=0;   //a counter for the number of lines in the file

  //END VARIABLES



  //OPEN FILE
  infile = fopen("./amzn_close.csv","r");

  //log the start position of the file
  init_pos= ftell(infile);

  //check the import and count lines
  while (fgets(price, sizeof(price), infile) !=0 ) {
    price[6]='\0'; //replace the newline with the null character

    //debugging line
    //printf("%s,%f \n", price, atof(price));

    lines++;
  }


  //reset the file pointer so we can use fgets again
  fseek( infile, init_pos, SEEK_SET);



  //MORE VARIABLES INIT HERE NECESSARILY
  //populate stock price array
  float stocks[lines];
  int line_iterator=0;
  //END ADDITIONAL VARIABLES
  while (fgets(price, sizeof(price), infile) !=0 ) {
    price[6]='\0';
    stocks[line_iterator]=atof(price);

    //debugging line
    //printf("%f \n", stocks[line_iterator]);

    line_iterator++;
  }


  //close the file to release resources
  fclose(infile);

  //print back the lines
  //printf("%d \n", lines);
  //
  //END THE PART OF THE CODE WHICH GETS IT INTO AN ARRAY

  //NOW WE CREATE THE POINTERS


  float circular_array[30];

  float *array_start, *array_end, *head_tail, *right_brim, *left_brim;

  head_tail = array_start = &circular_array[0];
  right_brim = &circular_array[20];
  left_brim = &circular_array[10];
  array_end = &circular_array[29];


  //LOAD CIRCULAR ARRAY
  int i;
  for (i=0; i < 30; i++ ) {
    circular_array[i] = stocks[i];
  }
  //END LOAD CIRCULAR ARRAY


  //Begin the HardHat wavelet -- and go in circles


  //fill each thing with 15 units
  for (i=0; i < 30/2; i++) {
  printf("left_brim %f; head_tail %f; right_brim %f\n\n\n", *(left_brim), *(head_tail), *(right_brim));
    //step 1: advance pointers
    head_tail  = head_tail++;
    left_brim  = left_brim++;
    right_brim = right_brim++;

    if ( head_tail - array_start >= 30 ) {
      head_tail = array_start;
    }
    else if ( left_brim - array_start >= 30 ) {
      left_brim = array_start;
    }
    else if ( right_brim - array_start >= 30 ) {
      right_brim = array_start;
    }

    //step 2: create the sums
    negative_sum -= *(left_brim);
    positive_sum += *(right_brim);
  printf("the negative_sum is %f; the positive_sum is %f \n", negative_sum, positive_sum);
  }


  printf("the negative_sum is %f; the positive_sum is %f \n", negative_sum, positive_sum);

// END INITIAL LOADING PHASE

  return 0;
  }
