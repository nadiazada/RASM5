extern "C" void aBubbleSort(int a[], int length);
#include <iostream>
#include <fstream>
#include <ctime>


using namespace std;

int main(){


const int MAX_SIZE = 200000;
fstream inFile;
ofstream outFile;
int choice = 0;
int count = 0;
int index = 0;
int arr1[MAX_SIZE];
int arr2[MAX_SIZE];

clock_t start;
clocl_t end;
double cTime =0.0;
double aTime = 0.0;



do
        {
                system("clear");

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
                cin  >> choice;
                int i = 0;

        switch(choice){
        case 1:
                inFile.open("input.txt");

                while (i < 200000) {
                    inFile >> arr1[index];   // Read data from file and store it in intArr1 at the current index

                    arr2[index] = arr1[index];   // Copy data from intArr1 to intArr2 at the same index

//Arr2 will be used for asmSorting

                    index++;   // Increment index to move to the next element in the array
                    count++;   // Increment count to track the number of items processed
                    i++;       // Increment loop counter
                }

                inFile.close();   // Close the file after reading all data

                cout << "\nINPUT FILE WAS LOADED\n";   // Output a success message
                break;

        case 2:
                start = clock();
                cBubbleSort(arr1, MAX_SIZE);
                end = clock();
                cTime = (end - start)/ CLOCKS_PER_SEC;
                save(arr1, MAX_SIZE, "c_bubblesort.txt");
                cout << "BubbleSort in C++ in done!/n";
                break;

        case 3:
                start = clock();
                aBubbleSort(arr2, MAX_SIZE);
                end = clock();
                aTime = (end - start)/ CLOCKS_PER_SEC;
                save(arr2, MAX_SIZE, "a_bubblesort.txt");
                cout << "BubbleSort in ASM in done!/n";
                break;
      case 4:

                cout << "Quitting program..";

        default:
                cout <<"invlaid case try again/n";
                break;

}while(choice!=4)


void save(int *arr, MAX_SIZE, const char* filename)
{
  ofstream outFile(filename);
        for(int i = 0; i < MAX_SIZE; ++i){
        outFile << arr[i] << endl;
        }
  outFile.close();
}


return 0;


}
