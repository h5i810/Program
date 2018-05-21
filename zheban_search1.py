def binarySearch(alist,target):
    first=0
    last=len(alist)-1
    found=False

    while first<=last and not found:
        mid=(first+last)//2
        if alist[mid]==target:
            found=True
        else:
            if target<alist[mid]:
                last=mid-1
            else:
                first=mid+1
    return found

testlist=[0,1,2,3,4,5,6,7,8,9,13,17,19,32,42]
print(binarySearch(testlist,3))
print(binarySearch(testlist,13))