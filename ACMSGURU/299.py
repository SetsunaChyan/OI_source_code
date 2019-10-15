a=[]
n=eval(input())
x,y,z=0,0,0
for i in range(0,n):
    a.append(eval(input()))
a.sort()
for i in range(0,n-2):
    if a[i]+a[i+1]>a[i+2]:
        x,y,z=a[i],a[i+1],a[i+2]
print(x,y,z)
