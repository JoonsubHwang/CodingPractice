/*
    vector
    https://www.codewars.com/kata/57b06f90e298a7b53d000a86/cpp
    
    customers: checking out time for each customer
    n: number of checkout tills
    return the total time required for the whole queue
*/

long queueTime(std::vector<int> customers, int n)
{
  std::vector<long> queues(n, 0);
  
  for (int time : customers)
    *std::min_element(queues.begin(), queues.end()) += time; // add customer's time to the shortest queue
  
  return *std::max_element(queues.begin(), queues.end()); // return longest queue
}
