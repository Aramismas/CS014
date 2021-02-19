//
//  Playlist.hpp
//  PlaylistLab
//
//  Created by Aramis Masarati on 1/8/20.
//  Copyright © 2020 Aramis Masarati. All rights reserved.
//

#ifndef Playlist_h
#define Playlist_h

//#include <stdio.h>
using namespace std;
#include <string>

class PlaylistNode {
    private:
        string uniqueID;
        string songName;
        string artistName;
        int songLength;
        PlaylistNode* nextNodePtr;
    public:
        PlaylistNode();
        PlaylistNode(string id, string sn, string an, int sl);
        void InsertAfter(PlaylistNode* temp);
        void SetNext(PlaylistNode* temp);
        string GetID();
        string GetSongName();
        string GetArtistName();
        int GetSongLength();
        PlaylistNode* GetNext();
        void PrintPlaylistNode();
};

class Playlist {
    private:
        PlaylistNode* head;
        PlaylistNode* tail;
    public:
        Playlist();
        void AddSong(PlaylistNode* temp);
        void RemoveSong(string id);
        void ChangePosition(int old, int n);
        void PrintPlaylist();
        void PrintArtist(string a);
        void PrintLength();
	void DisplaySong(string id);
};

#endif /* Playlist_h */
