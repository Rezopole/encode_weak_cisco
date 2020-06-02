// {
//
//  encode_weak_cisco, encodes passphrase like the old "7" weak and reversible cisco crypto algorithm 
//  Copyright (C) 2016-2020 Jean-Daniel Pauget <jdpauget@rezopole.net>
//  
//  This program is free software; you can redistribute it and/or
//  modify it under the terms of the GNU General Public License
//  as published by the Free Software Foundation; either version 2
//  of the License, or (at your option) any later version.
//  
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//  
//  You should have received a copy of the GNU General Public License
//  along with this program; if not, write to the Free Software
//  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
//
// }


#include <time.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

#include "config.h"

using namespace std;

string encrypt (const string &s, int salt) {
    string cisco_const = "dsfd;kfoA,.iyewrkldJKDHSUBsgvca69834ncxv9873254k;fg87";

    stringstream o;

    o << setw (2) << setfill ('0') << salt ;

    for (size_t i=0 ; i<s.size() ; i++) {
	int j = (i+salt) % 53;
	int cc = ((int)s[i]) ^ (int)cisco_const[j];
	o << setw (2) << setfill ('0') << setbase(16) << uppercase << cc;
    }

    return o.str();
}

int main (int nb, char ** cmde) {

    srand(time(NULL));   // Initialization, should only be called once.

    int salt = -1;
    bool nomoreparam = false;

    for (int i=1 ; i<nb ; i++) {
	if (nomoreparam || (cmde[i][0] != '-')) {
	    cout << encrypt (cmde[i], (salt==-1) ? rand()%16 : salt) << endl;
	} else {
	    if (strncmp("--salt=", cmde[i], 7) == 0) {
		salt = atoi (cmde[i]+7) % 16;
	    } else if ((strcmp ("-h", cmde[i]) ==0) || (strncmp("--help", cmde[i], 6) == 0)) {
		cerr << cmde[0] << " : encodes passphrases using weak reversible cisco algorithm" << endl
		     << "       version " << ENCODE_WEAK_CISCO_VERSION << endl
		     << "       " << cmde[0] << " [ --salt=SALT ] [ --help ] [ -- ] ... passphrases ..." << endl
		    ;
		exit (0);
	    } else if (strcmp ("--", cmde[i]) == 0) {
		nomoreparam = true;
	    } else {
		cerr << cmde[0] << " : error, unknown parameter \"" << cmde[i] << "\"" << endl;
		exit (1);
	    }
	}
    }

    return 0;
}
