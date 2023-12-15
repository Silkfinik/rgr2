#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

void print(std::vector<int> vec){
    for(int i = 0 ; i < vec.size(); ++i){
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> vec;
    int n;
    std::cout<<"Input vec size:";
    std::cin >> n;
    for(int i = 0; i < n; ++i){
        int temp;
        std::cin >> temp;
        vec.push_back(temp);
    }
    std::cout << "Vector: ";
    print(vec);
    int sum = 0;
    for(int i = 0; i < n; ++i){
        sum += vec[i];
    }
    std::cout << "Sum: " << sum << std::endl;
    int counter= 0;
    int num;
    std::cout << "Input number: ";
    std::cin >> num;
    for (int i = 0; i < n; ++i){
        if (vec[i] == num) {
            counter++;
        }
    }
    std::cout << counter << std::endl;
    counter = 0;
    for (int i = 0; i < n; ++i){
        if(vec[i] > num){
            counter++;
        }
    }
    std::cout << counter << std::endl;
    double avg_sum = floor(double(sum) / double(vec.size()));
    for (int i = 0 ; i < n; ++i){
        if (vec[i] == 0){
            vec[i] = int(avg_sum);
        }
    }
    print(vec);
    int a, b;
    std::cout << "Input interval(index): ";
    std::cin >> a >> b;
    int temp_sum = 0;
    for (int i = a; i <= b; ++i){
        temp_sum += vec[i];
    }
    std::cout << "Interval sum: " << temp_sum << std::endl;
    for(int i = 0; i < n; i++){
        vec[i] += temp_sum;
    }
    print(vec);
    int min = *std::min_element(begin(vec), end(vec));
    int max = *std::max_element(begin(vec), end(vec));
    int def = max - min;
    for (int i = 0; i < n; ++i){
        if (abs(vec[i]) % 2 == 0){
            vec[i] = def;
        }
    }
    print(vec);
    for(int i = 0; i < vec.size(); ++i){
        for(int j = i + 1; j < vec.size(); ++j){
            if (abs(vec[i]) == abs(vec[j])){
                vec.erase(vec.begin() + j);
            }
        }
    }
    print(vec);
}