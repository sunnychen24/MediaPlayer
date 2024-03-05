#include "commandProcessing.h"

using namespace cmdPro;
	/// @brief	commandProcessing is used to execute any of the commands inputted by the user.
	/// @details	commandProcessing contains a the following functions, which are made available to the user through the GUI
	///		- queue
	///		- play
	///		- pause
	///		- resume
	///		- stop
	///		- set volume
	///		- fade
	///		- repeat
	///		- restart
	///		- skip
	///		- shuffle
	///		- previous
	///		- remove
	/// @authors	Jacob Carson, Arnav Mehrotra, Ben Goodchild


	/// @brief	the constructor.
	/// @details	initializes value fade to be false, initializes SDL Audio, opens the Audio Device and sets the volume to 100%.
	commandProcessing::commandProcessing()
	{
		fade = false;
		
		if (SDL_Init(SDL_INIT_AUDIO) != 0)
		{
			cerr << "SDL_Init ERROR: " << SDL_GetError() << endl;
		}

		//open audio device
		if (Mix_OpenAudio(44100, AUDIO_S16SYS, 2, 2048) != 0)
		{
			cerr << "Mix_OpenAudio ERROR: " << Mix_GetError() << endl;
		}

		//set volume to 100%
		setVolume(100);
	}
	
	/// @brief	queues a song.
	/// @details	adds a user inputted file to the songQueue.
	/// @param 	file to insert, q to store file into
	void commandProcessing::queue(string file, songQueue q) {
		q.addToQueue(file);
	}
	
	/// @brief	plays a song.
	/// @details	adds a user inputted file to the front of the songQueue, and then plays it.
	/// @param 	file to insert, q to store file into
	void commandProcessing::play (string file, songQueue& q) {
		cout << "\nAdding: " << file << " to the queue" << endl;
		q.addToFront(file);
		//q->getQueue().push_back(file);	
		if(q.getLength() > 0){
			cout << "Up Next: " << q.getFirst() << endl;
		}
	
		//turn the file name into a char array
		char c[q.getFirst().size() + 1];
		strcpy(c, q.getFirst().c_str());

		//open audio file
		music = Mix_LoadMUS(c);
		cout << music << endl;

		if (music)
		{
			//start playback
			if (fade) {
				if (q.isLooping() && Mix_FadeInMusic(music, -1, 2000) == 0){
					unsigned int startTime = SDL_GetTicks();
				}
				else if (Mix_FadeInMusic(music, 1, 2000) == 0)
				{

					//wait while music is being played
					//while (Mix_PlayingMusic()) {
					//	SDL_Delay(1000);
					//}
				}
			}
			else {
				if (q.isLooping() && Mix_PlayMusic(music, -1) == 0){
					unsigned int startTime = SDL_GetTicks();
				}
				if (Mix_PlayMusic(music, 1) == 0)
				{

					//wait while music is being played
					//while (Mix_PlayingMusic()) {
					//	SDL_Delay(1000);
					//}
				}
			}
		}
	    else
	    {
			cerr << "Mix_PlayMusic ERROR: " << Mix_GetError() << endl;
	    }
	}

	/// @brief	pauses the music.
	/// @details	invokes the Mix_PauseMusic function to stop audio.
	void commandProcessing::pause () {
		//this will pause the audio
		Mix_PauseMusic();
	}

	/// @brief	resumes a currently paused song
	/// @details	resumes a currently paused song by invoking the Mix_ResumeMusic function.
	void commandProcessing::resume () {
		Mix_ResumeMusic();
	}	

	/// @brief	stops all music and clears the queue.
	/// @details	clears the queue and frees the music function.
	/// @param 	q to clear
	void commandProcessing::stop (songQueue& q) {
		//this will stop the audio
		q.clear();
		Mix_FreeMusic(music);
		music = 0;
		cout << "Audio has now stopped and queue has been cleared\n";
	}

	/// @brief	sets the volume.
	/// @details	sets the volume level to equal the inputted value as a percentage.
	/// @param 	integer vol accepting values 1-100 as a percentage of volume level.
	void commandProcessing::setVolume(int vol) {
		Mix_VolumeMusic(vol);
	}
	
	/// @brief	enables crossfade.
	/// @details	enables crossfade, which smooths the ending of one song before playing the next.
	/// @param 	fade, which is a toggle of whether the song should fade or not.
	void commandProcessing::setFade(bool fade) {
		this->fade = fade;
	}

	/// @brief	toggles repeat on/off.
	/// @details	if the repeat toggle is on, it turns it off. if the toggle is off, it turns it on.
	/// @param 	q, to change the toggle variable
	void commandProcessing::repeatToggle(songQueue& q){
		string activeSong;
		if (q.getLength() > 0){
			q.loop(q);
			if(q.isLooping()){
				//activeSong  = q.getRepeat();
				q.loop(q);
				play(q.getFirst(), q);
				cout << "The active song is now looping\n\n";
			}else{
				q.loop(q);
				play(q.getFirst(), q);				
				cout << "The active song is no longer looping\n\n";

			}
		}else{
			cout << "There are no songs to loop at this time\n";
		}
	}

	/// @brief	restarts a song.
	/// @details	reinvokes the play function on the currently playing song.
	/// @param 	q to play first song again
	void commandProcessing::restart(songQueue q){
		cout << "Time to start again!";
		play(q.getFirst(), q);
	}
	
	/// @brief	skips the currently playing song and plays the next one.
	/// @details	uses the songQueue's skip function to pop the currently playing song and invokes play on the new first song.
	/// @param 	q to pop the first file
	void commandProcessing::skip(songQueue q) {
		q.skip();
		play(q.getFirst(), q);
	}

	/// @brief	plays the last played song.
	/// @details	gets the last played song from the play history and plays it.
	/// @param 	q, to get play history
	void commandProcessing::previous(songQueue q){
		play(q.getLastPlayed(), q);
	}

	/// @brief	shuffles the queue.
	/// @details	creates a temporary queue to shuffle current contents into then swaps it back with q.
	/// @param 	q, to shuffle
	void commandProcessing::shuffle(songQueue q){
		q.shuffle(q);
	}
	
	/// @brief	removes a file from the queue, if it is in the queue.
	/// @details	finds the index of the file in queue and erases it.
	/// @param 	file to remove, q to remove file from
	void commandProcessing::remove(string file, songQueue q){
		q.remove(file, q);
	}
