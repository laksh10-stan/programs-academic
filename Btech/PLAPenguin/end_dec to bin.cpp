#include<bits/stdc++.h> 
using namespace std; 
  
// Function to convert decimal 
// to binary number 
void bin(unsigned n) 
{ 
    if (n > 1) 
    bin(n>>1); 
      
    printf("%d", n & 1); 
} 
  
// Driver code 
int main(void) 
{ 
    bin(131); 
    printf("\n"); 
    bin(3); 
    return 0; 
} 
