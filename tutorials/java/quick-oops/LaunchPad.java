// class where we instantiate the rockets for diplay or launch

import java.util.ArrayList; // a list for non primitive data types

public class LaunchPad{

    // DECLARE ARRAYLIST TO CONTAIN ROCKET OBJECTS
    private ArrayList<Rocket> launchPad;

    // CONSTRUCTOR ---> ASSIGNS NEW ARRAYLIST TO PREVIOUSLY DECLARED IDENTIFIER
    public LaunchPad() 
    {
        launchPad = new ArrayList<>();
    }

    // METHOD TO ADD A ROCKET OBJECT TO THE ARRAYLIST
    public void addRocket(Rocket rocket)
    {
        launchPad.add(rocket);
    }

    // PRINT METHOD FOR THE LAUNCHPAD LIST
    public void displayRockets()
    {
        for (Rocket rocket : launchPad)
        {
            System.out.println(rocket.toString());
        }
    }


}