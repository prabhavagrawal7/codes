file = open("input.txt", "w")
file.write(str(int(1e5)))
file.write("\n")
for i in range(int(1e5)):
    file.write("1 ")