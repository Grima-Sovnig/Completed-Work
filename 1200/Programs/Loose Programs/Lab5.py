#Gabriel Snider, CSC-1200-002. Travis Brumment. This program creates a game of Pig. The game will prompt the user to input the amount of players and their names until told to stop.
#The players will have the option to hold or roll, the first one to reach 100 wins the game.
import random
# The PlayerTurn() function is the main function that runs the game. It keeps track of each player's score, and whose turn it is.
#It allows the user to use a dice with the value of 1-6 to play the game. After each turn it will tell the players the overall score, and whose turn is next.
#The first person to get 100 points wins the game. After someone wins the programs tells the player the game is over and ends.
def PlayerTurn(PlayerNames, PlayerScore,PlayerNumber):
    CurrentTurn=0
    Dice=["1","2","3","4","5","6"]
    TempScore=0
    Hold=1

    while 1:
        if Hold ==1:
            print("It is now",PlayerNames[CurrentTurn],"'s Turn!")
            UserInput= input("Enter 1 to Hold or Press Anything Else to Roll!")
        if UserInput =="1":
            Hold=1
            PlayerScore[CurrentTurn]=PlayerScore[CurrentTurn]+TempScore
            if PlayerScore[CurrentTurn] >= 100:
                print("You are the Winner!",PlayerNames[CurrentTurn],"Go Ahead and Celebrate!")
                print("The Game is now Over!")
                break
            else:
                print(PlayerNames[CurrentTurn],"'s current score is:")
                print(PlayerScore[CurrentTurn])
            TempScore=0
            if CurrentTurn + 1 < int(PlayerNumber):
                CurrentTurn+= 1
            elif CurrentTurn +1 == int(PlayerNumber):
                CurrentTurn= 0
        else:
            DiceOutput= random.choice(Dice)
            if DiceOutput != "1":
                print("Your Roll Was A:", DiceOutput)
                TempScore += int(DiceOutput)
                UserInput= input("Enter 1 to Hold or Press Anything Else to Roll!")
                if UserInput=="1":
                     Hold= 1
                     PlayerScore[CurrentTurn]=PlayerScore[CurrentTurn]+TempScore
                     if PlayerScore[CurrentTurn] >= 100:
                         print("You are the Winner!",PlayerNames[CurrentTurn],"Go Ahead and Celebrate!")
                         print("The Game is now Over!")
                         break
                     else:
                        print(PlayerNames[CurrentTurn],"s current score is:")
                        print(PlayerScore[CurrentTurn])
                     if CurrentTurn + 1 < int(PlayerNumber):
                        CurrentTurn+= 1
                     elif CurrentTurn +1 == int(PlayerNumber):
                        CurrentTurn= 0
                     TempScore=0
                else:
                    Hold=0
            elif DiceOutput=="1":
                print("Well that sucks, you rolled a 1!")
                TempScore=0
                Hold=1
                print(PlayerNames[CurrentTurn],"'s current score is:")
                print(PlayerScore[CurrentTurn])
                TempScore=0
                if CurrentTurn + 1 < int(PlayerNumber):
                    CurrentTurn+= 1
                elif CurrentTurn + 1 == int(PlayerNumber):
                    CurrentTurn=0

#The main() function is what hold the players score and all of the players names. It creates a list the is filled by the user(s) when the game is started.
#Every name that is entered is appended to the the current list of names. It also assigns each player a number.
def main():
    PlayerScore= []
    PlayerNames= []

    PlayerNumber= input("Please enter the number of players:")
    i=0
    while(i != int(PlayerNumber)):
        print("Player",i+1,"'s Name")
        PlayerName=input()
        PlayerNames.append(PlayerName)
        PlayerScore.append(0)
        PlayerName=" "
        i += 1
    PlayerTurn(PlayerNames, PlayerScore, PlayerNumber)

main()


