// Sieve of Eratosthenes
// 
//  To compile using g++:
//      $ g++ <This_File> -o <Output> -std=c++11 -pthread

#include<chrono>
#include<cstdlib>
#include<iomanip>
#include<iostream>
#include<string>
#include<thread>
#include<vector>

bool go;
void calculating();

int main(int argc, char* argv[]){

  // Usage check.
  if(argc < 2){
    std::cout << "Usage: \n\t$ " << argv[0] << " <Prime_Limit> "
                 "[Print_Columns]\n\n"
                 "\t<Prime_Limit>\tRange to calculate.\n"
                 "\t[Print_Columns]\tSpecifies the number "
                 "of primes printed per row.\n\n";
    return 1;
  }

  int n     = atoi(argv[1]);    
  int len   = std::to_string(n).length();
  int col   = (argc >= 3) ? atoi(argv[2]) : 10;
  int count = 0;

  // Build vector of values to determine.
  std::vector<bool> primes;
  for(int i = 1; i <= n; i++){
    primes.push_back(true);
  }

  go = true;
  std::thread thread (calculating);

  // Sieve of Eratosthenes algorithm.
  for(int i = 2; i < n; i++){
    for(int j = i + 1; j <= n; j++){
      if(j % i == 0){
        primes.at(j-1) = false;
      }
    }
  }

  go = false;
  thread.join();  

  // Print all primes.
  std::cout << "List of primes:\n";
  for(int i = 0; i < primes.size(); i++){
    if(primes.at(i) == true){
      std::cout << std::setfill(' ') << std::setw(len);
      std::cout << i + 1 << " ";
      count = (count + 1) % col;
      if(count == 0){
        std::cout << std::endl;
      }
    }
  }

  std::cout << std::endl;

  return 0;
}

// Used by thread to print a running animation to let the user know 
// the program hasn't crashed when calculating large quantities of 
// primes.
void calculating(){
    
  int k = 0;
  int c = 0;

  while(go == true){
    
    k = (k+1) % 4;
    
    switch(k){
      case 0:
        c = 0x5c;
        break;
      case 1:
        c = 0x7c;
        break;
      case 2:
        c = 0x2f;
        break;
      case 3:
        c = 0x2d;
        break;
    }

    std::cout << "Calculating... " << (char)c << " \r";
    std::cout.flush();
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
  }

}
