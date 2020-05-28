/*
    reduce
    https://www.codewars.com/kata/5552101f47fc5178b1000050/train/javascript
    
    @param num > 0
    @param exponent > 0
    
    abcd: each digit of num
    if ( (a^exp + b^exp+1 + c^exp+2 + d^exp+3) % k === 0)
      return k
    else
      return -1
*/


// bad solution :(

function digPow(num, exponent)
{
  let nCopy = num;
  let sumPower = 0;
  exponent += num.toString().length - 1; // since it starts from the last digit, not first (e.g. c^3 + b^2 + a^1)
  
  while (nCopy) // Math.floor(nCopy / 10) will result to 0
  {
    sumPower += Math.pow(nCopy % 10, exponent--); // add ( last digit ^ exponent )
    nCopy = Math.floor(nCopy / 10); // next digit
  }
  
  let multiplier = (sumPower % num) ? -1 : (sumPower / num); // if total is a multiple of num, return the multiplier, otherwise return -1
  
  return multiplier; 
}

/*
    better solution
    
    function digPow(num, exp)
    {
      let digits = num.toString().split('');
      let sumPower = digits.reduce((sumP, digit) => sumP + Math.power(digit, exp++), 0);
      let multiplier = (sumPower % num) ? -1 : (sumPower / num);
      return multiplier;
    }
*/
