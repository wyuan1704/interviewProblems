  int vertexBsearch(const int A[], int s, int e)
  {
	  if(s == e-1)
		  return A[s] > A[e]? s:e;
	  int mid = (s+e)/2;

	  if(A[mid] > A[mid-1])
	  {
		  if(A[mid] > A[mid+1])
		  {
			  // Case 1: convex point. Vertex
			  return mid;
		  }
		  else
		  {
			  // case 2: Increase
			  return vertexBsearch(A, mid+1, e);
		  }
	  }
	  else
	  {
		  if(A[mid] < A[mid+1])
		  {
			  // Case 3: concave point.
			  return vertexBsearch(A, mid+1, e); // or vertexBsearch(A, s, mid-1);
		  }
		  else
		  {
			  // case 4: Decrease
			  return vertexBsearch(A, s, mid-1);
		  }
	  }
  }
  // Given n different positive integers. Find the index of an arbitrary vertex, whose value is greater than its precedent and successor. Assuming two zeros stand at two ends as sentinels. 
  int findArbitraryVertex(int A[], int n)
  {
	  if(n < 1)
		  return -1;
	  if(n == 1)
		  return 0;
	  if(A[0] > A[1]) // A[0] is  greater than the sentinel ZERO.
		  return 0;
	  if(A[n-1] > A[n-2]) // This improves the performance a lot and makes vertexBsearch easier.
		  return n-1;
	  // Only about 1/4 cases can reach here.
	  // Increase from 0 and decrease to n-1. A vertex must exist in between.
	  return vertexBsearch(A, 0, n-1);
  }
  