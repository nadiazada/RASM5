extern "C" void aBubbleSort(int a[], int length);
#include <iostream>
#include <fstream>
#include <ctime>


using namespace std;


void cBubbleSort(int a[], int length)               
{
        int i, j, temp;                //declares

        for (i = 0; i < length; i++)   //outerLoop
        {
                for (j = 0; j < length - i - 1; j++) //innerLoop performs actual comparisons
                {
                        if (a[j + 1] < a[j]) //if next element is smaller than current then swap
                        {
                                temp = a[j]; //store current elem in temp
                                a[j] = a[j + 1];//replace current with next elem
                                a[j + 1] = temp;//str temp in next
                        }
                }
        }
}

void save(int *arr, int size, const char* filename) //saves sorted array to a file
{
 ofstream outFile(filename);                //output file stream
        for(int i = 0; i < size; ++i){      //loop for writing to file
        outFile << arr[i] << endl;          // writes
        }
 outFile.close();                           //close the file
}

int main(){


const int MAX_SIZE = 200000;  //defines constant for maximum number of elements
fstream inFile;               //reading file
ofstream outFile;             //writing file
int choice = 0;               //declare
int count = 0;                //declare
int index = 0;                //declare
int arr1[MAX_SIZE];           //static array for sorting in c++
int arr2[MAX_SIZE];           //static array for sorting in asm

clock_t start;                //start time of sorting
clock_t end;                  //end time of sorting
double cTime =0.0;            //time variable for c++
double aTime = 0.0;           //time variable for asm


//do-while to show the menu until user quits
do
        {
                system("clear");        //clear screen

                //printing the menu
                cout << "\t\tRASM5 C++ vs. Assembly\n";
                cout << "File Element Count:"<< count  << endl;
                cout << "---------------------------------------------------------\n";
                cout << "C++ bubbleSort Time: " << cTime << " secs\n";
                cout << "Assembly bubbleSort Time: "<< aTime << " secs\n\n";
                cout << "---------------------------------------------------------\n";

                cout << "<1> Load input file (integers)\n";
                cout << "<2> Sort using C++ bubbleSort algorithm\n";
                cout << "<3> Sort using Assembly bubbleSort algorithm\n";
                cout << "<4> Quit\n\n";

                //get option
                cout << "Enter a number: ";
                cin  >> choice;                //get menu choice from user
                int i = 0;
//switch statement to handle choice 
        switch(choice){
        case 1:
                inFile.open("input.txt");      //open input.txt for readinf

                while (i < 200000) {           //read from file until array is full 
                    inFile >> arr1[index];     //read data from file and str it in arr1 at the curr index

                    arr2[index] = arr1[index];   //copy aar1 to arr2 at the same index

//Arr2 will be used for asmSorting

                    index++;   //increment index to move to next elem in the arr
                    count++;   //increment count to track number of items processed
                    i++;       //increment loop counter
                }

                inFile.close();   //close the file after reading all data

                cout << "\nINPUT FILE WAS LOADED\n"; 
                break;

        case 2:
                start = clock();                       //starts timing for c++ sorting
                cBubbleSort(arr1, count);              //calls func w param arr1 and count (200,000)
                end = clock();                         //end timing sort for c++
                cTime = (end - start)/ CLOCKS_PER_SEC; //clac time (got from chatgpt)
                save(arr1, count, "c_bubblesort.txt"); //save sorted array to txt file 
                cout << "BubbleSort in C++ in done!\n"; //success msg
                break;

        case 3:
                start = clock();                        //start clock for asmsort
                aBubbleSort(arr2, count);               //call external function for asm bubblesort
                end = clock();                          //end clock timing 
                aTime = (end - start)/ CLOCKS_PER_SEC;  //calc time (got from chatgpt)
                save(arr2, count, "a_bubblesort.txt");  //save sorted arr to txt file a_bubblesort.txt
                cout << "BubbleSort in ASM in done!\n"; //success msg
                break;
      case 4:

                cout << "Quitting program..\n";         //quit msg 

        }

}while(choice!=4) //if choice equals 4(quit) end program else continue to- dp


return 0;        //ends program 


}
