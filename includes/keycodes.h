/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycodes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 13:35:55 by brichard          #+#    #+#             */
/*   Updated: 2019/03/21 13:36:42 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYCODES_H
# define KEYCODES_H
# ifdef __APPLE__
#  include "TargetConditionals.h"
#  if TARGET_OS_MAC

/*
** Mouse button keycodes
*/

#   define BUT1_KEY 1
#   define BUT2_KEY 2
#   define BUT3_KEY 3
#   define SCROLLUP_KEY 4
#   define SCROLLDOWN_KEY 5
#   define SCROLLLEFT_KEY 6
#   define SCROLLRIGHT_KEY 7

/*
**			Keyboard keys
*/

/*
** Letters keys
*/

#   define A_KEY 0
#   define B_KEY 11
#   define C_KEY 8
#   define D_KEY 2
#   define E_KEY 14
#   define F_KEY 3
#   define G_KEY 5
#   define H_KEY 4
#   define I_KEY 34
#   define J_KEY 38
#   define K_KEY 40
#   define L_KEY 37
#   define M_KEY 46
#   define N_KEY 45
#   define O_KEY 31
#   define P_KEY 35
#   define Q_KEY 12
#   define R_KEY 15
#   define S_KEY 1
#   define T_KEY 17
#   define U_KEY 32
#   define V_KEY 9
#   define W_KEY 13
#   define X_KEY 7
#   define Y_KEY 16
#   define Z_KEY 6

/*
** Numbers (not numeric keypad ones)
*/

#   define K1_KEY 18
#   define K2_KEY 19
#   define K3_KEY 20
#   define K4_KEY 21
#   define K5_KEY 23
#   define K6_KEY 22
#   define K7_KEY 26
#   define K8_KEY 28
#   define K9_KEY 25
#   define K0_KEY 29

/*
** Special characters
** SP_KEY is the space ( ) key
** BQ_KEY is the back quote (`) and tilde (~) key
** MN_KEY is the minus (-) and underscore (_) key
** PL_KEY is the plus (+) and equal (=) key
** SBO_KEY is the square bracket opening ([) and brace opening ({) key
** SBC_KEY is the square bracket closing (]) and brace closing (}) key
** BSL_KEY is the backslash (\) and pipe (|) key
** SC_KEY is the semicolon (;) and colon (:) key
** SQ_KEY is the simple quote (') and double quote (") key
** CM_KEY is the comma (,) and angle bracket opening (<) key
** PT_KEY is the point (.) and angle bracket closing (>) key
** SL_KEY is the slash (/) and question mark (?) key
*/

#   define SP_KEY 49
#   define BQ_KEY 50
#   define MN_KEY 27
#   define PL_KEY 24
#   define SBO_KEY 33
#   define SBC_KEY 30
#   define BSL_KEY 42
#   define SC_KEY 41
#   define SQ_KEY 39
#   define CM_KEY 43
#   define PT_KEY 47
#   define SL_KEY 44

/*
** Functions keys, you might use fn key to use them
** I didn't find the F11_KEY value
*/

#   define F1_KEY 122
#   define F2_KEY 120
#   define F3_KEY 99
#   define F4_KEY 118
#   define F5_KEY 96
#   define F6_KEY 97
#   define F7_KEY 98
#   define F8_KEY 100
#   define F9_KEY 101
#   define F10_KEY 109
#   define F11_KEY
#   define F12_KEY 111
#   define F13_KEY 105
#   define F14_KEY 107
#   define F15_KEY 113
#   define F16_KEY 106
#   define F17_KEY 64
#   define F18_KEY 79
#   define F19_KEY 80

/*
** Arrow keys
*/

#   define UP_KEY 126
#   define DOWN_KEY 125
#   define RIGHT_KEY 124
#   define LEFT_KEY 123

/*
** Special keys
** CL_KEY is the caps lock key
** LSFT_KEY and RLFT_KEY are the left shift and right shift keys
** LCTRL_KEY and RCTRL_KEY are the left control and right control keys
** LOPT_KEY and ROPT_KEY are the left option and right option keys
** LCMD_KEY and RCMD_KEY are the left command and right command keys
** LDEL_KEY and RDEL_KEY are the left delete and right delete keys
** RTN_KEY is the return key
** EJ_KEY is the eject key and doesn't react
** PUP_KEY and PDOWN_KEY are the page up and page down keys
** CLR_KEY is the clear key
*/

#   define ESC_KEY 53
#   define TAB_KEY 48
#   define CL_KEY 272
#   define LSFT_KEY 257
#   define LCTRL_KEY 256
#   define LOPT_KEY 261
#   define LCMD_KEY 259
#   define LDEL_KEY 51
#   define RTN_KEY 36
#   define RSFT_KEY 258
#   define RCTRL_KEY 269
#   define ROPT_KEY 262
#   define RCMD_KEY 260
#   define EJ_KEY
#   define FN_KEY 279
#   define RDEL_KEY 117
#   define HOME_KEY 115
#   define END_KEY 119
#   define PUP_KEY 116
#   define PDOWN_KEY 121
#   define CLR_KEY 71

/*
** Numeric keyboard keys, preceded by NK
** NKEQ_KEY is the equal (=) key
** NKSL_KEY is the slash (/) key
** NKWC_KEY is the wildcard (*) key
** NKMN_KEY is the minus (-) key
** NKPL_KEY is the plus (+) key
** NKPT_KEY is the point (.) key
** NKNTR_KEY is the enter key
*/

#   define NK1_KEY 83
#   define NK2_KEY 84
#   define NK3_KEY 85
#   define NK4_KEY 86
#   define NK5_KEY 87
#   define NK6_KEY 88
#   define NK7_KEY 89
#   define NK8_KEY 91
#   define NK9_KEY 92
#   define NK0_KEY 82
#   define NKEQ_KEY 81
#   define NKSL_KEY 75
#   define NKWC_KEY 67
#   define NKMN_KEY 78
#   define NKPL_KEY 69
#   define NKPT_KEY 65
#   define NKNTR_KEY 76
#  endif
# elif __linux__
#  define KEY_ESCAPE         65307
#  define KEY_F1             65470
#  define KEY_F2             65471
#  define KEY_F3             65472
#  define KEY_F4             65473
#  define KEY_F5             65474
#  define KEY_F6             65475
#  define KEY_F7             65476
#  define KEY_F8             65477
#  define KEY_F9             65478
#  define KEY_F10            65479
#  define KEY_F11            65480
#  define KEY_F12            65481
#  define KEY_SCROLL_LOCK    65300
#  define KEY_PAUSE          65299
#  define KEY_TILDE          96
#  define KEY_1              49
#  define KEY_2              50
#  define KEY_3              51
#  define KEY_4              52
#  define KEY_5              53
#  define KEY_6              54
#  define KEY_7              55
#  define KEY_8              56
#  define KEY_9              57
#  define KEY_0              48
#  define KEY_MINUS          45
#  define KEY_UNDERSCORE     45
#  define KEY_EQUAL          61
#  define KEY_BACKSPACE      65288
#  define KEY_TAB            65289
#  define KEY_Q              113
#  define KEY_W              119
#  define KEY_E              101
#  define KEY_R              114
#  define KEY_T              116
#  define KEY_Y              121
#  define KEY_U              117
#  define KEY_I              105
#  define KEY_O              111
#  define KEY_P              112
#  define KEY_OPEN_BRACKET   91
#  define KEY_OPEN_BRACE     91
#  define KEY_CLOSE_BRACKET  93
#  define KEY_CLOSE_BRACE    93
#  define KEY_BACKSLASH      92
#  define KEY_PIPE           92
#  define KEY_CAPSLOCK       65509
#  define KEY_A              97
#  define KEY_S              115
#  define KEY_D              100
#  define KEY_F              102
#  define KEY_G              103
#  define KEY_H              104
#  define KEY_J              106
#  define KEY_K              107
#  define KEY_L              108
#  define KEY_COLON          52
#  define KEY_SEMI_COLON     52
#  define KEY_SIMPLE_QUOTE   39
#  define KEY_DOUBLE_QUOTES  39
#  define KEY_ENTER          65293
#  define KEY_SHIFT_LEFT     65505
#  define KEY_Z              122
#  define KEY_X              120
#  define KEY_C              99
#  define KEY_V              118
#  define KEY_B              98
#  define KEY_N              110
#  define KEY_M              109
#  define KEY_LESS_THAN      44
#  define KEY_COMMA          44
#  define KEY_GREATER_THAN   46
#  define KEY_DOT            46
#  define KEY_SLASH          47
#  define KEY_QUESTION_MARK  47
#  define KEY_SHIFT_RIGHT    65506
#  define KEY_CTRL_LEFT      65507
#  define KEY_ALT            65513
#  define KEY_SPACEBAR       32
#  define KEY_ALT_GR         65514
#  define KEY_MENU           65383
#  define KEY_CTRL_RIGHT     65508
#  define KEY_LEFT           65361
#  define KEY_DOWN           65364
#  define KEY_RIGHT          65363
#  define KEY_UP             65362
#  define KEY_INSERT         65379
#  define KEY_DEL            65535
#  define KEY_HOME           65360
#  define KEY_END            65367
#  define KEY_PAGE_UP        65365
#  define KEY_PAGE_DOWN      65366
#  define KEY_NUM_LOCK       65407
#  define KEY_PAD_1          65436
#  define KEY_PAD_2          65433
#  define KEY_PAD_3          65435
#  define KEY_PAD_4          65430
#  define KEY_PAD_5          65437
#  define KEY_PAD_6          65432
#  define KEY_PAD_7          65429
#  define KEY_PAD_8          65431
#  define KEY_PAD_9          65434
#  define KEY_PAD_0          65438
#  define KEY_PAD_DIVIDE     65455
#  define KEY_PAD_MULTIPLY   65450
#  define KEY_PAD_SUB        65453
#  define KEY_PAD_ADD        65451
#  define KEY_PAD_ENTER      65421
#  define KEY_PAD_DOT        65439
#  define KEY_PAD_DELETE     65439

# endif

#endif
