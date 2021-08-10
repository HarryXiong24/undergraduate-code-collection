package study12;

import java.util.*;
import java.util.Map.Entry;


public class Collection {
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		//集合
		Set<String> ex1 = new HashSet<String>();
		
		ex1.add("aaaa");
		ex1.add("2587");
		
		Iterator<String> iterator = ex1.iterator();
		while(iterator.hasNext()) {
			String str = iterator.next();
			System.out.println(str);
		}
		
		for(String str : ex1)
		{
			System.out.println(str);
		}
		
		//列表
		List<Integer> ex2 = new LinkedList<Integer>();
		
		ex2.add(6);
		ex2.add(7);
		ex2.add(1, 8);
		ex2.add(4);
		
		Iterator<Integer> iterator2 = ex2.iterator();
		while(iterator2.hasNext()) {
			Integer in = iterator2.next();
			System.out.printf("%d ", in);
		}
		
		System.out.println("");
		for (Integer integer : ex2) {
			System.out.printf("%d ", integer);
		}
		
		//Map
		Map<String, Integer> ex3 = new HashMap<String, Integer>();
		
		ex3.put("001", 100);
		ex3.put("002", 90);
		ex3.put("003", 70);
		
		Set<String> key = ex3.keySet();
		Set<Entry<String, Integer>> entries = ex3.entrySet();
		
		System.out.println("");
		for(String str : key)
		{
			System.out.println(str);
		}
		
		for (Entry<String, Integer> entry : entries) {
			System.out.println(entry.getKey() + " " +  entry.getValue());
		}
	}
}


class myType<type extends Number>{
	type obType;
}
