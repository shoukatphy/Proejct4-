# Proejct4
## Introduction
This project incudes two programs. The first **``generateData.C``** simulates the data by generating random numbers for the gaussain distribution. The another part **``NeuMass.C``** is used to analyze the data. It plots the distribution and makes a fit using a kernel density estimation class [TKDE](https://root.cern/doc/master/classTKDE.html) and estimate the unknown paramter by taking the maximization of the likelihood function. 
## How to Run the Programs?
These program can be run in [root](https://root.cern/) macros. An integer (equal to the number of the events) needs to be passed as argument of the function of both **``generateData.C``** and 
 **``NeuMass.C``** . In simple, open the root terminal ...root[0] and type  **``.x generateData.C (Int)``** and do the samething with the other program. **``NeuMass.C``** will print out the estimated values of the paramter. 
## Notes
As the data follows the gaussian distribution and the maximization of this function will return the mean values for the unkown parameter. Therefore, I have calculated the mean value of the fit instead of applying a minimizer. 

