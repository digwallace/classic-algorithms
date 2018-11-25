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
                     "\t-val=[starting_value]\n"
                     "\t\tThere are times when this algorithm\n"
                     "\t\twill fail to produce a nontrivial factor\n"
                     "\t\teven when n is composite. In such cases,\n"
                     "\t\tchanging the default value (2), may fix\n"
                     "\t\t this.\n"
                     "\t-orig=true\n"
                     "\t\tUses the original g(x) function:\n"
                     "\t\t\tg(x) = (x*x - 1) mod n\n"
                     "\t\tDefault g(x) function:\n"
                     "\t\t\tg(x) = (x*x + 1) mod n\n\n";
        return 1;
    }

    // TODO: Implement optional flags. For now, forced order.

    int  n   = atoi(argv[1]);
    int  x   = (argc >= 3) ? atoi(argv[2]) : 2;
    int  y   = x;
    int  d   = 1;
    bool opt = (argc >= 4) ? true : false;  

    // Pollard's Rho Algorithm.
    while(d == 1){
        x = opt ? (x*x - 1) % n : (x*x + 1) % n;
        y = opt ? ( ((y*y-1)%n) * ((y*y-1)%n) - 1) % n :
                  ( ((y*y+1)%n) * ((y*y+1)%n) + 1) % n ;
        d = gcd(std::abs(x - y), n);
    }
    if(d == n){
        std::cout << "No prime factors.\n";
    }else{
        std::cout << "Factor is: " << d << std::endl;
    }

    return 0;
}
