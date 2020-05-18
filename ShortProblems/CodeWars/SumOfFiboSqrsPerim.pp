/*
    https://www.codewars.com/kata/559a28007caad2ac4e000083/train/cpp

    return the sum of perimeters of n+1 squares of which sides are in Fibbonacci Sequence
    when n = 5, 4 * (1 + 1 + 2 + 3 + 5 + 8) = 80
*/

typedef signed long long sll;

sll perimeter(int n)
{
  sll prev = 0, curr = 1, total = 1;

  for (int  i = 0; i < n; ++i)
  {
    curr += prev;
    prev = curr - prev;
    total += curr;
  }

  return 4 * total;
}
