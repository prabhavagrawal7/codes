basearray = [3, 5]
joinedarray = []
for i in range(20
               ):
    newarray = [((1 << i) * x, x) for x in basearray]
    joinedarray += newarray

joinedarray.sort()
print(joinedarray)
