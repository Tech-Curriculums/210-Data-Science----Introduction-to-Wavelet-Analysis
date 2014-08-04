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
0. get current value of the head pointer, and remove from negative sum (by adding it's value)
1. get next-value, multiply by constant, and store new value at head
2. advance rightbrim pointer by 1, add + value to positive sum and + value to negative sum (removing it essentially) 
3. advance leftbrim pointer by 1, subtract (-) value from positive sum, and (-) value from negative sum
