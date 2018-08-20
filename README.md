# AIIT-Assignment
AIIT Assignment: See /Solution Items/assignment.pdf for the problem.

<h3>Assignment</h3>
Problem Statement:<br>
Create a matrix of size 1024 * 1024 filled with all random INTEGER values. Write a C++ code using multithreading to calculate the average of the values in the neighbourhood of N (radius) and
assign it to the corresponding position in result matrix.<br>
Note: N can take values from 1 to 5.<br>
E.g.: Consider a 5x 5 Matrix P(x, y) as shown below. In this example we are going to calculate average around position (2,2) in P matrix and write the result in Q matrix at location (2,2). Now to compute
an average at position P(2, 2) with radius N=1, you need to consider its neighbourhood as shown below and put the result after rounding up in an output matrix Q(2, 2).
<br>
Q(2, 2) = CEIL( (P(1,1) + P(1,2) + P(1,3) + P(2,1) + P(2,2) + P(2,3) + P(3,1) + P(3,2) + P(3,3) ) / 9)
<br>
Q(2, 2) = CEIL ( (3+5+0+5+8+7+2+2+3) /9 ) = 4
<br>
p(x,y) =
<br>
Q(x, y) =
<br>
Similarly, all the other elements of Q(x, y) are to be computed. For a cases like P(0,0), P(0,1), P(1,0), P(4,4) etc where there are no neighbouring elemnts on some
sides, the unavilable elements are assumed to be zero. 
<br>
Therefore, Q(0,0) = CEIL( (0+0+0+0+1+4+0+6+3)/9) = CEIL(1.5) = 2
<br>
Use 4 threads to compute Q(x,y).Expected Solution:
<br>
Your solution should contain:
<ol>
<li>Approach/Pseudo code.</li>
<li>Generic C++ code which works for diffrent values of N ranging from 1 to 5.</li>
<li>Performance comparison when running single threaded application vs mutithreaded application.</li>
<li>Code should be compliable.</li>
</ol>

<h3>My Approach to solve the problem:</h3>
1.	Develop Logic for getting average for each element and its neighbor’s in the array:
<br>
avgNeighbor (x,y,radius):<br>
For index (x,y):<br>
Calculating subarray indexes, no. of elements using radius:<br>
Count= 2 * radius +1<br>
MAX_SIZE :size of array <br>
Subarray index: x-radius, y-radius<br>
Size: x+radius, y+radius<br>
So,<br>
	Let sum=0<br>
	for i= x-radius to x+radius && i<MAX_SIZE  <br>
		for j=y-radius to y+radius && j<MAX_SIZE <br>
			if i>=0&&j>= 0			<br>
sum+=arr[i][j]<br>
			avg = sum/count<br>
<br>
2.	Logic for solving problem using main thread:
<br>
For I = 0 to i< MAX_SIZE<br>
	For j = 0 to j< MAX_SIZE<br>
	  avgNeighbor(I,j,radius):
<br>
3.	Logic using multithreading
<br>
For threadCount=4
<br>
Divide 2nd logic into 4 part programmatically.


