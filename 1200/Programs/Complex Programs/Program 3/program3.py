#Gabriel Snider CSC-1200-002. Travis Brumment. This program intakes a list of movies with runtimes,ratings, and dates from a text file.
#The functions within the program will allow the user to pull certain information from the file.
#The getInput() function is pulling the movies.txt file into python to read from it. It also has the ability to tell the user if the program cannot locate the file.
#It also turns the data from the file and turns it into a list which is used later on in the program
def getInput():
    try:
        movie=open('movies.txt')
        movies=movie.readlines()
        movie.close()
        return movies
    except IOError:
        raise IOError("File is not found")
#The Alphabetize function sorts the movies from movies.txt alphabetically, then lists them in that order with Name, Runtime, and Rating.
#The function has to look through the list created called movies. That list is also being affected by the sorted command.
def Alphabetize(movies):
    movies=sorted(movies)
    for i in movies:
        j=i.strip().split(',')
        print("Name: {:}, Runtime: {:}, Rating: {:}".format(j[0],j[1],j[2]))
#The rating() function calls the list movies, and takes the information it gets and sorts the movies by their rating. It only prints the movies with the user's desired rating.
#If the rate variable is not equal to the rating of the movie it will not be printed for the user to see.
def rating(movies):
    rate=input('\nEnter rating: ')
    for i in movies:
        rating=i.strip().split(",")
        if rating[2]==rate:
            print("Name: {:}, Runtime: {:}, Rating: {:}".format(rating[0],rating[1],rating[2]))
#The SortRuntime function takes the list of movies and sorts them by runtime.
def SortRuntime(movies):
    movies.sort(key=lambda x: x[1], reverse=True)
    print(movies)
#The lessThanRuntime() function allows the user to enter a desired runtime, and the program will print all the movies that have a runtime less than the input.
#The function compares the users input to the runtime of the movie and prints if it is below the users input.
def lessThanRuntime(movies):
    runtime=int(input('Enter runtime: '))
    for i in movies:
        lessthan=i.strip().split(',')
        if int(lessthan[1])<runtime:
            print("Name: {:}, Runtime: {:}, Rating: {:}".format(lessthan[0],lessthan[1],lessthan[2]))
#The greaterThanRuntime() function takes the users input of runtime and compares it to the runtime of the movie. It will then print the runtimes of the movies that exceed that value.
def greaterThanRuntime(movies):
    runtime=int(input('Enter runtime: '))
    for i in movies:
        greaterthan=i.strip().split(',')
        if int(greaterthan[1])>runtime:
            print("Name: {:}, Runtime: {:}, Rating: {:}".format(greaterthan[0],greaterthan[1],greaterthan[2]))
#The menu() function creates the menu that will be displayed to the user. It prompts them to enter a selection that will sort a list of movies.
#It uses if else statements to achieve this goal. If the user enters a option that does not work it will tel them to try again, and the program will exit when they type -1.
def menu():
    movies=getInput()
    choice=1
    while choice!='-1':
        print('\nOptions:')
        print('1. Print movies alphabetically by name')
        print('2. Print movies with a given rating')
        print('3. Print movies by run time')
        print('4. Find movies with a run time less than given time')
        print('5. Find movies with a run time greater than given time\n')
        choice=input('Enter option: ')
        if choice=='1':
            Alphabetize(movies)
        elif choice=='2':
            rating(movies)
        elif choice=='3':
            SortRuntime(movies)
        elif choice=='4':
            lessThanRuntime(movies)
        elif choice=='5':
            greaterThanRuntime(movies)
        elif choice=='-1':
            print('Goodbye')
        else:
            print("Please Try Another Option")


menu()