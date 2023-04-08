total = int(input())
n = int(input())
for i in range(1,n+1):
    pay,cnt = map(int,input().split())
    total -=pay*cnt
if total == 0 :
    print("Yes")
else : print("No")
