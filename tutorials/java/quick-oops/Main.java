// implementing the Rocket and LaunchPad Class

public class Main{
    public static void main(String[] args) {

        // INSTANTIATE LAUNCHPAD        
        LaunchPad launchPad = new LaunchPad();

        // INSTANTIATE ROCKETS
        Rocket starShip = new Rocket("Starship", 1);
        Rocket falcon = new Rocket("Falcon 9", 2);
        Rocket falconHeavy = new Rocket("Falcon Heavy", 3);

        // ADDING ROCKET OBJECTS INTO THE LAUNCHPAD ARRAYLIST
        launchPad.addRocket(starShip);
        launchPad.addRocket(falcon);
        launchPad.addRocket(falconHeavy);

        // DISPLAYING THE ROCKETS
        launchPad.displayRockets();
    }
}