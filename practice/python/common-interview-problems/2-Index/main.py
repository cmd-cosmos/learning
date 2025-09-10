### given: sorted int arr, and int target
### find idx of 1st and last posn of target in arr
### if target not in arr, return [-1, -1]

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
