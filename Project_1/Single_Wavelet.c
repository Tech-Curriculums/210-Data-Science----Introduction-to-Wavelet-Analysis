efficient algorithm of harr wavelet

We basically need to just multiply by a constant, then subtract the two halves. 

I would actually like a hard-hat (a pun) wavelet so that we can try to visualize teh location better.

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

1. multiply input by constant, and store in pointer (a) henceforth called head
2. 
