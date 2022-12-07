#include <iostream>
#include <Windows.h>
#include <mmsystem.h>
#include <iomanip>
#include <ios>
#include <vector>
#include <filesystem>

#pragma comment(lib, "Winmm.lib")

using namespace std;
namespace fs = std::filesystem;

/*
In order for program to be able to compile, you need to use
Multi-Byte char instead of Wide char.

Project Properties -> Advanced
	-> Character Set option to Use Multi-Byte Character Set



Also to use filesystem, make sure compiler is using at least C++ Version 17

Project Properties -> General -> C++ Language Standard
*/

class Playlist {
private:
	int count = 0;

	void fillwav() {
		for (const auto& entry : filesystem::directory_iterator(PATH)) {
			wav.push_back(entry.path().string());
		}
	}

public:
	vector<string> wav;
	string PATH;

	Playlist() {				// add songs in predetermined directory to vector
		PATH = "songs";
		fillwav();
	}

	Playlist(string userpath) {		// add songs in user defined directory to vector
		PATH = userpath;
		fillwav();
	}

	void setFolder(string userpath) {	// change PATH after initialization
		wav.clear();
		PATH = userpath;
		fillwav();
	}

	void play() {		//	play song

	}

	void pause() {
		// pause song
	}

	void stop() {
		//	 stop song
		PlaySound(NULL, 0, 0);
	}

	void skip() {
		//	skip song
	}

	void prev() {
		//	restart song/go back one song
	}

	void displayFolder() {			
		for (int i = 0; i < wav.size(); i++) {
			cout << wav[i] << endl;
		}
	}

};

class Song : public Playlist {		// for indiv songs

};

void Queue(Playlist p) {
	string base = "open " + p.wav[0] + " type waveaudio alias voice1";
	LPCSTR base2 = base.c_str();

	mciSendString(base2, 0, 0, 0);

	//mciSendString(base, 0&, 0, 0);
	mciSendString("play voice1 wait", 0, 0, 0);
	//Sleep(5000);
	//for (auto &song : p.wav) {}
}


void introGUI() {
	cout << "**********" << endl;
	cout << "Welcome to our project!" << endl;;
	cout << "Reading from the 'songs' folder: " << endl;
	cout << left << setfill('.') << setw(30) << "1 for" << right << setfill('.') << setw(20) << "Displaying the folder" << endl;
	cout << left << setfill('.') << setw(30) << "2 for" << right << setfill('.') << setw(20) << "Playing the queue in order" << endl;
	cout << left << setfill('.') << setw(30) << "3 for" << right << setfill('.') << setw(20) << "Playing the queue in random order" << endl;
	cout << "**********" << endl;
	cout << "For playback controls: " << endl;
	cout << left << setfill('.') << setw(30) << "4 for" << right << setfill('.') << setw(20) << "Pausing the currently playing song" << endl;
	cout << left << setfill('.') << setw(30) << "5 for" << right << setfill('.') << setw(20) << "Resuming the currently playing song" << endl;
	cout << left << setfill('.') << setw(30) << "6 for" << right << setfill('.') << setw(20) << "Skipping to the next song" << endl;
	cout << left << setfill('.') << setw(30) << "7 for" << right << setfill('.') << setw(20) << "Restart the currently playing song" << endl;



}





int main() {
	
	Playlist p("songs");
	//Queue(p);
	
	int choice;
	
	bool loop = true;
	introGUI();
	while (loop) {
		cin >> choice;
		switch (choice) {
		case 1:
			cout << "Displaying the songs within the folder: " << endl;
			p.displayFolder();
			break;
		case 2:
			cout << "Playing the queue in order! " << endl;
			break;
		case 3:
			cout << "Pleaying the queue in random order! " << endl;
			break;
		case 4:
			cout << "Pausing the current playing song! " << endl;
			break;
		case 5:
			cout << "Resuming the current playing song! " << endl;
			break;
		case 6:
			cout << "Skipping to the next song! " << endl;
			break;
		case 7:
			cout << "Restarting the current playing song! " << endl;
			break;

		default:
			cout << "Bad choice! Please try again: " << endl;
			break;
		}

	}
	


	/*
	introGUI();
	PlaySound("songs\\FollowYou.wav", NULL, SND_ASYNC);
	Sleep(5000);
	PlaySound(NULL, 0, 0);
	*/

}