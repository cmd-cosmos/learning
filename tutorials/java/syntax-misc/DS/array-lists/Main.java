// array lists
/*
- dynamic array --> resizable
*/
import java.util.ArrayList;

public class Main{
    public static void main(String[] args){
        ArrayList<String> characters = new ArrayList<String>();
        
        characters.add("Batman");
        characters.add("Joker");
        characters.add("Alfred");
        characters.add("Riddler");

        System.out.println("Characters: " + characters);

        System.out.println("Second Character: " + characters.get(1));

        characters.set(1, "Mr. J");
        System.out.println("Modified Second Character: " + characters.get(1));
        System.out.println("Characters: " + characters);

        characters.remove("Alfred");
        System.out.println("Characters: " + characters);

    }
}

