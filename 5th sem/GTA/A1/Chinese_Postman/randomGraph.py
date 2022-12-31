import random

seedValue = 27
random.seed(seedValue)
for i in range(3):
    f = open("testcase"+str(i+1)+'.txt', 'w')
    n = 20
    f.write(str(n)+'\n')
    edges = {i:[] for i in range(n)}
    maxcost = 500
    mincost = 10
    for j in range(n):
        ne = random.randint(1,n-1)
        for k in range(ne):
            v = random.randint(0,n-1)
            w = random.randint(mincost, maxcost)
            edges[j].append((v, w))
            edges[v].append((j, w))
            
    for i in edges:
        f.write(str(i))
        for j in edges[i]:
            f.write(" "+str(j[0])+" "+str(j[1]))
        f.write("\n")
    f.close()