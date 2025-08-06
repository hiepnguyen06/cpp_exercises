#include <iostream>
#include <algorithm>

using namespace std;

// Using reverse() in algorithm
#if 0
int main() {
    string str1, str2; 
    cout << "Enter line 1: "; getline(cin >> ws, str1); 
    cout << "Enter line 2: "; getline(cin >> ws, str2); 
    
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());
    cout << str1 <<endl; 
    cout << str2 << endl;

    return 0;
}
#endif

// Manual reverse using swap
#if 0
int main() {
    string str1; 
    cout << "Enter line 1: "; getline(cin >> ws, str1); 
    
    int left = 0;
    int right = str1.length() - 1;

    while (left < right) {
        std::swap(str1[left], str1[right]);
        left++;
        right--;
    }
     
    cout << str1 <<endl; 
    // cout << str2 << endl;

    return 0;
}
#endif

// Part b: Convert char to lower/upper 
#if 1
int main() {
    string str; cout << "Enter line: "; getline(cin >> ws, str);
    for (int i = 0; i < str.length() - 1; i++) {
        if (isalpha(str[i])) {
            str[i] = (isupper(str[i])) ? tolower(str[i]) : toupper(str[i]);
        }
    }
    cout << str << endl;
    return 0;
}
#endif