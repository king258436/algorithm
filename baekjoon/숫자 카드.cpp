
def binary_search(target,data) :
    start = 0
    end = len(data)-1

    while start<=end:
        mid = (start+ end)//2
        if(target == data[mid]) :
            return mid
        else :
            if target>data[mid] : start = mid+1
            else : end = mid-1
    return -1


sang_num = int(input())
sang_card = list(map(int, input().split()))
pan_num = int(input())
pan_card = list(map(int, input().split()))
sang_card.sort() #상근이 배열 정렬

for i in range(pan_num) :
    idx = binary_search(pan_card[i],sang_card)
    if idx >=0 : pan_card[i]=1
    else : pan_card[i]=0


for i in range(pan_num):
    print(pan_card[i],end=' ')
