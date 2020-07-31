# Best Case:
#      Comparisons = O(n)
#      Swaps = O(1)
# 
# Average Case:
#      Comparisons = O(n²)
#      Swaps = O(n²)
# 
# Worst Case:
#      Comparisons = O(n²)
#      Swaps = O(n²)

def insertionSort(list_to_sort):
    for i in range(1, len(list_to_sort)):
        tmp= list_to_sort[i]
        j= i-1

        while (j >= 0) and (tmp < list_to_sort[j]):
            list_to_sort[j+1]= list_to_sort[j]
            j-= 1
        list_to_sort[j+1]= tmp