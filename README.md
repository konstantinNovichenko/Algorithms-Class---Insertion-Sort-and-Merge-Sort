# Testing Algorithms - *Insertion Sort & Merge Sort*

This program was written for **CSC 382 Algorithms** class at **College of Staten Island (CUNY)**

Created by: **Konstantin Novichenko**

Time spent: **2** hours spent in total

## Overview

The program implements *Insertion Sort* and *Merge Sort Algorithms* and checks their efficiency for arrays of size **N = 100, 200, 300, 400, 500, 1000, 4000, 10000**
for the following test cases:
* Sorted Array
* Reversed Array
* Random Permunation of 1 to N Array
* 50 Random Instances of 1 to N (calculates average)

Efficiency is measured by execution time and the number of steps it took to sort the array
User see the results of the sorting in a table format

## Sample Output

Table with results

<img src='./Images/Sample Output.PNG' title='Sample Output' width='' alt='Sample Output' />


## Graphs

* Sorted Array - Execution Time
<img src='./Images/Sorted Array - Execution Time.PNG' title='Sample Output' width='' alt='Sample Output' />

* Sorted Array - Steps
<img src='./Images/Sorted Array - Steps.PNG' title='Sample Output' width='' alt='Sample Output' />

* Reversed Array - Execution Time
<img src='./Images/Reversed Array - Execution Time.PNG' title='Sample Output' width='' alt='Sample Output' />

* Reversed Array - Steps
<img src='./Images/Reversed Array - Steps.PNG' title='Sample Output' width='' alt='Sample Output' />

* Random Permutation Array - Execution Time
<img src='./Images/Random Permutation Array - Execution Time.PNG' title='Sample Output' width='' alt='Sample Output' />

* Random Permutation Array - Steps
<img src='./Images/Random Permutation Array - Steps.PNG' title='Sample Output' width='' alt='Sample Output' />

* Average of 50 Instances of Random Numbers - Execution Time
<img src='./Images/Average of 50 Instances of Random Numbers - Execution Time.PNG' title='Sample Output' width='' alt='Sample Output' />

* Average of 50 Instances of Random Numbers - Steps
<img src='./Images/Average of 50 Instances of Random Numbers - Steps.PNG' title='Sample Output' width='' alt='Sample Output' />

## Graphical Analysis of Data Sets
Uses Vernier Graphical Analysis to fit the curve and to find the approximate value of constant **C**. 

The *Insertion Sort* curve fit uses the equation: 
**C(x^2)**, where **x** represents **N** and **C** is a constant.

* Curve Fit for Insertion Sort Data Set
<img src='./Images/Insertion Sort Curve Fit Graphical Analysis.PNG' title='Sample Output' width='' alt='Sample Output' />

The *Merge Sort* curve fit uses the equation: 
**C(x(log(x)))**, where **x** represents **N** and **C** is a constant.

* Curve Fit for Merge Sort Data Set
<img src='./Images/Merge Sort Curve Fit Graphical Analysis.PNG' title='Sample Output' width='' alt='Sample Output' />

* Data Set

<img src='./Images/Data Set for Graphical Analysis.PNG' title='Sample Output' width='' alt='Sample Output' />

## Author

2020, Konstantin Novichenko
