#/run/current-system/sw/bin/bash

cat << FIN > a
aaa
 abb
  acc
a dd
ae   e
a f        f
agg 
ahh         
   
FIN


echo "< a grep -e ' ' | tr -s  ' ' % > z && cat z"
< a grep -e ' ' | tr -s  ' ' % > z && cat z
echo "./a.out a \"grep -e ' '\" \"tr -s  ' ' %\" z && cat z"
./a.out a "grep -e ' '" "tr -s  ' ' %" z && cat z
echo ""

 echo "./a.out a 'grep -e \" \"' 'tr   \" \" %' z && cat z"
./a.out a 'grep -e " "' 'tr   " " %' z && cat z
echo '< a grep -e " " | tr   " " % > z && cat z'
 < a grep -e " " | tr   " " % > z && cat z
echo ""

echo "./a.out a 'cut --delimiter \" \" --field 1,3' 'cat -e' z && cat z"
./a.out a 'cut --delimiter " " --field 1,3' 'cat -e' z && cat z
echo "< a cut --delimiter \" \" --field 1,3 | cat -e > z && cat z"
< a cut --delimiter " " --field 1,3 | cat -e > z && cat z
echo ""

echo "./a.out a \"cut --delimiter ' ' --field 1,3\" \"wc -c\" z && cat z"
./a.out a "cut --delimiter ' ' --field 1,3" "wc -c" z && cat z
echo "< a cut --delimiter ' ' --field 1,3 | wc -c > z && cat z"
< a cut --delimiter ' ' --field 1,3 | wc -c > z && cat z

./a.out a "ls -l" "tr -s ' '" "cut -d ' ' -f 1,5" "wc -w" "cat -e"  b && cat b
