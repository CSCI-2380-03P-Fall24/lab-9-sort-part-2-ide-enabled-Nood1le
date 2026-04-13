#include <iostream>
#include <string>

using namespace std;

/*
Implement Bubble Sort

Step 1: implement bubblePass()
        This function should make ONE full pass through the array.
        Compare each pair of adjacent elements.
        If they are out of order, swap them.

        After one full pass, the largest unsorted value should
        "bubble up" to the end of the array section being checked.

Step 2: implement bubbleSort()
        Repeatedly call bubblePass() until the whole array is sorted.
        Each time you complete a pass, one more value is in its
        correct position at the end of the array.

        You may shorten the range each time if you wish.
*/

void swapInt(int arr[], int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
}

void bubblePass(int arr[], int n) {
        for(int i = 0; i < n -1; i++){
                if(arr[i] > arr[i+1]){
                        swapInt(arr, i, i + 1);
                }
        }

}

void bubbleSort(int arr[], int n) {

}


/*
Implement Insertion Sort

Step 1: implement insertionStep()
        Assume the array from index 0 to currentIndex - 1 is already sorted.
        Take the value at currentIndex and insert it into the correct
        location in the sorted part of the array.

        To do this:
        - save the current value
        - shift larger values one position to the right
        - place the saved value into its correct position

Step 2: implement insertionSort()
        Treat the first element as already sorted.
        Then repeatedly call insertionStep() on each next index
        until the full array is sorted.
*/

void insertionStep(string arr[], int currentIndex) {
        int key = arr[currentIndex];
        int j = currentIndex - 1;

        while(j >= 0 && arr[j] > key){
                arr[j + currentIndex] = arr[j];
                j--;
        }

        arr[j + 1] = key;
}

void insertionSort(string arr[], int n) {
        for(int i = 1; i < n; i++){
                insertionStep(arr, i);
        }
}


// Implement a brand new sorting algorithm
//    Don't use a reference for this!
//    Be sure to do your best to implement the algorithm's logical steps
// Step 1: implement a function swap() that will swap any two elements in an array,
//          given their indices
// Step 2: implement a function minFind() that will find and return 
//          the **index** of the smallest element in an array
/*
Step 3: Finally, use your two functions above to complete the following in newSort():
        1 - search through the array to find the location of the smallest value
        2 - swap this value with the value at the start of the array (use the swap from the previous creation in exercise 1)
        3 - the first element is now sorted! 
            Redo your sort on the remaining elements (from index 1 to end)
            On the next iteration, you should be swapping the smallest remaining value 
                with the second index value in the array
            ...then swapping the smallest remaining value with the third indexed value... etc.
            
        4 - continue iterating until you reach the end of the list
        *** You can make this recursive, if you wish!
*/

void swap(double darray[], int index1, int index2) {
        int temp = darray[index1];
        darray[index1] = darray[index2];
        darray[index2] = temp;
}

int minFind(double darray[], int n) {
        int min = 0;
        for(int i = 0; i < n - 1; i++){
                if(darray[i] < darray[min]){
                        min = i;
                }
        }
    return min;
}

void newSort(double darray[], int n) {
        for(int i = 0; i < n -1; i++){
                int minIndex = minFind(darray + 1, n - if);
                swap(darray, i, i + minIndex);
        }

}