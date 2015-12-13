#include <stdio.h>
#include <stdlib.h>

int read_file_line(FILE *fp);
void mergeSort(int *arr, int l, int r);

int main(){
  int total_length = 0;
  int *arr = NULL;
  int line_no=0;
  char *line = NULL;
  size_t len = 0;
  ssize_t read;
  FILE *fp_writer = NULL;

  FILE *fp = fopen("DuplicateIntegerArray.txt", "r");
  total_length = read_file_line(fp);
  arr = (int *)malloc(sizeof(int) * total_length);
  rewind(fp);
  printf("Total Length %d\n", total_length);
  while ((read = getline(&line, &len, fp)) != -1) {
    //printf("Retrieved line of length %zu : %s\n", read, line);
    arr[line_no] = atoi(line);
    line_no++;
  }

  fclose(fp);
  mergeSort(arr, 0, total_length - 1);

  fp_writer = fopen("SortedArray.txt", "w");

  for(int i=0;i< total_length ;i++){
    //printf("Sorted Array %d\n", arr[i]);
    fprintf(fp_writer, "%d\n", arr[i]);
  }
  fclose(fp_writer);
  return 0;
}



int read_file_line(FILE *fp){
  int ch = 0;
  int l=0;
  while ((ch=fgetc(fp)) != EOF  ) {
    if(ch == '\n')
      l++;
  }
  return l;
}

/* Function to merge the two haves arr[l..m] and arr[m+1..r] of array arr[] */
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    /* create temp arrays */
    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for(i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for(j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

/* l is for left index and r is right index of the sub-array
  of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l+(r-l)/2; //Same as (l+r)/2, but avoids overflow for large l and h
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}
