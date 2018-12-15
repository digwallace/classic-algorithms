// Pollard's Rho Algorithm

#include<cmath>
#include<cstdlib>
#include<iostream>

// Using Euclid's GCD Algorithm as a helper function.
unsigned long long gcd(unsigned long long num,unsigned long long div){

  while(div){
    unsigned long long temp = div;
    div = num % div;
    num = temp;
  }

  return num;
}

int main(int argc, char* argv[]){
    
  // Check usage.
  if(argc < 2){
    std::cout << "Usage: \n\t$ " << argv[0] << " <Integer> "
                 "[Flags]\n\n"
                 "\t -val=[starting_value]                      \n"
                 "\t\t There are times when this algorithm      \n"
                 "\t\t will fail to produce a nontrivial factor \n"
                 "\t\t even when n is composite. In such cases, \n"
                 "\t\t changing the default value (2), may fix  \n"
                 "\t\t this.    \n"
                 "\t -orig=true \n"
                 "\t\t Uses the original g(x) function: \n"
                 "\t\t\t g(x) = (x*x - 1) mod n         \n"
                 "\t\t Default g(x) function:           \n"
                 "\t\t\t g(x) = (x*x + 1) mod n       \n\n";
    return 1;
  }

  // TODO: Implement optional flags. For now, forced order.

  unsigned long long  n   = atoi(argv[1]);
  unsigned long long  x   = (argc >= 3) ? atoi(argv[2]) : 2;
  unsigned long long  y   = x;
  unsigned long long  d   = 1;
  char                opt = (argc >= 4) ? -1 : 1;  

  // Pollard's Rho Algorithm.
  while(d == 1){
    // g(x) = (x^2 +- 1) % n
    x = (x*x + opt) % n;
    // f(y) = g(g(y));
    y = ((y*y+opt)%n * (y*y+opt)%n + opt) % n;
    
    d = gcd(std::abs(x - y), n);
  }

  // Result.
  if(d == n){
    std::cout << "No prime factors.\n";
  }else{
    std::cout << "Factor is: " << d << std::endl;
  }

  return 0;
}
