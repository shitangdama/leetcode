<<<<<<< HEAD
Given a string, we can ¡°shift¡± each of its letter to its successive letter, for example: ¡°abc¡± -> ¡°bcd¡±. We can keep ¡°shifting¡± which forms the sequence:

1

	

"abc" -> "bcd" -> ... -> "xyz"

Given a list of strings which contains only lowercase alphabets, group all strings that belong to the same shifting sequence.
For example,

given: ["abc", "bcd", "acef", "xyz", "az", "ba", "a", "z"], Return:

1

	

[
  ["abc","bcd","xyz"],
  ["az","ba"],
  ["acef"],
  ["a","z"]
]

=======
Given a string, we can ¡°shift¡± each of its letter to its successive letter, for example: ¡°abc¡± -> ¡°bcd¡±. We can keep ¡°shifting¡± which forms the sequence:

1

	

"abc" -> "bcd" -> ... -> "xyz"

Given a list of strings which contains only lowercase alphabets, group all strings that belong to the same shifting sequence.
For example,

given: ["abc", "bcd", "acef", "xyz", "az", "ba", "a", "z"], Return:

1

	

[
  ["abc","bcd","xyz"],
  ["az","ba"],
  ["acef"],
  ["a","z"]
]

>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74
Note: For the return value, each inner list¡¯s elements must follow the lexicographic order.