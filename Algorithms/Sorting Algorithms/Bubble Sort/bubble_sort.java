//"n" is the size of the structure to be sorted by the method
//"swap" performs the exchange of position between two elements 

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

public class bubble_sort{
    public void bubble_sort(){
        for(int i= (n-1); i > 0; i--){
            for(int j= 0; j < i; j++){
                if(array[j] > array[j + 1]){
                    swap(j, j+1);
                }
            }
        }
    }
}