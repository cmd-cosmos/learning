public class BasicClasses
{
    public static void main(String[] args)
    {
        Person batman = new Person("Batman", 22);
        batman.greet();
    }
}

class Person{
    String name;
    int age;

    Person(String name, int age)
    {
        this.name = name;
        this.age = age;
    }

    void greet()
    {
        System.out.println("Hello, I am " + name);
    }
}
