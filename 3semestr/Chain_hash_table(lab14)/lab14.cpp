
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void HashFunc(std::string str, std::vector<std::vector<std::string>>& table) {
    int sum = 0;

    for (int i = 0; i < str.size(); i++) {
        sum += (int)(char)str[i];
    }

    int j = sum % table.size();

    table[j].push_back(str);


}
int main()
{
    std::ifstream input("file.txt");
    std::string temp;
    std::vector <std::string> splited_text;

    if (input.is_open()) {

        while (!input.eof()) {
            input >> temp;
            splited_text.push_back(temp);
        }
    }
    int n = splited_text.size();

    std::vector <std::vector <std::string>> table(2 * n);

    for (int i = 0; i < splited_text.size(); i++) {
        HashFunc(splited_text[i], table);
    }

    input.close();

    std::ofstream output;
    output.open("output.txt");

    if (output.is_open()) {
        for (int i = 0; i < table.size(); i++) {
            output << i << ":";
            for (int j = 0; j < table[i].size(); j++) {
                output << table[i][j] << "\t";
            }
            output << "\n";
        }
    }
    output.close();
}

