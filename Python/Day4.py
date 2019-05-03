class Guard:
    def __init__(self):
        self.id = 0
        self.minutes = [0] * 60
        self.total = 0

class Entry:
    def __init__(self):
        self.datetime = 0
        self.minute = 0
        self.data = ""

logbook = []

with open("day4.txt") as f:
    data = f.read().splitlines()

for line in data:
    temp = Entry()
    temp.datetime = int(line[1:5] + line[6:8] + line[9:11] + line[12:14] + line[15:17])
    temp.minute = int(line[15:17])
    temp.data = line[19:]
    logbook.append(temp)

logbook = sorted(logbook, key= lambda x: x.datetime)
regiment = {}
currguard = 0
fellasleep = 0
for log in logbook:
    if log.data[0] == "G":
        currguard = int(log.data.split(' ')[1][1:])
        try:
            regiment[currguard] == 0
        except KeyError:
            regiment[currguard] = Guard()
            regiment[currguard].id = currguard
    elif log.data[0] == "f":
        fellasleep = log.minute
    elif log.data[0] == "w":
        for i in range(fellasleep, log.minute):
            regiment[currguard].minutes[i] += 1
            regiment[currguard].total += 1

mostasleep = Guard()
minuteasleep = Guard()

for g in regiment:
    if regiment[g].total > mostasleep.total:
        mostasleep = regiment[g]
    if max(regiment[g].minutes) > max(minuteasleep.minutes):
        minuteasleep = regiment[g]

print("Part one: " + str(mostasleep.minutes.index(max(mostasleep.minutes)) * mostasleep.id))
print("Part two: " + str(minuteasleep.minutes.index(max(minuteasleep.minutes)) * minuteasleep.id))
