days = 0;
a,b = input().split(' ');
a = int(a);b = int(b);
grains = a;
maxi = a;
while 1:
	days+=1;
	grains -= days;
	if(grains <= 0):
		break;
	grains+=b;
	if(grains > maxi):
		grains = maxi;
print(days);
sys.exit(0);