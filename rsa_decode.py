import os
import math

clear = lambda:os.system('cls')
clear()

def is_prime(n=100):
    for num in range(2,101):
        isPrime = True
        for i in range(2,num):
            if (num%i==0):
                isPrime = False
        if isPrime:
            prime.append(num)


def finding_d():
    global d
    global e
    global p
    global q

    d = 0
    div = (p-1)//math.gcd(p-1, q-1)
    q_minus1 = q - 1
    m = div * q_minus1

    # Step 2: compute modular inverse using pow()
    d = pow(e, -1, m)  # modular inverse of e mod m



prime = []
p = None
q = None
phi = None
n = None
e = None
d = None
info = 0


while info != -1:
    print(f"P = {p}\nQ = {q}\nphi = {phi}\nN = {n}\nE = {e}\nD = {d}\n\n\n")
    info = int(input("What do you have\n[1] P\n[2] Q\n[3] phi\n[4] N\n[5] E\n[6] D\n[-1] Exit\n---> "))

    match info:
        case 1:
            p = int(input("What is the value of P\n---> "))
        case 2:
            q = int(input("What is the value of Q\n---> "))
        case 3:
            phi = int(input("What is the value of phi\n---> "))
        case 4:
            n = int(input("What is the value of N\n---> "))
        case 5:
            e = int(input("What is the value of E\n---> "))
        case 6:
            d = int(input("What is the value of D\n---> "))

if p != None and q != None:
    phi = (p - 1) * (q - 1)
    if n == None:
        n = p * q

if n != None and (p == None and q == None):
    is_prime(n)
    for i in range(1,len(prime)):
        possible = n/i
        if int(possible) in prime and int(possible) * i == n:
            p = int(i)
            q = int(possible)

if phi == None and (p != None and q != None):
    phi = (p - 1) * (q - 1)

finding_d()
print(d)



clear()

ct = []
pt = []
user = 0

while user != -1:
    ct = str(input("What is the input (exit: -1)\n---> ")).split()
    print(ct)
    if int(ct[-1]) == -1:
        ct.pop(-1)
        break
    

for i in ct:
    pt.append(chr(pow(int(i),d,n)))

clear()

print(f"P = {p}\nQ = {q}\nphi = {phi}\nN = {n}\nE = {e}\nD = {d}\n\n\n")

print("Output: ",end="")

print(''.join(pt),end="")
