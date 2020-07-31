#"swap" performs the exchange of position between two elements

# Best Case:
#      Comparisons = O(n²)
#      Swaps = O(1)
# 
# Average Case:
#      Comparisons = O(n²)
#      Swaps = O(n)
# 
# Worst Case:
#      Comparisons = O(n²)
#      Swaps = O(n)
 

def selection_sort(list_to_sort):
    for i in range(len(list_to_sort)): 
        min = i 
        for j in range(i+1, len(list_to_sort)): 
            if list_to_sort[min] > list_to_sort[j]: 
                min = j 
        #swap             
        list_to_sort[i], list_to_sort[min] = list_to_sort[min], list_to_sort[i] 