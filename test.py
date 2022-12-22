    
faclist = [1]
for i in range(1, 5983):
    faclist.append((len(faclist) + 1) * faclist[-1])

print(faclist[-1])
faclist[-1] = str(faclist[-1])

for count, i in enumerate(faclist[-1][::-1]):
    if i == '0': continue
    print(count)
    break

    
