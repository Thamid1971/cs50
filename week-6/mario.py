while True:
    try:
        size = int(input("Height: "))
        if 1 <= size <= 8:
            break
    except ValueError:
        pass

for i in range(1, size + 1):

    for j in range(size - i):
        print(" ", end="")

    for h in range(i):
        print("#", end="")

    print()