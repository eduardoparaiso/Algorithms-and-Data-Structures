//"n" is the size of the structure to be sorted by the method
//"swap" performs the exchange of position between two elements

/**
 * Best Case:
 *      Comparisons = O(n²)
 *      Swaps = O(1)
 * 
 * Average Case:
 *      Comparisons = O(n²)
 *      Swaps = O(n)
 * 
 * Worst Case:
 *      Comparisons = O(n²)
 *      Swaps = O(n)
 */
#include <iostream>

void selection_sort(int array[], int n){      
    for(int i = 0; i < n-1; i++){  
        int min= i;

        for (int j = i+1; j < n; j++){
            if (array[j] < array[min])  
            min= j; 
        } 
  
        swap(min, j);  
    }  
}  