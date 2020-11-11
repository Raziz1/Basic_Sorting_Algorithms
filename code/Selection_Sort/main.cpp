///====================Include Libraries====================
#include "physics.h"
#include <vector>
#include <string>
#include <iostream>       // std::cout, std::endl
#include <thread>         // std::this_thread::sleep_for
#include <chrono>

///====================Namespace=========================
using namespace std;
using namespace sf; //for graphics
using namespace std::chrono;

///=========================Main Function=========================
int main()
{
    RenderWindow window(VideoMode(800,600),"Select Sort");  //creates a window on the screen that is 800 by 600
    window.setFramerateLimit(60); //sets the game loop to run 60 times per second

    ///=========================Variables=========================
    auto start = high_resolution_clock::now();

    int selectList[100];
    RectangleShape selectShape[100];
    for (int a=0; a<100; a++)
    {
        selectList[a]=rand()%100+1;
    }
    //Keep track of list size
    int n = sizeof(selectList)/sizeof(selectList[0]);
    int j=0;
    int minList;
    int next;

    ///=========================Main Graphics Loop=========================
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


        //Instant Sorting_________________________________________________________________
        /*
        for (int j = 0; j < n - 1; j++)
        {
            int min_idx = j;
            for (int i = j + 1; i < n; i++)
            {
                // To sort in descending order, change > to < in this line.
                // Select the minimum element in each loop.
                if (selectList[i] < selectList[min_idx])
                {
                    min_idx = i;
                }
            }
            swap(selectList[min_idx], selectList[j]);

        }
        */

        //Visible Sorting_________________________________________________________________
        for (j=j; j < n - 1; j++)
        {
            int min_idx = j;
            for (int i = j + 1; i < n; i++)
            {
                // To sort in descending order, change > to < in this line.
                // Select the minimum element in each loop.
                if (selectList[i] > selectList[min_idx])
                {
                    min_idx = i;
                    minList=i;
                    break;
                }
                else
                {
                    break;
                }

            }
            // put min at the correct position
            swap(selectList[min_idx], selectList[j]);
            j++;
            break;
        }

        //Manually step through loop and reset
        if (j==99)
        {
            j=0;
        }


        window.clear(); //clears the screen


        for (int i=0; i<n; i++)
        {
            selectShape[i].setPosition(i*8,window.getSize().y);
            selectShape[i].setSize(Vector2f(4,selectList[i]*(-5)));
            //Draw minimum bar as different color
            if (minList==i)
            {
                selectShape[i].setFillColor(Color(255,0,0));
            }
            else
            {
                selectShape[i].setFillColor(Color(0,i+100,0));
            }
            window.draw(selectShape[i]);
        }

        //Print time taken
        auto stop = high_resolution_clock::now();
        std::cout << "Program has been running for " << std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count() << " microseconds" << std::endl;
        //this_thread::sleep_for (std::chrono::milliseconds(25));



        window.display();   //displays everything on the video card to the monitor
    }   //ends the game loop

    return 0;
}
