#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <assert.h>
#include <algorithm>
using namespace std;

	/// @brief	songQueue is used to hold the upcoming songs, and the play history as well as play settings.
	/// @details	songQueue contains a the following functions, which are invoked through commandProcessing
	///		- addToQueue
	///		- addTopFront
	///		- getLength
	///		- getFirst
	///		- getLast
	///		- getLastPlayed
	///		- getQueue
	///		- getHistory
	///		- isLooping
	///		- skip
	///		- loop
	///		- clear
	///		- queueToString
	///		- remove
	///		- shuffle
	///		-addToHistory [private]
	///		-pop_front [private]
	/// @authors	Jacob Carson
class songQueue{
	private:
		//variables
		vector<string> q;
		vector<string> h;
		string fileName;
		bool looping;

		/// @brief	adds a song to the history vector.
		/// @details	adds a file string to the back of the history vector.
		/// @param 	file to insert
		void addToHistory(string fileName){
			this->h.push_back(fileName);
		}

		/// @brief	pops the frontmost value of a queue.
		/// @details	removes the first value from the queue and deletes it.
		/// @param 	queue to remove from.
		template<typename T>
		void pop_front(vector<T>& queue){
			assert(!queue.empty());
			addToHistory(queue[0]);
			queue.erase(queue.begin());
		} 

		void setQueue(vector<T>& queue){
			this->q = queue;
		}
		


	public:
		
		/// @brief	constructor.
		/// @details	initializes looping to be false.
		songQueue(){
			//this->r = "";
			this->looping = false;
		}
		
		/// @brief	adds file to the back of the play queue.
		/// @details	pushes the file to the back of the queue.
		/// @param 	file to add.
		void addToQueue (string& fileName){
			this->fileName = "localFiles/";
			this->fileName.append(fileName);
			this->q.push_back(this->fileName);
			
		}
		
		/// @brief	adds a file to the front of the play queue.
		/// @details	inserts the file in the front of the queue.
		/// @param 	file to add.
		void addToFront (string& fileName){
			this->fileName = "localFiles/";
			this->fileName.append(fileName);
			this->q.insert(q.begin(),this->fileName);
			
		}
		
		/// @brief	gets the size of the queue.
		/// @details	gets the size of the vector acting as a queue.
		/// @returns 	integer length.
		int getLength(){
			return this->q.size();
		}

		/// @brief	gets the first string of the queue.
		/// @details	gets the first element of the queue, if it exists.
		/// @returns 	string filename.
		string getFirst(){
			if(this->getLength() > 0){
				return this->q.front();
			}else{
				return "Nothing";
			}
		}
		
		/// @brief	gets the last string of the queue.
		/// @details	gets the last element of the queue, if it exists.
		/// @returns 	string filename.
		string getLast(){
			if(this->getLength() > 0){
				return this->q.back();
			}else{
				return "Nothing";
			}
		}

		/// @brief	gets the last played song from the history queue.
		/// @details	gets the back of the history queue.
		/// @returns 	string filename.
		string getLastPlayed(){
			return this->h.back();
		}

		/// @brief	returns the entire play queue.
		/// @details	returns the ENTIRE play queue.
		/// @returns 	vector of strings, also known as the entire play queue.
		vector<string> getQueue(){
			return this->q;
		}

		/// @brief	returns the entire history queue.
		/// @details	returns the ENTIRE history queue.
		/// @returns 	vector of strings, also known as the entire history queue.
		vector<string> getHistory(){
			return this->h;
		}

		/// @brief	gets the value of looping.
		/// @details	returns true if looping, otherwise false.
		/// @returns 	a boolean of whether the queue is looping.
		bool isLooping(){
			if(this->looping){
				return true;
			}else{
				return false; 
			}
		
		}

		/// @brief	skips the current song.
		/// @details	pops the first element of the play queue.
		void skip(){
			pop_front(this->q);
		}

		/// @brief	toggles looping on the queue.
		/// @details	if the queue isn't looping, loop, otherwise unloop.
		/// @param 	the playQueue to loop
		void loop(songQueue& q){			
			if(this->looping == false){
				//this->r = this->getFirst();
				
				cout <<"Looping: "<< q.getFirst() << "\n";
				this->looping = true;
			}else{
				//this->r = "";
				this->looping = false;
			}
		}

		/// @brief	clears the entire play queue.
		/// @details	pops the front of the play queue until are no elements reamining.
		void clear(){
			
			int j = this->getLength();
			for(int i = 0; i < j; i++){
				cout << "Clearing " << this->getFirst() << " from the queue\n";
				pop_front(this->q);
			} 
			cout << "Queue is empty\n";
		}

		/// @brief	prints every element in the play queue.
		/// @details	prints each element of the queue from fron to back.
		void queueToString(){
			int j = this->getLength();
			cout << "\nPrinting Queue: \n";
			for(string i: this->q){
				cout << i << "\n";	
			} 
			cout << "Done\n\n";

		}
		/// @brief	shuffles the play queue.
		/// @details	creates a new vector and adds each value from q alternating into the new queue, then swaps.
		/// @param	q to shufffle.
		void shuffle(songQueue& q){
		//new vector
			vector<string> temp;
			int i = 1;
			while(q.getLength() > 0){
				if(i%2 == 0){
					temp.push_back(getFirst());
				}else if(i%2 == 1){
					temp.push_back(getLast());
				}
				i++;
			}
			q.setQueue(temp);
		}

		/// @brief	removes a string from the play queue. 
		/// @details	searches for the string in the elements of q and erases it from q if found. 
		/// @param 	file to hunt down, q to remove from
		void remove(string file, songQueue& q){
			if(std::find(q.getQueue().begin(), q.getQueue().end(), file) != q.getQueue().end()) {
    				cout << "Removing: " << file;
				q.getQueue().erase(std::find(q.getQueue().begin(),q.getQueue().end(), file));
			} else {
    				cout << "file not fund.\n";
			}	
		}

};


