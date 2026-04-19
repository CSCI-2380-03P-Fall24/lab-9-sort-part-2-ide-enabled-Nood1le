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
        for(int i = 0; i < n - 1; i++){
                bubblePass(arr, n - 1);
        }
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
        string key = arr[currentIndex];
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
        double temp = darray[index1];
        darray[index1] = darray[index2];
        darray[index2] = temp;
}

int minFind(double darray[], int n) {
        //start off the min as index 0
        int min = 0;
        //loop to that searches the entire array and finds the index with the smallest value
        for(int i = 0; i < n; i++){
                if(darray[i] < darray[min]){
                        min = i;
                }
        }
        //returns index with smallest element
    return min;
}

void newSort(double darray[], int n) {
        //loop that repeats for the size of the array
        //minIndex is set to what minFind returns
        for(int i = 0; i < n; i++){
                //paramaters for minFind is a pointer to the current index i
                //this is because minFind sets the smallest element as the first index
                //so no need to check that one anymore
                //n - i to decrease the size of array for each iterration
                int minIndex = minFind(&darray[i], n - i);
                swap(darray, i, i + minIndex); // swaps the current index (i) with the smallest found index
                //i + minIndex is the index of the complete array to account that minFind is being called with a reduced array
        }

}