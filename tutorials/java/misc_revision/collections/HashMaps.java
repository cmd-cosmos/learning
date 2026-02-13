import java.util.HashMap;

public class HashMaps {
    public static void main(String[] args) {
        HashMap<Integer, String> map = new HashMap<>();

        map.put(1, "Batman");
        map.put(2, "Joker");
        map.put(3, "Alfred");
        map.put(4, "Scarecrow");

        System.out.println("val at key 3 = " + map.get(3));

        for (Integer key : map.keySet()) {
            System.out.println(key + " : " + map.get(key));
        }
    }
}