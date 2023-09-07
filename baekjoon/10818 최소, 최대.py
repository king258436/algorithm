nums=input()

num_list = list(map(int, input().split()))
def max1(num_list):
    result = -1000000
    for i in num_list:
        if i>=result:
            result=i
        else:
            result=result
    return result

def min2(num_list):
    result = 1000000
    for i in num_list:
        if result >=i:
            result=i
        else:
            result=result
    return result

    
a=max1(num_list)
b=min2(num_list)
print(b,a)