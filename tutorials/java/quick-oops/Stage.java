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

    @Override
    public String toString()
    {
        String fmtOut = "Stage: " + getName() + "\n" +
                        "   |---> Serial Number: " + getSerNum() + "\n" + 
                        "   |---> Type: " + getType(); 
        
        return fmtOut;
    }

    // using the abstract method
    public void displayInfo()
    {
        System.out.println("Stage: " + getName() + "\n" +
                        "   |---> Serial Number: " + getSerNum() + "\n" +
                        "   |---> Type: " + getType()); 
    }
}
