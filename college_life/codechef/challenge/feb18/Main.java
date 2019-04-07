import java.io.*;
public class Main{
	//we will try to return 3, but let's see
	public static int sum(){
		int m = 1;
		int n;
		m = 1;
		n = 2; // m has been initialized again
		int r = m + n;
		return r;
	}
	public static void main(String[] args) {
		int x = sum();
		System.out.println(x);
	}
}