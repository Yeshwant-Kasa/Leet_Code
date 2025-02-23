class Solution {
public:
    bool check_palindrome(int i, int j, string &s) {
        if(i>=j) 
            return true; //indices crossing palindrome met
        while (i<j && !isalnum(s[i])) i++; // skipping non-alpha from left
        while (i<j && !isalnum(s[j])) j--; // skipping non-alpha from right
        if(i>=j) 
            return true; //indices crossed after skipping
        if(tolower(s[i]) != tolower(s[j])) 
            return false; // checking character match (case sensitive)
        return check_palindrome(i+1,j-1,s);
       
    }
    bool isPalindrome(string s){ //bool return parameter must be called with other function
        return check_palindrome(0,s.size()-1,s); 
    } 
    
};

/*    Base Alg of Palindrome

 if(i>=s.size()/2);
            return true;
        if(s[i] == s[s.size()-i-1]){
            return true;
        }
        return check_palindrome(i+1, s);*/