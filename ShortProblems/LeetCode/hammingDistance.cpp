/*
    The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

    Given two integers x and y, calculate the Hamming distance.

    Condition: 0 ≤ x, y < 231.
*/

int hammingDistance(int x, int y) 
{
    vector<int> xBinary;
    vector<int> yBinary;

    // change to binary
    for (int exp = 30; exp >= 0; --exp) // goes from 2^30 to 2^0
    {
        int twoToExp = pow(2, exp);

        int one = x / twoToExp; // 2^exp = 0 or 1
        x -= one * twoToExp; // substract 2^exp
        xBinary.push_back(one);

       one = y / twoToExp;
        y -= one * twoToExp;
        yBinary.push_back(one);
    }

    int count = 0;
    for (int i = 0; i < 31; ++i) // 31 == vector size
        count += (int)(xBinary[i] != yBinary[i]); // if the bits are diffrent, ++count

    return count;
}
