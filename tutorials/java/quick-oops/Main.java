// implementing the Rocket and LaunchPad Class
// DEMONSTRATES:
// - POLYMORPHISM
// - INHERITANCE IN THE SUBCLASSES

public class Main{
    public static void main(String[] args) {

        // INSTANTIATE LAUNCHPAD        
        LaunchPad launchPad = new LaunchPad();

        // ADDING ROCKET OBJECTS INTO THE LAUNCHPAD ARRAYLIST
        Rocket starShip = new Rocket("Starship", 1);
        launchPad.addRocket(starShip);
        Stage stage = new Stage("Stage", 38, "Booster");
        launchPad.addRocket(stage);
        Engines engines = new Engines("Veloci", 13, 33, "Raptor III");
        launchPad.addRocket(engines);
        
        // POLYMORPHIC BEHAVOR ----> METHOD OVERLOADING
        Rocket falcon = new Rocket("Falcon 9", 2);
        launchPad.addRocket(falcon);
        launchPad.addRocket("Stage", 1029, "Landing Stage");
        launchPad.addRocket("Mueller", 21, 8, "Merlin 1-D");   
        
        // ***** DISPLAYING THE ROCKETS
        launchPad.displayRockets();
        
        Rocket falconHeavy = new Rocket("Falcon Heavy", 3);
        System.out.println("Using the abstract logger:");
        launchPad.addRocket(falconHeavy);
        falconHeavy.displayInfo();

    }
}