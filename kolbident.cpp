#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <map>

std::string nosuccessor = "No Successor";

long unsigned pow(unsigned short base, unsigned expo) {
    unsigned long res = 1;
    for (unsigned exprem = expo; exprem > 0; exprem--)
        res *= base;
    return res;
}

bool ok_occur(std::string input, std::map<char, short unsigned> &occurences) {
    for (std::pair<char, short unsigned> occur : occurences) {
        int count_current = 0;
        for (char current : input)
            if (current == occur.first) count_current++;
        if (count_current > occur.second) return false;
    }
    return true;
}

long unsigned value(std::string input, short unsigned base,
                    std::map<char, short unsigned> &digit_meanings) {
    std::vector<char> &
    std::string reversed(input);
    std::reverse(reversed.begin(), reversed.end());
    unsigned expo = 0;
    long unsigned int value = 0;
    for (char i : reversed) {
        value += pow(base, expo) * digit_meanings[i];
        expo++;
    }
    return value;
}

std::string reverse_writing(unsigned long value, unsigned long valueminus1
                            short unsigned base, std::vector<char> &digits) {
    return std::string(1, digits[value % base]) +
           ((value / base) || (valueminus1 / base)
            ? reverse_writing(value / base, valueminus1 / base, base, digits)
            : "");
}

std::string increment_reversed(std::string reversed, short unsigned base, std::vector<char> &digits,
                               std::map<char, short unsigned> &meanings) {
    for (char &i : reversed)
        if (meanings[i] == base - 1) i = digits[0];
        else {
            i = digits[meanings[i] + 1];
            break;
        }
}

std::string add_reversed(std::string reversed, short unsigned base, std::vector<char> &digits,
                         std::map<char, short unsigned> &meanings,
                         std::map<char, short unsigned> &occurences) {
    std::string result = increment_reversed(reversed, base, digits, meanings);
    return ok_occur(result, occurences)
           ? result
           : add_reversed(result, base, digits, meanings, occurences);
}

std::string worker(std::string input) {
    std::map<char, short unsigned> occurences;
    for (char i : input) occurences[i] = 0;
    for (char i : input) occurences[i]++;
    std::string check(input);
    std::sort(check.begin(),check.end());
    std::reverse(check.begin(),check.end());
    if(check==input) return nosuccessor;
    std::vector<char> digits;
    for (std::pair<char, short unsigned> occur : occurences)
        digits.push_back(occur.first);
    std::sort(digits.begin(), digits.end());
    short unsigned base = static_cast<unsigned short>(digits.size());
    std::map<char, short unsigned> digit_meanings;
    for (short unsigned i = 0; i < base; i++)
        digit_meanings[digits[i]] = i;
    //unsigned long value = value(input, base, digit_meanings);
    std::string reversed(input);
    std::reverse(reversed.begin(), reversed.end());
    std::string added = add_reversed(reversed, base, digits, digit_meanings, occurences);
}

int main() {
    //std::reverse(nosuccessor.begin(),nosuccessor.end());
    std::string input;
    while (std::cin >> input) {
        if (input == "#") return 0;
        std::cout << worker(input);
    }
    return 0;
}