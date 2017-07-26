import java.io.*;
import java.util.AbstractMap.SimpleEntry;
import java.util.*;
import java.lang.*;

public class Main {
	public static void main(String[] args) throws IOException  {

		BufferedReader br =new BufferedReader(new InputStreamReader(System.in));
		
		HashMap<Integer, ArrayList<SimpleEntry<Integer, Integer>>> map;

		ArrayList<SimpleEntry<Integer, Integer>> list;

		ArrayList<SimpleEntry<Integer, Integer>> nextList;

		int t = Integer.parseInt(br.readLine());
		int n,d,di,ti,si;
		String input="";
		String[] temp;
		int max,maxIndex,sizeOfNextList;
		int result;
		for(int i=0;i<t;i++){
			input=br.readLine();
			temp=input.split(" ");
			
			n = Integer.parseInt(temp[0]);
			d = Integer.parseInt(temp[1]);
			
			map = new HashMap<>();
			result=0;
			
			for(int j=0;j<n;j++){
				input=br.readLine();
				temp=input.split(" ");
				
				di=Integer.parseInt(temp[0]);
				ti=Integer.parseInt(temp[1]);
				si=Integer.parseInt(temp[2]);
				if(map.get(di) != null){
					map.get(di).add(new SimpleEntry<Integer, Integer>(si, ti));
				}
				else {
					list = new ArrayList<>();
					list.add(new SimpleEntry<Integer, Integer>(si, ti));
					map.put(di, list);
				}
			}
			for(int j=1;j<=d;j++){
				if(map.containsKey(j) && map.get(j).size() > 0){
					list=map.get(j);
					
					max=0;
					maxIndex=0;
					sizeOfNextList=0;
					
					if(map.containsKey(j+1) ){
						nextList=map.get(j+1);
						map.remove(j+1);
					}
					else{
						nextList=new ArrayList<>();
					}
					sizeOfNextList=nextList.size();
					
					for(int k=0;k<list.size();k++){
						if(list.get(k).getValue() > 0 && list.get(k).getKey() > max){
							max = list.get(k).getKey();
							maxIndex=k;
						}
						nextList.add(list.get(k));
					}
					
					if(nextList.get(sizeOfNextList+maxIndex).getValue()>0)
						nextList.get(sizeOfNextList+maxIndex).setValue(nextList.get(sizeOfNextList+maxIndex).getValue()-1);
					
					map.put(j+1, nextList);
				}
			}
			if(map.containsKey(d+1)){
				list = map.get(d+1);
				for(int j=0;j<list.size();j++){
					result=result + (list.get(j).getKey()*list.get(j).getValue());
				}
				System.out.println(result);
			}
			else {
				System.out.println(0);
			}
		}
	}
}