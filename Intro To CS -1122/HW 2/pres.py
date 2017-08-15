import urllib2
import re


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