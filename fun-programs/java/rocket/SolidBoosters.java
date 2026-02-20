public class SolidBoosters implements Engine{

    private double thrust;
    public SolidBoosters(double thrust)
    {
        this.thrust = thrust;
    }

    @Override
    public void ignite()
    {
        System.out.println("Solid booster ingition sequence commenced.");
        System.out.println("Solid boosters ingited.");
    }

    @Override
    public void shutdown()
    {
        System.out.println("Solid booster burn complete.");
        System.out.println("Solid booster shutdown.");
    }

    @Override
    public double getThrust()
    {
        return thrust;
    }

    @Override
    public void gimble()
    {
        System.out.println("Solid boosters gimbal locked.");
    }

    @Override
    public boolean getHealth()
    {
        return true;
    }
}