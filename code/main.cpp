///====================Libraries====================
#include "physics.h"
#include <vector>
#include <string>
#include <iostream>       // std::cout, std::endl
#include <thread>         // std::this_thread::sleep_for
#include <chrono>

///====================Namespace====================
using namespace std;
using namespace sf; //for graphics
using namespace std::chrono;

///====================Main Function=========================
int main()
{
    RenderWindow window(VideoMode(800,600),"Bubble Sort");  //creates a window on the screen that is 800 by 600
    window.setFramerateLimit(60); //sets the game loop to run 60 times per second

    ///====================Variables====================
    auto start = high_resolution_clock::now();
    int bubbleList[100];
    RectangleShape bubbleShape[100];
    //Randomize List
    for (int a=0; a<100; a++)
    {
        bubbleList[a]=rand()%100+1;
    }
    //Get the size of the list
    int n = sizeof(bubbleList)/sizeof(bubbleList[0]);
    //Keep track if items being swapped
    int current;
    int next;

    ///========================================Main Graphics Functions========================================
    while (window.isOpen()&& !Keyboard::isKeyPressed(Keyboard::Escape))     //the main game loop, exits if someone closes the window
    {
        Event event; //creates an event object, events include mouse clicks, mouse movement, keyboard presses, etc..
        while (window.pollEvent(event)) //loop that checks for events
        {
            if (event.type == Event::Closed) //checks if window is closed
                window.close();
        }   //ends the event loop

        if (Mouse::isButtonPressed(Mouse::Left))
        {
        }

        //Instant Sorting___________________________________________________________
        int swapped = 0;
        for (int j = 0; j < n; j++)
        {
            for (int i = 0; i < n-j-1; i++)
            {
                if (bubbleList[i] > bubbleList[i+1])
                {
                    swap(bubbleList[i], bubbleList[i+1]);
                    swapped=1;
                }
            }
            // If there is not swapping in the last swap, then the array is already sorted.
            if (swapped ==0)
            {
                break;
            }
        }


        //Visible Sorting (Slower)_____________________________________________________
        /*
        for (int i = 0; i < n; i++)
        {
            if (bubbleList[i] > bubbleList[i+1])
            {
                swap(bubbleList[i], bubbleList[i+1]);
                current=i;
                next=i+1;
                break;
            }
        }
        */
        //Drawing Graphics___________________________________________________________________

        window.clear(); //clears the screen

        for (int i=0; i<100; i++)
        {
            bubbleShape[i].setPosition(i*8,window.getSize().y);
            bubbleShape[i].setSize(Vector2f(4,bubbleList[i]*(-5)));
            if (current==i|next==i)
            {
                bubbleShape[i].setFillColor(Color(255,0,0));

            }
            else
            {
                bubbleShape[i].setFillColor(Color(0,i+100,0));
            }
            window.draw(bubbleShape[i]);
        }
        auto stop = high_resolution_clock::now();
        std::cout << "Program has been running for " << std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count() << " milliseconds" << std::endl;

        //this_thread::sleep_for (std::chrono::milliseconds(100));

        window.display();   //displays everything on the video card to the monitor
    }   //ends the game loop

    return 0;
}
