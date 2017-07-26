$n = [-2, -3, 4, -5];
	$minus = 0;
	$product = 1;
	$nNeg = [];
	for ($i=0; $i < sizeof($n); $i++) { 
		if ($n[$i] < 0) {
			$minus += 1;
			$nNeg[$i] = $n[$i];
		}
	}
	for ($i=0; $i < sizeof($n); $i++) { 
		if ($minus%2!=0) {
			if (($n[$i]!=0) && ($n[$i]!=max($nNeg))) {
				$product = $product*$n[$i];
			}
		} else {
			if ($n[$i]!=0) {
				$product = $product*$n[$i];
			}
		}
	}
	echo $product;