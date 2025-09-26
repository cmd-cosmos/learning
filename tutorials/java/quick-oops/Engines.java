// another class to demo INHERITANCE later merged with polymorphism to manipulate array printing 

public class Engines extends Rocket {
    private int count;
    private String engineName;

    public Engines(String name, int serial_number, int count, String engineName)
    {
        super(name, serial_number);
        this.count = count;
        this.engineName = engineName;
    }

    public int getCount()
    {
        return count;
    }
    public String getEngineName()
    {
        return engineName;
    }

    @Override
    public String toString()
    {
        String fmtOut = "Engine: " + getName() + "\n" +
                        "   |---> Batch Number: " + getSerNum() + "\n" + 
                        "   |---> Count: " + getCount() + "\n"; 
        
        return fmtOut;
    }

    public void displayInfo()
    {
        System.out.println("Engine: " + getName() + "\n" +
                           "   |---> Batch Number: " + getSerNum() + "\n" + 
                           "   |---> Count: " + getCount() + "\n");
    }
}
