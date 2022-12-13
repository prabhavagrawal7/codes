file = open("output.txt", 'w')
faclst = [(1, 1)]
for i in range(2, 5982 + 1):
    faclst.append((i, faclst[-1][1] * i))

for item in faclst:
    file.write(f"{item[0]}, {len(str(item[1]))}, {str(item[1])[::-1]}\n")
