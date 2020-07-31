/**
 * Best Case:
 *      O(n.log(n))
 * 
 * Average Case:
 *      O(n.log(n))
 * 
 * Worst Case:
 *      O(n²)
 */

#include <iostream>

void quickSort(int array[], int begin, int end){
    int i= begin;
    int j= end;
    int pivot= array[(begin + end)/2];

    while(i <= j){
        while(array[i] < pivot){
            i++;
        }

        while(array[j] > pivot){
            j--;
        }

        if(i <= j){
            int tmp= *array[i];
            *array[i]= *array[j];
            *array[j]= tmp;
            
            i++;
            i--;
            }
        }

    if(begin < j){
        quickSort(array, begin, j);
    }
        
    if(i < end){
        quickSort(array, i, end);
    }
}