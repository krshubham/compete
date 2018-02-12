for x in range(-100,100):
	for y in range(-100,100):
		z = x**y + (x+y-3)**y + (x+y-1)**y + (x+y)**y
		if(z == 2018):
			print(x,y)
			print(x+y)
			print(x**y)