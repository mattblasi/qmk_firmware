#include QMK_KEYBOARD_H
#define TAPPING_TERM 200

enum custom_keycodes {
    S_ZELDA = SAFE_RANGE,
    S_IMPERIAL,
    M_PAGEDOWN,
    M_PAGEUP
};

#ifdef AUDIO_ENABLE
    float song_zelda[][2] = SONG(ZELDA);
    float song_imperial[][2] = SONG(STAR_WARS);
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT_planck_1x2uC(
            KC_GESC, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC,
            KC_TAB, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_ENT,
            KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_UP, KC_SLSH,
            MO(3), KC_LCTL, KC_LALT, KC_LGUI, M_PAGEDOWN, KC_SPC, M_PAGEUP, KC_QUOT, KC_LEFT, KC_DOWN, KC_RGHT
        ),
	[1] = LAYOUT_planck_1x2uC(
            KC_GESC, KC_LBRC, KC_RBRC, KC_LT, KC_GT, KC_PSLS, KC_PAST, KC_7, KC_8, KC_9, KC_UNDS, KC_BSPC,
            KC_TAB, KC_LCBR, KC_RCBR, KC_LPRN, KC_RPRN, KC_PMNS, KC_PPLS, KC_4, KC_5, KC_6, KC_AT, KC_ENT,
            KC_LSFT, KC_HASH, KC_DLR, KC_PERC, KC_AMPR, KC_EXLM, KC_PIPE, KC_1, KC_2, KC_3, KC_PGUP, KC_BSLS,
            LCTL(LGUI(KC_Q)), KC_LCTL, KC_LALT, KC_LGUI, KC_TRNS, KC_SPC, KC_0, KC_GRV, KC_PEQL, KC_PGDN, KC_CIRC
        ),
	[2] = LAYOUT_planck_1x2uC(
            KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12,
            KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC__MUTE, KC_NO,
            KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC__VOLUP, KC_BRMU,
            LCTL(LGUI(KC_Q)), LCTL(KC_GRV), KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, KC__VOLDOWN, KC_BRMD
        ),
	[3] = LAYOUT_planck_1x2uC(
            LCTL(LGUI(KC_Q)), LSFT(LGUI(KC_A)), LSFT(LGUI(KC_D)), LSFT(LGUI(KC_U)), LSFT(LGUI(KC_H)), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
            LSFT(LGUI(KC_3)), LSFT(LGUI(KC_4)), LGUI(KC_H), LALT(LGUI(KC_H)), LSFT(LGUI(KC_G)), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
            S_ZELDA, S_IMPERIAL, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
            KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
        )
};

// Custom keycodes for playing songs on keypress.
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint16_t my_key_timer;

    switch (keycode) {
        case S_ZELDA:
            if (record->event.pressed) {
                stop_all_notes();
                PLAY_SONG(song_zelda);
            }
            return false;

        case S_IMPERIAL:
            if (record->event.pressed) {
                stop_all_notes();
                PLAY_SONG(song_imperial);
            }
            return false;

        // on tap trigger page down, on hold is layer key
        case M_PAGEDOWN:
            if(record->event.pressed) {
                my_key_timer = timer_read();
                layer_on(1); // Change the key to be held here
            } else {
                layer_off(1); // Change the key that was held here, too!
                if (timer_elapsed(my_key_timer) < TAPPING_TERM) {
                    tap_code(KC_PGDOWN); // Change the character(s) to be sent on tap here
                }
            }
            return false;

        // on tap trigger page up, on hold is layer key
        case M_PAGEUP: //
            if(record->event.pressed) {
                my_key_timer = timer_read();
                layer_on(2); // Change the key to be held here
            } else {
                layer_off(2); // Change the key that was held here, too!
                if (timer_elapsed(my_key_timer) < TAPPING_TERM) {
                    tap_code(KC_PGUP);  // Change the character(s) to be sent on tap here
                }
            }
            return false;
    }
    return true;
}
