package SortHashMapByKey;

import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.Iterator;
import java.util.LinkedHashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Set;

class Node {
	String name;
	public Node (String str){
		this.name = str;
	}
}
public class SortHashMapByValue {
  public static void main(String[] args) {
      HashMap<Node, Integer> hmap = new HashMap<Node, Integer>();
      hmap.put(new Node ("A"), 5);
      hmap.put(new Node ("C"), 11);
      hmap.put(new Node ("Y"), 77);
      hmap.put(new Node ("P"), 9);
      hmap.put(new Node ("Q"), 66);
      hmap.put(new Node ("R"), 0);
     
      System.out.println("Before Sorting:");
      Set set = hmap.entrySet();
      Iterator<Node> iterator = set.iterator();
      while(iterator.hasNext()) {
    	  	
           Map.Entry me = (Map.Entry)iterator.next();
           System.out.print(me.getKey() +  ": "); 
           System.out.println(me.getValue());
      }
      for (Map.Entry<Node, Integer> entry : hmap.entrySet()) {
//    	  Node key = entry.getKey();
//    	  int value = entry.getValue();
    	  System.out.println(entry.getKey().name + " " + entry.getValue());
      }
      //Iterator Method 1:
      Map<Integer, String> map = sortByValues(hmap);  /* input: hmap , return: map */
      System.out.println("After Sorting:");
      Set set2 = map.entrySet();
      Iterator iterator2 = set2.iterator();
      while(iterator2.hasNext()) {
           Map.Entry me2 = (Map.Entry)iterator2.next();
           System.out.print(me2.getKey() + ": ");
           System.out.println(me2.getValue());
      }
      //Method 2:
      Iterator iterator3 = set2.iterator();
      while(iterator3.hasNext()){
    	  Map.Entry me3 = (Map.Entry)iterator3.next();
    	  Node key = (Node)me3.getKey();
    	  Integer value = (Integer)me3.getValue();
    	  System.out.println("Key = " + key.name + ", Value = " + value);
      }
      //Method 3:
      for(Entry<?, ?> e: map.entrySet()){  //FAIL if Entry<Node, Integer> e: map.entrySet())
    	  Node key = (Node) e.getKey();
    	  int value = (Integer) e.getValue();
    	  System.out.println(key.name + " " + value);
      }
  }

  private static HashMap sortByValues(HashMap map) { 
       List list = new LinkedList(map.entrySet());
       // Defined Custom Comparator here
       Collections.sort(list, new Comparator() {
            public int compare(Object o1, Object o2) {
               return ((Comparable) ((Map.Entry) (o1)).getValue())
                  .compareTo(((Map.Entry) (o2)).getValue());
            }
       });

       // Here I am copying the sorted list in HashMap
       // using LinkedHashMap to preserve the insertion order
       HashMap sortedHashMap = new LinkedHashMap();
       for (Iterator it = list.iterator(); it.hasNext();) {
              Map.Entry entry = (Map.Entry) it.next();
              sortedHashMap.put(entry.getKey(), entry.getValue());
       } 
       return sortedHashMap;
  }
}