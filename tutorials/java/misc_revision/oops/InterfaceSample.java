interface LaunchVehicle {
    void liftoff();
}

class Falcon implements LaunchVehicle {
    public void liftoff()
    {
        System.out.println("We have liftoff");
    }
}

public class InterfaceSample {
    public static void main(String[] args)
    {
        LaunchVehicle lv = new Falcon();
        lv.liftoff();
    }
}