public class FirstExample 
{
    /**
     * 
     * javac -d out src/2310/Feb3rd.java
     * java -cp out Feb3rd
     */
    public static void main(String args[])
    {
        //Greeter greet = new Greeter("Dev");                       I do not know why this line doesn't work.
        //System.out.println("Hello, World # 901" + greet.getName());

        FirstExample f3 = new FirstExample();

        f3.Yo("Gabriel");
    }

    public void Yo(String adrian)
    {
        System.out.println("Yo, " + adrian);
        System.out.println("Yo, " + adrian +"!!!");
    }

}