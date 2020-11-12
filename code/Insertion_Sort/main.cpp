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

///====================Main Function====================
int main()
{
    RenderWindow window(VideoMode(800,600),"SFML Works");  //creates a window on the screen that is 800 by 600

    ///====================Variables====================
    auto start = high_resolution_clock::now();
    int insertionList[100];
    RectangleShape insertionShape[100];
    for (int a=0; a<100; a++)
    {
        insertionList[a]=rand()%100+1;
    }
    int n = sizeof(insertionList)/sizeof(insertionList[0]);
    int key;
    int i=1;
    int current;

    ///====================Main Graphics Loop====================
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

        //Instant Sort_________________________________________________

        for (int i=1; i<n; i++)
        {
            key = insertionList[i];
            int j = i-1;
            while(key<insertionList[j] &&j>=0)
            {
                insertionList[j+1]= insertionList[j];
                --j;
            }
            insertionList[j+1]=key;
        }


        //Visualize Sort__________________________________________________
        /*
        for (i=i; i<n; i++)
        {
            key = insertionList[i];
            int j = i-1;
            while(key<insertionList[j] && j>=0)
            {
                insertionList[j+1]= insertionList[j];
                current = j;
                --j;
                //break;
            }
            insertionList[j+1]=key;
            i++;
            break;
        }
        */

        window.clear(); //clears the screen

        for (int i=0; i<n; i++)
        {
            insertionShape[i].setPosition(i*8,window.getSize().y);
            insertionShape[i].setSize(Vector2f(4,insertionList[i]*(-5)));
            if (i==current)
            {
                insertionShape[i].setFillColor(Color(255,0,0));

            }
            else
            {
                insertionShape[i].setFillColor(Color(0,i+100,0));
            }
            window.draw(insertionShape[i]);
        }

        auto stop = high_resolution_clock::now();
        std::cout << "Program has been running for " << std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count() << " milliseconds" << std::endl;
        //this_thread::sleep_for (std::chrono::milliseconds(200));

        window.display();   //displays everything on the video card to the monitor
    }   //ends the game loop

    return 0;
}
