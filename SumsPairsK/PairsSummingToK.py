import json
import random
import sys


# TODO Add normal args
# TODO Add opts args
class PairsSumToK:

    def __init__(self, k):
        self.upper_limit = 1000
        self.lower_limit = 0
        self.size = 1000
        self.sum = int(k)
        self.count = 0
        self.random_dict = dict()
        self.validation_count = 0
        
        self.get_random_numbers()
        self.mappify()
        self.count_pairs_summing_to_k()
        self.validation()
        

    def get_random_numbers(self):
        self.random_list = random.sample(range(self.lower_limit, self.upper_limit), self.size)
        print(self.random_list)
        
    
    def mappify(self):
        for number in self.random_list:
            if number in self.random_dict:
                self.random_dict[number] += 1
            else:
                self.random_dict[number] = 1
                
        #print(json.dumps(self.random_dict, indent=2))
    
    
    def count_pairs_summing_to_k(self):
        for key, value in self.random_dict.items():
            remainder = self.sum - int(key)
            if remainder in self.random_dict and self.random_dict[remainder] > 0 and remainder >= self.lower_limit:
                self.random_dict[remainder] -= 1
                self.random_dict[key]       -= 1
                self.count += 1
            
        print(self.count)
    
    
    def validation(self):
        for number_one in self.random_list:
            for number_two in self.random_list:
                if int(number_one) + int(number_two) == self.sum:
                    self.validation_count += 1
        self.validation_count /= 2
        self.validation_count = int(self.validation_count)
    
    
def main():
    if len(sys.argv) > 1:
        k = sys.argv[1]
        print("Parameter detected!\n>> Using " + k + " as k!")
    else:
        k = 69
        print("No parameter for k given, using 69 as k!")
    solution = PairsSumToK(k)
    print("Number of pairs summing to " + str(k) + " is " + str(solution.count))
    
    
if __name__ == "__main__":
    main()