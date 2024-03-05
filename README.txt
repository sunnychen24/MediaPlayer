This project is dependent on the use of libSDL_mixer which is available from the libsdl developer packages. 

Run the following to install:
sudo apt-get install libsdl-mixer1.2-dev libsdl1.2-dev

Use g++ `sdl-config --cflags --libs` main.cpp -lSDL_mixer -o player to compile.
Use ./player to run.

The Code will then run through the test suite created covering the logic we can do until we find a suitable C++ Linux audio library. We have editied the story point
value of this section because of the amount of real hours we have spent looking for one such library, and the time spent programming this section. The Class
Diagram has been updated to match our current code.
