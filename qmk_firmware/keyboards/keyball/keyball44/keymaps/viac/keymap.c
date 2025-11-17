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

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // keymap for default (VIA)
  [0] = LAYOUT_universal(
    KC_ESC   , KC_Q     , KC_W     , KC_E     , KC_R     , KC_T     ,                                        KC_Y     , KC_U     , KC_I     , KC_O     , KC_P     , KC_DEL   ,
    KC_TAB   , KC_A     , KC_S     , KC_D     , KC_F     , KC_G     ,                                        KC_H     , KC_J     , KC_K     , KC_L     , KC_SCLN  , S(KC_7)  ,
    KC_LSFT  , KC_Z     , KC_X     , KC_C     , KC_V     , KC_B     ,                                        KC_N     , KC_M     , KC_COMM  , KC_DOT   , KC_SLSH  , KC_INT1  ,
              KC_LALT,KC_LGUI,LCTL_T(KC_LNG2)     ,LT(1,KC_SPC),LT(3,KC_LNG1),                  KC_BSPC,LT(2,KC_ENT), RCTL_T(KC_LNG2),     KC_RALT  , KC_PSCR
  ),

  [1] = LAYOUT_universal(
    SSNP_FRE ,  KC_F1   , KC_F2    , KC_F3   , KC_F4    , KC_F5    ,                                         KC_F6    , KC_F7    , KC_F8    , KC_F9    , KC_F10   , KC_F11   ,
    SSNP_VRT ,  _______ , _______  , KC_UP   , KC_ENT   , KC_DEL   ,                                         KC_PGUP  , KC_BTN1  , KC_UP    , KC_BTN2  , KC_BTN3  , KC_F12   ,
    SSNP_HOR ,  _______ , KC_LEFT  , KC_DOWN , KC_RGHT  , KC_BSPC  ,                                         KC_PGDN  , KC_LEFT  , KC_DOWN  , KC_RGHT  , _______  , _______  ,
                  _______  , _______ , _______  ,         _______  , _______  ,                   _______  , _______  , _______       , _______  , _______
  ),

  [2] = LAYOUT_universal(
    _______  ,S(KC_QUOT), KC_7     , KC_8    , KC_9     , S(KC_8)  ,                                         S(KC_9)  , S(KC_1)  , S(KC_6)  , KC_LBRC  , S(KC_4)  , _______  ,
    _______  ,S(KC_SCLN), KC_4     , KC_5    , KC_6     , KC_RBRC  ,                                         KC_NUHS  , KC_MINS  , S(KC_EQL), S(KC_3)  , KC_QUOT  , S(KC_2)  ,
    _______  ,S(KC_MINS), KC_1     , KC_2    , KC_3     ,S(KC_RBRC),                                        S(KC_NUHS),S(KC_INT1), KC_EQL   ,S(KC_LBRC),S(KC_SLSH),S(KC_INT3),
                  KC_0     , KC_DOT  , _______  ,         _______  , _______  ,                   KC_DEL   , _______  , _______       , _______  , _______
  ),

  [3] = LAYOUT_universal(
    RGB_TOG  , AML_TO   , AML_I50  , AML_D50  , _______  , _______  ,                                        RGB_M_P  , RGB_M_B  , RGB_M_R  , RGB_M_SW , RGB_M_SN , RGB_M_K  ,
    RGB_MOD  , RGB_HUI  , RGB_SAI  , RGB_VAI  , _______  , SCRL_DVI ,                                        RGB_M_X  , RGB_M_G  , RGB_M_T  , RGB_M_TW , _______  , _______  ,
    RGB_RMOD , RGB_HUD  , RGB_SAD  , RGB_VAD  , _______  , SCRL_DVD ,                                        CPI_D1K  , CPI_D100 , CPI_I100 , CPI_I1K  , _______  , KBC_SAVE ,
                  QK_BOOT  , KBC_RST  , _______  ,        _______  , _______  ,                   _______  , _______  , _______       , KBC_RST  , QK_BOOT
  ),

  [4] = LAYOUT_universal(
    KC_ESC   , KC_Q     , KC_W     , KC_E     , KC_R     , KC_T     ,                                        KC_Y     , KC_U     , KC_I     , KC_O     , KC_P     , KC_DEL   ,
    KC_TAB   , KC_A     , KC_S     , KC_D     , KC_F     , KC_G     ,                                        KC_H     , KC_J     , KC_K     , KC_L     , KC_SCLN  , S(KC_7)  ,
    KC_LSFT  , KC_Z     , KC_X     , KC_C     , KC_V     , KC_B     ,                                        KC_N     , KC_M     , KC_COMM  , KC_DOT   , KC_SLSH  , KC_INT1  ,
              KC_LALT,KC_LGUI,LCTL_T(KC_LNG2)     ,LT(1,KC_SPC),LT(3,KC_LNG1),                  KC_BSPC,LT(2,KC_ENT), RCTL_T(KC_LNG2),     KC_RALT  , KC_PSCR
  ),

  [5] = LAYOUT_universal(
    RGB_TOG  , AML_TO   , AML_I50  , AML_D50  , _______  , _______  ,                                        RGB_M_P  , RGB_M_B  , RGB_M_R  , RGB_M_SW , RGB_M_SN , RGB_M_K  ,
    RGB_MOD  , RGB_HUI  , RGB_SAI  , RGB_VAI  , _______  , SCRL_DVI ,                                        RGB_M_X  , RGB_M_G  , RGB_M_T  , RGB_M_TW , _______  , _______  ,
    RGB_RMOD , RGB_HUD  , RGB_SAD  , RGB_VAD  , _______  , SCRL_DVD ,                                        CPI_D1K  , CPI_D100 , CPI_I100 , CPI_I1K  , _______  , KBC_SAVE ,
                  QK_BOOT  , KBC_RST  , _______  ,        _______  , _______  ,                   _______  , _______  , _______       , KBC_RST  , QK_BOOT
  )
};
// clang-format on

#ifdef OLED_ENABLE

#    include "lib/oledkit/oledkit.h"

void oledkit_render_info_user(void) {
  keyball_oled_render_layerinfo();
}
#endif

const uint16_t PROGMEM btn1[] = {KC_T, KC_N, COMBO_END};
const uint16_t PROGMEM btn1_2[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM btn2[] = {KC_N, KC_S, COMBO_END};
const uint16_t PROGMEM btn4[] = {KC_D, KC_M, COMBO_END};
const uint16_t PROGMEM btn5[] = {KC_M, KC_J, COMBO_END};
const uint16_t PROGMEM scroll[] = {KC_T, KC_S, COMBO_END};

enum custom_keycodes {
  USER_0 = SAFE_RANGE, 
  USER_1,
  USER_2,
  USER_3,
  USER_4,
  USER_5,
  SCROLL,
};

combo_t key_combos[] = {
  COMBO(btn1, KC_BTN1),
  COMBO(btn1_2, KC_BTN1),
  COMBO(btn2, KC_BTN2),
  COMBO(btn4, KC_BTN4),
  COMBO(btn5, KC_BTN5),
  COMBO(scroll, SCROLL),
};

enum {
  TD_IME,
};

void td_ime_finished(tap_dance_state_t *state, void *user_data) {
  if (state->pressed) {
    layer_on(5);
    register_code(KC_LCTL);
  } else {
    register_code(KC_LCTL);
    register_code(KC_LALT);
    register_code(KC_LGUI);
    tap_code(KC_I);
  }
}

void td_ime_reset(tap_dance_state_t *state, void *user_data) {
  unregister_code(KC_LCTL);
  unregister_code(KC_LALT);
  unregister_code(KC_LGUI);
  layer_off(5);
}

tap_dance_action_t tap_dance_actions[] = {
  [TD_IME] = ACTION_TAP_DANCE_FN_ADVANCED(
    NULL,
    td_ime_finished,
    td_ime_reset
  )
};

static bool alt_tab_active = false;
static bool ctrl_tab_active = false;
static uint8_t scroll_div = 4;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case USER_0:
      if (record->event.pressed) {
        ctrl_tab_active = false;
        if (!alt_tab_active) {
          alt_tab_active = true;
          register_code(KC_LALT);
          tap_code(KC_TAB);
        } else {
          tap_code(KC_TAB);
        }
      }
      return false;
    case USER_1:
      if (record->event.pressed) {
        alt_tab_active = false;
        if (!ctrl_tab_active) {
          ctrl_tab_active = true;
          register_code(KC_LCTL);
          tap_code(KC_TAB);
        } else {
          tap_code(KC_TAB);
        }
      }
      return false;
    case USER_2:
      if (record->event.pressed) {
        scroll_div = keyball_get_scroll_div();
        keyball_set_scroll_div(7);
      } else {
        keyball_set_scroll_div(scroll_div);
      }
      return false;
    case USER_3:
      if (record->event.pressed) {
        keyball_set_scrollsnap_mode(KEYBALL_SCROLLSNAP_MODE_HORIZONTAL);
      } else {
        keyball_set_scrollsnap_mode(KEYBALL_SCROLLSNAP_MODE_VERTICAL);
      }
      return false;
    case USER_4:
      process_tap_dance(TD(TD_IME), record);
      return false;
    case USER_5:
      process_tap_hold(LT(1, KC_LSFT), record);
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
  }
  return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    // Auto enable scroll mode when the highest layer is 3
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
