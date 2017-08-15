import matplotlib.pyplot
import random
import sys


if len(sys.argv) != 2:
  print 'usage: ./filename.py your-first-name'
  sys.exit(1)
theName = sys.argv[1]



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
# fig.savefig('plotcircles.png')
matplotlib.pyplot.show()