from random import randint

#schimb reach, n si m de aici pentru a genera testele
reach = 11    #nr maxim
n = 10        #nr elemente vector
m = 3    #nr perechi
file1 = open("testpy.out", "w+")
file1.write(str(n)+" "+str(m) + "\n")
i = n
while i > 0:
    number = randint(0, reach)
    i = i - 1
    file1.write(str(number)+" ")

file1.write("\n")
while m > 0:
    x = randint(0, n-1)
    y = randint(x, n-1)
    file1.write(str(x) + " " + str(y))
    file1.write("\n")
    m=m-1
file1.close()
