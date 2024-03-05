//help command, prints all commands with descriptions
void help(){
    	cout<< "\nCommands:\n" << 
	"//help - display commands\n" <<
	"//play [file or link] - plays audio from file or link, adds to queue if audio is currently playing\n" <<
	"//pause - pauses the audio currently playing\n" <<
	"//resume - resumes the audio from pause point\n" <<
	"//stop - stop and ends the audio playback\n" <<
	"//repeat [on,off] - toggle repeat of current song\n" <<
	"//queue - displays all items in queue\n" <<
	"//clear - clears the queue of all items\n" <<
	"//current - display information of current audio\n" <<
	"//skip - play next song in queue\n" <<
	"//restart - start current audio from beginning\n" //<<
	//"//remove [queue position] - removes song from queue at position requested\n" <<
	//"//shuffle - randomizes the order of items in the queue\n" <<
	//"//volume [1-10] - set the volume of playback to level desired\n"
	;
}