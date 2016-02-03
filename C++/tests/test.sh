echo -----------------------------------------------------------
echo Tests pour le binome : B3334
echo -----------------------------------------------------------

nTestCount=0
nSuccesfulTests=0
nStrResult="B3334 : "

echo EXAMPLE 1
let "nTestCount=$nTestCount+1"
./$1 < ex1.in > temp1.txt
grep -v '^#' temp1.txt > temp2.txt
diff -wB ex1.out temp2.txt
if [ $? -eq 0 ]
        then
		echo PASSED
            	let "nSuccesfulTests=$nSuccesfulTests+1"
		nStrResult=$nStrResult" 1"
	else
		echo FAILED
		nStrResult=$nStrResult" 0"
fi

echo EXAMPLE 2
let "nTestCount=$nTestCount+1"
./$1 < ex2.in > temp1.txt
grep -v '^#' temp1.txt > temp2.txt
diff -wB ex2.out temp2.txt
if [ $? -eq 0 ]
        then
		echo PASSED
            	let "nSuccesfulTests=$nSuccesfulTests+1"
		nStrResult=$nStrResult" 1"
	else
		echo FAILED
		nStrResult=$nStrResult" 0"
fi

echo EXAMPLE 3
let "nTestCount=$nTestCount+1"
./$1 < ex3.in > temp1.txt
grep -v '^#' temp1.txt > temp2.txt
diff -wB ex3.out temp2.txt
if [ $? -eq 0 ]
        then
		echo PASSED
            	let "nSuccesfulTests=$nSuccesfulTests+1"
		nStrResult=$nStrResult" 1"
	else
		echo FAILED
		nStrResult=$nStrResult" 0"
fi

rm temp1.txt
rm temp2.txt

echo -----------------------------------------------------------
echo RESULTS
echo -----------------------------------------------------------
echo Results: $nSuccesfulTests/$nTestCount
echo CSVLine: $nStrResult
echo $nStrResult >> results.txt
