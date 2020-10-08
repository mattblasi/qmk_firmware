#include QMK_KEYBOARD_H

// layer declarations
enum {
    _BASE = 0,      // base default functions layer
    _LIGHTROOM,     // Lightroom culling and copy past functionality
    _LUMAFUSION_1,  // LumaFusion Set 1
    _LUMAFUSION_2,  // LumaFusion Set 2
    _SAFARI,        // Safari Shortcuts
    _MEDIA,         // Media controls
    _MODS,          // Modifiers
    _STARS,         // Numbers for Lightroom Stars
    _RGB,           // RGB Controls
    _LAYERS         // Layers to select
};

// tap dance declarations
enum {
    TD_SE = 0,      // Single Tap = SPACE  &&  Double Tap = ENTER
    TD_CP,          // Single Tap = PASTE  &&  Double Tap = COPY
    TD_FLAG,        // Tap Dance  1: Flag, 2: Reject, 3: Unflagged
    TD_PUD,         // Single Tap = Page Down  && Double Tap = Page Up
};

// HANDLE KEY TAP
#define TAP_ONCE(code)  \
    register_code (code); \
    unregister_code (code)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* BASE LAYER
    * ,-------------------------------------.
    * |  LEFT      |  MUTE  |  RIGHT        |
    * |------------+--------+---------------|
    * |  CMD       |  TAB   |  DOCK         |
    * |------------+--------+---------------|
    * |  SCRN SHOT |  HOME  |  LAYER SELCT  |
    * `-------------------------------------'
    */
    [_BASE] = LAYOUT_ortho_3x3 (
        KC_LEFT     ,   KC_MUTE     ,   KC_RIGHT,
        KC_LGUI     ,   KC_TAB      ,   LGUI(LALT(KC_D)),
        SGUI(KC_3)  ,   LGUI(KC_H)  ,   OSL(_LAYERS)
    ),

    /* LIGHTROOM LAYER
    * ,----------------------------------------------.
    * |  LEFT       |  INFO          |  RIGHT        |
    * |-------------+----------------+---------------|
    * |  FLAG       |  BEFORE/AFTER  |  STAR RATING  |
    * |-------------+----------------+---------------|
    * |  COPY/PASTE |  ENTER         |               |
    * `----------------------------------------------'
    */
    [_LIGHTROOM] = LAYOUT_ortho_3x3 (
        KC_LEFT     ,   KC_I        ,   KC_RIGHT,
        TD(TD_FLAG) ,   KC_Y        ,   OSL(_STARS),
        TD(TD_CP)   ,   KC_ENTER    ,   KC_TRNS
    ),

    /* LUMAFUSION 1 LAYER
    * ,---------------------------------.
    * |         |           |           |
    * |---------+-----------+-----------|
    * |         |           |           |
    * |---------+-----------+-----------|
    * |         |           |           |
    * `---------------------------------'
    */
    [_LUMAFUSION_1] = LAYOUT_ortho_3x3 (
        KC_LEFT     ,   KC_TRNS     ,   KC_RIGHT,
        KC_TRNS     ,   KC_TRNS     ,   KC_TRNS,
        KC_TRNS     ,   KC_TRNS     ,   KC_TRNS
    ),

    /* LUMAFUSION 2 LAYER
    * ,---------------------------------.
    * |         |           |           |
    * |---------+-----------+-----------|
    * |         |           |           |
    * |---------+-----------+-----------|
    * |         |           |           |
    * `---------------------------------'
    */
    [_LUMAFUSION_2] = LAYOUT_ortho_3x3 (
        KC_LEFT     ,   KC_TRNS     ,   KC_RIGHT,
        KC_TRNS     ,   KC_TRNS     ,   KC_TRNS,
        KC_TRNS     ,   KC_TRNS     ,   KC_TRNS
    ),

    /* SAFARI LAYER
    * ,------------------------------------------.
    * |  BACK        |              |  FORWARD   |
    * |--------------+--------------+------------|
    * |  PREV TAB    |  SPLIT VIEW  |  NEXT TAB  |
    * |--------------+--------------+------------|
    * |  PD UP/DOWN  |              |            |
    * `------------------------------------------'
    */
    [_SAFARI] = LAYOUT_ortho_3x3 (
        LGUI(KC_LBRACKET)   ,   KC_TRNS     ,   LGUI(KC_RBRACKET),
        LCTL(LSFT(KC_TAB))  ,   LGUI(KC_N)  ,   LCTL(KC_TAB),
        TD(TD_PUD)          ,   KC_TRNS     ,   KC_TRNS
    ),

    /* MEDIA LAYER
    * ,---------------------------------.
    * |         |           |           |
    * |---------+-----------+-----------|
    * |         |           |           |
    * |---------+-----------+-----------|
    * |         |           |           |
    * `---------------------------------'
    */
    [_MEDIA] = LAYOUT_ortho_3x3 (
        KC_LEFT     ,   KC_TRNS     ,   KC_RIGHT,
        KC_TRNS     ,   KC_TRNS     ,   KC_TRNS,
        KC_TRNS     ,   KC_TRNS     ,   KC_TRNS
    ),

    /* MODIFIER KEYS LAYER
    * ,---------------------------------.
    * |         |           |           |
    * |---------+-----------+-----------|
    * |         |           |           |
    * |---------+-----------+-----------|
    * |         |           |           |
    * `---------------------------------'
    */
    [_MODS] = LAYOUT_ortho_3x3 (
        KC_LGUI     ,   KC_TRNS     ,   KC_LCTRL,
        KC_LSHIFT   ,   KC_TAB      ,   KC_TRNS,
        KC_TRNS     ,   KC_TRNS     ,   KC_TRNS
    ),

    /* NUMBERS LAYER FOR LIGHTROOM STARS
    * ,-----------------.
    * |  1  |     |  0  |
    * |-----+-----+-----|
    * |  2  |  3  |  4  |
    * |-----+-----+-----|
    * |  5  |     |     |
    * `-----------------'
    */
    [_STARS] = LAYOUT_ortho_3x3 (
        KC_1        ,   KC_TRNS     ,   KC_0,
        KC_2        ,   KC_3        ,   KC_4,
        KC_5        ,   KC_TRNS     ,   KC_TRNS
    ),

    /* RGB CONTROL LAYER
    * ,------------------------------.
    * |  MODE+ |  RGB TOG  |  MODE-  |
    * |--------+-----------+---------|
    * |  SPD-  |  SPD+     |  Bright |
    * |--------+-----------+---------|
    * |  SAT+  |  SAT-     |         |
    * `------------------------------'
    */
    [_RGB] = LAYOUT_ortho_3x3 (
        RGB_MOD     ,   RGB_TOG     ,   RGB_RMOD,
        RGB_SPI     ,   RGB_SPD     ,   RGB_VAI,
        RGB_SAI     ,   RGB_SAD     ,   KC_TRNS
    ),

    /* LAYER SELECT
    * ,-----------------------------------------------.
    * |  BASE       |                |  MEDIA         |
    * |-------------+----------------+----------------|
    * |  LIGHTROOM  |  LUMAFUSION 1  |  LUMAFUSION 2  |
    * |-------------+----------------+----------------|
    * |  SAFARI     |  RGB           |                |
    * `-----------------------------------------------'
    */
    [_LAYERS] = LAYOUT_ortho_3x3 (
        TO(_BASE)       ,   KC_TRNS             ,   TO(_MEDIA),
        TO(_LIGHTROOM)  ,   TO(_LUMAFUSION_1)   ,   TO(_LUMAFUSION_2),
        TO(_SAFARI)     ,   TO(_RGB)            ,   KC_TRNS
    ),
};


// TAP DANCE FUNCTIONS
void lightroomFlag(qk_tap_dance_state_t *state, void *user_data) {
    switch(state->count) {
    case 1:
        TAP_ONCE(KC_P);
        break;
    case 2:
        TAP_ONCE(KC_X);
        break;
    default:
        TAP_ONCE(KC_U);
        break;
    }
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_SE]  = ACTION_TAP_DANCE_DOUBLE(KC_SPACE, KC_ENTER),
    [TD_CP]  = ACTION_TAP_DANCE_DOUBLE(LGUI(KC_V), LGUI(KC_C)),
    [TD_FLAG]= ACTION_TAP_DANCE_FN(lightroomFlag),
    [TD_PUD] = ACTION_TAP_DANCE_DOUBLE(KC_SPACE, LSFT(KC_SPACE)),
};

// LAYER STATE FOR RGB COLOR
layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
    case _BASE:
        rgblight_setrgb_blue();
        break;
    case _LIGHTROOM:
        rgblight_setrgb_purple();
        break;
    case _LUMAFUSION_1:
        rgblight_setrgb_teal();
        break;
    case _LUMAFUSION_2:
        rgblight_setrgb_orange();
        break;
    case _MEDIA:
        rgblight_setrgb_green();
        break;
    case _MODS:
        rgblight_setrgb_chartreuse();
        break;
    case _STARS:
        rgblight_setrgb_coral();
        break;
    case _RGB:
        rgblight_setrgb_red();
        break;
    case _LAYERS:
        rgblight_setrgb_white();
        break;
    default:
        rgblight_setrgb_blue();
        break;
    }
    return state;
}

// ENCODER FUNCTION BASED ON LAYER
void encoder_update_user(uint8_t index, bool clockwise) {
    switch (biton32(layer_state)) {
    case _RGB:
        if (clockwise) {
            rgblight_increase_hue();
        } else {
            rgblight_decrease_hue();
        }
        break;
    case _MEDIA:
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
        break;
    default:
        if (clockwise) {
            tap_code(KC_DOWN);
        } else {
            tap_code(KC_UP);
        }
        break;

    }
}
