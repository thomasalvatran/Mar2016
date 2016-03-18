package ListTree;


import java.io.ObjectInputStream.GetField;
import java.util.*;
import java.util.Map.Entry;


class Person implements Comparable<Person>{
	
	private String name;
	public Person(String name){
		this.name = name;
	}
	public String toString() {
		return name;
	}
	@Override
//	public int compareTo(Person o) {
//		return this.name.compareTo(o.name);
//	}
	public int compareTo(Person p) {
		int len1 = name.length();
		int len2 = p.name.length();
		if (len1 > len2)
			return 1;
		else if (len1 < len2)
			return -1;
		else
//			return 0;
			return name.compareTo(p.name);
	}
	@Override
	public int hashCode() {
		final int prime = 31;
		int result = 1;
		result = prime * result + ((name == null) ? 0 : name.hashCode());
		return result;
	}
	@Override
	public boolean equals(Object obj) {
		if (this == obj)
			return true;
		if (obj == null)
			return false;
		if (getClass() != obj.getClass())
			return false;
		Person other = (Person) obj;
		if (name == null) {
			if (other.name != null)
				return false;
		} else if (!name.equals(other.name))
			return false;
		return true;
	}
	
}

public class ListTreeCustom {
	public static void main(String[] args) {
		HashMap<Integer, String> hashMap = new HashMap<Integer, String>();
		LinkedHashMap<Integer, String> linkedHashMap = new LinkedHashMap <Integer, String>();
		TreeMap<Integer, String> treeMap = new TreeMap <Integer, String>();
		testMap(hashMap);

		HashMap<Integer, Person> hash = new HashMap<>();
		LinkedHashMap<Integer, Person> link = new LinkedHashMap <>();
		TreeMap<Integer, Person> tree = new TreeMap <>();
		testMaps(tree);

		HashSet<Person> h = new HashSet<>(); //does keep order
		List<Person> l = new ArrayList <>();
		SortedSet<Person> t = new TreeSet <>();
		testSet(t);
	}
	public static void testMap(Map<Integer, String> map){
		map.put(9, "fox");
		map.put(4, "cat");
		map.put(8, "dog");
		map.put(1, "giraffe");
		map.put(15, "near");
		map.put(6, "make");
		
		for( Integer key: map.keySet()){
			String value = map.get(key);
			System.out.println(key + ":" + value);
		}
		List<String> list = new ArrayList<String>();
		SortedSet<String> set = new TreeSet<String>();

		addElements(list);
		addElements(set);
		Collections.sort(list); //Sort ArrayList
		showElements(list);
		System.out.println();
		showElements(set);
	}
	
	private static void addElements(Collection<String> col) {
		col.add("Joe");
		col.add("Sue");
		col.add("Juliet");
		col.add("Clair");
		col.add("Mike");
	}
	private static void showElements(Collection<String> col){
		for (String e : col)
			System.out.println(e); 
	}

	public static void testMaps(Map<Integer, Person> map) {
		map.put(10, new Person("Tim"));
		map.put(1, new Person("Thomas"));
		map.put(100, new Person("Mary"));
		for ( Entry<Integer, Person> e : map.entrySet())
		{
			System.out.println(e.getKey() + " " + e.getValue());
		}
	}
	public static void testSet(Collection<Person> set){
		set.add(new Person("Eddy"));
		set.add(new Person("Sue"));
		set.add(new Person("John"));
//		ArrayList l = (ArrayList) set;//cast
//		Collections.sort(l);
		for (Person e : set)
			System.out.println(e);
	}
}