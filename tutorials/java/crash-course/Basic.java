// basic java program

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