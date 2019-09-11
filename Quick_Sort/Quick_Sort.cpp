// Helper function.
void SwapArrayElements(int *first, int *second){    
    // Traditional XOR swap.
    *first  ^= *second;
    *second ^= *first;
    *first  ^= *second;
}

// Primary algorithm.
int GetPartitionIndex(int unsorted_array[], int first, int last){

    // Set pivot. May be changed to beginning of array.
    int pivot = unsorted_array[last];

    int i = first - 1;

    for(int j = first; j <= last - 1; j++){
        if(unsorted_array[j] < pivot){
            i++;
            SwapArrayElements(&unsorted_array[i], &unsorted_array[j]);
        }
    }

    SwapArrayElements(&unsorted_array[i + 1], &unsorted_array[last]);
    return i + 1;
}

// Top-level sorting algorithm.
void QuickSort(int unsorted_array[], int first, int last){

    // Traverse array until sorted.
    if(low < high){
        // Find the index to split the array at.
        int partition_index = GetPartitionIndex(unsorted_array, first, last);
        
        QuickSort(unsorted_array, first, partition_index - 1);
        QuickSort(unsorted_array, partition_index + 1, last);
    }

}
