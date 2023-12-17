#include <bits/stdc++.h>

class Train{
private:
    unsigned number;
    std::string destination;
    std::string type;
    std::string departure_time;
    unsigned travel_time;
public:
    Train(unsigned value1, const std::string& value2, const std::string& value3, const std::string& value4, unsigned value5)
    :number(value1), destination(value2), type(value3), departure_time(value4), travel_time(value5)
    {
    }
    Train(){
        number = 0;
        destination = "";
        type = "";
        departure_time = "";
        travel_time = 0;
    }
    void set_number(int n){
        number = n;
    }
    void set_name(const std::string& str){
        destination = str;
    }
    void set_type(const std::string& str){
        type = str;
    }
    void set_dep_time(const std::string& str){
        departure_time = str;
    }
    void set_travel_time(int n){
        travel_time = n;
    }
    unsigned get_num() const{
        return number;
    }
    std::string get_name() const{
        return destination;
    }
    std::string get_type() const{
        return type;
    }
    std::string get_dep_time() const{
        return departure_time;
    }
    unsigned get_tr_time() const{
        return travel_time;
    }
};

void read(std::vector<Train>& vec) {
    std::string str;
    std::ifstream in;
    Train temp;
    in.open("C:\\Users\\silkfinik\\CLionProjects\\rgr2\\Input.txt");
    if (in.is_open()){
        while (std::getline(in, str)){
            temp.set_number(std::stoi(str.substr(0, str.find(' '))));
            str = str.substr(str.find(' ') + 1);
            temp.set_name(str.substr(0, str.find(' ')));
            str = str.substr(str.find(' ') + 1);
            temp.set_type(str.substr(0, str.find(' ')));
            str = str.substr(str.find(' ') + 1);
            temp.set_dep_time(str.substr(0, str.find(' ')));
            temp.set_travel_time(std::stoi(str.substr(str.rfind(' '))));
            vec.push_back(temp);
        }
    }
    in.close();
}

bool comp_by_dep_time(const Train& a, const Train& b){
    return a.get_dep_time() < b.get_dep_time();
}

bool comp_by_tr_time(const Train& a, const Train& b){
    return a.get_tr_time() < b.get_tr_time();
}

void print_train(const Train& train){
    std::cout << train.get_num() << " " << train.get_name() << " " << train.get_type() << " "
    << train.get_dep_time() << " " << train.get_tr_time() << " " << std::endl;
}

void print_by_time(const std::vector<Train>& vec, const std::string& first, const std::string& second){
    for(const auto & i : vec){
        if(i.get_dep_time()  >= first && i.get_dep_time() <= second){
            print_train(i);
        }
    }
    std::cout << std::endl;
}

void print_by_name(const std::vector<Train>& vec, const std::string& str){
    for(const auto & i : vec){
        if(i.get_name() == str){
            print_train(i);
        }
    }
    std::cout << std::endl;
}

void print_by_name_express(const std::vector<Train>& vec, const std::string& str){
    for(const auto & i : vec){
        if(i.get_name() == str && i.get_type() == "express"){
            print_train(i);
        }
    }
    std::cout << std::endl;
}

void print_by_name_fastest(std::vector<Train> vec, const std::string& str){
    std::sort(vec.begin(), vec.end(), comp_by_tr_time);
    for(auto & i : vec){
        if(i.get_name() == str){
            print_train(i);
            std::cout << std::endl;
            return;
        }
    }
}

int main(){
    std::vector<Train> vec;
    read(vec);
    std::sort(vec.begin(), vec.end(), comp_by_dep_time);
    std::string first, second;
    std::cout << "Input time range(HH:MM):" << std::endl;
    std::cin >> first >> second;
    std::cout << "All trains from a given time range:" << std::endl;
    print_by_time(vec, first, second);
    std::string destination;
    std::cout << "Input destination:" << std::endl;
    std::cin >> destination;
    std::cout << "All trains arriving at destination:" << std::endl;
    print_by_name(vec, destination);
    std::cout << "All express trains arriving at destination:" << std::endl;
    print_by_name_express(vec, destination);
    std::cout << "Fastest train arriving at destination:" << std::endl;
    print_by_name_fastest(vec, destination);
}