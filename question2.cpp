#include <bits/stdc++.h>
using namespace std;
 
// Recursively removes adjacent duplicates from str and
// returns new string. last_removed is a pointer to
// last_removed character
char* removeUtil(char* str, char* last_removed)
{
 
    // If length of string is 1 or 0
    if (str[0] == '\0' || str[1] == '\0')
        return str;
 
    // Remove leftmost same characters and recur for
    // remaining string
    if (str[0] == str[1]) {
        *last_removed = str[0];
        while (str[1] && str[0] == str[1])
            str++;
        str++;
        return removeUtil(str, last_removed);
    }
    char* rem_str = removeUtil(str + 1, last_removed);
 
    // Check if the first character of the rem_string
    // matches with the first character of the original
    // string
    if (rem_str[0] && rem_str[0] == str[0]) {
        *last_removed = str[0];
 
        // Remove first character
        return (rem_str + 1);
    }
 
    // If remaining string becomes empty and last removed
    // character is same as first character of original
    // string. This is needed for a string like "acbbcddc"
    if (rem_str[0] == '\0' && *last_removed == str[0])
        return rem_str;
 
    // If the two first characters of str and rem_str don't
    // match, append first character of str before the first
    // character of rem_str.
    rem_str--;
    rem_str[0] = str[0];
    return rem_str;
}
 char* remove(char* str)
{
    char last_removed = '\0';
    return removeUtil(str, &last_removed);
}
 
// Driver program to test above functions
int main()
{
    char str1[] = "careermonk";
    cout << remove(str1) << endl;
    char str2[] ="Mississippi" ;
    cout << remove(str2) << endl;
 
    return 0;
}