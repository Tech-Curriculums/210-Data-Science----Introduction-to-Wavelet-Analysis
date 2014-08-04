efficient algorithm of harr wavelet

We basically need to just multiply by a constant, then subtract the two halves. 

I would actually like a hard-hat (a pun) wavelet so that we can try to visualize the location better.

1. multiply signal by a constant. 


Data structure:

keep a circular array with three pointers.

a. first pointer is to shift in new data and pop oldest
b. second pointer is at boundary of left side hat and brim
c. third pointer is brim and right side

we will need two running doubles:

positive sum -- a running sum of positive numbers
negative sum -- a running sum of the negative numbers

Algorithm:

NOTE: all numbers are kept positive always, we subtract from negative sum, and add to positive sum

-1. advance head pointer by 1
0. get current value of the head pointer, and (+) to negative sum (essentially removing it)
1. get next-value, ~~multiply by a constant here if not harr or hard-hat wavelet~~ and store new value at head
2. advance rightbrim pointer by 1, add + value to positive sum and + value to negative sum (removing it essentially) 
3. advance leftbrim pointer by 1, subtract (-) value from positive sum, and (-) value from negative sum


4. add (+) positive and negative sums, and then divide by the length of the array, and store this into a value at the center point of the results array.
 
operations are clearly 3 pointer movements, 1 overwrite, 6 arithmetic for running sums, 1 big arithmetic for combining sums, 1 division, and 1 array storage, and 1 pointer movement from array storage.




