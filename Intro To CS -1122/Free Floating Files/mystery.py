# Sorts
def mystery1(l):
    for p in range(len(l)-1,0,-1):
        for i in range(p):
            if l[i] > l[i + 1]:
                temp = l[i]
                l[i] = l[i+1]
                l[i+1] = temp

# Shits list over
def mystery2(l, n):
    lostNums = l[0:n]
    for i in range(len(l)):
        l[i] = l[(i + n) % len(l)]
    l[-n:] = lostNums

# Biggest common factor
def mystery3(q, d):
    if d == 0:
        return q
    else:
        return mystery3(d, q % d)

alist = [54,26,93,17,77,31,44,55,20]
print "Original list:" + str(alist) + "\n"
mystery1(alist)
print "Mystery 1:" + str(alist) + "\n"

alist = [54,26,93,17,77,31,44,55,20]
print "Original list:" + str(alist) + "\n"
mystery2(alist, 2)
print "Mystery 2: " + str(alist) + "\n"

print "Mystery 3: " + str(mystery3(20, 8))
