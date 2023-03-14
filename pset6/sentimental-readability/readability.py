# TODO

text = input("Text: ")

# text_list = [text]


def addOneSpaceCount(text_amount):
    space_count = 0
    for i in text_amount:
        if i == " ":
            space_count += 1
    return (space_count) + 1


words = addOneSpaceCount(text)


def countSentences(text_amount):
    sentence_count = 0
    for i in text_amount:
        if i == "." or i == "!" or i == "?":
            sentence_count += 1
    return sentence_count


sentences = countSentences(text)


def letterCount(text_amount):
    letter_count = 0
    # newstring1 =""
    for i in text_amount:
        if (i.isalpha()) == True:
            letter_count += 1
            # newstring1 += i
    # return newstring1
    return letter_count


letters = letterCount(text)

L = (letters / float(words)) * 100
S = (sentences / float(words)) * 100

cl_index = round(0.0588 * L - 0.296 * S - 15.8)

if cl_index < 1:
    print("Before Grade 1")
    # print("we here", cl_index)
elif cl_index >= 16:
    print("Grade 16+")
    print(cl_index)
else:
    print("Grade", cl_index)
    print(cl_index)


print("Words:", words)
print("Sentences:", sentences)
print("Letters:", letters)


# from cs50 import get_float

# # get input from user as positive
# while True:
#     try:
#         input = get_float("Change Owed: ")
#         if input > 0:
#             break
#     except:
#         print("", end="")

# # declare number of coins variable
# coins = 0


# def checkLetters(text):
#     for i in len(text):
#         if

#     return letters


# if __name__=="__main__":
#     main()