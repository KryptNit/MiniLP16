// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layer_name {
    _MAKRO,
    _CAL,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT(
        TO(_CAL),                      KC_MUTE, 
        KC_Q,   KC_W,   KC_E,   KC_R,
        KC_A,   KC_S,   KC_D,   KC_F,
        KC_Z,   KC_X,   KC_C,   KC_V,
        KC_Y,   KC_U, KC_I, KC_O
    ),

    [1] = LAYOUT(
        TO(_MAKRO),                      KC_MUTE, 
        KC_P7,   KC_P8,   KC_P9,   KC_PSLS,
        KC_P4,   KC_P5,   KC_P6,   KC_PAST,
        KC_P1,   KC_P2,   KC_P3,   KC_PMNS,
        KC_P0,   KC_PDOT, KC_PENT, KC_PPLS
    )
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] =   { ENCODER_CCW_CW(KC_P1, KC_P2), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [1] =   { ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) }
};
#endif

#ifdef  OLED_ENABLE

bool oled_task_user(void) {
    
    oled_write_P(PSTR("Layer: "), false);

    switch (get_highest_layer(layer_state)) {
        case _MAKRO:
            oled_write_P(PSTR("Based\n"), false);
            break;
        case _CAL:
            oled_write_P(PSTR("Cal\n"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undefined"), false);
    }

    return false;
}

#endif