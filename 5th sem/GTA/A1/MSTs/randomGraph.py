import random

seedValue = 27
random.seed(seedValue)
n_files = 5
for i in range(5):
    f = open("testcase"+str(i+1)+'.txt', 'w')
    n = 100
    f.write(str(n)+'\n')
    edges = {i:[] for i in range(n)}
    maxcost = 100
    mincost = 10
    for j in range(n):
        ne = random.randint(1,n-1)
        for k in range(ne):
            v = random.randint(0,n-1)
            w = random.randint(mincost, maxcost)
            if(v!=j):
                edges[j].append((v, w))
                edges[v].append((j, w))
            
    for i in edges:
        f.write(str(i))
        for j in edges[i]:
            f.write(" "+str(j[0])+" "+str(j[1]))
        f.write("\n")
    f.close()