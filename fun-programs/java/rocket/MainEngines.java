public class MainEngines implements Engine{

    private double thrust;
    public MainEngines(double thrust)
    {
        this.thrust = thrust;
    }

    @Override
    public void ignite()
    {
        System.out.println("Main engine ingition sequence commenced.");
        System.out.println("Main engine ingited.");
    }

    @Override
    public void shutdown()
    {
        System.out.println("Main engine burn complete.");
        System.out.println("Main engine shutdown.");
    }

    @Override
    public double getThrust()
    {
        return thrust;
    }

    @Override
    public void gimble()
    {
        System.out.println("Main engine gimbal.");
    }

    @Override
    public boolean getHealth()
    {
        return true;
    }
}