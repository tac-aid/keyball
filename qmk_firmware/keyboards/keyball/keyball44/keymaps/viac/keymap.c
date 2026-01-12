/*
Copyright 2022 @Yowkees
Copyright 2022 MURAOKA Taro (aka KoRoN, @kaoriya)

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

#include "quantum.h"

enum custom_keycodes {
  USER_0 = SAFE_RANGE, 
  USER_1,
  USER_2,
  USER_3,
  USER_4,
  USER_5,
  USER_6,
  SCROLL,
  H_SCROLL,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // keymap for default (VIA)
  [0] = LAYOUT_universal(
    KC_TAB         , KC_Q   , KC_L   , KC_U           , KC_SCLN        , KC_COLN,                                             KC_F  , KC_W , KC_R , KC_Y , KC_P      , KC_BSPC     ,
    LM(5, MOD_LCTL), KC_E   , KC_I   , KC_A           , KC_O           , KC_COMM,                                             KC_K  , KC_T , KC_N , KC_S , KC_H      , KC_ESC      ,
    KC_LSFT        , KC_Z   , KC_X   , KC_C           , KC_V           , KC_DOT ,                                             KC_G  , KC_D , KC_M , KC_J , KC_B      , LGUI(KC_SPC),
                              KC_LALT, LM(5, MOD_LALT), LM(5, MOD_LGUI), USER_6 , LT(4, KC_SPC),              LSFT_T(KC_ENT), USER_5,        KC_NO, KC_NO, HYPR(KC_S)
  ),

  [1] = LAYOUT_universal(
    KC_NO  ,  KC_ASTR, KC_SLSH, KC_GRV         , KC_DLR , KC_COMM,                       KC_DOT  , KC_LBRC, KC_RBRC, KC_EXLM, KC_QUES, KC_NO,
    KC_LCTL,  KC_PLUS, KC_MINS, KC_DOUBLE_QUOTE, KC_EQL , KC_PERC,                       KC_AT   , KC_LPRN, KC_RPRN, KC_LABK, KC_RABK, KC_NO,
    KC_NO  ,  KC_CIRC, KC_TILD, KC_QUOT        , KC_UNDS, KC_BSLS,                       KC_HASH, KC_LCBR, KC_RCBR, KC_AMPR, KC_PIPE, KC_NO,
                      KC_NO  , KC_LALT ,        KC_LGUI  ,USER_6 , KC_SPC,        KC_NO, KC_NO,             KC_NO  , KC_NO  , KC_NO
  ),

  [2] = LAYOUT_universal(
    KC_NO  ,KC_F1, KC_F2 , KC_F3 , KC_F4 , KC_NO      ,                              KC_COLN , KC_1 , KC_2 , KC_3 , KC_NO, KC_NO,
    KC_NO  ,KC_F5, KC_F6 , KC_F7 , KC_F8 , KC_NO      ,                              KC_DOT  , KC_4 , KC_5 , KC_6 , KC_NO, KC_NO,
    KC_NO  ,KC_F9, KC_F10, KC_F11, KC_F12, LALT(KC_F7),                              KC_SLASH, KC_7 , KC_8 , KC_9 , KC_0 , KC_NO,
                   KC_NO , KC_NO  ,KC_NO , KC_NO      , KC_NO,                USER_3, USER_5 ,        KC_NO, KC_NO, KC_NO
  ),

  [3] = LAYOUT_universal(
    KC_NO, KC_NO , KC_NO, KC_NO   , KC_NO   , KC_NO   ,                              KC_NO, KC_NO, KC_NO , KC_NO, KC_NO, KC_NO,
    KC_NO, USER_2, KC_NO, SCRL_DVI, CPI_I100, KBC_SAVE,                              KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_NO , KC_NO, SCRL_DVD, CPI_D100, KC_NO   ,                              KC_NO, KC_NO, KC_NO , KC_NO, KC_NO, KC_NO,
                   KC_NO, KC_NO   , KC_NO   , KC_NO   , KC_NO,                KC_NO, KC_NO,        KC_NO , KC_NO, KC_NO
  ),

  [4] = LAYOUT_universal(
    KC_NO, KC_NO, KC_NO     , LSFT(KC_TAB), USER_1, KC_NO ,                            KC_NO  , LALT(KC_LEFT), KC_UP  , LALT(KC_RIGHT), KC_NO        , KC_NO,
    KC_NO, KC_NO, LALT(KC_S), LSFT(KC_TAB), USER_0, USER_2 ,                           KC_PGUP, KC_LEFT      , KC_DOWN, KC_RIGHT      , LCTL(KC_LEFT), LCTL(KC_RIGHT),
    KC_NO, KC_NO, LALT(KC_X), LALT(KC_C)  , KC_NO , KC_NO ,                            KC_PGDN, LGUI(KC_LEFT), KC_NO  , LGUI(KC_RIGHT), LCTL(KC_UP)  , KC_F11,
                  KC_NO     , KC_NO       ,KC_NO  , KC_NO , KC_NO,            KC_LSFT, KC_NO  ,                KC_NO   , KC_NO        , KC_NO
  ),

  [5] = LAYOUT_universal(
    KC_TAB , KC_Q, KC_W , KC_E   , KC_R   , KC_T   ,                                  KC_Y   , KC_U, KC_I   , KC_O  , KC_P   , KC_BSPC,
    KC_LCTL, KC_A, KC_S , KC_D   , KC_F   , KC_G   ,                                  KC_H   , KC_J, KC_K   , KC_L  , KC_SCLN, KC_NO  ,
    KC_LSFT, KC_Z, KC_X , KC_C   , KC_V   , KC_B   ,                                  KC_N   , KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_NO  ,
                   KC_NO, KC_LALT, KC_LGUI, KC_LNG1, KC_SPC,                  KC_ENT, KC_LNG1,       KC_NO  , KC_NO , KC_NO
  )
};
// clang-format on

#ifdef OLED_ENABLE

#    include "lib/oledkit/oledkit.h"

void oledkit_render_info_user(void) {
  keyball_oled_render_keyinfo();
  keyball_oled_render_ballinfo();
  keyball_oled_render_layerinfo();
}
#endif

const uint16_t PROGMEM btn1[] = {KC_T, KC_N, COMBO_END};
const uint16_t PROGMEM btn1_2[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM btn2[] = {KC_N, KC_S, COMBO_END};
const uint16_t PROGMEM btn4[] = {KC_D, KC_M, COMBO_END};
const uint16_t PROGMEM btn5[] = {KC_M, KC_J, COMBO_END};
const uint16_t PROGMEM scroll[] = {KC_T, KC_S, COMBO_END};
const uint16_t PROGMEM h_scroll[] = {KC_D, KC_J, COMBO_END};

combo_t key_combos[] = {
  COMBO(btn1, KC_BTN1),
  COMBO(btn1_2, KC_BTN1),
  COMBO(btn2, KC_BTN2),
  COMBO(btn4, KC_BTN4),
  COMBO(btn5, KC_BTN5),
  COMBO(scroll, SCROLL),
  COMBO(h_scroll, H_SCROLL),
};

static bool alt_tab_active = false;
static bool ctrl_tab_active = false;
static bool alt_ctrl_tab_active = false;
static uint8_t scroll_div = 4;
static bool user5_active = false;
static bool user6_active = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case USER_0:
      if (record->event.pressed) {
        ctrl_tab_active = false;
        alt_ctrl_tab_active = false;
        unregister_code(KC_LCTL);
        if (alt_tab_active) {
          tap_code(KC_TAB);
        } else {
          alt_tab_active = true;
          register_code(KC_LALT);
          tap_code(KC_TAB);
        }
      }
      return false;
    case USER_1:
      if (record->event.pressed) {
        alt_tab_active = false;
        alt_ctrl_tab_active = false;
        unregister_code(KC_LALT);
        if (ctrl_tab_active) {
          tap_code(KC_TAB);
        } else {
          ctrl_tab_active = true;
          register_code(KC_LCTL);
          tap_code(KC_TAB);
        }
      }
      return false;
    case USER_2:
      if (record->event.pressed) { 
        alt_tab_active = false;
        ctrl_tab_active = false;
        unregister_code(KC_LALT);
        if (ctrl_tab_active) {
          tap_code(KC_TAB);
        } else {
          ctrl_tab_active = true;
          register_code(KC_LCTL);
          register_code(KC_LALT);
          tap_code(KC_TAB);
        }
      }
      return false;
    case USER_3:
      if (record->event.pressed) {
        if (user6_active) {
          register_code(KC_LCTL);
          register_code(KC_LALT);
        }
      } else {
        if (user6_active) {
          unregister_code(KC_LCTL);
          unregister_code(KC_LALT);
        }
      }
      return false;
    case USER_5:
      if (record->event.pressed) {
        user5_active = true;
        if (user6_active) {
          layer_off(2);
          register_code(KC_LSFT);
        } else {
          layer_on(1);
        }
      } else {
        user5_active = false;
        if (user6_active) {
          unregister_code(KC_LSFT);
          layer_on(2);
        } else {
          layer_off(1);
        }
      }
      return false;
    case USER_6:
      if (record->event.pressed) {
        user6_active = true;
        if (user5_active) {
          layer_off(1);
          register_code(KC_LSFT);
        } else {
          layer_on(2);
        }
      } else {
        user6_active = false;
        if (user5_active) {
          layer_on(1);
          unregister_code(KC_LSFT);
        } else {
          layer_off(2);
        }
      }
      return false;
    case SCROLL:
      if (record->event.pressed) {
        keyball_set_scrollsnap_mode(KEYBALL_SCROLLSNAP_MODE_VERTICAL);
        layer_on(3);
      } else {
        keyball_set_scrollsnap_mode(KEYBALL_SCROLLSNAP_MODE_VERTICAL);
        layer_off(3);
      }
      return false;
    case H_SCROLL:
      if (record->event.pressed) {
        keyball_set_scrollsnap_mode(KEYBALL_SCROLLSNAP_MODE_HORIZONTAL);
        layer_on(3);
      } else {
        keyball_set_scrollsnap_mode(KEYBALL_SCROLLSNAP_MODE_VERTICAL);
        layer_off(3);
      }
      return false;
  }
  return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    keyball_set_scroll_mode(get_highest_layer(state) == 3);
    if (get_highest_layer(state) != 4) {
      if (alt_tab_active) {
        unregister_code(KC_LALT);
        alt_tab_active = false;
      }
      if (ctrl_tab_active) {
        unregister_code(KC_LCTL);
        ctrl_tab_active = false;
      }
    }
    return state;
}
