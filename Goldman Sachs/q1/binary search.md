## Idea

The proposed solution involves using Binary Search on potential answers. For each candidate 'x', the algorithm checks whether taking values from the range [1, x] satisfies certain conditions. If the conditions are met, all numbers greater than or equal to 'x' become valid answers, leading the search towards lesser numbers. Conversely, if 'x' does not satisfy the requirements, no number less than or equal to 'x' can fulfill them, prompting the search to move towards higher numbers.

## Checking the Requirements (Explained in Code Comments)

The `check()` function is responsible for verifying whether a given number 'x' satisfies the specified conditions. The explanation is provided through code comments:

```cpp
long long A = x / d1;  // A = # of numbers divisible by d1
long long A_ = x - A;  // A' = # of numbers not divisible by d1
long long B = x / d2;  // B = # of numbers divisible by d2
long long B_ = x - B;  // B' = # of numbers not divisible by d2
long long AIB = x / lcm(d1, d2);  // A Intersection B = # of numbers divisible by BOTH d1 AND d2
long long AuB = A + B - AIB;  // A Union B = # of numbers divisible by EITHER d1 OR d2
long long A_I_B_ = x - (AuB);  // (A' Union B') = (A Intersection B)' = # of numbers not divisible by NEITHER OF THEM

// needA = # of numbers needed to have at least u1 numbers of set1, these numbers
// don't include (A' Union B')
long long needA = (A_ - A_I_B_ >= u1) ? 0 : u1 - (A_ - A_I_B_);

// needB = # of numbers needed to have at least u2 numbers of set2, these numbers
// don't include (A' Union B')
long long needB = (B_ - A_I_B_ >= u2) ? 0 : u2 - (B_ - A_I_B_);

/*
Why not consider (A' Union B')?
-> I will assign those numbers to whichever set needs it.
*/

// Available (A' Union B') value should be more than the needed # of values to make sets
return (A_I_B_ >= needA + needB);
