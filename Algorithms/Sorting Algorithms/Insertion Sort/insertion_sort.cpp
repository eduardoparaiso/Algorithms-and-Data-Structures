//"n" is the size of the structure to be sorted by the method

/**
 * Best Case:
 *      Comparisons = O(n)
 *      Swaps = O(1)
 * 
 * Average Case:
 *      Comparisons = O(n²)
 *      Swaps = O(n²)
 * 
 * Worst Case:
 *      Comparisons = O(n²)
 *      Swaps = O(n²)
 */

#include <iostream>

void insertionSort(int array[], int n){
    for(int i= 1; i < n; i++){
        int tmp= array[i];
        int j= i-1;

        while(j >= 0 && array[j] > tmp){
            array[j+1]= array[j];
            j-= 1;
        }
        
        array[j+1]= tmp;
    }
}