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

public class selection_sort{
    public void selectionSort(int array[]){
        int n = array.length; 

        for (int i = 0; i < (n - 1); i++){
            int min= i;
            for (int j = (i + 1); j < n; j++){
                if (array[min] > array[j]){
                    min = j;
                }
            }
            swap(min, i);
        }
    }      
}
