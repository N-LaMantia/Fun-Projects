#String Fun
import string

str = "Hello, World!"
#Some String methods ------------------
print(str.upper())
print(str.lower())
print(str.swapcase())

strReversed = str[::-1]
print(strReversed)

#Separating Even and Odd numbers in an array ------------------
arr = [3, 4, 5, 6]
longerarr = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
def separatingEvenOdd(arr): 
    leftPtr, rightPtr = 0, len(arr) - 1
    while leftPtr < rightPtr: 
        if arr[leftPtr] % 2 == 0: 
            leftPtr += 1
        else: 
            arr[leftPtr], arr[rightPtr] = arr[rightPtr], arr[leftPtr]
            rightPtr -= 1

    return arr
print(separatingEvenOdd(arr))
print(separatingEvenOdd(longerarr))

#Palindrome Creation Move Counter ------------------
def palindromeMoveCounter(s):
    left, right = 0, len(s) - 1
    moves = 0
    while left < right:
        if s[left] != s[right]: 
            moves += 1
            s[left], s[right] = s[right], s[left]
        left += 1
        right -= 1
    return moves
print(palindromeMoveCounter(list("abcda")))
print(palindromeMoveCounter(list("abccbaabcbacbabca")))
