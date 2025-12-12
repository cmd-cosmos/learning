import java.util.Scanner;

public class Projectile{
    public static void main(String[] args)
    {
        Scanner scanner = new Scanner(System.in);
        
        System.out.println("ASCII Projectile Simulator\n");
        
        System.out.print("Initial speed(m/s): ");
        double init_speed = scanner.nextDouble();

        System.out.print("Launch angle(degrees): ");
        double angle = scanner.nextDouble();

        System.out.print("Launch height(meters): ");
        double height = scanner.nextDouble();
    
        final double g = 9.81;
        double dt = 0.1;

        double angle_radian = Math.toRadians(angle);
        double v0x = init_speed * Math.cos(angle_radian);
        double v0y = init_speed * Math.sin(angle_radian);

        double timeOfFlight = (v0y + Math.sqrt(v0y *v0y + 2 * g* height)) / g;

        System.out.println("Projectile landed after: " + String.format("%.2f", timeOfFlight) + " seconds");
    }
}
