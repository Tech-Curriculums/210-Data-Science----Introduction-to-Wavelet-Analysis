Choose a mother wavelet,
Find the Fourier transform of the mother wavelet,
Find the Fourier transform of the time series,
Choose a minimum scale s0, and all other scales,
For each scale, do:
Using Eqn. 3.4 (or whatever is appropriate for your mother wavelet), compute the daughter wavelet at that scale;
Normalize the daughter wavelet by dividing by the square-root of the total wavelet variance (the total of (Psi)2 should then be one, thus preserving the variance of the time series);
Multiply by the FT of your time series;
Using Eqn. 3.2, inverse transform back to real space;
Make a contour plot.




## References:

http://paos.colorado.edu/research/wavelets/wavelet3.html
