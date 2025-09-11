### given: sorted int arr, and int target
### find idx of 1st and last posn of target in arr
### if target not in arr, return [-1, -1]

# Solution 1 ---> O(n) time complexity

arr = [2,4,5,5,5,5,7,9,9]
print(arr)
reuslt = []
target = int(input("Enter Target: "))
start = None
end = None

if target in arr:
    for i in range(len(arr)):
        if arr[i] == target:
            start = i
            while i+1 < len(arr) and arr[i+1] == target:
                i+=1
            end = i
            break    
    reuslt.append(start)
    reuslt.append(end)
    print(reuslt)
else:
    reuslt = [-1,-1]
    print(reuslt)

print("==============================================================")
# Solution 2 ---> binary search ---> due to the sorted nature of the array
# O(logn) time and O(1) space

def bs_left(arr, target):
    '''function to search for the left index'''
    if arr[0] == target:
        return 0
    left, right = 0, len(arr)-1
    while left <= right:
        mid = (left + right) // 2 
        if arr[mid] == target and arr[mid-1] < target:
            return mid
        elif arr[mid] < target:
            left = mid + 1
        else:
            right = mid - 1
    return -1
    
def bs_right(arr, target):
    if arr[0] == target:
        return 0
    left, right = 0 , len(arr)-1
    while left <= right:
        mid = (left + right) // 2
        if arr[mid] == target and arr[mid+1] > target:
            return mid
        elif arr[mid] > target:
            right = mid - 1
        else:
            left = mid + 1
    return -1

def algo(arr, target):
    if len(arr) == 0 or arr[0] > target or arr[-1] < target:
        return [-1,-1]
    start_idx = bs_left(arr, target)
    end_idx = bs_right(arr, target)
    return [start_idx, end_idx]

bs_result = algo(arr=arr, target=target)
print(bs_result)
