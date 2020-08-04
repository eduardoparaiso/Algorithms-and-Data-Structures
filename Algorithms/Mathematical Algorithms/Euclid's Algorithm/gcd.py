# O(log(min(a, b)))

def recursive_gcd(int a, int b):
    if(b == 0):
        return a
    else:
        return recursive_gcd(b, a%b)


def iterative_gcd(int a, int b):
    while(b != 0):
        r= a%b
        a= b
        b= r
    return a