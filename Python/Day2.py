with open('day2.txt') as f:
    data = f.read().splitlines()

twos = 0
threes = 0
for s in data:
    twocount = False
    threecount = False
    for c in s:
        if s.count(c) == 2 and not twocount:
            twos += 1
            twocount = True
        if s.count(c) == 3 and not threecount:
            threes += 1
            threecount = True
        if twocount and threecount:
            break
    for t in data:
        count = 0
        for i in range(len(t)):
            if t[i] != s[i]:
                count += 1
                bad = i
            if count > 1:
                break
        if count == 1:
            parttwo = list(t)
            parttwo.pop(bad)
            parttwo = ''.join(parttwo)

print("Part one: " + str(twos * threes))
print("Part two: " + parttwo)
