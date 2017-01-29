/*
 This project is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.

 Deviation is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with Deviation.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdlib.h>
#include <string.h>
#include "common.h"
#include "model.h"
#include "../music.h"

#if HAS_EXTENDED_AUDIO

void CONFIG_AlertParse(const char* filename)
{
    FILE *file;
    char *pt;
    int textlen;
    int val;
    u32 j,k = 0;
    char line[MAX_MUSICMAP_ENTRIES];

    file = fopen(filename, "r");
    if (!file) {
	printf("Can't open alert file: %s\n", filename);
        return;
    }

    while (fgets(line, sizeof(line), file) != NULL) {
        j=0;
        textlen = strlen(line);
        // strip LF or CRLF
        if (line[textlen-1] == '\n') {
            line[--textlen] = '\0';
            if ((textlen > 0) && (line[textlen-1] == '\r'))
                line[--textlen] = '\0';
        }
/* removed to fit on devo7e, and since trailing spaces are just part of the label we don't need stripping them
        // strip trailing spaces
        while ((textlen > 0) && ((line[textlen-1] == ' ') || (line[textlen-1] == '\t')))
            line[--textlen] = '\0';
*/
        // Ignore comments or empty lines
        if ((line[0] == '\0') || (line[0] == ';'))
            continue;
        pt = strtok(line,":");
        while(pt != NULL) {
            j++;
            val = atoi(pt);
            switch (j) {
              case 2: music_map[k].music = val;
              case 3: music_map[k].duration = val;
#if HAS_MUSIC_CONFIG
              case 4: strcpy(music_map[k].label,pt);
#endif
            }
            pt = strtok(NULL, ":");
        }
        k++;
    }
    fclose(file);
}
#endif
