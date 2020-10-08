#ifndef CONFIG_USER_H
    #define CONFIG_USER_H

    #include "../../config.h"

    /*
    * Strartup Song Change
    */
    #ifdef AUDIO_ENABLE

        #undef TEMPO_DEFAULT
        #define TEMPO_DEFAULT 200

        #undef MUSICAL_NOTE
        #define MUSICAL_NOTE(note, duration) \
            { (NOTE##note), duration * 4 }

        #define NOTE_R 0

        #define STAR_WARS \
        Q__NOTE(_A4), Q__NOTE(_A4), Q__NOTE(_A4), ED_NOTE(_F4), S__NOTE(_C5), \
        Q__NOTE(_A4), ED_NOTE(_F4), S__NOTE(_C5), H__NOTE(_A4), \
        Q__NOTE(_E5), Q__NOTE(_E5), Q__NOTE(_E5), ED_NOTE(_F5), S__NOTE(_C5), \
        Q__NOTE(_A4), ED_NOTE(_F4), S__NOTE(_C5), H__NOTE(_A4), \
        Q__NOTE(_A5), ED_NOTE(_A4), S__NOTE(_A4), Q__NOTE(_A5), ED_NOTE(_GS5), S__NOTE(_G5), \
        S__NOTE(_DS5), S__NOTE(_D5), E__NOTE(_DS5), E__NOTE(_R), E__NOTE(_A4), Q__NOTE(_DS5), ED_NOTE(_D5), S__NOTE(_CS5), \
        S__NOTE(_C5), S__NOTE(_B4), S__NOTE(_C5), E__NOTE(_R), E__NOTE(_F4), Q__NOTE(_GS4), ED_NOTE(_F4), SD_NOTE(_A4), \
        Q__NOTE(_C5), ED_NOTE(_A4), S__NOTE(_C5), H__NOTE(_E5), \
        Q__NOTE(_A5), ED_NOTE(_A4), S__NOTE(_A4), Q__NOTE(_A5), ED_NOTE(_GS5), S__NOTE(_G5), \
        S__NOTE(_DS5), S__NOTE(_D5), E__NOTE(_DS5), E__NOTE(_R), E__NOTE(_A4), Q__NOTE(_DS5), ED_NOTE(_D5), S__NOTE(_CS5), \
        S__NOTE(_C5), S__NOTE(_B4), S__NOTE(_C5), E__NOTE(_R), E__NOTE(_F4), Q__NOTE(_GS4), ED_NOTE(_F4), SD_NOTE(_A4), \
        Q__NOTE(_A4), ED_NOTE(_F4), S__NOTE(_C5), H__NOTE(_A4),

        #define ZELDA \
        HD_NOTE(_AS4), E__NOTE(_F4), E__NOTE(_F4), E__NOTE(_AS4), \
        S__NOTE(_GS4), S__NOTE(_FS4), HD_NOTE(_GS4), \
        HD_NOTE(_AS4), E__NOTE(_FS4), E__NOTE(_FS4), E__NOTE(_AS4), \
        S__NOTE(_A4), S__NOTE(_G4), HD_NOTE(_A4), \
        W__NOTE(_R), \
        Q__NOTE(_AS4), QD_NOTE(_F4), E__NOTE(_AS4), S__NOTE(_AS4), S__NOTE(_C5), S__NOTE(_D5), S__NOTE(_DS5),  \
        H__NOTE(_F5), E__NOTE(_F5), E__NOTE(_F5), E__NOTE(_F5), S__NOTE(_FS5), S__NOTE(_GS5), \
        HD_NOTE(_AS5), E__NOTE(_AS5), E__NOTE(_AS5), E__NOTE(_GS5), S__NOTE(_FS5), \
        ED_NOTE(_GS5), S__NOTE(_FS5), H__NOTE(_F5), Q__NOTE(_F5), \
        ED_NOTE(_DS5), S__NOTE(_F5), H__NOTE(_FS5), E__NOTE(_F5), E__NOTE(_DS5), \
        ED_NOTE(_CS5), S__NOTE(_DS5), H__NOTE(_F5), E__NOTE(_DS5), E__NOTE(_CS5), \
        ED_NOTE(_C5), S__NOTE(_D5), H__NOTE(_E5), E__NOTE(_G5), \
        S__NOTE(_F5), S__NOTE(_F4), S__NOTE(_F4), S__NOTE(_F4), S__NOTE(_F4), S__NOTE(_F4), S__NOTE(_F4), S__NOTE(_F4), E__NOTE(_F4), S__NOTE(_F4), E__NOTE(_F4), \
        Q__NOTE(_AS4), QD_NOTE(_F4), E__NOTE(_AS4), S__NOTE(_AS4), S__NOTE(_C5), S__NOTE(_D5), S__NOTE(_DS5), \
        H__NOTE(_F5), E__NOTE(_F5), E__NOTE(_F5), E__NOTE(_F5), S__NOTE(_FS5), S__NOTE(_CS5), \
        HD_NOTE(_AS5), Q__NOTE(_CS6), \
        Q__NOTE(_C6), H__NOTE(_A5), Q__NOTE(_F5), \
        HD_NOTE(_FS5), Q__NOTE(_AS5), \
        Q__NOTE(_A5), H__NOTE(_F5), Q__NOTE(_F5), \
        HD_NOTE(_FS5), Q__NOTE(_AS5), \
        Q__NOTE(_A5), H__NOTE(_F5), Q__NOTE(_D5), \
        HD_NOTE(_DS5), Q__NOTE(_FS5), \
        Q__NOTE(_F5), H__NOTE(_CS5), Q__NOTE(_AS4), \
        ED_NOTE(_C5), S__NOTE(_D5), H__NOTE(_E5), E__NOTE(_G5), \
        S__NOTE(_F5), S__NOTE(_F4), S__NOTE(_F4), S__NOTE(_F4), S__NOTE(_F4), S__NOTE(_F4), S__NOTE(_F4), S__NOTE(_F4), E__NOTE(_F4), S__NOTE(_F4), E__NOTE(_F4), \

        //#define STARTUP_SONG SONG(ZELDA)
    #endif


#endif
