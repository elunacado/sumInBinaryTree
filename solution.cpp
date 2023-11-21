#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1000000007;
#define deb(x) cerr << #x << " is " << x << endl;
#define IOS ios:: sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define all(a) a.begin(), a.end()
using namespace std;

int main() {
     IOS;
            #ifndef ONLINE_JUDGE
                freopen("input.txt", "r", stdin);
                freopen("solution.txt", "w", stdout);
            #endif

    string input_string; cin >> input_string;    

    std::vector<int> numbers;

    std::istringstream iss(input_string);
    std::string number_str;

    while (std::getline(iss, number_str, '+')) {
        int number = std::stoi(number_str);
        numbers.push_back(number);
    }

    std::sort(numbers.begin(), numbers.end());

    for (int i = 0; i < numbers.size(); i++) {
        std::cout << numbers[i];
        if (i < numbers.size() - 1) {
            std::cout << "+";
        }
    }
    std::cout << std::endl;

    return 0;
}
