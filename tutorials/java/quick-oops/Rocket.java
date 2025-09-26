// private ---> access modifier
// getters and setters allow to access and modify private/protected vals
// this is an example of encapsulation

public class Rocket{
    // ATTRIBUTES
    private String name; // model ---> falcon, starship, SLS, PSLV
    private int serial_number;

    // CONSTRUCTOR
    public Rocket(String name, int serial_number)
    {
        this.name = name;
        this.serial_number = serial_number;
    }

    // GETTER METHODS FOR THE PRIVATE/PROTECTED ATTRIBUTES
    public String getName()
    {
        return name; 
    }
    public int getSerNum()
    {
        return serial_number; 
    }

    // POLYMORPHIC BEHAVIOR
    @Override
    public String toString()
    {
        String fmtOut = "ROCKET: " + getName() + "\n" +
                        "  |----> Serial Number: " + getSerNum();
        
        return fmtOut;
    }
}