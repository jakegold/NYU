def greedyAlg(lista, listb, inputval):
	i = 1
	while i <=4:
		listb[i-1] = inputval / (lista[i-1])
		inputval = inputval%lista[i-1]
		print 'inputval: ', inputval
		i = i+1
	return listb

def main():
	lista = [25,10,7,1]
	# listb = [0,0,0,0]
	# greedyAlg(lista,listb,68)
	# print listb
	listb = [0,0,0,0]
	greedyAlg(lista,listb,30)
	print listb


if __name__ == "__main__":
    main()