/* A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise. 


Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.

Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.
*/


/*
 Few Key Points before jumping to solution

 isalnum() -> checks whether the given character is alphanumeric or not
 
 tolower()  -> converts a given character to lowercase 
 */

bool isPalindrome(string s) {
          int l=0,r=s.size()-1; // two variables to point to start and end of string
        
        while(l<r)
        {
            if(!isalnum(s[l])) // If not alphanumeric we move forward pointer
                l++;
            else if(!isalnum(s[r]))// If not alphanumeric we move backward pointer
                r--;
            else if(tolower(s[l])!=tolower(s[r])) // Make both characters lowercase for comparision and if no match then return false instantly
                return false;
            else // 
            {
                l++;
                r--;
            }
        }
        return true;
    }


