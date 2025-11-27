class CustomThread extends Thread{

    private int id;
    public CustomThread(int id){
        this.id = id;
    }
    @Override
    public void run(){
        try{
            for(int i = 0; i <= 5; i++){
                System.out.println("Custom Thread " + id +  " is Running.");
                Thread.sleep(300);
            }
        } catch (InterruptedException e){
            System.out.println("Thread " + id + " was interrupted.");
        }
    }
}

public class Custom{
    public static void main(String[] args){
        CustomThread t1 = new CustomThread(1);
        CustomThread t2 = new CustomThread(2);
        CustomThread t3 = new CustomThread(3);
        t1.start();
        t2.start();
        t3.start();
    }
}