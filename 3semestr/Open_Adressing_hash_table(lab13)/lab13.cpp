#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void HashFunc(std::string str, std::vector<std::string>& table) {
    int sum = 0;
    for (int i = 0; i < str.size(); i++) {
        sum += (char)str[i];
    }
    int j = sum % table.size();
    if (table[j] == "") {
        table[j] = str;
    }
    else {
        while (table[j] != "") {
            j++;
        }
        table[j] = str;
    }
}

int main()
{
    std::ifstream file("file.txt", std::ios::app);
    std::string temp;
    std::vector <std::string> splited_text;
    if (file.is_open()) 
    {

        while (!file.eof()) 
        {
            file >> temp;
            splited_text.push_back(temp);
        }
    }
    int n = splited_text.size();

    std::vector <std::string> table(2*n);

    for (int i = 0; i < splited_text.size(); i++) {
        HashFunc(splited_text[i], table);
    }

    file.close();

    std::ofstream out;
    out.open("table.txt");

    if (out.is_open()) {
        for (int i = 0; i < table.size(); ++i) {
            out << i << ": " << table[i] << "\n";
        }
    }
    out.close();
}
