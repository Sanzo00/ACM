import os, datetime, time

all = 0
lastweek = 0

R = open('/root/ACM/README.md', 'r')

def getLastweek():
	global lastweek
	for line in R.readlines():
		pos = line.find("Until Last Week")
		if pos > -1:
			lastweek = int(line[17:])
			# print(lastweek)
	
	weekday = int(time.strftime("%w"))
	if weekday == 0 : weekday = 7
	hour = int(time.strftime("%H")) + 12

	lastweek = -1 if weekday >= 4 and hour >= 0 else lastweek


def getFiles(path):
	Dirs = os.listdir(path)
	tot = 0
	for dir in Dirs:
		if os.path.isdir(path + '/' + dir):
			tot += getFiles(path + '/' + dir)
		else:
			tot += 1
	return tot

def getReadme():
	# getLastweek()
	global all, weekday, lastweek
	W = open('/root/ACM/README.md', 'w')
	W.write('# All the problems I solved\n\n```\n')
	path = "/root/ACM/ACcode"
	OJ = os.listdir(path)
	OJ.sort()
	for i in OJ:
		cnt = getFiles(path + '/' + i)
		all += cnt
		W.write('{:<30s}{:d}{:s}'.format(i, cnt, '\n'))

	
	# if lastweek == -1
	# W.write("\n\nUntil Last Week: {}\n".format(lastweek))
	W.write("```\n## Total: " + str(all) + "\n")


if __name__ == '__main__':	

	days = time.strftime("%Y/%m/%d")

	# print(days)
	getReadme()
	os.system("cd /root/ACM && git add .")
	os.system("cd /root/ACM && git commit -m {}".format("update_" + days))
	os.system("cd /root/ACM && git push")
	
