with open('day5.txt') as f:
    data = f.read().strip()

pairs = []
parttwo = []

for i in range(ord('a'), ord('z') + 1):
	pairs.append(chr(i) + chr(i).swapcase())
	pairs.append(chr(i).swapcase() + chr(i))

def react(poly):
	newpoly = poly
	while True:
		for s in pairs:
			newpoly = newpoly.replace(s, '')
		if newpoly == poly:
			break
		else:
			poly = newpoly
	return newpoly

for i in range(ord('a'), ord('z') + 1):
	parttwo.append(len(react(data.replace(chr(i), '').replace(chr(i).swapcase(), ''))))

newdata = react(data)

print("Part 1: " + str(len(react(data))))
print("Part 2: " + str(min(parttwo)))
