#Iteration 2 Completed

For this iteration we refactored the code to implement the super class Generator Junior.

In this iteration we made changes to:

*Which data type the program chooses to run with.

*The classes in which methods are in, and which classes are subclasses or super classes.


#Dependencies

In this iteration it was required to have wireshark downloaded, and added to your path variable.

We learned how to edit our environment variable in previous labs.

To go along with Wireshark it was also required for us to include the libraries used in previous iterations.

These include:

1)GraphStream Library

2)JavaFx Library

These can be found these links:

* [GraphStream](https://graphstream-project.org/download/)

* [JavaFx](https://gluonhq.com/products/javafx/)


#Running the program

For running this program you need to make sure the previous dependicies are added to the project library.

Once you have compiled the program you will run it with this command choosing whether you want to take data from a file or TShark.

**java -cp %CLASSPATH% standalone.VizSharkJunior {--csv filename | --live interface }**

When you run the code the program will check for these command line arguements like this in the code.

`    public static void main(String[] args) `
`     { `

`        if ((args.length < 2) || ((!args[0].contentEquals("--csv")) && (!args[0].contentEquals("--live"))))` 
`         {`

`            System.err.println("Usage: java -cp %CLASSPATH% standalone.VizSharkJunior {--csv filename | --live interface }");`

`        }` 
`         else `
`         {`
            
`            VizSharkJunior client = new VizSharkJunior(args[0], args[1]);`
`        }`
`    }`
