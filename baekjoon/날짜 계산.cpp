e_,s_,m_=map(int, input().split())
cnt,e,s,m=0,0,0,0
while e!=e_ or s!=s_ or m!= m_:
    cnt+=1
    e = (e+1)%16
    if e==0  :e=1
    s = (s+1)%29
    if s==0 :s=1
    m = (m+1)%20
    if m==0:  m=1
    

print(cnt)


