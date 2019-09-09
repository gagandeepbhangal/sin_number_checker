#include <stdio.h>
#include <stdlib.h>

int populate_array(int, int *);
int check_sin(int *);


int main(int argc, char **argv) {
    // TODO: Verify that command line arguments are valid.
    if (argc != 2){
      return 1;
    }
    // TODO: Parse arguments and then call the two helpers in sin_helpers.c
    // to verify the SIN given as a command line argument.
    if (argv[1][0] == '0'){
      printf("Invalid SIN\n");
      return 0;
    }
    //Parse string to long int
    int num = strtol(argv[1], NULL, 10);

    int sin_num[9];

    if (populate_array(num, sin_num) == 0 && check_sin(sin_num) == 0){
      printf("Valid SIN\n");
    }
    else{
      printf("Invalid SIN\n");
    }
    return 0;
}
