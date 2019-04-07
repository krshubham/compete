filename=$1
if [ ${filename: -4} == ".cpp" ]
	then
	g++-7 $filename && ./a.out < in
elif [ ${filename: -3} == ".py" ]; 
	then
	python3 $filename < in
fi
