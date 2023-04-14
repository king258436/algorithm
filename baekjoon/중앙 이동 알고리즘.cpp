import math
arr = [4]
n = int(input())
for i in range(1,n+1):
    a = math.sqrt(arr[i-1])
    a= a*2-1
    arr.append(int(math.pow(a,2)))
print(arr[n])
