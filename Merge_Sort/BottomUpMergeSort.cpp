// TODO: Change to template.

void BottomUpMergeSort(int A[], int B[], int n){
  
  // Makes successively longer sorted runs, starting
  // with each 1-element run in A already sorted.
  for(int width = 1; width < n; width *= 2){
    // Array A is full of runs of length width.
    for(int i = 0; i < n; i = i + 2 * width){
      BottomUpMerge(A, i, min(i+width, n), min(i+2*width, n), B);
    }
    CopyArray(B, A, n);
  }
  

  return 0;
}

void BottomUpMerge(int A[], int left, int right, int end, int B[]){

  for(int k = left; k < end; k++){
    if(i < right && (j >= end || A[i] <= A[j])){
      B[k] = A[i];
      i = i + 1;
    }else{
      B[k] = A[j];
      j = j + 1;
    }
  }
}

void CopyArray(int B[], int A[], int n){
  for(int i = 0; i < n; i++){
    A[i] = B[i];
  }
}

