/*
    algorithm
    https://www.codewars.com/kata/578aa45ee9fd15ff4600090d/cpp
    
    
    only sort odd numbers in an array
*/

#include <utility>
using namespace std;

vector<int> sortArray(vector<int> nums)
{
  vector<int> odds;

  for (int n : nums) // take out odd numbers
    if (n % 2 == 1)
      odds.push_back(n);

  sort(odds.begin(), odds.end()); // sort odd numbers

    for (int iOdds = 0, iNums = 0; iNums < nums.size(); ++iNums) // put odds numbers back in
      if (nums[iNums] % 2 == 1)
        nums[iNums] = odds[iOdds++];

  return nums;
}
