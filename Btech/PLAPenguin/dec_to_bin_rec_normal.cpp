// C++ Program for the binary 
// representation of a given number 
#include<bits/stdc++.h> 
using namespace std; 

void bin(unsigned n) 
{ 
	/* step 1 */
	if (n > 1) 
		bin(n/2); 

	/* step 2 */
	cout << n % 2; 
} 

int main(void) 
{ 
	bin(7); 
	cout << endl; 
	bin(4); 
} 

// This code is contributed 
// by Akanksha Rai 

