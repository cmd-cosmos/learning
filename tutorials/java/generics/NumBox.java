// extending Number to allow different primitve number types
public class NumBox<T extends Number> {
    private T num;

    public NumBox(T num) {
        this.num = num;
    }

    public double doubleVal() {
        return num.doubleValue();
    }

    public T get() {
        return num;
    }

    public static void main(String[] args) {
        NumBox<Integer> numBox = new NumBox<Integer>(100);
        double numValDouble = numBox.doubleVal();
        System.out.println(numValDouble);
    }
}