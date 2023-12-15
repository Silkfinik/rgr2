#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

struct Student {
    std::string name;
    int course;
    int group;
};

void read(std::vector<Student>& vec){
    std::string str;
    std::ifstream in;
    in.open("C:\\Users\\silkfinik\\CLionProjects\\rgr2\\Students.txt");
    if (in.is_open()){
        while (std::getline(in, str)){
            Student temp;
            std::string temp_str;
            int counter = 1;
            for (int i = 0; i < str.size(); ++i) {
                if (str[i] != ';') {
                    temp_str += str[i];
                }
                else if (str[i] == ';') {
                    if (!temp_str.empty()) {
                        if(counter == 1){
                            counter++;
                            temp.name = temp_str;
                            temp_str = "";
                        }
                        else if(counter == 2){
                            counter++;
                            temp.course = std::stoi(temp_str);
                            temp_str = "";
                        }
                    }
                }
            }
            temp.group = std::stoi(temp_str);
            if(!(temp.name.empty()))
            vec.push_back(temp);
        }
    }
    in.close();
}

bool compareByName(const Student &a, const Student &b) {
    return a.name > b.name;
}

bool compareByCourseGroupName(const Student &a, const Student &b) {
    if (a.course != b.course) {
        return a.course < b.course;
    } else if (a.group != b.group) {
        return a.group < b.group;
    } else {
        return a.name > b.name;
    }
}

void print_first(std::vector<Student> vec){
    std::sort(vec.begin(), vec.end(), compareByName);
    std::ofstream out;
    out.open("C:\\Users\\silkfinik\\CLionProjects\\rgr2\\Fio.txt");
    if(out.is_open()){
        for(int i = 0; i < vec.size(); ++i){
            std::string temp_str;
            temp_str += vec[i].name + ";" + std::to_string(vec[i].course) + ";" + std::to_string(vec[i].group) + ";";
            out << temp_str << std::endl;
        }
    }
    out.close();
}

void print_second(std::vector<Student> vec){
    std::sort(vec.begin(), vec.end(), compareByCourseGroupName);
    std::ofstream out;
    out.open("C:\\Users\\silkfinik\\CLionProjects\\rgr2\\Groups.txt");
    if(out.is_open()){
        for(int i = 0; i < vec.size(); ++i){
            std::string temp_str;
            temp_str += vec[i].name + ";" + std::to_string(vec[i].course) + ";" + std::to_string(vec[i].group) + ";";
            out << temp_str << std::endl;
        }
    }
    out.close();
}

int main(){
    std::vector<Student> list;
    read(list);
    print_first(list);
    print_second(list);
}