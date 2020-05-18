/*
    algorithm
    
    
    replace each leeter with the letter 13 letters behind it
*/

#include <string>

using namespace std;


string rot13(string msg)
{
  string alphas = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
  
  for (char &c : msg)
    for (int i = 0; i < 52; ++i) 
      if (c == alphas[i])
      {
        int shifted = islower(c) ? (i+13) % 26 : ((i+13) % 26) + 26; // upper letters stay upper
        c = alphas[shifted];
        break; // prevents ciphering a 'c' more than once when (shifted > i)
      }
    
  return msg;
}


/*
    better way
    
    string rot13(string msg)
    {
      for(char &x : msg) 
      {
        if (islower(x)) 
          x = 'a' + (((x-'a') + 13) % 26); 
        else if(isupper(x)) 
          x = 'A' + (((x-'A') + 13) % 26);
      }
      return msg;
    }
*/
