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

	~Playlist();

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

	void test() {			// delete before submission
		for (int i = 0; i < wav.size(); i++) {
			cout << wav[i] << endl;
		}
	}

};

class Song : public Playlist {		// for indiv songs

};

void Queue(Playlist p) {
	mciSendString("play FollowYou.wav wait", NULL, 0, 0);

	//for (auto &song : p.wav) {}
}

/*
void introGUI() {
	cout << "**********" << endl;
	cout << "Welcome to our project!" << endl;;
	cout << "Please type in the number of the song you want to play: " << endl;
	cout << left << setfill('.') << setw(30) << "1 for" << right << setfill('.') << setw(20) << "'Follow You' by Imagine Dragons" << endl;
	cout << left << setfill('.') << setw(30) << "2 for" << right << setfill('.') << setw(20) << "'good 4 u' by Olivia Rodrigo" << endl;
	cout << "**********" << endl;
	cout << "For playback controls: " << endl;
	cout << left << setfill('.') << setw(30) << "3 for" << right << setfill('.') << setw(20) << "Stopping the currently playing song" << endl;

}

int choice;

void decision(Playlist p) {
	switch (choice) {
	case 1:
		PlaySound(TEXT("Follow You.wav"), NULL, SND_ASYNC);
		cout << "Playing 'Follow You' by Imagine Dragons!" << endl;
		break;
	case 2:

		PlaySound(TEXT("good 4 u.wav"), NULL, SND_ASYNC);
		cout << "Playing 'good 4 u' by Olivia Rodrigo!" << endl;

		break;
	case 3:
		p.stop();
		cout << "Stopped the song being played!" << endl;
		break;
	default:
		cout << "Bad choice! Please try again: " << endl;
		break;
	}
}
*/

int main() {
	Playlist p("songs");
	p.test();


	/*
	bool loop = true;
	introGUI();
	while (loop) {
		cin >> choice;
		decision();

	}
	*/


	/*
	introGUI();
	PlaySound(TEXT("Follow You.wav"), NULL, SND_ASYNC);
	Sleep(5000);
	PlaySound(NULL, 0, 0);
	*/

}