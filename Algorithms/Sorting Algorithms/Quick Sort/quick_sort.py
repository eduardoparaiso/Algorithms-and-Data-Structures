# Best Case:
#      O(n.log(n))
# 
# Average Case:
#      O(n.log(n))
# 
# Worst Case:
#      O(n²)

def quickSort(array, begin, end):
    i= begin
    j= end
    pivot= array[(begin + end)//2]

    while (i <= j):
        while (array[i] < pivot):
            i+= 1
        
        while (array[j] > pivot):
            j-=1
        
        if(i <=j):
            tmp= array[i]
            array[i]= array[j]
            array[j]= tmp
            i+=1
            j-=1
    
    if(begin < j):
        quickSort(array, begin, j)

    if(i < end):
        quickSort(array, i, end)