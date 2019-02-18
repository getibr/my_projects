import random

def start_new_strategies(N):
    start_sigmas=[]
    lst=[-1,1]
    file=open('start_sigmas.txt','w')
    for i in range(N):
        start_sigmas=int(random.choice(lst))
        start_sigmas=str(start_sigmas)
        file.write(start_sigmas+'\n')
    file.close()
    return()



