T = int(input())
for _ in range(T):
    arr = list(map(int,input().split()))
    avg = sum(arr[1:])//arr[0]
    cnt=0
    for score in arr [1:] :
        if score>avg : cnt +=1
    per = cnt/arr[0] *100
    print(f"{per:.3f}%")
