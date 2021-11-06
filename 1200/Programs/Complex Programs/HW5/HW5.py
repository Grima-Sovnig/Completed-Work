def build_house():
    print("Please enter the House File Name:")
    house_file= input()
    housefp= open(house_file, "r")
    myhouse= []
    line=housefp.readline()
    while line:
        myhouse.append(list(line))
        line= housefp.readline()
    return myhouse
def main():
    house= build_house()
    startrow=house[2]
    startcol=house[2][4]
    num_treasures= 2
    tcount= 0
    while tcount < num_treasures:
        print (house)
        print("You can go North, East, South, and West. You cannot go into a wall.")
        command =input("Enter the direction that you want to go:")
       #trow=command
       #tcol=command
        #check_north=
        #heck_south=
        if command is "n":
            trow= startrow-1
            tcol= startcol
        elif command is "e":
            trow=startrow
            tcol=startcol+1
        elif command is "s":
            trow= startrow+1
            tcol= startcol
        elif command is "w":
            trow=startrow
            tcol=startcol-1
        if command is "q":
            break
main()

        