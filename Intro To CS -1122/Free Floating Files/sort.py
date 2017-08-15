# Brian Kao
# Henry Chen
# Jake Goldstein
# Jeff Wagner

lista = [5,2,234,67,8,4,3,1,2345]
listb = []
for thing in range(len(lista)):
	big = 0
	for item in lista:
		if item > big and item not in listb:
			big = item
	listb.append(big)
print listb
