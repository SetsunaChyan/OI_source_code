x=eval(input())
l=0
r=x
while l<r:
    m=(l+r+1)//2
    if m*m>x:
        r=m-1
    else:
        l=m
print(l)
