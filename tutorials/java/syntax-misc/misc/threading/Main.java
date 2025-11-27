public class Main{
    public static void main(String[] args){
        Thread t = new Thread(() -> {
            System.out.println("I am a thread");
        });

        t.start();
    }
}