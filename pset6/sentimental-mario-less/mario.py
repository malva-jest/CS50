# TODO


# noOfRows = int(input("Give me a number: "))

# while True:
#     while noOfRows.isalpha() == True or noOfRows == "" end="" and not in range(1,9):

while True:
    try:
        noOfRows = int(input("Height: "))
        if (noOfRows >= 1) and (noOfRows <= 8):
            break
    except:
        print("", end="")


# if noOfRows.isalpha() == True or noOfRows == int(""):
#     noOfRows = int(input("Give me a number: "))


for i in range(1, noOfRows + 1):
    print(" " * (noOfRows - i) + "#" * i)


# counter = 0

# while True:
#     noOfRows = int(input("Give me a number: "))
#     counter = counter + 1
#     if noOfRows in range(1, 9):
#         continue
#     if noOfRows not in range(1, 9) and counter > 1:
#         break
