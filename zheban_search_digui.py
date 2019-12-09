def binarySearch(alist,target):
    if len(alist)==0:
        return False
    else:
        mid=len(alist)//2
        if alist[mid]==target:
            return True
        else:
            if target<alist[mid]:
                return binarySearch(alist[:mid],target)
            else:
                return binarySearch(alist[mid+1:],target)

testlist=[0,1,2,3,4,5,6,7,8,9,13,17,19,32,42]
print(binarySearch(testlist,3))
print(binarySearch(testlist,13))