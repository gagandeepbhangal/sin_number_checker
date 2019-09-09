

// TODO: Implement populate_array
/*
 * Convert a 9 digit int to a 9 element int array.
 */
int populate_array(int sin, int *sin_array) {
  int counter = 0;
  int temp[9];
  while (sin > 0){
    //Check to make sure the integer is 9 digits, no more, no less
    if (counter < 8 && (sin/10) == 0){
      return 1;
    }
    else if (sin > 999999999){
      return 1;
    }
    //Add the numbers to the list (this is done in reverse)
    temp[counter] = sin%10;
    sin = sin/10;
    counter += 1;
  }
  //Create a loop to take the reversed set of numbers and add them in the correct
  //order to sin_array
  int reverse_count = 8;
  for (int i = 0; i < 9; i++){
    sin_array[reverse_count] = temp[i];
    reverse_count -= 1;
  }
  return 0;
}

// TODO: Implement check_sin
/*
 * Return 0 (true) iff the given sin_array is a valid SIN.
 */
int check_sin(int *sin_array) {
  //Check to see if the number starts with a 0
  if (sin_array[0] == 0){
    return 1;
  }
  int sum = 0;
  int temp = 0;
  for (int i = 0; i < 9; i++){
    //Multiply all even indexes by 1 (starting at index 0) and all odd indexes by 2
      if (i%2 == 0){
        sum += sin_array[i];
      }
      else{
        temp = sin_array[i] * 2;
        if (temp >= 10){
          //I do += 1 because the max number we can obtain is 9*2 which is 18
          //Therfore, I would never have more than 1 for the first digit
          sum += temp - 10;
          sum += 1;
        }
        else{
          sum += temp;
        }
      }
  }
  if (sum % 10 != 0){
    return 1;
  }
  else{
    return 0;
  }
}
