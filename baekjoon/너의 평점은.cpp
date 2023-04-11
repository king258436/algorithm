rating = ["A+", "A0", "B+", "B0", "C+", "C0", "D+", "D0", "F"]
grade = [4.5, 4.0, 3.5, 3.0, 2.5, 2.0, 1.5, 1.0, 0]
sum = 0
hak =0
for _ in range(20):
    s,j,g = input().split()
    j = float(j)
    if g !='P':
        sum += j * grade[rating.index(g)]
        hak +=j
print('%.6f'%(sum/hak))
