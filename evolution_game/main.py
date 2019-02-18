import random_sigmas
import last_random_sigmas
import n_for_gamer_i
import peyment_for_gamer
import var

N=var.N()
igr_i=var.ig_i()

#Раскомментировать, чтобы выбрать новый набор стартовых стратегий
#start_sigmas=random_sigmas.start_new_strategies(N)
start_sigmas=last_random_sigmas.start_strategies(N)
n=n_for_gamer_i.n_for_gamer_i(igr_i,start_sigmas)
p=peyment_for_gamer.peyment_for_gamer(igr_i,start_sigmas)
print(p)
print(start_sigmas)
print(n)
