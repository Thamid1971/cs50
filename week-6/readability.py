text = input("Text:")

words = 1
letters = 0
sentence = 0

for i in range(len(text)):
    char = text[i].upper()
    index = ord(char) - ord('A')

    if index >= 0 and index < 26:
        letters += 1
    elif char == ' ':
        words += 1
    elif char == '.' or char == '!' or char == '?':
        sentence += 1

L = (letters / words) * 100
S = (sentence / words) * 100

grade = round(0.0588 * L - 0.296 * S - 15.8)

if grade < 1:
    print("Before Grade 1")
elif grade >= 16:
    print("Grade 16+")
else:
    print(f"Grade {grade}")