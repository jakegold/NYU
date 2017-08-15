import matplotlib.pyplot
import random
import sys
import urllib2
import re

def partOne(theName):
	mycolors = matplotlib.colors.cnames.values()
	thecolor = random.choice(mycolors)

	rback = matplotlib.pyplot.Rectangle((.2,.1), .6, .8, color = 'k')
	rface = matplotlib.pyplot.Rectangle((.3,.3), .4, .5, color = thecolor)
	lefteye = matplotlib.pyplot.Circle((.4,.7), .03, color = 'w')
	righteye = matplotlib.pyplot.Circle((.6,.7), .03, color = 'w')
	smile = matplotlib.pyplot.Rectangle((.45,.45), .2, .01, color = 'w')
	name = matplotlib.pyplot.annotate(theName, (.4,.2), color = 'w')


	fig = matplotlib.pyplot.gcf()

	fig.gca().add_artist(rback)
	fig.gca().add_artist(rface)
	fig.gca().add_artist(lefteye)
	fig.gca().add_artist(righteye)
	fig.gca().add_artist(smile)
	print 'Close pop-up for part two'
	# fig.savefig('plotcircles.png')
	matplotlib.pyplot.show()
	return

def partTwo():
	web = urllib2.urlopen('http://elections.huffingtonpost.com/pollster/api/charts/2016-national-gop-primary')
	words = web.read()
	party = re.search(r'(\d+) National (\w+)', words)
	print party.group(1), party.group(2) + ' Info:'
	index = words.index('estimates_by_date')
	words = words[:index]
	index = words.index('estimates')
	words = words[index:]
	runners = re.findall(r'"choice":"(\w+)","value":(\d+.\d),"lead_confidence":\w+,"first_name":"(\w+)', words)
	Undecided = re.search(r'(Undecided)","value":(\d+.\d)', words)
	Other = re.search(r'(Other)","value":(\d+.\d)', words)
	for triple in runners:
		print triple[2], triple[0] + ':', triple[1]
	print Undecided.group(1) + ': ' + Undecided.group(2)
	print Other.group(1) + ': ' + Undecided.group(2)
	return

def main():
	if len(sys.argv) != 2:
  		print 'USAGE: python hw02_goldstein.py your-first-name'
		sys.exit(1)
	theName = sys.argv[1]
	partOne(theName)
	partTwo()

main()




