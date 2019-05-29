#Exercise 1 in advanced cpp course

First we set the number of players and the number of cards for each one by the user input.

Then the program recieves the players name, and randomly draws cards. Also it draws a random start card, and then the game starts.

In example:

![](https://user-images.githubusercontent.com/33619352/58573803-2a91d500-8247-11e9-8d45-9fe533da0a05.png)

Game play:

The program will give each player their turn by order, there is no significance for who the first player is.

in every turn beginning the program should print this:

![](https://user-images.githubusercontent.com/33619352/58574140-fcf95b80-8247-11e9-86f0-fffd9aa04668.png)

Now there are 3 options: 

1.The user have made a legal choice (same symbol or color)- in this case the chosen card replaces the current card and the turn goes to the next player.

![](https://user-images.githubusercontent.com/33619352/58574440-a50f2480-8248-11e9-91ec-3530a697b341.png)

2.The user have made an ilegal card choice- the following error line will occur (in the example), and the program will wait for another input.

![](https://user-images.githubusercontent.com/33619352/58574616-0cc56f80-8249-11e9-8bb4-02dbd80b8e1b.png)

3.The user picked 0 or any other number which is not in the range- the current player recieves a card from the bank, and the turn continues to next player anyway.

The turn play in option 1 goes by these rules:
* Card **+**- the turn is still the current players.
* Card **Change direction**- changes the players turn direction.
* Card **Stop**- skips the next player.
* Any other card- go to the next player.

The winner is the one who is left without any cards, and the program ends.

![](https://user-images.githubusercontent.com/33619352/58575613-1b148b00-824b-11e9-9140-6559acee0ddc.png)
