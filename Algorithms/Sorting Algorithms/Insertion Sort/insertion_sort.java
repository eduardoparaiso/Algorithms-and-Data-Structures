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

public class insertion_sort{
    public void insertionSort(int array[]){
        int n= array.length; 

        for(int i= 1; i < n; i++){
            int tmp= array[i];
            int j = i-1;

            while((j >=0) && (array[j] > tmp)){
                array[j+1]= array[j];
                j--;
            }
            array[j+1]= tmp;
        }
    }   
}