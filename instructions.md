# Instructions
## Starting the Program
```cpp
start //write "start" to start program 
    yourCode //your code in between
end //write "end" to end program
```
## Key Instructions
```cpp
start
    Number x, y, z eL //all lines must end in eL
    in > x eL
    in > y eL
    z = pS x == y pE eL //pS (parenthese start) pE (parenthese end)
    out < z eL
    space // write space to add a space
end
```
## Initialization
```cpp
start 
    Number x, y eL //Number Initialization
    Word word1, word2 eL // Word Initialization
end
```
## Input/Output
```cpp
start
    Word word1 eL 
    in > word1 eL //Input 
    out < word1 eL//Output
end
```
## Assignment 
```cpp
start
    Word word1 eL   
    Number x eL
    word1 = "Hello" eL //Assignment of Word
    x = 5 eL //Assignment of Number
end
```
## Arithmetic Operations 
```cpp
start
    Number x, y , z eL 
    x = 5 eL
    y = 3 eL
    z = x + y eL// + operation 
    z = x - 5 eL// - operation 
    z = x / 5 eL// / operation 
    z = x * 5 eL// * operation 
    z = x * 5 eL// * operation 
    //Operations of Number and Char will result in char being converted to ASCII Value
    Word word1, word2, result eL
    word1= "hello" eL
    word2= "hello" eL
    result = word1 + word2 eL // + operation (concatenation) == hellohello
    result = word1 + 'a' eL // + operation (concatenation) == helloa
    result = word1 + "hello" eL // + operation (concatenation) == hellohello
    //All other operations on words will result in Error

end
```
## Logical Operations
```cpp
start 
    //using invalid flags will result in Error being printed plus 0 or error being assigned to respective variables
    Number a, b, c , flag1, flag2 eL
    Word word1, word2, result, flag3, flag4 eL
    a = 5 eL
    b = 5 eL
    flag1 = 0 eL
    flag2 = 0 eL

    word1 = "word1" eL
    word2 = "word2" eL
    flag3 = "false" eL
    flag4 = "false" eL

    //Operations of Number and Char will result in char being converted to ASCII Value
    //Number flags 1 = true | 0 = false
    c = a == b eL// == operation result = 1
    c = a != b eL // != operation result = 0
    c = a OREQUAL b eL //OREQUAL result = 0 and Error as flags must be booleans
    c = flag1 OREQUAL flag2 eL //OREQUAL result = 0
    c = flag1 ANDAND flag2 eL //ANDAND result = 0

    result = word1 == word2 //== operation result = "false"
    result = word1 != word2 //== operation result = "true"
    result = word1 OREQUAL word2 //OREQUAL operation result = "false"  Error as flags must be booleans
    result = flag3 OREQUAL flag4 //OREQUAL operation result = "false" 
    result = flag3 ANDAND flag4 //ANDAND operation result = "false" 
end
```