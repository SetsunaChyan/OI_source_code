def toi(c):
    c=ord(c)
    if c>=ord('0') and c<=ord('9'):
        return c-ord('0')
    elif c>=ord('A') and c<=ord('Z'):
        return c-ord('A')+10
    else:
        return c-ord('a')+36

def toc(c):
    if c<10:
        return chr(ord('0')+c)
    elif c<36:
        return chr(ord('A')+c-10)
    else:
        return chr(ord('a')+c-36)
    
x,y,z=input().split()
x=int(x)
y=int(y)
t=0
now=1
for i in range(len(z)-1,-1,-1):
    t+=now*toi(z[i])
    now*=x;
c=[]
while t>0:
    c.append(t%y)
    t//=y
if len(c)==0:
    c.append(0)
for i in range(len(c)-1,-1,-1):
    print(toc(c[i]),end='')
