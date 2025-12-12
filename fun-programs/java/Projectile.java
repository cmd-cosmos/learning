import java.util.Scanner;

public class Projectile {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("ASCII Projectile Simulator\n");

        System.out.print("Initial speed (m/s): ");
        double speed = scanner.nextDouble();

        System.out.print("Launch angle (degrees): ");
        double angle = scanner.nextDouble();

        System.out.print("Launch height (m): ");
        double height = scanner.nextDouble();

        final double g = 9.81;
        double angleRad = Math.toRadians(angle);
        double v0x = speed * Math.cos(angleRad);
        double v0y = speed * Math.sin(angleRad);

        double timeOfFlight = (v0y + Math.sqrt(v0y * v0y + 2 * g * height)) / g;

        // Grid size
        int rows = 20;
        int cols = 80;
        char[][] grid = new char[rows][cols];

        // Initialize grid with spaces
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                grid[i][j] = ' ';
            }
        }

        // Scaling factors
        double xscale = cols / (v0x * timeOfFlight);
        double yscale = rows / (v0y * timeOfFlight / 2 + height); 
        
        double dt = 0.05;

        for (double t = 0; t <= timeOfFlight; t += dt) {
            double x = v0x * t;
            double y = height + v0y * t - 0.5 * g * t * t;

            if (y < 0) y = 0;

            int col = Math.min((int) (x * xscale), cols - 1);
            int row = Math.min(rows - 1 - (int) (y * yscale), rows - 1);

            grid[row][col] = '*';
        }

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                System.out.print(grid[i][j]);
            }
            System.out.println();
        }

        System.out.println("\nProjectile landed after: " + String.format("%.2f", timeOfFlight) + " seconds");

        scanner.close();
    }
}
