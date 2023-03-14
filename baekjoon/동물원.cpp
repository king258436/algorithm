import collections
N = int(input())
arr = list(map(int,input().split()))
a = collections.Counter(arr)
if max(a.values()) > 2 or  len(a.keys()) != max(a.keys())+1:
    print(0)
else:
    keys = sorted(a.keys())
    result = 1
    prev_cnt = a[0]
    flag = True
    onecnt = False
    for k in keys:
 
        if prev_cnt < a[k]:
            flag = False
            break
        else:
            prev_cnt = a[k]
            if a[k] == 2:
                result*=2
            else:
                onecnt = True
    if flag:
        if onecnt:
            print(result*2)
        else:    
            print(result)
    else:
        print(0)
