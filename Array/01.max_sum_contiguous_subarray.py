def maxSubArray(arr, n):
    maxSum = arr[0]
    currentSum = 0

    for i in range(len(arr)):
        currentSum += arr[i]
        
        if(currentSum > maxSum):
            maxSum = currentSum
        
        if(currentSum < 0):
            currentSum = 0
    
    return maxSum

arr = [-2, 1, -3, 4, -1, 2, 1, -5, 4]
print(maxSubArray(arr, len(arr)))