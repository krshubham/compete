//$Id$
import java.util.*;
import java.io.*;
import java.lang.*;
import java.util.HashMap;
import java.util.Map;

class Point{
   int x,y;
   
   public Point(int x,int y){
      this.x = x;
      this.y = y;
   }
}

public class GFG {

   private static int max(int a,int b){
      return a>b?a:b; 
   }
   
   private static boolean arePonitsSame(Point p1,Point p2){
      return p1.x == p2.x && p1.y == p2.y; 
   }
   
   private static int gcd(int a,int b){
      if(a==0){
         return b; 
      }
      if(b==0){
         return a; 
      }
      if(a<0){
         return gcd(-1*a,b); 
      }
      if(b<0){
         return gcd(a,-1*b); 
      }
      if(a>b){
         return gcd(b,a); 
      }
      return gcd(b%a,a);
   }
   
   private static String makePair(int a,int b){
      return String.valueOf(a)+String.valueOf(b); 
   }
    
   private static int findMaxNumberOfPointsOnTheSameLine(Point[] points){
      int pointsSize = points.length;
      int verticalPoints,overLappingPoints,horizontalPoints,maxNumberOfPoints=0,currMax;
      int xDiff,yDiff,gcd;
      Map<String,Integer> slopeMap;
      
      for(int i=0;i<pointsSize;i++){
          currMax = verticalPoints = horizontalPoints = overLappingPoints = 0;
          slopeMap = new HashMap<String, Integer>();
          
          for(int j=i+1;j<pointsSize;j++){
              if(arePonitsSame(points[i],points[j])){
                 overLappingPoints++; 
              }else if(points[i].x == points[j].x){
                 verticalPoints++; 
              }else if(points[i].y == points[j].y){
                 horizontalPoints++; 
              }else{
                 yDiff = points[j].y-points[i].y;
                 xDiff = points[j].x-points[i].x;
                 gcd = gcd(yDiff,xDiff);
                 
                 yDiff /= gcd;
                 xDiff /= gcd;
                 
                 String pair = makePair(yDiff,xDiff);
                 if(!slopeMap.containsKey(pair)){
                    slopeMap.put(pair,1); 
                    currMax = max(currMax,1);
                 }else{
                    slopeMap.put(pair,slopeMap.get(pair)+1);
                    currMax = max(currMax,slopeMap.get(pair));
                 }
              }
          }      
      
          currMax = max(max(currMax,verticalPoints),horizontalPoints);
          maxNumberOfPoints = max(maxNumberOfPoints,currMax+1+overLappingPoints);
      }
      
      return maxNumberOfPoints;
   }
   
    
   public static void main(String args[]){
      Scanner sc = new Scanner(System.in);
      Point[] = {};
      int n = sc.nextInt();
      int arr[n];
      for(int i=0;i<n;i++)
      {
        int a = sc.nextInt();
        Point[i] points = {new Point(a,i)};
      }
      //Point[] points = {new Point(-1,1),new Point(0,0),new Point(1,1),new Point(2,2),new Point(3,3),new Point(3,4)};
      System.out.println(findMaxNumberOfPointsOnTheSameLine(points));
   }
}
