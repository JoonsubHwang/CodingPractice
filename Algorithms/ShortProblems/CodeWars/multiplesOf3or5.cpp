/*
    returns the sum of every multiples of 3 or 5 that are in the range of 1 to 'number'
*/

int solution(int number) 
{
  int sum = 0;
  
  int multiplier = 1, multiple;
  bool inRange;
  
  
  // add multiples of 5
  do 
  {
    multiple = 5 * multiplier++;
    inRange = multiple < number;
    
    if (inRange)
      sum += multiple;
  } 
  while (inRange);
  
  
  // add multiples of 3
  multiplier = 1;
  do 
  {
    multiple = 3 * multiplier++;
    inRange = multiple < number;
    
    if (inRange && ((multiple % 5) != 0)) // exclude multiples of 5
      sum += multiple;
  } 
  while (inRange);
  
  return sum;
}
