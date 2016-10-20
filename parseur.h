#ifndef PARSEUR_H
#define PARSEUR_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include <algorithm> 
#include <functional> 
#include <cctype>
#include <locale>

typedef struct sQD {
	int r[8][8][8][8];
} QD;

class Parseur {
public:
	Parseur () {
		;
	}

	static inline std::string& ltrim (std::string &s) {
		s.erase (s.begin (), std::find_if (s.begin (), s.end (), std::not1 (std::ptr_fun<int, int> (std::isspace))));
		return s;
	}

	static inline std::string& rtrim (std::string &s) {
		s.erase (std::find_if (s.rbegin (), s.rend (), std::not1 (std::ptr_fun<int, int> (std::isspace))).base (), s.end ());
		return s;
	}

	static inline std::string trim (std::string &s) {
		std::string::const_iterator it = s.begin();
		while (it != s.end() && isspace(*it)) it ++;
		std::string::const_reverse_iterator rit = s.rbegin();
		while (rit.base() != it && isspace(*rit)) rit++;
		return std::string(it, rit.base());
	}

	std::vector<int> ParsingMap (char* fichier, char marqueur=' ') {
		std::ifstream f (fichier);
		if (!f.is_open ())
			std::cout << "Pas d'ouverture" << std::endl;

		std::string str, s_tmp;
		
		std::vector<int> t;

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

				break;
			}
		}
		return t;
	}

	std::string ftos (char* fichier) {
		std::ifstream f (fichier);
		if (!f.is_open ())
			std::cout << "Pas d'ouverture" << std::endl;
		std::string str, sfile;

		while (std::getline (f, str)) {
			sfile += trim(str);
			sfile += '\n';
		} 
		return sfile;
	}

	std::vector<std::string> ParsingString (std::string s, char marqueur) { 
		std::cout << "Analyse de la String : " << s << " selon le marqueur " << marqueur << std::endl;
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

	std::vector<std::vector<std::vector<std::vector<int> > > > ParsingTextures (char* fichier) {
		QD ret;

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
						std::cout << "Dir : " << dir << ", Text : " << text << ", Post : " << pos << ", Coord : " << coor << std::endl;
						r2[dir][text][pos][coor] = std::stoi (stmp);
					}
				}
			}
		}
		return r2;
	}
private:
};

#endif
