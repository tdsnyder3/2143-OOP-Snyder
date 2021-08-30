/*****************************************************************************
*                    
*  Author:           Trevor Snyder
*  Email:            tdsnyder0309@my.msutexas.edu
*  Label:            A04
*  Title:            Linked List Class
*  Course:           CMPS 2143
*  Semester:         Spring 2021
* 
*  Description:
*        
*        
*  Usage: 
*       - This program uses a class that manipulates a standard integer array 
*
*       
*  Files:            
*       main.cpp    : driver program 
*****************************************************************************/


#include <iostream>
using namespace std;

/**
 * CircularArrayQue
 * 
 * Description:
 *      This class changes the standard integer array
 * 
 * Public Methods:
 *            - CircularArrayQue()
 *            - CircularArrayQue(int size)
 *  void      Push(int item)
 *  int       Pop()
 *  ostream   &operator<<(ostream &os, const CircularArrayQue &other)
 *  
 * Private Methods:
 *            int *Container;
 *  int       Front
 *  int       Rear
 *  int       QueSize
 *  int       CurrentSize
 *  void      init(int size = 0)
 *  bool      Full()
 * 
 * Usage: 
 *      CircularArrayQue c()                //creates a circular array with a size of 10
 *      CircularArrayQue a(n)               //creates a circular array with a size of n
 *      c.Push(f)                           //if queue isn't full, pushes int f in behind the data already in CircularArrayQue c
 *      c.Pop ()                            //removes the interger number in front of CircularArrayQue c
 *      cout << c;                          //prints out every interger number in CircularArrayQue c from front to back
 */

class CircularArrayQue {
private:
    int *Container;
    int Front;
    int Rear;
    int QueSize; // items in the queue
    int CurrentSize;

    /**
     * Private : init
     * 
     * Description:
     *      Initializes local variables for the class
     * 
     * Params:
     *      int     : queue size, defaults to 0
     * 
     * Returns:
     *      No explicit returns, sets QueSize to the size parameter and Front/Rear/CurrentSize to 0;
     */
    void init(int size = 0) {
        Front = Rear = CurrentSize = 0;
        QueSize = size;
    }

    /**
     * Private : Full
     * 
     * Description:
     *      Compares CurrentSize to QueSize and returns the result as a boolean.
     * 
     * Params:
     *      N/A
     * 
     * Returns:
     *      returns a boolean of CurrentSize equal to QueSize
     */
    bool Full() {
        return CurrentSize == QueSize;
    }

public:
    /**
     * Public : CircularArrayQue
     * 
     * Description:
     *      Default constructor for the class CircularArrayQue, initializes to 10
     * 
     * Params:
     *      N/A
     * 
     * Returns:
     *      Sets the queue size to 10 and runs the init function with a param of 10, no return 
     */
    CircularArrayQue() {
        Container = new int[10];
        init(10);
    }

    /**
     * Public : CircularArrayQue
     * 
     * Description:
     *      Default constructor for the class CircularArrayQue, initializes to 10
     * 
     * Params:
     *      int     size  : Size of Queue
     * 
     * Returns:
     *      Sets the queue size to 10 and runs the init function with a param of 10, no return 
     */
    CircularArrayQue(int size) {
        Container = new int[size];
        init(size);
    }

    /**
     * Public : Push
     * 
     * Description:
     *      Checks to make sure the queue isn't full and adds param item to the end of the queue
     * 
     * Params:
     *      int     item  : item to add to the queue
     * 
     * Returns:
     *      Adds item or prints message, no return
     */
    void Push(int item) {
        if (!Full()) {
            Container[Rear] = item;
            Rear = (Rear + 1) % QueSize;
            CurrentSize++;
        } else {
            cout << "FULL!!!!" << endl;
        }
    }

    /**  
     * Public : Pop
     * 
     * Description:
     *      Checks to make sure the queue isn't full and adds param item to the end of the queue
     * 
     * Params:
     *      N/A
     * 
     * Returns:
     *      Returns the temp variable which contains the removed integer from the front of the queue.
     */
    int Pop() {
        int temp = Container[Front];
        Front = (Front + 1) % QueSize;
        CurrentSize--;
        return temp;
    }
    friend ostream &operator<<(ostream &os, const CircularArrayQue &other);
};

/**
 * Public : &operator<<
 * 
 * Description:
 *      prints entire contents of queue from front to back to the command line
 * 
 * Params:
 *      ostream             : &os references outstream component used to output to terminal
 *      CircularArrayQue    : &other references the queue this function is attached to.
 * 
 * Returns:
 *      No explicit returns, prints content to the terminal
 */
ostream &operator<<(ostream &os, const CircularArrayQue &other) {

    for (int i = other.Front; i < other.CurrentSize; i = (i + 1) % other.QueSize) {
        os << other.Container[i] << " ";
    }
    os << endl;
    return os;
}

/**
 * Main Driver
 * 
 * For this program, the main driver was used to test the CircularArrayQue class
 * 
 */
int main() {
    CircularArrayQue C1(5);

    // C1.Push(34);
    // C1.Push(38);
    // C1.Push(44);
    // C1.Push(22);
    // C1.Push(99);
    // C1.Push(100);

    C1.Push(1);
    C1.Push(2);
    C1.Push(3);
    // C1.Push(6);
    // C1.Push(7);
    cout << C1 << endl;

    // C1.Push(1);
    // C1.Push(2);
    // C1.Push(3);

    cout << C1 << endl;
}
