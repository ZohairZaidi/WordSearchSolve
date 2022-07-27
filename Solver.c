#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool search1D(char word[], int wordSize, const int Size, char grid[Size][Size], int row, int col, int rowDir, int colDir){
    int numofwordlettermatched = 1; //counter is starting from one because it is compared to wordsize and word[] is an array so it starts from 0

    //loop to iterate and see if the two words match in each direction
    for (int i=0;i<wordSize;i++){
        if(grid[row+rowDir * i][col+colDir* i] != word[i]){ //plugs in value for each direction to see if words match
            return false;
        }
        else{ //if it matches it increments and then checks if the words matches the wordsize
            numofwordlettermatched++;
            if (numofwordlettermatched == wordSize){
                return true;
            }
        }
    }
}

void printFoundLocation(int i, int j){ //function to print where the first letter is found
    printf("Word found at row %d and column %d ", i,j);
}

void search2D(char word[], int wordSize, const int Size, char grid[Size][Size]){
    bool check = false; //starts false but returns true if a direction matches the word

    //reads through the 2d array
    for (int i=0;i<Size;i++){
        for (int j=0;j< Size;j++){
            if (grid[i][j] == word[0]){
                //checking each direction from south to counterclockwise
                if (search1D(word, wordSize,Size,grid, i,j,1,0)&& check == false){ //calls search1D with appropriate directions
                    printFoundLocation(i,j); //prints coordinates
                    printf("in the south direction."); //prints the directions
                    check = true; //returns true
                }
                else if (search1D(word, wordSize,Size,grid, i,j,1,-1)&& check == false){
                    printFoundLocation(i,j);
                    printf("in the southwest direction.");
                    check = true;
                }
                else if (search1D(word, wordSize,Size,grid, i,j,0,-1)&& check == false){
                    printFoundLocation(i,j);
                    printf("in the west direction.");
                    check = true;
                }
                else if (search1D(word, wordSize,Size,grid, i,j,-1,-1)&& check == false){
                    printFoundLocation(i,j);
                    printf("in the northwest direction.");
                    check = true;
                }
                else if (search1D(word, wordSize,Size,grid, i,j,-1,0)&& check == false){
                    printFoundLocation(i,j);
                    printf("in the north direction.");
                    check = true;
                }
                else if (search1D(word, wordSize,Size,grid, i,j,-1,1)&& check == false){
                    printFoundLocation(i,j);
                    printf("in the northeast direction.");
                    check = true;
                }
                else if (search1D(word, wordSize,Size,grid, i,j,0,1)&& check == false){
                    printFoundLocation(i,j);
                    printf("in the east direction.");
                    check = true;
                }
                else if (search1D(word, wordSize,Size,grid, i,j,1,1)&& check == false){
                    printFoundLocation(i,j);
                    printf("in the southeast direction.");
                    check = true;
                }
            }
        }
    }
    if (check==false){ //if none of the function returned true, word does not exist
        printf("Word not found.");
    }
}