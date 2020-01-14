https://www.hackerrank.com/challenges/operator-overloading/problem

Classes define new types in C++. Types in C++ not only interact by means of constructions and assignments but also via operators. For example:
int a=2, b=1, c;
c = b + a;
The result of variable c will be 3. 
Similarly, classes can also perform operations using operator overloading. Operators are overloaded by means of operator functions, which are regular functions with special names. Their name begins with the operator keyword followed by the operator sign that is overloaded. The syntax is:
type operator sign (parameters) { /*... body ...*/ }
You are given a main() function which takes a set of inputs to create two matrices and prints the result of their addition. You need to write the class Matrix which has a member a of type vector<vector<int> >. You also need to write a member function to overload the operator +. The function's job will be to add two objects of Matrix type and return the resultant Matrix.
Input Format
First line will contain the number of test cases . For each test case, there are three lines of input.
The first line of each test case will contain two integers  and  which denote the number of the rows and columns respectively of the two matrices that will follow on the next two lines. These next two lines will each contain elements describing the two matrices in row-wise format i.e. first  elements belong to the first row,next  elements belong to the second row and so on.
Constraints 
 
 
 
 , where  is the element in the  row and  column of the matrix.
Output Format
The code provided in the editor will use your class  and overloaded operator function to add the two matrices and give the output.
Sample Input
1
2 2
2 2 2 2
1 2 3 4
Sample Output
3 4 
5 6
Explanation
The sum of first matrix and the second matrix is the matrix given in the output.
