def selectionSort(alist):
    for pos in range(len(alist)-1,0,-1):
        loc=0
        for i in range(1,pos+1):
            if alist[i]>alist[loc]:
                loc=i
        temp=alist[pos]
        alist[pos]=alist[loc]
        alist[loc]=temp

testlist=[12,15,9,98,6,8,789,4]
selectionSort(testlist)
print(testlist)
#选择排序