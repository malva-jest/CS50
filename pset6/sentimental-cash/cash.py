# TODO

# and change.isalpha() == True

from cs50 import get_float

# get input from user as positive
while True:
    try:
        input = get_float("Change Owed: ")
        if input > 0:
            break
    except:
        print("", end="")

# declare number of coins variable
coins = 0

# make change act like an int so it's more precise
change = input * 100

# count 25c coins
while change >= 25:
    change = change - 25
    coins = coins + 1

# count 10c coins
while change >= 10:
    change = change - 10
    coins = coins + 1

# count 5c coins
while change >= 5:
    change = change - 5
    coins = coins + 1

# count 1c coins
while change >= 1:
    change = change - 1
    coins = coins + 1

print(coins)

# change = float(input("Change owed: "))

# coin_counter = 0

# while (change <= 0.00):
#     while (change >= 0.25):
#         coin_counter += 1
#         change -= 0.25

#     while (change >= 0.10):
#         coin_counter += 1
#         change -= 0.10

#     while (change >= 0.05):
#         coin_counter += 1
#         change -= 0.05

#     while (change >= 0.01):
#         coin_counter += 1
#         change -= 0.01

# print(coin_counter)


# amount = float(input("Change owed: "))


# def checkCoins(amount):
#     coins = [0.25, 0.10, 0.05, 0.01]
#     coin_counter = 0
#     for coin in coins:
#         if amount >= coin:
#             amount -= coin
#             coin_counter += 1
#     return coin_counter
# print(checkCoins(amount))

# if __name__ == "__main__":
#     main()