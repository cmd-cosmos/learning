// basic java program
// class --> blueprint for everything ---> contain members
// object --> instance of a class
// methods --> member of class ---> member functions --> do something
// property --> member of class ---> member variables --> store something
// access modifiers --> public, private or protected --> who can use it
// static --> in this context --> remove the need for object instantiation of the class.
// identifiers --> names given to property or class itself

public class Basic{
    public static void main(String[] args){
        System.out.println("Flight Director: Go for Launch");
        Log("T -10s");
        try {
            CountDown();
        } catch (InterruptedException e) {
            System.err.println(e);
        }
    }
    public static void Log(String str)
    {
        System.out.println("Logger: " + str);
    }
    public static void CountDown() throws InterruptedException
    {
        for (int i = 10; i > 0; i--) {
            System.out.println(i);
            Thread.sleep(1000);
        }
        System.out.println("Liftoff...");
    }
}