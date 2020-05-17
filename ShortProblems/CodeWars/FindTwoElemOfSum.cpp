/*
    vector, pair
    
    return two indexes of two elements which add up to 'target'
    (inputs are always valid, indexes will always be found)
*/

std::pair<std::size_t, std::size_t> two_sum(const std::vector<int>& numbers, int target) 
{
  for (int a = 0; a < numbers.size(); ++a)
    for (int b = 0; b < numbers.size(); ++b)
      if ((a != b) && (numbers[a] + numbers[b] == target))
        return {a, b};
}
