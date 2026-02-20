import java.util.HashMap;

public class Rocket {
    private int id;
    private String name;
    HashMap<Integer, String> map = new HashMap<>();

    public Rocket(int id, String name)
    {
        this.name = name;
        this.id = id;
    }

    public HashMap<Integer, String> getInfo()
    {
        map.put(this.id, this.name);
        return map;
    }
}