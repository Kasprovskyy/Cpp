#include <iostream>
#include <chrono>
#include <cstdlib>

using namespace std;
using namespace std::chrono;

int tab[50000];
int tab2[50000];
int* tabPtr = tab;
int tabSize = sizeof(tab) / sizeof(int);

void bubbleSortByIndex();
void bubbleSortByPointers();


int main()
{
    srand(std::time(0));
    for (int i = 0; i < 50000; i++) {
        int a = std::rand() % 100;
        tab[i] = a;
        tab2[i] = a;
    }

    bubbleSortByPointers();
    bubbleSortByIndex();
    
}

void bubbleSortByIndex()
{
    auto start = high_resolution_clock::now();

    for (int i = 0; i < tabSize; i++)
    {
        for (int j = 0; j < tabSize - 1; j++)
        {
            if (tab2[j] > tab2[j + 1])
            {
                int temp = tab2[j];
                tab2[j] = tab2[j + 1];
                tab2[j] = temp;
            }
        }
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    /*for (int i = 0; i < tabSize; i++)
    {
        cout << tab[i] << endl;
    }*/
    cout << "Execution time: " << duration.count() << "ms" <<" by index" << endl;
}

void bubbleSortByPointers()
{
    auto start = high_resolution_clock::now();
    for (int i = 0; i < tabSize; i++)
    {
        for (int j = 0; j < tabSize - 1; j++)
        {
            if (*tabPtr > *(tabPtr + 1))
            {
                swap(*tabPtr, *(tabPtr + 1));
            }
            tabPtr++;
        }
        tabPtr = tab;
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);

    cout << "Execution time: " << duration.count() << "ms" <<" by pointers" << endl;
}

void swap(int& alias1, int& alias2)
{
    int temp = alias1;
    alias1 = alias2;
    alias2 = temp;
}