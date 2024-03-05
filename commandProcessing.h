// commandProcessing.h
#ifndef commandProcessing_H // include guard
#define commandProcessing_H

#include "songQueue.cpp"
#include "help.cpp"
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>

namespace cmdPro
{
    class commandProcessing
    {
    public:
		commandProcessing();
        void play(string file, songQueue& q);
        void pause();
        void resume();
        void stop(songQueue& q);
        void setVolume(int vol);
        void repeatToggle(songQueue& q);
        void restart(songQueue q);
	void setFade(bool f);
	void skip(songQueue q);
	void queue(string file, songQueue q);
	void previous(songQueue q);
	void shuffle(songQueue q);
	void remove(string file, songQueue q);
    private:
		Mix_Music* music;
		bool fade;
    };
}

#endif // commandProcessing_H
