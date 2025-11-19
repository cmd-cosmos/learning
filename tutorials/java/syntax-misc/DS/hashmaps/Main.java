// hashmaps

import java.util.HashMap;

public class Main{
    public static void main(String[] args){
        HashMap<String, Integer> specs = new HashMap<>();

        specs.put("Batman", 100);
        specs.put("Joker", 90);
        specs.put("Riddler", 70);
        specs.put("Scarecrow", 80);

        int batmanPower = specs.get("Batman");
        System.out.println("Batman Power: " + batmanPower);

        // checking if key exists
        if (specs.containsKey("Alfred"))
        {
            System.out.println("Alfred Exists in Dict.");
        }
        else{
            System.out.println("Alfred --> not a Key in the hashmap.");
        }

        // modifying existing val for a key
        specs.put("Joker", 95);
        printMap(specs);
        
        // removing a pair
        specs.remove("Riddler");
        printMap(specs);

    }
    public static void printMap(HashMap<String, Integer> inpMap)
    {
        System.out.println("*********************************************");
        for (String character : inpMap.keySet())
        {
            System.out.println(character + " : " + inpMap.get(character));
        }
    }
}