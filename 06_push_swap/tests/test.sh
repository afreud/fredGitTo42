
./test_pushswap.sh > temp
TOTAL=$(cat temp | paste -sd+ | bc)
NBR=$(cat temp | wc -l)
echo
echo
echo "Test 5 nombres"
cat temp
echo "--------"
echo "moyenne:"
echo "$((TOTAL / NBR))"
echo "--------"
echo "--------"
sleep 2

./test_pushswap100.sh > temp
TOTAL=$(cat temp | paste -sd+ | bc)
NBR=$(cat temp | wc -l)
echo
echo
echo "Test 100 nombres"
cat temp | sort
echo "--------"
echo "moyenne:"
echo "$((TOTAL / NBR))"
echo "--------"
echo "--------"
sleep 2

./test_pushswap500.sh > temp
TOTAL=$(cat temp | paste -sd+ | bc)
NBR=$(cat temp | wc -l)
echo
echo
echo "Test 500 nombres"
cat temp | sort
echo "--------"
echo "moyenne:"
echo "$((TOTAL / NBR))"
echo "--------"
echo "--------"
