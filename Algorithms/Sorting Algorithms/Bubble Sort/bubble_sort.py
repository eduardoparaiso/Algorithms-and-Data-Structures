# Best Case:
#      Comparisons = O(n)
#      Swaps = O(1)

# Average Case:
#      Comparisons = O(n²)
#      Swaps = O(n²)

# Worst Case:
#      Comparisons = O(n²)
#      Swaps = O(n²)

def bubbleSort(list_to_sort):
    for i in range(len(list_to_sort)-1,0,-1):
        for j in range(i):
            if list_to_sort[j]>list_to_sort[j+1]:
                temp = list_to_sort[j]
                list_to_sort[j] = list_to_sort[j+1]
                list_to_sort[j+1] = temp