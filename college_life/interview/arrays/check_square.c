#include<stdio.h>
#include <stdlib.h>

#define bye return 0
typedef struct point{
	int x, y;
} Point;

int distance(Point p, Point q){
	return (p.x - q.x)*(p.x - q.x) + (p.y - q.y)*(p.y - q.y);
}


int main(){
	//using custom points
	// Point p1 = {20, 11}, p2 = {10, 20},p3 = {20, 20}, p4 = {10, 10}; //No
	Point p1 = {20, 10}, p2 = {10, 20},p3 = {20, 20}, p4 = {10, 10}; // yes
	int d2 = distance(p1, p2);
	int d3 = distance(p1, p3);
	int d4 = distance(p1, p4);
	if (d2 == d3 && 2*d2 == d4){
		int d = distance(p2, p4);
		(d == distance(p3, p4) && d == d2) ? printf("Yes\n") : printf("No\n");
		bye;
	}
	if (d3 == d4 && 2*d3 == d2){
		int d = distance(p2, p3);
		(d == distance(p2, p4) && d == d3) ? printf("Yes\n") : printf("No\n");
		bye;
	}
	if (d2 == d4 && 2*d2 == d3){
		int d = distance(p2, p3);
		(d == distance(p3, p4) && d == d2) ? printf("Yes\n") : printf("No\n");
		bye;
	}
	printf("No\n");
	return 0;
}