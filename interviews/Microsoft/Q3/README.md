I've got an array of integer numbers (positive and negative) representing points in space, the distance between two points is defined as abs(A[i]-A[j]) and I need to check that that distance is divisible by a given integer M.

So this is the situation :

Array : [-3 -2 1 0 8 7 1]

M = 3

abs(A[1]-A[2]) = 3 (for example and it's divisible by the integer)

The complexity should be O(N+M) and the space O(M)

