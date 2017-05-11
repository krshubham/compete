//https://www.codechef.com/MAY17/problems/CHEFSUBA


import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;
 
class Solution {
 
    static Deque<Integer> ks = new ArrayDeque<Integer>();
    static int n,k,mid,last;
    static int arr[];
    static TreeMap<Integer,Integer> hm = new TreeMap<Integer, Integer>();
    
    
    static void call_change()
    {
        int val1 = arr[mid--];
        if(mid == -1)
            mid = n-1;
        
        int val2 = arr[last--];
        if(last == -1)
            last = n-1;
        
        int s = ks.removeLast();
        
        remove(s);
        
        s = ks.getFirst() + val2 - val1;
        
        put(s);
        
        ks.addFirst(s);
        
        
    }
    
    static void print(){
        System.out.println(get_max());
    }
    
    static void put(int k)
    {
        k = -k;
        if(hm.containsKey(k))
            hm.put(k,hm.get(k)+1);
        else
            hm.put(k,1);
    }
    
    static void remove(int k)
    {
        k = -k;
        hm.put(k,hm.get(k)-1);
       
        if(hm.get(k) == 0)
            hm.remove(k);
    }
    
    static int get_max()
    {
        for(int i : hm.keySet())
            return -i;
        return -1;
    }    
    
    
    public static void main(String[] args)
    {
       
        n = i();
        k = i();
        mid = k-1;
        last = n-1;
        int p = i();
        arr = new int[n+1];
       // System.out.println(n+" "+k+" "+p);
        for(int i=0;i<n;i++)
        {
            arr[i] = i();
         //   System.out.print(arr[i]+" ");
        }
        
        String ps = s();//for_string(10);
       // System.out.println("\n"+ps);
        
        
        int s = 0;
        
        for(int i=0;i<Math.min(k,n);i++)
        s += arr[i];
           
       
        
        if(k>=n)
        {
            int l = ps.replace("!","").length();
            for(int i=0;i<l;i++)
                System.out.println(s);
            
            return ;
        }
        
        for(int i=0;i<n-k+1;i++)
        {
            ks.add(s);
            //System.out.println(s);
            put(s);
            if(i+k<n)
            s +=(arr[i+k]-arr[i]);
        }
        
        
    //    System.out.println(ks+" "+hm);
        for(int i=0;i<p;i++)
            if(ps.charAt(i) == '!')
                call_change();
            else
                print();
    }
    
    static Scanner sc = new Scanner(System.in);
    static Random r = new Random();
    static int i(){
        return sc.nextInt();
    }
    
    static String s(){
        return sc.next();
    }
    
    static int i(int n){
        return r.nextInt(n);
    }
    
    static String for_string(int l)
    {
        String s = "";
        
        for(int i=0;i<l;i++)
            if(i(2) == 1)
            s = s.concat("!");
            else
            s = s.concat("?");
        return s;    
    }
} 