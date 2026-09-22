import csv
import sys


def main():

    if len(sys.argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")
        sys.exit(1)
        
        

    # TODO: Read database file into a variable
    with open(sys.argv[1]) as file:
        reader = csv.DictReader(file)



        count = {}



        for row in reader:
            for key in row:
                if key != "name":
                    
                    count[key] = 0

    # TODO: Read DNA sequence file into a variable
    with open(sys.argv[2]) as DNA:
        
        dna = DNA.read()

    # TODO: Find longest match of each STR in DNA sequence
    for keys in count:
        count[keys] = longest_match(dna, keys)

    # TODO: Check database for matching profiles
    with open(sys.argv[1]) as CANDIDATES:
        
        candidates = csv.DictReader(CANDIDATES)

        for row in candidates:

            match = True

            for key in count:
                if int(row[key]) != count[key]:
                    match = False
                    break

            if match:
                print(row["name"])
                
                return




    print("No match")


def longest_match(sequence, subsequence):

    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # Return longest run found
    return longest_run


main()