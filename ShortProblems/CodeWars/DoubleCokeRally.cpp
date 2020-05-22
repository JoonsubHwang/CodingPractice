/*
    math, algorithm
    https://www.codewars.com/kata/551dd1f424b7a4cdae0001f0/cpp

    People drink cans of coke in a queue. After they drink, they go back to the end of the queue. The number of cans they drink start from
    one, and it doubles each time one drinks.
    intput: string vector containing names, long long representing number of cans
    output: the name of a person who drinks the last can of coke

    This is a bad solution. :(
*/

#include <string>
#include <vector>

std::string who_is_next(const std::vector<std::string>& names, long long cokeLeft) 
{
  std::vector<int> numCoke;
  for (int i = 0; i < names.size(); ++i)
    numCoke.push_back(1); // everyone starts with 1 coke per turn
  
  int person = 0;
  while (cokeLeft > 0)  
  {
    cokeLeft -= numCoke[person]; // drink cokes
    numCoke[person] *= 2; // double numCoke the person has to drink next time
    
    if (cokeLeft > 0) // drink cokes; if coke is left, go to next person (otherwise, return this person;)
      if (++person == names.size()) // 1st person drinks after the last one
        person = 0;
  }
  
  return names[person];
}

/*
    GOOD SOLUTIONS
    
    
1.  std::string who_is_next(std::vector<std::string> names, long long r) 
    {
      int numPeople = names.size();
      long long step = 1;
      while((r / step) > numPeople){
          r -= numPeople * step;
          step *= 2;
      }
      return names[(r - 1) / step];
    }


2.  std::string who_is_next(const std::vector<std::string>& names, const long long& r) 
    {
      if(r > names.size())
        return who_is_next(names, (r - 1 - names.size()) / 2 + 1);

      return names[r - 1];
    }
    
    
  3.  std::string who_is_next(std::vector<std::string> names, long long r) 
    {
      int numPeople = names.size();
      
      while (r > numPeople)
        r = (r - (numPeople - 1)) / 2; // same as r = ceil((r - numPeople) / 2.0);

      return names[r-1];
    }
*/
