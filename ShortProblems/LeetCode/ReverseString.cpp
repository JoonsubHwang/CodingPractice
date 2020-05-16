/*
    Recursion
    https://leetcode.com/explore/learn/card/recursion-i/250/principle-of-recursion/1440/
    
    
    Reverse char[] in-place
    
    Input: ["h","e","l","l","o"]
    Output: ["o","l","l","e","h"]
*/

void reverseString(vector<char>& s) 
{
    if (s.size() >= 2) // store the first and last char and remove from string
    {
        char front = s.front();
        char back = s.back();

        s.erase(s.begin());
        s.pop_back();

        if (s.size() >= 2) // if there are still more than 1 char left, reverseString(theRestOfString)
            reverseString(s);

        // after reversing all the chars inside,
        // insert the first and last char back in to the list but in reverse
            s.insert(s.begin(), back);
            s.push_back(front);
    }
}
