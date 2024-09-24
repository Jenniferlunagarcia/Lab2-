//
//  main.cpp
//  "Hi" == "hi"? Lab 2
//
//  Created by Jennifer Luna 
//

#include <iostream>
#include <cctype>  // For tolower()

using namespace std;

// Function for case-insensitive string comparison
int strcmp_case_insensitive(const string& str1, const string& str2) {
    // Iterate through both strings
    for (size_t i = 0; i < str1.size() && i < str2.size(); ++i) {
        // Convert both characters to lowercase for comparison
        char ch1 = tolower(str1[i]);
        char ch2 = tolower(str2[i]);

        // If characters differ, return the difference
        if (ch1 != ch2) {
            return (ch1 < ch2) ? -1 : 1;
        }
    }

    // If the loop ends, the strings are either equal or one is a prefix of the other
    if (str1.size() == str2.size()) {
        return 0;  // Strings are equal
    } else {
        return (str1.size() < str2.size()) ? -1 : 1;
    }
}

// Driver function to test the strcmp_case_insensitive function
void test_strcmp_case_insensitive() {
    cout << "Test 1: \"Hello\" vs \"hello\" -> " << strcmp_case_insensitive("Hello", "hello") << endl;
    cout << "Test 2: \"world\" vs \"WORLD\" -> " << strcmp_case_insensitive("world", "WORLD") << endl;
    cout << "Test 3: \"apple\" vs \"apples\" -> " << strcmp_case_insensitive("apple", "apples") << endl;
    cout << "Test 4: \"Apple\" vs \"ApplE\" -> " << strcmp_case_insensitive("Apple", "ApplE") << endl;
    cout << "Test 5: \"Test\" vs \"testers\" -> " << strcmp_case_insensitive("Test", "testers") << endl;
    cout << "Test 6: \"test\" vs \"test\" -> " << strcmp_case_insensitive("test", "test") << endl;
    cout << "Test 7: \"Case\" vs \"cAseS\" -> " << strcmp_case_insensitive("Case", "cAseS") << endl;
    cout << "Test 8: Empty string \"\" vs \"\" -> " << strcmp_case_insensitive("", "") << endl;
    cout << "Test 9: Empty string \"\" vs \"NonEmpty\" -> " << strcmp_case_insensitive("", "NonEmpty") << endl;
    cout << "Test 10: \"NonEmpty\" vs Empty string \"\" -> " << strcmp_case_insensitive("NonEmpty", "") << endl;
}

int main() {
    test_strcmp_case_insensitive();
    return 0;
}
