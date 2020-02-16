# Autocomplete : required min word
When searching with a word, obtain the minimum number of words required. <br>
The words in the learned list is sorted and obtains them using backtracking. <br>
Example,  <br>
&nbsp;&nbsp;&nbsp;&nbsp;    solution(["word", "war", "warrior", "world"]) => 15 <br>
&nbsp;&nbsp;&nbsp;&nbsp;    solution(["abc", "def", "ghi", "jklm"]) => 4 <br>
&nbsp;&nbsp;&nbsp;&nbsp;    solution(["go", "gone", "guild"]) => 7 <b>(go : 2,  gon : 3, gu : 2  => 2 + 3 + 2 = 7)</b> <br>
