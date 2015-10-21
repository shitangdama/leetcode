Given two strings S and T, determine if they are both one edit distance apart.
Implement a function OneEditApart with the following signature:
bool OneEditApart(string s1, string s2)
isOneEditDistance("cat", "dog") = false
isOneEditDistance("cat", "cats") = true
isOneEditDistance("cat", "cut") = true
isOneEditDistance("cat", "cast") = true
isOneEditDistance("cat", "at") = true
isOneEditDistance("cat", "acts") = false