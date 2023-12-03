// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
#include "raw_hid.h"
#include "quantum.h"
led_config_t g_led_config = { {
  // Key Matrix to LED Index
  { NO_LED, NO_LED, NO_LED, NO_LED },
  { NO_LED, NO_LED, NO_LED},
  { NO_LED, NO_LED, NO_LED, NO_LED },
  { NO_LED, NO_LED, 0, NO_LED },
  { NO_LED, NO_LED, NO_LED, NO_LED },
}, {
  // LED Index to Physical Position
    { 112, 32}
}, {
  // LED Index to Flag
  4
} };

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┐
     * │Num│ / │ * │ - │
     * ├───┼───┼───┼───┤
     * │ 7 │ 8 │ 9 │   │
     * ├───┼───┼───┤ + │
     * │ 4 │ 5 │ 6 │   │
     * ├───┼───┼───┼───┤
     * │ 1 │ 2 │ 3 │   │
     * ├───┴───┼───┤Ent│
     * │   0   │ . │   │
     * └───────┴───┴───┘
     */
    [0] = LAYOUT_numpad_5x4(
        KC_NUM,   KC_PSLS, KC_PAST, KC_PMNS,
        KC_P7,   KC_P8,   KC_P9,
        KC_P4,   KC_P5,   KC_P6,   KC_PPLS,
        KC_P1,   KC_P2,   KC_P3,
        KC_P0,   KC_PDOT,          KC_PENT
    )

};
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    const int led_index = 0;
    bool num_lock_active = host_keyboard_led_state().num_lock;
    switch(get_highest_layer(layer_state)) {
        case 0:
        case 1:

             if (num_lock_active) {
                rgb_matrix_set_color(led_index, RGB_BLUE); // Cambia a turquesa si el bloqueo numérico está activado
            } else {
                rgb_matrix_set_color(led_index, RGB_CYAN); // Mantiene el color cian si el bloqueo numérico está desactivado
            }
            break;

        case 2:
            rgb_matrix_set_color(led_index, RGB_GOLD);
            break;
        case 3:
            rgb_matrix_set_color(led_index, RGB_GREEN);
            break;
        case 4:
            rgb_matrix_set_color(led_index, RGB_PURPLE);
            break;
        case 5:
            rgb_matrix_set_color(led_index, RGB_MAGENTA);
            break;
        case 6:
            rgb_matrix_set_color(led_index, RGB_AZURE);
            break;
        case 7:
            rgb_matrix_set_color(led_index, RGB_RED);
            break;
        default:
            break;

    }
        return true;
}
