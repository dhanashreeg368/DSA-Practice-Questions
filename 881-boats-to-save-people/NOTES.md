ALGORITHM
​
Sort the Vector.
We can make the lightest & heaviest person to go together.
using Two pointer appraoch i is the lightest person & j is the heaviest.
Traversing till start <= end.
if sum of lightest & heaviest person are under limit then both can go together , updating i & j both.
If sum exceeds the limit, then heaviest person will go alone, hence updating only the j pointer.
increment the count .
Return cnt.
ANALYSIS:-
​
TIME COMPLEXITY :- O(NlogN)
SPACE COMPLEXITY :- O(1)