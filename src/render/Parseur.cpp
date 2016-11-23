#include "../render.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include <algorithm> 
#include <functional> 
#include <cctype>
#include <locale>

using namespace render;

typedef struct sQD {
	int r[8][8][8][8];
} QD;

	inline std::string Parseur::trim (std::string &s) {
		std::string::const_iterator it = s.begin();
		while (it != s.end() && isspace(*it)) it ++;
		std::string::const_reverse_iterator rit = s.rbegin();
		while (rit.base() != it && isspace(*rit)) rit++;
		return std::string(it, rit.base());
	}

	std::vector<int> Parseur::ParsingMap (char* fichier) {
		std::ifstream f (fichier);
		if (!f.is_open ())
			std::cout << "Parseur::ParsingMap : Pas d'ouverture (" << fichier << ")" << std::endl;

		std::string str, s_tmp;
		
		std::vector<int> t;
		char marqueur = ' ';
		
		while (std::getline (f, str)) {
			if (str[0] == '#')
				continue;
			for (int i = 0; i < str.size (); i++) {
				if (str[i] != marqueur) {
					s_tmp += str[i];
				}
				else {
					s_tmp = trim (s_tmp);

					if (s_tmp.size () > 0) {
						t.push_back (std::stoi (s_tmp));
						s_tmp.clear ();
					}
				}
			}
			if (s_tmp.size () > 0) {
				s_tmp = trim (s_tmp);
				t.push_back (std::stoi (s_tmp));
			}
		} 
		return t;
	}

	std::string Parseur::ftos (char* fichier) {
		std::ifstream f (fichier);
		if (!f.is_open ())
			std::cout << "Pas d'ouverture" << std::endl;
		std::string str, sfile;

		while (std::getline (f, str)) {
			if (str[0] == '#')
				continue;
				
			sfile += trim(str);
			sfile += '\n';
		} 
		return sfile;
	}

	std::vector<std::string> Parseur::ParsingString (std::string s, char marqueur) { 
		std::string s_tmp;

		std::vector<std::string> t; 
		for (int i = 0; i < s.length(); i++) {
			if (s[i] != marqueur) {
				s_tmp += s[i];
			}
			else {
				s_tmp = trim (s_tmp);

				if (s_tmp.size () > 0) {
					t.push_back (s_tmp);
					s_tmp.clear ();
				}
			}
		}
		if (s_tmp.size () > 0) {
			s_tmp = trim (s_tmp);
			t.push_back (s_tmp);
		}
		return t;
	}

	std::vector<std::vector<std::vector<std::vector<int> > > > Parseur::ParsingTextures (char* fichier) {
		std::vector<std::vector<std::vector<std::vector<int> > > > r2;
		std::vector<std::string> decoupe_direction;
		std::vector<std::string> decoupe_texture;
		std::vector<std::string> decoupe_position;
		std::vector<std::string> decoupe_coordonnees;

		std::string tdir, ttext, tpos, tcoord, stmp;
		std::string f;

		f = ftos (fichier);
		decoupe_direction = ParsingString (f, '\n');
		for (int dir = 0; dir < decoupe_direction.size (); dir++) {
			r2.resize (r2.size () + 1);

			tdir = decoupe_direction[dir];
			decoupe_texture = ParsingString (tdir, '/');

			for (int text = 0; text < decoupe_texture.size (); text++) {
				(r2[dir]).resize ((r2[dir]).size () + 1);

				ttext = decoupe_texture[text];
				decoupe_position = ParsingString (ttext, ',');

				for (int pos = 0; pos < decoupe_position.size (); pos++) {
					(r2[dir][text]).resize ((r2[dir][text]).size () + 1);

					tcoord = decoupe_position[pos];
					decoupe_coordonnees = ParsingString (tcoord, ' ');

					for (int coor = 0; coor < decoupe_coordonnees.size (); coor++) {
						(r2[dir][text][pos]).resize ((r2[dir][text][pos]).size () + 1);
						stmp = trim (decoupe_coordonnees[coor]); 
						r2[dir][text][pos][coor] = std::stoi (stmp);
					}
				}
			}
		}
		return r2;
	}
