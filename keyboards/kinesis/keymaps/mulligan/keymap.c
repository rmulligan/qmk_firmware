#include QMK_KEYBOARD_H

#define QWERTY 0 // Base qwerty
#include "version.h"
#include "keymap_steno.h"

enum layer_names { _DVORAK, _KEYPAD, _PROGRAM, _PLOVER };
enum my_keycodes { DVORAK = SAFE_RANGE, STATUS, PROGRAM, PLOVER, EXT_PLV, PASS };

void eeconfig_init_user() {
    steno_set_mode(STENO_MODE_GEMINI); // or STENO_MODE_BOLT
}

/****************************************************************************************************
 *
 * Keymap: Default Layer in Qwerty
 *
 * ,-------------------------------------------------------------------------------------------------------------------.
 * | Esc    |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F8  |  F9  |  F10 |  F12 | PSCR | SLCK | PAUS |  FN0 |  BOOT  |
 * |--------+------+------+------+------+------+---------------------------+------+------+------+------+------+--------|
 * | =+     |  1!  |  2@  |  3#  |  4$  |  5%  |                           |  6^  |  7&  |  8*  |  9(  |  0)  | -_     |
 * |--------+------+------+------+------+------|                           +------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |                           |   Y  |   U  |   I  |   O  |   P  | \|     |
 * |--------+------+------+------+------+------|                           |------+------+------+------+------+--------|
 * | Caps   |   A  |   S  |   D  |   F  |   G  |                           |   H  |   J  |   K  |   L  |  ;:  | '"     |
 * |--------+------+------+------+------+------|                           |------+------+------+------+------+--------|
 * | Shift  |   Z  |   X  |   C  |   V  |   B  |                           |   N  |   M  |  ,.  |  .>  |  /?  | Shift  |
 * `--------+------+------+------+------+-------                           `------+------+------+------+------+--------'
 *          | `~   | INS  | Left | Right|                                         | Up   | Down |  [{  |  ]}  |
 *          `---------------------------'                                         `---------------------------'
 *                                        ,-------------.         ,-------------.
 *                                        | Ctrl | Alt  |         | Gui  | Ctrl |
 *                                 ,------|------|------|         |------+------+------.
 *                                 |      |      | Home |         | PgUp |      |      |
 *                                 | BkSp | Del  |------|         |------|Return| Space|
 *                                 |      |      | End  |         | PgDn |      |      |
 *                                 `--------------------'         `--------------------'
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_DVORAK] = LAYOUT(
        // Left Hand
        DYN_REC_START1, DYN_REC_START2, DYN_REC_STOP, DYN_MACRO_PLAY1, DYN_MACRO_PLAY2, KC_F5, KC_F6, KC_F7, KC_F8, KC_EQL, KC_1, KC_2, KC_3, KC_4, KC_5, KC_TAB, KC_QUOT, KC_COMM, KC_DOT, KC_P, KC_Y, KC_ESC, KC_A, KC_O, KC_E, KC_U, KC_I, KC_LSPO, KC_SCLN, KC_Q, KC_J, KC_K, KC_X, KC_GRV, KC_NUBS, KC_LEFT, KC_RGHT,
        // Left Thumb
        KC_DEL, KC_LALT, KC_LALT, KC_BSPC, KC_LCTL, KC_LGUI,

        // Right Hand
        KC_F9, KC_F10, KC_F11, KC_F12, KC_PSCR, KC_SLCK, KC_PAUS, TG(_KEYPAD), MO(_PROGRAM), KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_F, KC_G, KC_C, KC_R, KC_L, KC_SLSH, KC_D, KC_H, KC_T, KC_N, KC_S, KC_BSLS, KC_B, KC_M, KC_W, KC_V, KC_Z, KC_RSPC, KC_UP, KC_DOWN, KC_LBRC, KC_RBRC,
        // Right Thumb
        PLOVER, KC_TAB, KC_PGUP, KC_PGDN, KC_ENT, KC_SPC),

    [_PLOVER] = LAYOUT(
        // Left Hand
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, STN_N1, STN_N2, STN_N3, STN_N4, STN_N5, STN_FN, STN_S1, STN_TL, STN_PL, STN_HL, STN_ST1, _______, STN_S2, STN_KL, STN_WL, STN_RL, STN_ST2, EXT_PLV, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        // Left Thumb
        _______, _______, _______, STN_A, STN_O, _______,

        // Right Hand
        _______, _______, _______, _______, _______, _______, _______, _______, _______, STN_N6, STN_N7, STN_N8, STN_N9, STN_NA, _______, STN_ST3, STN_FR, STN_PR, STN_LR, STN_TR, STN_DR, STN_ST4, STN_RR, STN_BR, STN_GR, STN_SR, STN_ZR, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        // Right Thumb
        STN_RE1, STN_RE2, _______, _______, STN_E, STN_U),

    [_KEYPAD] = LAYOUT(
        // Left Hand
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_INS, _______, _______,
        // Left Thumb
        _______, _______, _______, _______, _______, _______,

        // Right Hand
        _______, _______, _______, _______, KC__MUTE, KC__VOLDOWN, KC__VOLUP, _______, _______, _______, KC_NLCK, KC_PEQL, KC_PSLS, KC_PAST, _______, _______, KC_P7, KC_P8, KC_P9, KC_PMNS, _______, _______, KC_P4, KC_P5, KC_P6, KC_PPLS, _______, _______, KC_P1, KC_P2, KC_P3, KC_PENT, _______, _______, _______, KC_PDOT, KC_PENT,
        // Right Thumb
        _______, _______, _______, _______, _______, KC_P0),

    [_PROGRAM] = LAYOUT(
        // Left Hand
        STATUS, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        // Left Thumb
        _______, _______, _______, _______, _______, _______,

        // Right Hand
        RESET, _______, _______, _______, _______, _______, _______, _______, PASS, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        // Right Thumb
        _______, _______, _______, _______, _______, _______)

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case DVORAK:
                set_single_persistent_default_layer(_DVORAK);
                return false;
            case PLOVER:
                layer_on(_PLOVER);
                return false;
            case EXT_PLV:
                layer_off(_PLOVER);
                return false;
            case PASS:
                SEND_STRING("S100680r073083J071617c041819");
                return false;
            case STATUS:
                SEND_STRING("Firmware> QMK " QMK_VERSION ", " QMK_BUILDDATE "\n");
                SEND_STRING("Keyboard> " QMK_KEYBOARD "\n");
                SEND_STRING("Keymap> " QMK_KEYMAP "\n");

                if (keymap_config.nkro)
                    SEND_STRING("NKRO> Enabled\n");
                else
                    SEND_STRING("NKRO> Disabled\n");

                if (debug_enable)
                    SEND_STRING("Debug> Enabled\n");
                else
                    SEND_STRING("Debug> Disabled\n");

                return false;
        }
    }

    return true;
}
