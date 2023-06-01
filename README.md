# DSAL
set
a=[]
b=[]
c=[]
d=[]
e=[]

#accept or adding element
def accept(a):
    n=int(input("enter a number of elements in set a:"))
    for i in range(0,n):
        x=int(input())
        a.append(x)
    print("set A:",a)
accept(a)

def accept(b):
    m=int(input("enter a number of elements in set b:"))
    for i in range(0,m):
        x=int(input())
        b.append(x)
    print("set B:",b)
accept(b)

#delete element
def remove1(a):
    i=int(input("enter a element to delete from set A:"))
    if i in a:
            a.remove(i)
            print(a)
    else:
        print("element is not present in set")
        return
remove1(a)

def remove1(b):
    i=int(input("enter a element to delete from set B:"))
    if i in b:
            b.remove(i)
            print(b)
    else:
        print("element is not present in set")
        return
remove1(b)

#search

def search1(a):
     i=int(input("enter a element to search from set A:"))
     if i in a:
            print("element found")
     else:
        print("element not found")
        return
search1(a)

def search2(b):
     i=int(input("enter a element to search from set B:"))
     if i in b:
        print("element found")
        
     else:
        print("element not found")
        return
search2(b)

#size

def size1(a):
     print("size of set A is:",len(a))
size1(a)

def size2(b):
     print("size of set B is:",len(b))
size1(b)

#iter

def iter1(a):
    myit=iter(a)
    print(next(myit))
   
iter1(a)

def iter2(b):
    myit=iter(b)
    print(next(myit))
iter2(b)

#union

def union(a,b):
    for i in a:
        c.append(i)
    for i in b:
        if i not in c:
            c.append(i)
    print("union of A & B is:",c)
union(a,b)

#intersection

def inter(a,b):
    for i in a:
         if i in b:
              d.append(i)
    print("intersection of A & B is:",d)
inter(a,b)

#difference

def diff(a,b):
    for i in a:
        if i not in b:
            e.append(i)
    print("difference of A & B is:",e)
diff(a,b)

#subset

def ssubset(a):
    subset =[[]]
    for i in a:
        for j in subset:
            subset=subset+[list(j)+[i]]
    print(subset)
ssubset(a)
 
