// DEMO ABSTRACTION
// this class can not be instantiated by itself but can be used as a base to target a specific requirement

public abstract class Prototype {
    private String name;
    private int serial_number;

    public Prototype(String name, int serial_number)
    {
        this.name = name;
        this.serial_number = serial_number;
    }

    public String getName()
    {
        return name;
    }

    public int getSerialNumber()
    {
        return serial_number;
    }

    public abstract void displayInfo();
}