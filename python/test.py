def palindrome(a):
        a = a.upper()
        return a == a[::-1]
name = input("Enter a name: ")
if palindrome(name):
        print("It's a palindrome name.")
else:
        print("It's not a palindrome name.")
