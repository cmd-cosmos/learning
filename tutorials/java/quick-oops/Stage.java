// class to demo INHERITANCE 

public class Stage extends Rocket{
    private String type;

    public Stage(String name, int serial_number, String type)
    {
        super(name, serial_number);
        this.type = type;
    }

    public String getType(){
        return type;
    }
}
