// IMPORTANT!!
/*
    Explanation -

    Our first Instinct in problems like these should be that we're going to have to work with bits. Why, Because when you take the + sign, what other choice do we have? Plus, that's how computers do it!
    Our next thought should be to deeply understand how addition works. We can walk through an addition problem to see if we can understand something new—some pattern—and then see if we can replicate that with code. So let, do just that—let, walk through an addition problem. We'll work in base 10 so that it, easier to see.
    To add 759 + 674, would usually add digit [0] from each number, carry the one, add digit [1] from each number, carry the one, and so on. You could take the same approach in binary: add each digit, and carry the one as necessary.
    Can we make this a little easier? Yes! Imagine I decided to split apart the "addition" and "carry" steps. That is, I do the following:

    Add 759 + 674, but "forget" to carry. I then get 323.
    Add 759 + 674 but only do the carrying, rather than the addition of each digit. I then get 1110.
    Add the result of the first two operations (recursively, using the same process described in step 1 and 2): 1110 + 323 = 1433.
    Now, how would we do this in binary?

    If I add two binary numbers together, but forget to carry, the ith bit in the sum will be 0 only if a and b have the same ith bit (both 0 or both 1).This is essentially an XOR.
    If I add two numbers together but only carry, I will have a 1 in the ith bit of the sum only if bits i - 1 of a and b are both 1s. This is an AND, shifted.
    Now, recurse until there's nothing to carry.

*/
class Solution
{
    int sum(int a, int b)
    {
        if (b == 0)
            return a;
        return sum(a ^ b, (unsigned int)(a & b) << 1);
    }

public:
    int getSum(int a, int b)
    {
        return sum(a, b);
    }
};