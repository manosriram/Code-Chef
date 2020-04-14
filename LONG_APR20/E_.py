T = int(input())

def does(n):
    return (n % 2 != 0 or n % 4 == 0);

while T>0:
    n = int(input())
    a = list(map(int, input().split()))

    ct = 0
    for i in range(0, len(a)):
        prod = a[i]
        if(does(prod)):
            ct+=1
        for j in range(i+1, len(a)):
            prod *= a[j]
            if (does(prod)):
                ct +=1
    
    print(ct)
    T-=1

