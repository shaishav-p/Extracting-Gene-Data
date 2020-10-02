
#include <stdio.h>
#include <string.h>
#include <limits.h>

int highest_index(int *arr, int arr_len){
  int max = INT_MIN;
  int max_index = 0;
  for(int i = 0; i < arr_len; ++i){
    if(arr[i] > max){
      max_index = i;
      max = arr[i];
    }

  }

  return max_index;
}

int find_index(char *arr){
  char *data_arr[16] = {"AA", "AT", "AG", "AC", "TA", "TT", "TG", "TC","GA", "GT", "GG", "GC", "CA", "CT", "CG", "CC"};
  int data_arr_len = 16;
  for(int i = 0; i < data_arr_len; ++i){
    //printf("data_arr: %s %s  strcmp result: %d \n", data_arr[i], arr, strcmp(data_arr[i], arr));
    if( ((data_arr[i][0] == arr[0]) != 0) &&  ((data_arr[i][1] == arr[1]) != 0) ){
      return i;
    }
  }
  return 16;
}

int main(void) {
  char *data[16] = {"AA", "AT", "AG", "AC", "TA", "TT", "TG", "TC","GA", "GT", "GG", "GC", "CA", "CT", "CG", "CC"};
  int data_counter[16] = {};
  int data_counter_len = 16;

  //file reading
  FILE *fp;
  fp = fopen("data.txt", "r");

  char input[490] = {0};

  int loop_counter = 0;
  while(fscanf(fp,"%s", input) == 1){
    loop_counter++;
    if( ((loop_counter % 10) == 5) && (loop_counter > 20)){
      int len = strlen(input) - 1;
      char two_letters[2] = {0};

      for(int i = 0; i < len; ++i){     //loops through input str
        two_letters[0] = input[i];
        two_letters[1] = input[i + 1];

        int index = find_index(two_letters);
        if(index == 16){
          printf("error for loop_counter: %d    two_letters: %s\n", loop_counter, two_letters);
          return 0;
        } else{
          data_counter[index] += 1;
        }
      }

    }

  }
  int high_index = highest_index(data_counter, data_counter_len);
  printf("%s repeats %d times\n", data[high_index], data_counter[high_index]);


  fclose(fp);
  return 0;
}
