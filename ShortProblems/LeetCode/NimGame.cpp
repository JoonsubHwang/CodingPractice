/*
    Two players take turns to remove 1 to 3 stones. 
    The one who removes the last stone wins. 
    You start first.
    
    Given the number of stones, determine if you can win the game or not.
*/

bool canWinNim(int n) 
{
  return n%4;
}

// found the pattern by drawing diagrams
// which means this was not the best way to solve the problem
