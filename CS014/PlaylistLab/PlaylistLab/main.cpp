//
//  main.cpp
//  PlaylistLab
//
//  Created by Aramis Masarati on 1/8/20.
//  Copyright © 2020 Aramis Masarati. All rights reserved.
//

#include <iostream>
#include "Playlist.h"

using namespace std;

void PrintMenu (string title);

int main() {
    string title;
    cout << "Enter playlist's title:" << endl;
    getline(cin,title);
    cout << endl;
    PrintMenu(title);
    return 0;
}

void PrintMenu (string title) {
    char response;
    Playlist song;
    while (response != 'q') {
        cout << title << " PLAYLIST MENU" << endl;
        cout << "a - Add song" << endl;
        cout << "d - Remove song" << endl;
        cout << "c - Change position of song" << endl;
        cout << "s - Output songs by specific artist" << endl;
        cout << "t - Output total time of playlist (in seconds)" << endl;
        cout << "o - Output full playlist" << endl;
        cout << "q - Quit" << endl;
        cout << endl << "Choose an option:";
        cin >> response;
        cout << endl;
        if (response == 'a') {
            string id, sn, an;
            int sl;
            cout << "ADD SONG" << endl;
            cout << "Enter song's unique ID:" << endl;
            cin >> id;
            cout << "Enter song's name:" << endl;
            cin.ignore();
            getline(cin, sn);
            cout << "Enter artist's name:" << endl;
            getline(cin, an);
            cout << "Enter song's length (in seconds):" << endl;
            cin >> sl;
            PlaylistNode* temp = new PlaylistNode(id,sn,an,sl);
            song.AddSong(temp);
            cout << endl;
        }
        if (response == 'd') {
            string id;
            cout << "REMOVE SONG" << endl;
            cout << "Enter song's unique ID:" << endl;
            cin >> id;
            song.DisplaySong(id);
            song.RemoveSong(id);
            cout << endl;
        }
        if (response == 'c') {
            int old, n;
            cout << "CHANGE POSITION OF SONG" << endl;
            cout << "Enter song's current position:" << endl;
            cin >> old;
            cout << "Enter new position for song:" << endl;
            cin >> n;
            song.ChangePosition(old, n);
        }
        if (response == 's') {
            string an;
            cout << "OUTPUT SONGS BY SPECIFIC ARTIST" << endl;
            cout << "Enter artist's name:" << endl;
            cin.ignore();
            getline(cin, an);
            cout << endl;
            song.PrintArtist(an);
        }
        if (response == 't') {
            cout << "OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)" << endl;
            song.PrintLength();
            cout << endl;
        }
        if (response == 'o') {
            cout << title << " - OUTPUT FULL PLAYLIST" << endl;
            song.PrintPlaylist();
        }
    }
}
