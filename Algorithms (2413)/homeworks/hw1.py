import math

def question1(num):
	result = 0
	for x in xrange(1,num):
		print "This is the ", x, " loop"
		for y in xrange(1,x):
			print "Old result = ", result
			result = result + 2
			print "new result = ", result
	print result

def question2(num):
	j = 1
	result = 0
	print "square root: ", math.sqrt(num)
	while j < math.sqrt(num):
		result = result + j
		j = j + 1
	print "result: ", result


def question3(num):
	result = 0
	i = 1
	while i < num:
		i = 2 * i
		result = result + 1
	print "result: ", result

def main():
	# print "question1"

	# print "2"
	# question1(2)
	# print
	# print

	# print "3"
	# question1(3)
	# print
	# print

	# print "4"
	# question1(4)
	# print
	# print

	# print "5"
	# question1(5)
	# print
	# print

	# print "6"
	# question1(6)
	# print
	# print

	# print "7"
	# question1(7)
	# print
	# print

	# print "8"
	# question1(8)
	# print
	# print

	# print "question2"
	# for x in xrange(1,30):
	# 	print x
	# 	question2(x)
	# 	print
	# 	print
	
	# print "question3"
	# for x in xrange(1,10):
	# 	number = pow(2,x)
	# 	print x
	# 	print number
	# 	question3(number)
	# 	print

if __name__ == '__main__':
  main()
