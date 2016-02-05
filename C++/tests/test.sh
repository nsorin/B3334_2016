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

echo TEST ADD SEGMENT 1
let "nTestCount=$nTestCount+1"
./$1 < testAddSegment.in > temp1.txt
grep -v '^#' temp1.txt > temp2.txt
diff -wB testAddSegment.out temp2.txt
if [ $? -eq 0 ]
        then
		echo PASSED
            	let "nSuccesfulTests=$nSuccesfulTests+1"
		nStrResult=$nStrResult" 1"
	else
		echo FAILED
		nStrResult=$nStrResult" 0"
fi

echo TEST ADD RECTANGLE 1
let "nTestCount=$nTestCount+1"
./$1 < testAddRectangle.in > temp1.txt
grep -v '^#' temp1.txt > temp2.txt
diff -wB testAddRectangle.out temp2.txt
if [ $? -eq 0 ]
        then
		echo PASSED
            	let "nSuccesfulTests=$nSuccesfulTests+1"
		nStrResult=$nStrResult" 1"
	else
		echo FAILED
		nStrResult=$nStrResult" 0"
fi

echo TEST ADD RECTANGLE 2
let "nTestCount=$nTestCount+1"
./$1 < testAddRectangle2.in > temp1.txt
grep -v '^#' temp1.txt > temp2.txt
diff -wB testAddRectangle2.out temp2.txt
if [ $? -eq 0 ]
        then
		echo PASSED
            	let "nSuccesfulTests=$nSuccesfulTests+1"
		nStrResult=$nStrResult" 1"
	else
		echo FAILED
		nStrResult=$nStrResult" 0"
fi

echo TEST ADD PC 1
let "nTestCount=$nTestCount+1"
./$1 < testAddPC.in > temp1.txt
grep -v '^#' temp1.txt > temp2.txt
diff -wB testAddPC.out temp2.txt
if [ $? -eq 0 ]
        then
		echo PASSED
            	let "nSuccesfulTests=$nSuccesfulTests+1"
		nStrResult=$nStrResult" 1"
	else
		echo FAILED
		nStrResult=$nStrResult" 0"
fi

echo TEST ADD PC 2
let "nTestCount=$nTestCount+1"
./$1 < testAddPC2.in > temp1.txt
grep -v '^#' temp1.txt > temp2.txt
diff -wB testAddPC2.out temp2.txt
if [ $? -eq 0 ]
        then
		echo PASSED
            	let "nSuccesfulTests=$nSuccesfulTests+1"
		nStrResult=$nStrResult" 1"
	else
		echo FAILED
		nStrResult=$nStrResult" 0"
fi

echo TEST ADD PC 3
let "nTestCount=$nTestCount+1"
./$1 < testAddPC3.in > temp1.txt
grep -v '^#' temp1.txt > temp2.txt
diff -wB testAddPC3.out temp2.txt
if [ $? -eq 0 ]
        then
		echo PASSED
            	let "nSuccesfulTests=$nSuccesfulTests+1"
		nStrResult=$nStrResult" 1"
	else
		echo FAILED
		nStrResult=$nStrResult" 0"
fi

echo TEST ADD PC 4
let "nTestCount=$nTestCount+1"
./$1 < testAddPC4.in > temp1.txt
grep -v '^#' temp1.txt > temp2.txt
diff -wB testAddPC4.out temp2.txt
if [ $? -eq 0 ]
        then
		echo PASSED
            	let "nSuccesfulTests=$nSuccesfulTests+1"
		nStrResult=$nStrResult" 1"
	else
		echo FAILED
		nStrResult=$nStrResult" 0"
fi

echo TEST ADD SEGMENT 2
let "nTestCount=$nTestCount+1"
./$1 < testAddSegment2.in > temp1.txt
grep -v '^#' temp1.txt > temp2.txt
diff -wB testAddSegment2.out temp2.txt
if [ $? -eq 0 ]
        then
		echo PASSED
            	let "nSuccesfulTests=$nSuccesfulTests+1"
		nStrResult=$nStrResult" 1"
	else
		echo FAILED
		nStrResult=$nStrResult" 0"
fi

echo TEST UNION
let "nTestCount=$nTestCount+1"
./$1 < testUnion.in > temp1.txt
grep -v '^#' temp1.txt > temp2.txt
diff -wB testUnion.out temp2.txt
if [ $? -eq 0 ]
        then
		echo PASSED
            	let "nSuccesfulTests=$nSuccesfulTests+1"
		nStrResult=$nStrResult" 1"
	else
		echo FAILED
		nStrResult=$nStrResult" 0"
fi

echo TEST INTERSECTION
let "nTestCount=$nTestCount+1"
./$1 < testIntersect.in > temp1.txt
grep -v '^#' temp1.txt > temp2.txt
diff -wB testIntersect.out temp2.txt
if [ $? -eq 0 ]
        then
		echo PASSED
            	let "nSuccesfulTests=$nSuccesfulTests+1"
		nStrResult=$nStrResult" 1"
	else
		echo FAILED
		nStrResult=$nStrResult" 0"
fi

echo TEST HIT 1
let "nTestCount=$nTestCount+1"
./$1 < testHit.in > temp1.txt
grep -v '^#' temp1.txt > temp2.txt
diff -wB testHit.out temp2.txt
if [ $? -eq 0 ]
        then
		echo PASSED
            	let "nSuccesfulTests=$nSuccesfulTests+1"
		nStrResult=$nStrResult" 1"
	else
		echo FAILED
		nStrResult=$nStrResult" 0"
fi

echo TEST MOVE
let "nTestCount=$nTestCount+1"
./$1 < testMove.in > temp1.txt
grep -v '^#' temp1.txt > temp2.txt
diff -wB testMove.out temp2.txt
if [ $? -eq 0 ]
        then
		echo PASSED
            	let "nSuccesfulTests=$nSuccesfulTests+1"
		nStrResult=$nStrResult" 1"
	else
		echo FAILED
		nStrResult=$nStrResult" 0"
fi

echo TEST UNDO REDO MOVE
let "nTestCount=$nTestCount+1"
./$1 < testUndoRedoMove.in > temp1.txt
grep -v '^#' temp1.txt > temp2.txt
diff -wB testUndoRedoMove.out temp2.txt
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
