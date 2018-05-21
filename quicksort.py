def quick_sort(alist,first,last):
    if first<last:
        mid=partition(alist,first,last)
        quick_sort(alist,first,mid-1)
        quick_sort(alist,mid+1,last)

def partition(alist,first,last):
    x=alist[last]
    i=first-1
    for j in range(first,last):
        if alist[j]<=x:
            i+=1
            alist[i],alist[j]=alist[j],alist[i]

    alist[i+1],alist[last]=alist[last],alist[i+1]
    return i+1

alist=[545,65,645,6,54,8,6,26,565,65]
quick_sort(alist,0,9)
print(alist)
