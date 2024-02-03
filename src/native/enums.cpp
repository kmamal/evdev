#include "enums.h"
extern "C" {
	#include <linux/input-event-codes.h>
}

Napi::Value
enums::get(const Napi::CallbackInfo &info)
{
Napi::Env env = info.Env();

Napi::Object result = Napi::Object::New(env);

/*
* Device properties and quirks
*/

result.Set("INPUT_PROP_POINTER", Napi::Number::New(env, INPUT_PROP_POINTER)); /* needs a pointer */
result.Set("INPUT_PROP_DIRECT", Napi::Number::New(env, INPUT_PROP_DIRECT)); /* direct input devices */
result.Set("INPUT_PROP_BUTTONPAD", Napi::Number::New(env, INPUT_PROP_BUTTONPAD)); /* has button(s) under pad */
result.Set("INPUT_PROP_SEMI_MT", Napi::Number::New(env, INPUT_PROP_SEMI_MT)); /* touch rectangle only */
result.Set("INPUT_PROP_TOPBUTTONPAD", Napi::Number::New(env, INPUT_PROP_TOPBUTTONPAD)); /* softbuttons at top of pad */
result.Set("INPUT_PROP_POINTING_STICK", Napi::Number::New(env, INPUT_PROP_POINTING_STICK)); /* is a pointing stick */
result.Set("INPUT_PROP_ACCELEROMETER", Napi::Number::New(env, INPUT_PROP_ACCELEROMETER)); /* has accelerometer */

/*
* Event types
*/

result.Set("EV_SYN", Napi::Number::New(env, EV_SYN));
result.Set("EV_KEY", Napi::Number::New(env, EV_KEY));
result.Set("EV_REL", Napi::Number::New(env, EV_REL));
result.Set("EV_ABS", Napi::Number::New(env, EV_ABS));
result.Set("EV_MSC", Napi::Number::New(env, EV_MSC));
result.Set("EV_SW", Napi::Number::New(env, EV_SW));
result.Set("EV_LED", Napi::Number::New(env, EV_LED));
result.Set("EV_SND", Napi::Number::New(env, EV_SND));
result.Set("EV_REP", Napi::Number::New(env, EV_REP));
result.Set("EV_FF", Napi::Number::New(env, EV_FF));
result.Set("EV_PWR", Napi::Number::New(env, EV_PWR));
result.Set("EV_FF_STATUS", Napi::Number::New(env, EV_FF_STATUS));

/*
* Synchronization events.
*/

result.Set("SYN_REPORT", Napi::Number::New(env, SYN_REPORT));
result.Set("SYN_CONFIG", Napi::Number::New(env, SYN_CONFIG));
result.Set("SYN_MT_REPORT", Napi::Number::New(env, SYN_MT_REPORT));
result.Set("SYN_DROPPED", Napi::Number::New(env, SYN_DROPPED));

/*
* Keys and buttons
*
* Most of the keys/buttons are modeled after USB HUT 1.12
* (see http://www.usb.org/developers/hidpage).
* Abbreviations in the comments:
* AC - Application Control
* AL - Application Launch Button
* SC - System Control
*/

result.Set("KEY_RESERVED", Napi::Number::New(env, KEY_RESERVED));
result.Set("KEY_ESC", Napi::Number::New(env, KEY_ESC));
result.Set("KEY_1", Napi::Number::New(env, KEY_1));
result.Set("KEY_2", Napi::Number::New(env, KEY_2));
result.Set("KEY_3", Napi::Number::New(env, KEY_3));
result.Set("KEY_4", Napi::Number::New(env, KEY_4));
result.Set("KEY_5", Napi::Number::New(env, KEY_5));
result.Set("KEY_6", Napi::Number::New(env, KEY_6));
result.Set("KEY_7", Napi::Number::New(env, KEY_7));
result.Set("KEY_8", Napi::Number::New(env, KEY_8));
result.Set("KEY_9", Napi::Number::New(env, KEY_9));
result.Set("KEY_0", Napi::Number::New(env, KEY_0));
result.Set("KEY_MINUS", Napi::Number::New(env, KEY_MINUS));
result.Set("KEY_EQUAL", Napi::Number::New(env, KEY_EQUAL));
result.Set("KEY_BACKSPACE", Napi::Number::New(env, KEY_BACKSPACE));
result.Set("KEY_TAB", Napi::Number::New(env, KEY_TAB));
result.Set("KEY_Q", Napi::Number::New(env, KEY_Q));
result.Set("KEY_W", Napi::Number::New(env, KEY_W));
result.Set("KEY_E", Napi::Number::New(env, KEY_E));
result.Set("KEY_R", Napi::Number::New(env, KEY_R));
result.Set("KEY_T", Napi::Number::New(env, KEY_T));
result.Set("KEY_Y", Napi::Number::New(env, KEY_Y));
result.Set("KEY_U", Napi::Number::New(env, KEY_U));
result.Set("KEY_I", Napi::Number::New(env, KEY_I));
result.Set("KEY_O", Napi::Number::New(env, KEY_O));
result.Set("KEY_P", Napi::Number::New(env, KEY_P));
result.Set("KEY_LEFTBRACE", Napi::Number::New(env, KEY_LEFTBRACE));
result.Set("KEY_RIGHTBRACE", Napi::Number::New(env, KEY_RIGHTBRACE));
result.Set("KEY_ENTER", Napi::Number::New(env, KEY_ENTER));
result.Set("KEY_LEFTCTRL", Napi::Number::New(env, KEY_LEFTCTRL));
result.Set("KEY_A", Napi::Number::New(env, KEY_A));
result.Set("KEY_S", Napi::Number::New(env, KEY_S));
result.Set("KEY_D", Napi::Number::New(env, KEY_D));
result.Set("KEY_F", Napi::Number::New(env, KEY_F));
result.Set("KEY_G", Napi::Number::New(env, KEY_G));
result.Set("KEY_H", Napi::Number::New(env, KEY_H));
result.Set("KEY_J", Napi::Number::New(env, KEY_J));
result.Set("KEY_K", Napi::Number::New(env, KEY_K));
result.Set("KEY_L", Napi::Number::New(env, KEY_L));
result.Set("KEY_SEMICOLON", Napi::Number::New(env, KEY_SEMICOLON));
result.Set("KEY_APOSTROPHE", Napi::Number::New(env, KEY_APOSTROPHE));
result.Set("KEY_GRAVE", Napi::Number::New(env, KEY_GRAVE));
result.Set("KEY_LEFTSHIFT", Napi::Number::New(env, KEY_LEFTSHIFT));
result.Set("KEY_BACKSLASH", Napi::Number::New(env, KEY_BACKSLASH));
result.Set("KEY_Z", Napi::Number::New(env, KEY_Z));
result.Set("KEY_X", Napi::Number::New(env, KEY_X));
result.Set("KEY_C", Napi::Number::New(env, KEY_C));
result.Set("KEY_V", Napi::Number::New(env, KEY_V));
result.Set("KEY_B", Napi::Number::New(env, KEY_B));
result.Set("KEY_N", Napi::Number::New(env, KEY_N));
result.Set("KEY_M", Napi::Number::New(env, KEY_M));
result.Set("KEY_COMMA", Napi::Number::New(env, KEY_COMMA));
result.Set("KEY_DOT", Napi::Number::New(env, KEY_DOT));
result.Set("KEY_SLASH", Napi::Number::New(env, KEY_SLASH));
result.Set("KEY_RIGHTSHIFT", Napi::Number::New(env, KEY_RIGHTSHIFT));
result.Set("KEY_KPASTERISK", Napi::Number::New(env, KEY_KPASTERISK));
result.Set("KEY_LEFTALT", Napi::Number::New(env, KEY_LEFTALT));
result.Set("KEY_SPACE", Napi::Number::New(env, KEY_SPACE));
result.Set("KEY_CAPSLOCK", Napi::Number::New(env, KEY_CAPSLOCK));
result.Set("KEY_F1", Napi::Number::New(env, KEY_F1));
result.Set("KEY_F2", Napi::Number::New(env, KEY_F2));
result.Set("KEY_F3", Napi::Number::New(env, KEY_F3));
result.Set("KEY_F4", Napi::Number::New(env, KEY_F4));
result.Set("KEY_F5", Napi::Number::New(env, KEY_F5));
result.Set("KEY_F6", Napi::Number::New(env, KEY_F6));
result.Set("KEY_F7", Napi::Number::New(env, KEY_F7));
result.Set("KEY_F8", Napi::Number::New(env, KEY_F8));
result.Set("KEY_F9", Napi::Number::New(env, KEY_F9));
result.Set("KEY_F10", Napi::Number::New(env, KEY_F10));
result.Set("KEY_NUMLOCK", Napi::Number::New(env, KEY_NUMLOCK));
result.Set("KEY_SCROLLLOCK", Napi::Number::New(env, KEY_SCROLLLOCK));
result.Set("KEY_KP7", Napi::Number::New(env, KEY_KP7));
result.Set("KEY_KP8", Napi::Number::New(env, KEY_KP8));
result.Set("KEY_KP9", Napi::Number::New(env, KEY_KP9));
result.Set("KEY_KPMINUS", Napi::Number::New(env, KEY_KPMINUS));
result.Set("KEY_KP4", Napi::Number::New(env, KEY_KP4));
result.Set("KEY_KP5", Napi::Number::New(env, KEY_KP5));
result.Set("KEY_KP6", Napi::Number::New(env, KEY_KP6));
result.Set("KEY_KPPLUS", Napi::Number::New(env, KEY_KPPLUS));
result.Set("KEY_KP1", Napi::Number::New(env, KEY_KP1));
result.Set("KEY_KP2", Napi::Number::New(env, KEY_KP2));
result.Set("KEY_KP3", Napi::Number::New(env, KEY_KP3));
result.Set("KEY_KP0", Napi::Number::New(env, KEY_KP0));
result.Set("KEY_KPDOT", Napi::Number::New(env, KEY_KPDOT));

result.Set("KEY_ZENKAKUHANKAKU", Napi::Number::New(env, KEY_ZENKAKUHANKAKU));
result.Set("KEY_102ND", Napi::Number::New(env, KEY_102ND));
result.Set("KEY_F11", Napi::Number::New(env, KEY_F11));
result.Set("KEY_F12", Napi::Number::New(env, KEY_F12));
result.Set("KEY_RO", Napi::Number::New(env, KEY_RO));
result.Set("KEY_KATAKANA", Napi::Number::New(env, KEY_KATAKANA));
result.Set("KEY_HIRAGANA", Napi::Number::New(env, KEY_HIRAGANA));
result.Set("KEY_HENKAN", Napi::Number::New(env, KEY_HENKAN));
result.Set("KEY_KATAKANAHIRAGANA", Napi::Number::New(env, KEY_KATAKANAHIRAGANA));
result.Set("KEY_MUHENKAN", Napi::Number::New(env, KEY_MUHENKAN));
result.Set("KEY_KPJPCOMMA", Napi::Number::New(env, KEY_KPJPCOMMA));
result.Set("KEY_KPENTER", Napi::Number::New(env, KEY_KPENTER));
result.Set("KEY_RIGHTCTRL", Napi::Number::New(env, KEY_RIGHTCTRL));
result.Set("KEY_KPSLASH", Napi::Number::New(env, KEY_KPSLASH));
result.Set("KEY_SYSRQ", Napi::Number::New(env, KEY_SYSRQ));
result.Set("KEY_RIGHTALT", Napi::Number::New(env, KEY_RIGHTALT));
result.Set("KEY_LINEFEED", Napi::Number::New(env, KEY_LINEFEED));
result.Set("KEY_HOME", Napi::Number::New(env, KEY_HOME));
result.Set("KEY_UP", Napi::Number::New(env, KEY_UP));
result.Set("KEY_PAGEUP", Napi::Number::New(env, KEY_PAGEUP));
result.Set("KEY_LEFT", Napi::Number::New(env, KEY_LEFT));
result.Set("KEY_RIGHT", Napi::Number::New(env, KEY_RIGHT));
result.Set("KEY_END", Napi::Number::New(env, KEY_END));
result.Set("KEY_DOWN", Napi::Number::New(env, KEY_DOWN));
result.Set("KEY_PAGEDOWN", Napi::Number::New(env, KEY_PAGEDOWN));
result.Set("KEY_INSERT", Napi::Number::New(env, KEY_INSERT));
result.Set("KEY_DELETE", Napi::Number::New(env, KEY_DELETE));
result.Set("KEY_MACRO", Napi::Number::New(env, KEY_MACRO));
result.Set("KEY_MUTE", Napi::Number::New(env, KEY_MUTE));
result.Set("KEY_VOLUMEDOWN", Napi::Number::New(env, KEY_VOLUMEDOWN));
result.Set("KEY_VOLUMEUP", Napi::Number::New(env, KEY_VOLUMEUP));
result.Set("KEY_POWER", Napi::Number::New(env, KEY_POWER)); /* SC System Power Down */
result.Set("KEY_KPEQUAL", Napi::Number::New(env, KEY_KPEQUAL));
result.Set("KEY_KPPLUSMINUS", Napi::Number::New(env, KEY_KPPLUSMINUS));
result.Set("KEY_PAUSE", Napi::Number::New(env, KEY_PAUSE));
result.Set("KEY_SCALE", Napi::Number::New(env, KEY_SCALE)); /* AL Compiz Scale (Expose) */

result.Set("KEY_KPCOMMA", Napi::Number::New(env, KEY_KPCOMMA));
result.Set("KEY_HANGEUL", Napi::Number::New(env, KEY_HANGEUL));
result.Set("KEY_HANGUEL", Napi::Number::New(env, KEY_HANGUEL));
result.Set("KEY_HANJA", Napi::Number::New(env, KEY_HANJA));
result.Set("KEY_YEN", Napi::Number::New(env, KEY_YEN));
result.Set("KEY_LEFTMETA", Napi::Number::New(env, KEY_LEFTMETA));
result.Set("KEY_RIGHTMETA", Napi::Number::New(env, KEY_RIGHTMETA));
result.Set("KEY_COMPOSE", Napi::Number::New(env, KEY_COMPOSE));

result.Set("KEY_STOP", Napi::Number::New(env, KEY_STOP)); /* AC Stop */
result.Set("KEY_AGAIN", Napi::Number::New(env, KEY_AGAIN));
result.Set("KEY_PROPS", Napi::Number::New(env, KEY_PROPS)); /* AC Properties */
result.Set("KEY_UNDO", Napi::Number::New(env, KEY_UNDO)); /* AC Undo */
result.Set("KEY_FRONT", Napi::Number::New(env, KEY_FRONT));
result.Set("KEY_COPY", Napi::Number::New(env, KEY_COPY)); /* AC Copy */
result.Set("KEY_OPEN", Napi::Number::New(env, KEY_OPEN)); /* AC Open */
result.Set("KEY_PASTE", Napi::Number::New(env, KEY_PASTE)); /* AC Paste */
result.Set("KEY_FIND", Napi::Number::New(env, KEY_FIND)); /* AC Search */
result.Set("KEY_CUT", Napi::Number::New(env, KEY_CUT)); /* AC Cut */
result.Set("KEY_HELP", Napi::Number::New(env, KEY_HELP)); /* AL Integrated Help Center */
result.Set("KEY_MENU", Napi::Number::New(env, KEY_MENU)); /* Menu (show menu) */
result.Set("KEY_CALC", Napi::Number::New(env, KEY_CALC)); /* AL Calculator */
result.Set("KEY_SETUP", Napi::Number::New(env, KEY_SETUP));
result.Set("KEY_SLEEP", Napi::Number::New(env, KEY_SLEEP)); /* SC System Sleep */
result.Set("KEY_WAKEUP", Napi::Number::New(env, KEY_WAKEUP)); /* System Wake Up */
result.Set("KEY_FILE", Napi::Number::New(env, KEY_FILE)); /* AL Local Machine Browser */
result.Set("KEY_SENDFILE", Napi::Number::New(env, KEY_SENDFILE));
result.Set("KEY_DELETEFILE", Napi::Number::New(env, KEY_DELETEFILE));
result.Set("KEY_XFER", Napi::Number::New(env, KEY_XFER));
result.Set("KEY_PROG1", Napi::Number::New(env, KEY_PROG1));
result.Set("KEY_PROG2", Napi::Number::New(env, KEY_PROG2));
result.Set("KEY_WWW", Napi::Number::New(env, KEY_WWW)); /* AL Internet Browser */
result.Set("KEY_MSDOS", Napi::Number::New(env, KEY_MSDOS));
result.Set("KEY_COFFEE", Napi::Number::New(env, KEY_COFFEE)); /* AL Terminal Lock/Screensaver */
result.Set("KEY_SCREENLOCK", Napi::Number::New(env, KEY_SCREENLOCK));
result.Set("KEY_ROTATE_DISPLAY", Napi::Number::New(env, KEY_ROTATE_DISPLAY)); /* Display orientation for e.g. tablets */
result.Set("KEY_DIRECTION", Napi::Number::New(env, KEY_DIRECTION));
result.Set("KEY_CYCLEWINDOWS", Napi::Number::New(env, KEY_CYCLEWINDOWS));
result.Set("KEY_MAIL", Napi::Number::New(env, KEY_MAIL));
result.Set("KEY_BOOKMARKS", Napi::Number::New(env, KEY_BOOKMARKS)); /* AC Bookmarks */
result.Set("KEY_COMPUTER", Napi::Number::New(env, KEY_COMPUTER));
result.Set("KEY_BACK", Napi::Number::New(env, KEY_BACK)); /* AC Back */
result.Set("KEY_FORWARD", Napi::Number::New(env, KEY_FORWARD)); /* AC Forward */
result.Set("KEY_CLOSECD", Napi::Number::New(env, KEY_CLOSECD));
result.Set("KEY_EJECTCD", Napi::Number::New(env, KEY_EJECTCD));
result.Set("KEY_EJECTCLOSECD", Napi::Number::New(env, KEY_EJECTCLOSECD));
result.Set("KEY_NEXTSONG", Napi::Number::New(env, KEY_NEXTSONG));
result.Set("KEY_PLAYPAUSE", Napi::Number::New(env, KEY_PLAYPAUSE));
result.Set("KEY_PREVIOUSSONG", Napi::Number::New(env, KEY_PREVIOUSSONG));
result.Set("KEY_STOPCD", Napi::Number::New(env, KEY_STOPCD));
result.Set("KEY_RECORD", Napi::Number::New(env, KEY_RECORD));
result.Set("KEY_REWIND", Napi::Number::New(env, KEY_REWIND));
result.Set("KEY_PHONE", Napi::Number::New(env, KEY_PHONE)); /* Media Select Telephone */
result.Set("KEY_ISO", Napi::Number::New(env, KEY_ISO));
result.Set("KEY_CONFIG", Napi::Number::New(env, KEY_CONFIG)); /* AL Consumer Control Configuration */
result.Set("KEY_HOMEPAGE", Napi::Number::New(env, KEY_HOMEPAGE)); /* AC Home */
result.Set("KEY_REFRESH", Napi::Number::New(env, KEY_REFRESH)); /* AC Refresh */
result.Set("KEY_EXIT", Napi::Number::New(env, KEY_EXIT)); /* AC Exit */
result.Set("KEY_MOVE", Napi::Number::New(env, KEY_MOVE));
result.Set("KEY_EDIT", Napi::Number::New(env, KEY_EDIT));
result.Set("KEY_SCROLLUP", Napi::Number::New(env, KEY_SCROLLUP));
result.Set("KEY_SCROLLDOWN", Napi::Number::New(env, KEY_SCROLLDOWN));
result.Set("KEY_KPLEFTPAREN", Napi::Number::New(env, KEY_KPLEFTPAREN));
result.Set("KEY_KPRIGHTPAREN", Napi::Number::New(env, KEY_KPRIGHTPAREN));
result.Set("KEY_NEW", Napi::Number::New(env, KEY_NEW)); /* AC New */
result.Set("KEY_REDO", Napi::Number::New(env, KEY_REDO)); /* AC Redo/Repeat */

result.Set("KEY_F13", Napi::Number::New(env, KEY_F13));
result.Set("KEY_F14", Napi::Number::New(env, KEY_F14));
result.Set("KEY_F15", Napi::Number::New(env, KEY_F15));
result.Set("KEY_F16", Napi::Number::New(env, KEY_F16));
result.Set("KEY_F17", Napi::Number::New(env, KEY_F17));
result.Set("KEY_F18", Napi::Number::New(env, KEY_F18));
result.Set("KEY_F19", Napi::Number::New(env, KEY_F19));
result.Set("KEY_F20", Napi::Number::New(env, KEY_F20));
result.Set("KEY_F21", Napi::Number::New(env, KEY_F21));
result.Set("KEY_F22", Napi::Number::New(env, KEY_F22));
result.Set("KEY_F23", Napi::Number::New(env, KEY_F23));
result.Set("KEY_F24", Napi::Number::New(env, KEY_F24));

result.Set("KEY_PLAYCD", Napi::Number::New(env, KEY_PLAYCD));
result.Set("KEY_PAUSECD", Napi::Number::New(env, KEY_PAUSECD));
result.Set("KEY_PROG3", Napi::Number::New(env, KEY_PROG3));
result.Set("KEY_PROG4", Napi::Number::New(env, KEY_PROG4));
result.Set("KEY_ALL_APPLICATIONS", Napi::Number::New(env, KEY_ALL_APPLICATIONS)); /* AC Desktop Show All Applications */
result.Set("KEY_DASHBOARD", Napi::Number::New(env, KEY_DASHBOARD));
result.Set("KEY_SUSPEND", Napi::Number::New(env, KEY_SUSPEND));
result.Set("KEY_CLOSE", Napi::Number::New(env, KEY_CLOSE)); /* AC Close */
result.Set("KEY_PLAY", Napi::Number::New(env, KEY_PLAY));
result.Set("KEY_FASTFORWARD", Napi::Number::New(env, KEY_FASTFORWARD));
result.Set("KEY_BASSBOOST", Napi::Number::New(env, KEY_BASSBOOST));
result.Set("KEY_PRINT", Napi::Number::New(env, KEY_PRINT)); /* AC Print */
result.Set("KEY_HP", Napi::Number::New(env, KEY_HP));
result.Set("KEY_CAMERA", Napi::Number::New(env, KEY_CAMERA));
result.Set("KEY_SOUND", Napi::Number::New(env, KEY_SOUND));
result.Set("KEY_QUESTION", Napi::Number::New(env, KEY_QUESTION));
result.Set("KEY_EMAIL", Napi::Number::New(env, KEY_EMAIL));
result.Set("KEY_CHAT", Napi::Number::New(env, KEY_CHAT));
result.Set("KEY_SEARCH", Napi::Number::New(env, KEY_SEARCH));
result.Set("KEY_CONNECT", Napi::Number::New(env, KEY_CONNECT));
result.Set("KEY_FINANCE", Napi::Number::New(env, KEY_FINANCE)); /* AL Checkbook/Finance */
result.Set("KEY_SPORT", Napi::Number::New(env, KEY_SPORT));
result.Set("KEY_SHOP", Napi::Number::New(env, KEY_SHOP));
result.Set("KEY_ALTERASE", Napi::Number::New(env, KEY_ALTERASE));
result.Set("KEY_CANCEL", Napi::Number::New(env, KEY_CANCEL)); /* AC Cancel */
result.Set("KEY_BRIGHTNESSDOWN", Napi::Number::New(env, KEY_BRIGHTNESSDOWN));
result.Set("KEY_BRIGHTNESSUP", Napi::Number::New(env, KEY_BRIGHTNESSUP));
result.Set("KEY_MEDIA", Napi::Number::New(env, KEY_MEDIA));

result.Set("KEY_SWITCHVIDEOMODE", Napi::Number::New(env, KEY_SWITCHVIDEOMODE)); /* Cycle between available video outputs (Monitor/LCD/TV-out/etc) */
result.Set("KEY_KBDILLUMTOGGLE", Napi::Number::New(env, KEY_KBDILLUMTOGGLE));
result.Set("KEY_KBDILLUMDOWN", Napi::Number::New(env, KEY_KBDILLUMDOWN));
result.Set("KEY_KBDILLUMUP", Napi::Number::New(env, KEY_KBDILLUMUP));

result.Set("KEY_SEND", Napi::Number::New(env, KEY_SEND)); /* AC Send */
result.Set("KEY_REPLY", Napi::Number::New(env, KEY_REPLY)); /* AC Reply */
result.Set("KEY_FORWARDMAIL", Napi::Number::New(env, KEY_FORWARDMAIL)); /* AC Forward Msg */
result.Set("KEY_SAVE", Napi::Number::New(env, KEY_SAVE)); /* AC Save */
result.Set("KEY_DOCUMENTS", Napi::Number::New(env, KEY_DOCUMENTS));

result.Set("KEY_BATTERY", Napi::Number::New(env, KEY_BATTERY));

result.Set("KEY_BLUETOOTH", Napi::Number::New(env, KEY_BLUETOOTH));
result.Set("KEY_WLAN", Napi::Number::New(env, KEY_WLAN));
result.Set("KEY_UWB", Napi::Number::New(env, KEY_UWB));

result.Set("KEY_UNKNOWN", Napi::Number::New(env, KEY_UNKNOWN));

result.Set("KEY_VIDEO_NEXT", Napi::Number::New(env, KEY_VIDEO_NEXT)); /* drive next video source */
result.Set("KEY_VIDEO_PREV", Napi::Number::New(env, KEY_VIDEO_PREV)); /* drive previous video source */
result.Set("KEY_BRIGHTNESS_CYCLE", Napi::Number::New(env, KEY_BRIGHTNESS_CYCLE)); /* brightness up, after max is min */
result.Set("KEY_BRIGHTNESS_AUTO", Napi::Number::New(env, KEY_BRIGHTNESS_AUTO)); /* Set Auto Brightness: manual
;  control is off,
;  on ambient */
result.Set("KEY_BRIGHTNESS_ZERO", Napi::Number::New(env, KEY_BRIGHTNESS_ZERO));
result.Set("KEY_DISPLAY_OFF", Napi::Number::New(env, KEY_DISPLAY_OFF)); /* display device to off state */

result.Set("KEY_WWAN", Napi::Number::New(env, KEY_WWAN)); /* Wireless WAN (LTE, UMTS, GSM, etc.) */
result.Set("KEY_WIMAX", Napi::Number::New(env, KEY_WIMAX));
result.Set("KEY_RFKILL", Napi::Number::New(env, KEY_RFKILL)); /* Key that controls all radios */

result.Set("KEY_MICMUTE", Napi::Number::New(env, KEY_MICMUTE)); /* Mute / unmute the microphone */

/* Code 255 is reserved for special needs of AT keyboard driver */

result.Set("BTN_MISC", Napi::Number::New(env, BTN_MISC));
result.Set("BTN_0", Napi::Number::New(env, BTN_0));
result.Set("BTN_1", Napi::Number::New(env, BTN_1));
result.Set("BTN_2", Napi::Number::New(env, BTN_2));
result.Set("BTN_3", Napi::Number::New(env, BTN_3));
result.Set("BTN_4", Napi::Number::New(env, BTN_4));
result.Set("BTN_5", Napi::Number::New(env, BTN_5));
result.Set("BTN_6", Napi::Number::New(env, BTN_6));
result.Set("BTN_7", Napi::Number::New(env, BTN_7));
result.Set("BTN_8", Napi::Number::New(env, BTN_8));
result.Set("BTN_9", Napi::Number::New(env, BTN_9));

result.Set("BTN_MOUSE", Napi::Number::New(env, BTN_MOUSE));
result.Set("BTN_LEFT", Napi::Number::New(env, BTN_LEFT));
result.Set("BTN_RIGHT", Napi::Number::New(env, BTN_RIGHT));
result.Set("BTN_MIDDLE", Napi::Number::New(env, BTN_MIDDLE));
result.Set("BTN_SIDE", Napi::Number::New(env, BTN_SIDE));
result.Set("BTN_EXTRA", Napi::Number::New(env, BTN_EXTRA));
result.Set("BTN_FORWARD", Napi::Number::New(env, BTN_FORWARD));
result.Set("BTN_BACK", Napi::Number::New(env, BTN_BACK));
result.Set("BTN_TASK", Napi::Number::New(env, BTN_TASK));

result.Set("BTN_JOYSTICK", Napi::Number::New(env, BTN_JOYSTICK));
result.Set("BTN_TRIGGER", Napi::Number::New(env, BTN_TRIGGER));
result.Set("BTN_THUMB", Napi::Number::New(env, BTN_THUMB));
result.Set("BTN_THUMB2", Napi::Number::New(env, BTN_THUMB2));
result.Set("BTN_TOP", Napi::Number::New(env, BTN_TOP));
result.Set("BTN_TOP2", Napi::Number::New(env, BTN_TOP2));
result.Set("BTN_PINKIE", Napi::Number::New(env, BTN_PINKIE));
result.Set("BTN_BASE", Napi::Number::New(env, BTN_BASE));
result.Set("BTN_BASE2", Napi::Number::New(env, BTN_BASE2));
result.Set("BTN_BASE3", Napi::Number::New(env, BTN_BASE3));
result.Set("BTN_BASE4", Napi::Number::New(env, BTN_BASE4));
result.Set("BTN_BASE5", Napi::Number::New(env, BTN_BASE5));
result.Set("BTN_BASE6", Napi::Number::New(env, BTN_BASE6));
result.Set("BTN_DEAD", Napi::Number::New(env, BTN_DEAD));

result.Set("BTN_GAMEPAD", Napi::Number::New(env, BTN_GAMEPAD));
result.Set("BTN_SOUTH", Napi::Number::New(env, BTN_SOUTH));
result.Set("BTN_A", Napi::Number::New(env, BTN_A));
result.Set("BTN_EAST", Napi::Number::New(env, BTN_EAST));
result.Set("BTN_B", Napi::Number::New(env, BTN_B));
result.Set("BTN_C", Napi::Number::New(env, BTN_C));
result.Set("BTN_NORTH", Napi::Number::New(env, BTN_NORTH));
result.Set("BTN_X", Napi::Number::New(env, BTN_X));
result.Set("BTN_WEST", Napi::Number::New(env, BTN_WEST));
result.Set("BTN_Y", Napi::Number::New(env, BTN_Y));
result.Set("BTN_Z", Napi::Number::New(env, BTN_Z));
result.Set("BTN_TL", Napi::Number::New(env, BTN_TL));
result.Set("BTN_TR", Napi::Number::New(env, BTN_TR));
result.Set("BTN_TL2", Napi::Number::New(env, BTN_TL2));
result.Set("BTN_TR2", Napi::Number::New(env, BTN_TR2));
result.Set("BTN_SELECT", Napi::Number::New(env, BTN_SELECT));
result.Set("BTN_START", Napi::Number::New(env, BTN_START));
result.Set("BTN_MODE", Napi::Number::New(env, BTN_MODE));
result.Set("BTN_THUMBL", Napi::Number::New(env, BTN_THUMBL));
result.Set("BTN_THUMBR", Napi::Number::New(env, BTN_THUMBR));

result.Set("BTN_DIGI", Napi::Number::New(env, BTN_DIGI));
result.Set("BTN_TOOL_PEN", Napi::Number::New(env, BTN_TOOL_PEN));
result.Set("BTN_TOOL_RUBBER", Napi::Number::New(env, BTN_TOOL_RUBBER));
result.Set("BTN_TOOL_BRUSH", Napi::Number::New(env, BTN_TOOL_BRUSH));
result.Set("BTN_TOOL_PENCIL", Napi::Number::New(env, BTN_TOOL_PENCIL));
result.Set("BTN_TOOL_AIRBRUSH", Napi::Number::New(env, BTN_TOOL_AIRBRUSH));
result.Set("BTN_TOOL_FINGER", Napi::Number::New(env, BTN_TOOL_FINGER));
result.Set("BTN_TOOL_MOUSE", Napi::Number::New(env, BTN_TOOL_MOUSE));
result.Set("BTN_TOOL_LENS", Napi::Number::New(env, BTN_TOOL_LENS));
result.Set("BTN_TOOL_QUINTTAP", Napi::Number::New(env, BTN_TOOL_QUINTTAP)); /* Five fingers on trackpad */
result.Set("BTN_STYLUS3", Napi::Number::New(env, BTN_STYLUS3));
result.Set("BTN_TOUCH", Napi::Number::New(env, BTN_TOUCH));
result.Set("BTN_STYLUS", Napi::Number::New(env, BTN_STYLUS));
result.Set("BTN_STYLUS2", Napi::Number::New(env, BTN_STYLUS2));
result.Set("BTN_TOOL_DOUBLETAP", Napi::Number::New(env, BTN_TOOL_DOUBLETAP));
result.Set("BTN_TOOL_TRIPLETAP", Napi::Number::New(env, BTN_TOOL_TRIPLETAP));
result.Set("BTN_TOOL_QUADTAP", Napi::Number::New(env, BTN_TOOL_QUADTAP)); /* Four fingers on trackpad */

result.Set("BTN_WHEEL", Napi::Number::New(env, BTN_WHEEL));
result.Set("BTN_GEAR_DOWN", Napi::Number::New(env, BTN_GEAR_DOWN));
result.Set("BTN_GEAR_UP", Napi::Number::New(env, BTN_GEAR_UP));

result.Set("KEY_OK", Napi::Number::New(env, KEY_OK));
result.Set("KEY_SELECT", Napi::Number::New(env, KEY_SELECT));
result.Set("KEY_GOTO", Napi::Number::New(env, KEY_GOTO));
result.Set("KEY_CLEAR", Napi::Number::New(env, KEY_CLEAR));
result.Set("KEY_POWER2", Napi::Number::New(env, KEY_POWER2));
result.Set("KEY_OPTION", Napi::Number::New(env, KEY_OPTION));
result.Set("KEY_INFO", Napi::Number::New(env, KEY_INFO)); /* AL OEM Features/Tips/Tutorial */
result.Set("KEY_TIME", Napi::Number::New(env, KEY_TIME));
result.Set("KEY_VENDOR", Napi::Number::New(env, KEY_VENDOR));
result.Set("KEY_ARCHIVE", Napi::Number::New(env, KEY_ARCHIVE));
result.Set("KEY_PROGRAM", Napi::Number::New(env, KEY_PROGRAM)); /* Media Select Program Guide */
result.Set("KEY_CHANNEL", Napi::Number::New(env, KEY_CHANNEL));
result.Set("KEY_FAVORITES", Napi::Number::New(env, KEY_FAVORITES));
result.Set("KEY_EPG", Napi::Number::New(env, KEY_EPG));
result.Set("KEY_PVR", Napi::Number::New(env, KEY_PVR)); /* Media Select Home */
result.Set("KEY_MHP", Napi::Number::New(env, KEY_MHP));
result.Set("KEY_LANGUAGE", Napi::Number::New(env, KEY_LANGUAGE));
result.Set("KEY_TITLE", Napi::Number::New(env, KEY_TITLE));
result.Set("KEY_SUBTITLE", Napi::Number::New(env, KEY_SUBTITLE));
result.Set("KEY_ANGLE", Napi::Number::New(env, KEY_ANGLE));
result.Set("KEY_FULL_SCREEN", Napi::Number::New(env, KEY_FULL_SCREEN)); /* AC View Toggle */
result.Set("KEY_ZOOM", Napi::Number::New(env, KEY_ZOOM));
result.Set("KEY_MODE", Napi::Number::New(env, KEY_MODE));
result.Set("KEY_KEYBOARD", Napi::Number::New(env, KEY_KEYBOARD));
result.Set("KEY_ASPECT_RATIO", Napi::Number::New(env, KEY_ASPECT_RATIO)); /* HUTRR37: Aspect */
result.Set("KEY_SCREEN", Napi::Number::New(env, KEY_SCREEN));
result.Set("KEY_PC", Napi::Number::New(env, KEY_PC)); /* Media Select Computer */
result.Set("KEY_TV", Napi::Number::New(env, KEY_TV)); /* Media Select TV */
result.Set("KEY_TV2", Napi::Number::New(env, KEY_TV2)); /* Media Select Cable */
result.Set("KEY_VCR", Napi::Number::New(env, KEY_VCR)); /* Media Select VCR */
result.Set("KEY_VCR2", Napi::Number::New(env, KEY_VCR2)); /* VCR Plus */
result.Set("KEY_SAT", Napi::Number::New(env, KEY_SAT)); /* Media Select Satellite */
result.Set("KEY_SAT2", Napi::Number::New(env, KEY_SAT2));
result.Set("KEY_CD", Napi::Number::New(env, KEY_CD)); /* Media Select CD */
result.Set("KEY_TAPE", Napi::Number::New(env, KEY_TAPE)); /* Media Select Tape */
result.Set("KEY_RADIO", Napi::Number::New(env, KEY_RADIO));
result.Set("KEY_TUNER", Napi::Number::New(env, KEY_TUNER)); /* Media Select Tuner */
result.Set("KEY_PLAYER", Napi::Number::New(env, KEY_PLAYER));
result.Set("KEY_TEXT", Napi::Number::New(env, KEY_TEXT));
result.Set("KEY_DVD", Napi::Number::New(env, KEY_DVD)); /* Media Select DVD */
result.Set("KEY_AUX", Napi::Number::New(env, KEY_AUX));
result.Set("KEY_MP3", Napi::Number::New(env, KEY_MP3));
result.Set("KEY_AUDIO", Napi::Number::New(env, KEY_AUDIO)); /* AL Audio Browser */
result.Set("KEY_VIDEO", Napi::Number::New(env, KEY_VIDEO)); /* AL Movie Browser */
result.Set("KEY_DIRECTORY", Napi::Number::New(env, KEY_DIRECTORY));
result.Set("KEY_LIST", Napi::Number::New(env, KEY_LIST));
result.Set("KEY_MEMO", Napi::Number::New(env, KEY_MEMO)); /* Media Select Messages */
result.Set("KEY_CALENDAR", Napi::Number::New(env, KEY_CALENDAR));
result.Set("KEY_RED", Napi::Number::New(env, KEY_RED));
result.Set("KEY_GREEN", Napi::Number::New(env, KEY_GREEN));
result.Set("KEY_YELLOW", Napi::Number::New(env, KEY_YELLOW));
result.Set("KEY_BLUE", Napi::Number::New(env, KEY_BLUE));
result.Set("KEY_CHANNELUP", Napi::Number::New(env, KEY_CHANNELUP)); /* Channel Increment */
result.Set("KEY_CHANNELDOWN", Napi::Number::New(env, KEY_CHANNELDOWN)); /* Channel Decrement */
result.Set("KEY_FIRST", Napi::Number::New(env, KEY_FIRST));
result.Set("KEY_LAST", Napi::Number::New(env, KEY_LAST)); /* Recall Last */
result.Set("KEY_AB", Napi::Number::New(env, KEY_AB));
result.Set("KEY_NEXT", Napi::Number::New(env, KEY_NEXT));
result.Set("KEY_RESTART", Napi::Number::New(env, KEY_RESTART));
result.Set("KEY_SLOW", Napi::Number::New(env, KEY_SLOW));
result.Set("KEY_SHUFFLE", Napi::Number::New(env, KEY_SHUFFLE));
result.Set("KEY_BREAK", Napi::Number::New(env, KEY_BREAK));
result.Set("KEY_PREVIOUS", Napi::Number::New(env, KEY_PREVIOUS));
result.Set("KEY_DIGITS", Napi::Number::New(env, KEY_DIGITS));
result.Set("KEY_TEEN", Napi::Number::New(env, KEY_TEEN));
result.Set("KEY_TWEN", Napi::Number::New(env, KEY_TWEN));
result.Set("KEY_VIDEOPHONE", Napi::Number::New(env, KEY_VIDEOPHONE)); /* Media Select Video Phone */
result.Set("KEY_GAMES", Napi::Number::New(env, KEY_GAMES)); /* Media Select Games */
result.Set("KEY_ZOOMIN", Napi::Number::New(env, KEY_ZOOMIN)); /* AC Zoom In */
result.Set("KEY_ZOOMOUT", Napi::Number::New(env, KEY_ZOOMOUT)); /* AC Zoom Out */
result.Set("KEY_ZOOMRESET", Napi::Number::New(env, KEY_ZOOMRESET)); /* AC Zoom */
result.Set("KEY_WORDPROCESSOR", Napi::Number::New(env, KEY_WORDPROCESSOR)); /* AL Word Processor */
result.Set("KEY_EDITOR", Napi::Number::New(env, KEY_EDITOR)); /* AL Text Editor */
result.Set("KEY_SPREADSHEET", Napi::Number::New(env, KEY_SPREADSHEET)); /* AL Spreadsheet */
result.Set("KEY_GRAPHICSEDITOR", Napi::Number::New(env, KEY_GRAPHICSEDITOR)); /* AL Graphics Editor */
result.Set("KEY_PRESENTATION", Napi::Number::New(env, KEY_PRESENTATION)); /* AL Presentation App */
result.Set("KEY_DATABASE", Napi::Number::New(env, KEY_DATABASE)); /* AL Database App */
result.Set("KEY_NEWS", Napi::Number::New(env, KEY_NEWS)); /* AL Newsreader */
result.Set("KEY_VOICEMAIL", Napi::Number::New(env, KEY_VOICEMAIL)); /* AL Voicemail */
result.Set("KEY_ADDRESSBOOK", Napi::Number::New(env, KEY_ADDRESSBOOK)); /* AL Contacts/Address Book */
result.Set("KEY_MESSENGER", Napi::Number::New(env, KEY_MESSENGER)); /* AL Instant Messaging */
result.Set("KEY_DISPLAYTOGGLE", Napi::Number::New(env, KEY_DISPLAYTOGGLE)); /* Turn display (LCD) on and off */
result.Set("KEY_BRIGHTNESS_TOGGLE", Napi::Number::New(env, KEY_BRIGHTNESS_TOGGLE));
result.Set("KEY_SPELLCHECK", Napi::Number::New(env, KEY_SPELLCHECK));    /* AL Spell Check */
result.Set("KEY_LOGOFF", Napi::Number::New(env, KEY_LOGOFF));    /* AL Logoff */

result.Set("KEY_DOLLAR", Napi::Number::New(env, KEY_DOLLAR));
result.Set("KEY_EURO", Napi::Number::New(env, KEY_EURO));

result.Set("KEY_FRAMEBACK", Napi::Number::New(env, KEY_FRAMEBACK)); /* Consumer - transport controls */
result.Set("KEY_FRAMEFORWARD", Napi::Number::New(env, KEY_FRAMEFORWARD));
result.Set("KEY_CONTEXT_MENU", Napi::Number::New(env, KEY_CONTEXT_MENU)); /* GenDesc - system context menu */
result.Set("KEY_MEDIA_REPEAT", Napi::Number::New(env, KEY_MEDIA_REPEAT)); /* Consumer - transport control */
result.Set("KEY_10CHANNELSUP", Napi::Number::New(env, KEY_10CHANNELSUP)); /* 10 channels up (10+) */
result.Set("KEY_10CHANNELSDOWN", Napi::Number::New(env, KEY_10CHANNELSDOWN)); /* 10 channels down (10-) */
result.Set("KEY_IMAGES", Napi::Number::New(env, KEY_IMAGES)); /* AL Image Browser */
result.Set("KEY_NOTIFICATION_CENTER", Napi::Number::New(env, KEY_NOTIFICATION_CENTER)); /* Show/hide the notification center */
result.Set("KEY_PICKUP_PHONE", Napi::Number::New(env, KEY_PICKUP_PHONE)); /* Answer incoming call */
result.Set("KEY_HANGUP_PHONE", Napi::Number::New(env, KEY_HANGUP_PHONE)); /* Decline incoming call */

result.Set("KEY_DEL_EOL", Napi::Number::New(env, KEY_DEL_EOL));
result.Set("KEY_DEL_EOS", Napi::Number::New(env, KEY_DEL_EOS));
result.Set("KEY_INS_LINE", Napi::Number::New(env, KEY_INS_LINE));
result.Set("KEY_DEL_LINE", Napi::Number::New(env, KEY_DEL_LINE));

result.Set("KEY_FN", Napi::Number::New(env, KEY_FN));
result.Set("KEY_FN_ESC", Napi::Number::New(env, KEY_FN_ESC));
result.Set("KEY_FN_F1", Napi::Number::New(env, KEY_FN_F1));
result.Set("KEY_FN_F2", Napi::Number::New(env, KEY_FN_F2));
result.Set("KEY_FN_F3", Napi::Number::New(env, KEY_FN_F3));
result.Set("KEY_FN_F4", Napi::Number::New(env, KEY_FN_F4));
result.Set("KEY_FN_F5", Napi::Number::New(env, KEY_FN_F5));
result.Set("KEY_FN_F6", Napi::Number::New(env, KEY_FN_F6));
result.Set("KEY_FN_F7", Napi::Number::New(env, KEY_FN_F7));
result.Set("KEY_FN_F8", Napi::Number::New(env, KEY_FN_F8));
result.Set("KEY_FN_F9", Napi::Number::New(env, KEY_FN_F9));
result.Set("KEY_FN_F10", Napi::Number::New(env, KEY_FN_F10));
result.Set("KEY_FN_F11", Napi::Number::New(env, KEY_FN_F11));
result.Set("KEY_FN_F12", Napi::Number::New(env, KEY_FN_F12));
result.Set("KEY_FN_1", Napi::Number::New(env, KEY_FN_1));
result.Set("KEY_FN_2", Napi::Number::New(env, KEY_FN_2));
result.Set("KEY_FN_D", Napi::Number::New(env, KEY_FN_D));
result.Set("KEY_FN_E", Napi::Number::New(env, KEY_FN_E));
result.Set("KEY_FN_F", Napi::Number::New(env, KEY_FN_F));
result.Set("KEY_FN_S", Napi::Number::New(env, KEY_FN_S));
result.Set("KEY_FN_B", Napi::Number::New(env, KEY_FN_B));
result.Set("KEY_FN_RIGHT_SHIFT", Napi::Number::New(env, KEY_FN_RIGHT_SHIFT));

result.Set("KEY_BRL_DOT1", Napi::Number::New(env, KEY_BRL_DOT1));
result.Set("KEY_BRL_DOT2", Napi::Number::New(env, KEY_BRL_DOT2));
result.Set("KEY_BRL_DOT3", Napi::Number::New(env, KEY_BRL_DOT3));
result.Set("KEY_BRL_DOT4", Napi::Number::New(env, KEY_BRL_DOT4));
result.Set("KEY_BRL_DOT5", Napi::Number::New(env, KEY_BRL_DOT5));
result.Set("KEY_BRL_DOT6", Napi::Number::New(env, KEY_BRL_DOT6));
result.Set("KEY_BRL_DOT7", Napi::Number::New(env, KEY_BRL_DOT7));
result.Set("KEY_BRL_DOT8", Napi::Number::New(env, KEY_BRL_DOT8));
result.Set("KEY_BRL_DOT9", Napi::Number::New(env, KEY_BRL_DOT9));
result.Set("KEY_BRL_DOT10", Napi::Number::New(env, KEY_BRL_DOT10));

result.Set("KEY_NUMERIC_0", Napi::Number::New(env, KEY_NUMERIC_0)); /* used by phones, remote controls, */
result.Set("KEY_NUMERIC_1", Napi::Number::New(env, KEY_NUMERIC_1)); /* and other keypads */
result.Set("KEY_NUMERIC_2", Napi::Number::New(env, KEY_NUMERIC_2));
result.Set("KEY_NUMERIC_3", Napi::Number::New(env, KEY_NUMERIC_3));
result.Set("KEY_NUMERIC_4", Napi::Number::New(env, KEY_NUMERIC_4));
result.Set("KEY_NUMERIC_5", Napi::Number::New(env, KEY_NUMERIC_5));
result.Set("KEY_NUMERIC_6", Napi::Number::New(env, KEY_NUMERIC_6));
result.Set("KEY_NUMERIC_7", Napi::Number::New(env, KEY_NUMERIC_7));
result.Set("KEY_NUMERIC_8", Napi::Number::New(env, KEY_NUMERIC_8));
result.Set("KEY_NUMERIC_9", Napi::Number::New(env, KEY_NUMERIC_9));
result.Set("KEY_NUMERIC_STAR", Napi::Number::New(env, KEY_NUMERIC_STAR));
result.Set("KEY_NUMERIC_POUND", Napi::Number::New(env, KEY_NUMERIC_POUND));
result.Set("KEY_NUMERIC_A", Napi::Number::New(env, KEY_NUMERIC_A)); /* Phone key A - HUT Telephony  */
result.Set("KEY_NUMERIC_B", Napi::Number::New(env, KEY_NUMERIC_B));
result.Set("KEY_NUMERIC_C", Napi::Number::New(env, KEY_NUMERIC_C));
result.Set("KEY_NUMERIC_D", Napi::Number::New(env, KEY_NUMERIC_D));

result.Set("KEY_CAMERA_FOCUS", Napi::Number::New(env, KEY_CAMERA_FOCUS));
result.Set("KEY_WPS_BUTTON", Napi::Number::New(env, KEY_WPS_BUTTON)); /* WiFi Protected Setup key */

result.Set("KEY_TOUCHPAD_TOGGLE", Napi::Number::New(env, KEY_TOUCHPAD_TOGGLE)); /* Request switch touchpad on or off */
result.Set("KEY_TOUCHPAD_ON", Napi::Number::New(env, KEY_TOUCHPAD_ON));
result.Set("KEY_TOUCHPAD_OFF", Napi::Number::New(env, KEY_TOUCHPAD_OFF));

result.Set("KEY_CAMERA_ZOOMIN", Napi::Number::New(env, KEY_CAMERA_ZOOMIN));
result.Set("KEY_CAMERA_ZOOMOUT", Napi::Number::New(env, KEY_CAMERA_ZOOMOUT));
result.Set("KEY_CAMERA_UP", Napi::Number::New(env, KEY_CAMERA_UP));
result.Set("KEY_CAMERA_DOWN", Napi::Number::New(env, KEY_CAMERA_DOWN));
result.Set("KEY_CAMERA_LEFT", Napi::Number::New(env, KEY_CAMERA_LEFT));
result.Set("KEY_CAMERA_RIGHT", Napi::Number::New(env, KEY_CAMERA_RIGHT));

result.Set("KEY_ATTENDANT_ON", Napi::Number::New(env, KEY_ATTENDANT_ON));
result.Set("KEY_ATTENDANT_OFF", Napi::Number::New(env, KEY_ATTENDANT_OFF));
result.Set("KEY_ATTENDANT_TOGGLE", Napi::Number::New(env, KEY_ATTENDANT_TOGGLE)); /* Attendant call on or off */
result.Set("KEY_LIGHTS_TOGGLE", Napi::Number::New(env, KEY_LIGHTS_TOGGLE)); /* Reading light on or off */

result.Set("BTN_DPAD_UP", Napi::Number::New(env, BTN_DPAD_UP));
result.Set("BTN_DPAD_DOWN", Napi::Number::New(env, BTN_DPAD_DOWN));
result.Set("BTN_DPAD_LEFT", Napi::Number::New(env, BTN_DPAD_LEFT));
result.Set("BTN_DPAD_RIGHT", Napi::Number::New(env, BTN_DPAD_RIGHT));

result.Set("KEY_ALS_TOGGLE", Napi::Number::New(env, KEY_ALS_TOGGLE)); /* Ambient light sensor */
result.Set("KEY_ROTATE_LOCK_TOGGLE", Napi::Number::New(env, KEY_ROTATE_LOCK_TOGGLE)); /* Display rotation lock */

result.Set("KEY_BUTTONCONFIG", Napi::Number::New(env, KEY_BUTTONCONFIG)); /* AL Button Configuration */
result.Set("KEY_TASKMANAGER", Napi::Number::New(env, KEY_TASKMANAGER)); /* AL Task/Project Manager */
result.Set("KEY_JOURNAL", Napi::Number::New(env, KEY_JOURNAL)); /* AL Log/Journal/Timecard */
result.Set("KEY_CONTROLPANEL", Napi::Number::New(env, KEY_CONTROLPANEL)); /* AL Control Panel */
result.Set("KEY_APPSELECT", Napi::Number::New(env, KEY_APPSELECT)); /* AL Select Task/Application */
result.Set("KEY_SCREENSAVER", Napi::Number::New(env, KEY_SCREENSAVER)); /* AL Screen Saver */
result.Set("KEY_VOICECOMMAND", Napi::Number::New(env, KEY_VOICECOMMAND)); /* Listening Voice Command */
result.Set("KEY_ASSISTANT", Napi::Number::New(env, KEY_ASSISTANT)); /* AL Context-aware desktop assistant */
result.Set("KEY_KBD_LAYOUT_NEXT", Napi::Number::New(env, KEY_KBD_LAYOUT_NEXT)); /* AC Next Keyboard Layout Select */
result.Set("KEY_EMOJI_PICKER", Napi::Number::New(env, KEY_EMOJI_PICKER)); /* Show/hide emoji picker (HUTRR101) */
result.Set("KEY_DICTATE", Napi::Number::New(env, KEY_DICTATE)); /* Start or Stop Voice Dictation Session (HUTRR99) */
// result.Set("KEY_CAMERA_ACCESS_ENABLE", Napi::Number::New(env, KEY_CAMERA_ACCESS_ENABLE)); /* Enables programmatic access to camera devices. (HUTRR72) */
// result.Set("KEY_CAMERA_ACCESS_DISABLE", Napi::Number::New(env, KEY_CAMERA_ACCESS_DISABLE)); /* Disables programmatic access to camera devices. (HUTRR72) */
// result.Set("KEY_CAMERA_ACCESS_TOGGLE", Napi::Number::New(env, KEY_CAMERA_ACCESS_TOGGLE)); /* Toggles the current state of the camera access control. (HUTRR72) */

result.Set("KEY_BRIGHTNESS_MIN", Napi::Number::New(env, KEY_BRIGHTNESS_MIN)); /* Set Brightness to Minimum */

result.Set("KEY_KBDINPUTASSIST_PREV", Napi::Number::New(env, KEY_KBDINPUTASSIST_PREV));
result.Set("KEY_KBDINPUTASSIST_NEXT", Napi::Number::New(env, KEY_KBDINPUTASSIST_NEXT));
result.Set("KEY_KBDINPUTASSIST_PREVGROUP", Napi::Number::New(env, KEY_KBDINPUTASSIST_PREVGROUP));
result.Set("KEY_KBDINPUTASSIST_NEXTGROUP", Napi::Number::New(env, KEY_KBDINPUTASSIST_NEXTGROUP));
result.Set("KEY_KBDINPUTASSIST_ACCEPT", Napi::Number::New(env, KEY_KBDINPUTASSIST_ACCEPT));
result.Set("KEY_KBDINPUTASSIST_CANCEL", Napi::Number::New(env, KEY_KBDINPUTASSIST_CANCEL));

/* Diagonal movement keys */
result.Set("KEY_RIGHT_UP", Napi::Number::New(env, KEY_RIGHT_UP));
result.Set("KEY_RIGHT_DOWN", Napi::Number::New(env, KEY_RIGHT_DOWN));
result.Set("KEY_LEFT_UP", Napi::Number::New(env, KEY_LEFT_UP));
result.Set("KEY_LEFT_DOWN", Napi::Number::New(env, KEY_LEFT_DOWN));

result.Set("KEY_ROOT_MENU", Napi::Number::New(env, KEY_ROOT_MENU));  /* Show Device's Root Menu */
/* Show Top Menu of the Media (e.g. DVD) */
result.Set("KEY_MEDIA_TOP_MENU", Napi::Number::New(env, KEY_MEDIA_TOP_MENU));
result.Set("KEY_NUMERIC_11", Napi::Number::New(env, KEY_NUMERIC_11));
result.Set("KEY_NUMERIC_12", Napi::Number::New(env, KEY_NUMERIC_12));
/*
* Toggle Audio Description: refers to an audio service that helps blind and
* visually impaired consumers understand the action in a program. Note: in
* some countries this is referred to as "Video Description".
*/
result.Set("KEY_AUDIO_DESC", Napi::Number::New(env, KEY_AUDIO_DESC));
result.Set("KEY_3D_MODE", Napi::Number::New(env, KEY_3D_MODE));
result.Set("KEY_NEXT_FAVORITE", Napi::Number::New(env, KEY_NEXT_FAVORITE));
result.Set("KEY_STOP_RECORD", Napi::Number::New(env, KEY_STOP_RECORD));
result.Set("KEY_PAUSE_RECORD", Napi::Number::New(env, KEY_PAUSE_RECORD));
result.Set("KEY_VOD", Napi::Number::New(env, KEY_VOD));  /* Video on Demand */
result.Set("KEY_UNMUTE", Napi::Number::New(env, KEY_UNMUTE));
result.Set("KEY_FASTREVERSE", Napi::Number::New(env, KEY_FASTREVERSE));
result.Set("KEY_SLOWREVERSE", Napi::Number::New(env, KEY_SLOWREVERSE));
/*
* Control a data application associated with the currently viewed channel,
* e.g. teletext or data broadcast application (MHEG, MHP, HbbTV, etc.)
*/
result.Set("KEY_DATA", Napi::Number::New(env, KEY_DATA));
result.Set("KEY_ONSCREEN_KEYBOARD", Napi::Number::New(env, KEY_ONSCREEN_KEYBOARD));
/* Electronic privacy screen control */
result.Set("KEY_PRIVACY_SCREEN_TOGGLE", Napi::Number::New(env, KEY_PRIVACY_SCREEN_TOGGLE));

/* Select an area of screen to be copied */
result.Set("KEY_SELECTIVE_SCREENSHOT", Napi::Number::New(env, KEY_SELECTIVE_SCREENSHOT));

/* Move the focus to the next or previous user controllable element within a UI container */
// result.Set("KEY_NEXT_ELEMENT", Napi::Number::New(env, KEY_NEXT_ELEMENT));
// result.Set("KEY_PREVIOUS_ELEMENT", Napi::Number::New(env, KEY_PREVIOUS_ELEMENT));

/* Toggle Autopilot engagement */
// result.Set("KEY_AUTOPILOT_ENGAGE_TOGGLE", Napi::Number::New(env, KEY_AUTOPILOT_ENGAGE_TOGGLE));

/* Shortcut Keys */
// result.Set("KEY_MARK_WAYPOINT", Napi::Number::New(env, KEY_MARK_WAYPOINT));
// result.Set("KEY_SOS", Napi::Number::New(env, KEY_SOS));
// result.Set("KEY_NAV_CHART", Napi::Number::New(env, KEY_NAV_CHART));
// result.Set("KEY_FISHING_CHART", Napi::Number::New(env, KEY_FISHING_CHART));
// result.Set("KEY_SINGLE_RANGE_RADAR", Napi::Number::New(env, KEY_SINGLE_RANGE_RADAR));
// result.Set("KEY_DUAL_RANGE_RADAR", Napi::Number::New(env, KEY_DUAL_RANGE_RADAR));
// result.Set("KEY_RADAR_OVERLAY", Napi::Number::New(env, KEY_RADAR_OVERLAY));
// result.Set("KEY_TRADITIONAL_SONAR", Napi::Number::New(env, KEY_TRADITIONAL_SONAR));
// result.Set("KEY_CLEARVU_SONAR", Napi::Number::New(env, KEY_CLEARVU_SONAR));
// result.Set("KEY_SIDEVU_SONAR", Napi::Number::New(env, KEY_SIDEVU_SONAR));
// result.Set("KEY_NAV_INFO", Napi::Number::New(env, KEY_NAV_INFO));
// result.Set("KEY_BRIGHTNESS_MENU", Napi::Number::New(env, KEY_BRIGHTNESS_MENU));

/*
* Some keyboards have keys which do not have a defined meaning, these keys
* are intended to be programmed / bound to macros by the user. For most
* keyboards with these macro-keys the key-sequence to inject, or action to
* take, is all handled by software on the host side. So from the kernel's
* point of view these are just normal keys.
*
* The KEY_MACRO# codes below are intended for such keys, which may be labeled
* e.g. G1-G18, or S1 - S30. The KEY_MACRO# codes MUST NOT be used for keys
* where the marking on the key does indicate a defined meaning / purpose.
*
* The KEY_MACRO# codes MUST also NOT be used as fallback for when no existing
* KEY_FOO define matches the marking / purpose. In this case a new KEY_FOO
* define MUST be added.
*/
result.Set("KEY_MACRO1", Napi::Number::New(env, KEY_MACRO1));
result.Set("KEY_MACRO2", Napi::Number::New(env, KEY_MACRO2));
result.Set("KEY_MACRO3", Napi::Number::New(env, KEY_MACRO3));
result.Set("KEY_MACRO4", Napi::Number::New(env, KEY_MACRO4));
result.Set("KEY_MACRO5", Napi::Number::New(env, KEY_MACRO5));
result.Set("KEY_MACRO6", Napi::Number::New(env, KEY_MACRO6));
result.Set("KEY_MACRO7", Napi::Number::New(env, KEY_MACRO7));
result.Set("KEY_MACRO8", Napi::Number::New(env, KEY_MACRO8));
result.Set("KEY_MACRO9", Napi::Number::New(env, KEY_MACRO9));
result.Set("KEY_MACRO10", Napi::Number::New(env, KEY_MACRO10));
result.Set("KEY_MACRO11", Napi::Number::New(env, KEY_MACRO11));
result.Set("KEY_MACRO12", Napi::Number::New(env, KEY_MACRO12));
result.Set("KEY_MACRO13", Napi::Number::New(env, KEY_MACRO13));
result.Set("KEY_MACRO14", Napi::Number::New(env, KEY_MACRO14));
result.Set("KEY_MACRO15", Napi::Number::New(env, KEY_MACRO15));
result.Set("KEY_MACRO16", Napi::Number::New(env, KEY_MACRO16));
result.Set("KEY_MACRO17", Napi::Number::New(env, KEY_MACRO17));
result.Set("KEY_MACRO18", Napi::Number::New(env, KEY_MACRO18));
result.Set("KEY_MACRO19", Napi::Number::New(env, KEY_MACRO19));
result.Set("KEY_MACRO20", Napi::Number::New(env, KEY_MACRO20));
result.Set("KEY_MACRO21", Napi::Number::New(env, KEY_MACRO21));
result.Set("KEY_MACRO22", Napi::Number::New(env, KEY_MACRO22));
result.Set("KEY_MACRO23", Napi::Number::New(env, KEY_MACRO23));
result.Set("KEY_MACRO24", Napi::Number::New(env, KEY_MACRO24));
result.Set("KEY_MACRO25", Napi::Number::New(env, KEY_MACRO25));
result.Set("KEY_MACRO26", Napi::Number::New(env, KEY_MACRO26));
result.Set("KEY_MACRO27", Napi::Number::New(env, KEY_MACRO27));
result.Set("KEY_MACRO28", Napi::Number::New(env, KEY_MACRO28));
result.Set("KEY_MACRO29", Napi::Number::New(env, KEY_MACRO29));
result.Set("KEY_MACRO30", Napi::Number::New(env, KEY_MACRO30));

/*
* Some keyboards with the macro-keys described above have some extra keys
* for controlling the host-side software responsible for the macro handling:
* -A macro recording start/stop key. Note that not all keyboards which emit
*  KEY_MACRO_RECORD_START will also emit KEY_MACRO_RECORD_STOP if
*  KEY_MACRO_RECORD_STOP is not advertised, then KEY_MACRO_RECORD_START
*  should be interpreted as a recording start/stop toggle;
* -Keys for switching between different macro (pre)sets, either a key for
*  cycling through the configured presets or keys to directly select a preset.
*/
result.Set("KEY_MACRO_RECORD_START", Napi::Number::New(env, KEY_MACRO_RECORD_START));
result.Set("KEY_MACRO_RECORD_STOP", Napi::Number::New(env, KEY_MACRO_RECORD_STOP));
result.Set("KEY_MACRO_PRESET_CYCLE", Napi::Number::New(env, KEY_MACRO_PRESET_CYCLE));
result.Set("KEY_MACRO_PRESET1", Napi::Number::New(env, KEY_MACRO_PRESET1));
result.Set("KEY_MACRO_PRESET2", Napi::Number::New(env, KEY_MACRO_PRESET2));
result.Set("KEY_MACRO_PRESET3", Napi::Number::New(env, KEY_MACRO_PRESET3));

/*
* Some keyboards have a buildin LCD panel where the contents are controlled
* by the host. Often these have a number of keys directly below the LCD
* intended for controlling a menu shown on the LCD. These keys often don't
* have any labeling so we just name them KEY_KBD_LCD_MENU#
*/
result.Set("KEY_KBD_LCD_MENU1", Napi::Number::New(env, KEY_KBD_LCD_MENU1));
result.Set("KEY_KBD_LCD_MENU2", Napi::Number::New(env, KEY_KBD_LCD_MENU2));
result.Set("KEY_KBD_LCD_MENU3", Napi::Number::New(env, KEY_KBD_LCD_MENU3));
result.Set("KEY_KBD_LCD_MENU4", Napi::Number::New(env, KEY_KBD_LCD_MENU4));
result.Set("KEY_KBD_LCD_MENU5", Napi::Number::New(env, KEY_KBD_LCD_MENU5));

result.Set("BTN_TRIGGER_HAPPY", Napi::Number::New(env, BTN_TRIGGER_HAPPY));
result.Set("BTN_TRIGGER_HAPPY1", Napi::Number::New(env, BTN_TRIGGER_HAPPY1));
result.Set("BTN_TRIGGER_HAPPY2", Napi::Number::New(env, BTN_TRIGGER_HAPPY2));
result.Set("BTN_TRIGGER_HAPPY3", Napi::Number::New(env, BTN_TRIGGER_HAPPY3));
result.Set("BTN_TRIGGER_HAPPY4", Napi::Number::New(env, BTN_TRIGGER_HAPPY4));
result.Set("BTN_TRIGGER_HAPPY5", Napi::Number::New(env, BTN_TRIGGER_HAPPY5));
result.Set("BTN_TRIGGER_HAPPY6", Napi::Number::New(env, BTN_TRIGGER_HAPPY6));
result.Set("BTN_TRIGGER_HAPPY7", Napi::Number::New(env, BTN_TRIGGER_HAPPY7));
result.Set("BTN_TRIGGER_HAPPY8", Napi::Number::New(env, BTN_TRIGGER_HAPPY8));
result.Set("BTN_TRIGGER_HAPPY9", Napi::Number::New(env, BTN_TRIGGER_HAPPY9));
result.Set("BTN_TRIGGER_HAPPY10", Napi::Number::New(env, BTN_TRIGGER_HAPPY10));
result.Set("BTN_TRIGGER_HAPPY11", Napi::Number::New(env, BTN_TRIGGER_HAPPY11));
result.Set("BTN_TRIGGER_HAPPY12", Napi::Number::New(env, BTN_TRIGGER_HAPPY12));
result.Set("BTN_TRIGGER_HAPPY13", Napi::Number::New(env, BTN_TRIGGER_HAPPY13));
result.Set("BTN_TRIGGER_HAPPY14", Napi::Number::New(env, BTN_TRIGGER_HAPPY14));
result.Set("BTN_TRIGGER_HAPPY15", Napi::Number::New(env, BTN_TRIGGER_HAPPY15));
result.Set("BTN_TRIGGER_HAPPY16", Napi::Number::New(env, BTN_TRIGGER_HAPPY16));
result.Set("BTN_TRIGGER_HAPPY17", Napi::Number::New(env, BTN_TRIGGER_HAPPY17));
result.Set("BTN_TRIGGER_HAPPY18", Napi::Number::New(env, BTN_TRIGGER_HAPPY18));
result.Set("BTN_TRIGGER_HAPPY19", Napi::Number::New(env, BTN_TRIGGER_HAPPY19));
result.Set("BTN_TRIGGER_HAPPY20", Napi::Number::New(env, BTN_TRIGGER_HAPPY20));
result.Set("BTN_TRIGGER_HAPPY21", Napi::Number::New(env, BTN_TRIGGER_HAPPY21));
result.Set("BTN_TRIGGER_HAPPY22", Napi::Number::New(env, BTN_TRIGGER_HAPPY22));
result.Set("BTN_TRIGGER_HAPPY23", Napi::Number::New(env, BTN_TRIGGER_HAPPY23));
result.Set("BTN_TRIGGER_HAPPY24", Napi::Number::New(env, BTN_TRIGGER_HAPPY24));
result.Set("BTN_TRIGGER_HAPPY25", Napi::Number::New(env, BTN_TRIGGER_HAPPY25));
result.Set("BTN_TRIGGER_HAPPY26", Napi::Number::New(env, BTN_TRIGGER_HAPPY26));
result.Set("BTN_TRIGGER_HAPPY27", Napi::Number::New(env, BTN_TRIGGER_HAPPY27));
result.Set("BTN_TRIGGER_HAPPY28", Napi::Number::New(env, BTN_TRIGGER_HAPPY28));
result.Set("BTN_TRIGGER_HAPPY29", Napi::Number::New(env, BTN_TRIGGER_HAPPY29));
result.Set("BTN_TRIGGER_HAPPY30", Napi::Number::New(env, BTN_TRIGGER_HAPPY30));
result.Set("BTN_TRIGGER_HAPPY31", Napi::Number::New(env, BTN_TRIGGER_HAPPY31));
result.Set("BTN_TRIGGER_HAPPY32", Napi::Number::New(env, BTN_TRIGGER_HAPPY32));
result.Set("BTN_TRIGGER_HAPPY33", Napi::Number::New(env, BTN_TRIGGER_HAPPY33));
result.Set("BTN_TRIGGER_HAPPY34", Napi::Number::New(env, BTN_TRIGGER_HAPPY34));
result.Set("BTN_TRIGGER_HAPPY35", Napi::Number::New(env, BTN_TRIGGER_HAPPY35));
result.Set("BTN_TRIGGER_HAPPY36", Napi::Number::New(env, BTN_TRIGGER_HAPPY36));
result.Set("BTN_TRIGGER_HAPPY37", Napi::Number::New(env, BTN_TRIGGER_HAPPY37));
result.Set("BTN_TRIGGER_HAPPY38", Napi::Number::New(env, BTN_TRIGGER_HAPPY38));
result.Set("BTN_TRIGGER_HAPPY39", Napi::Number::New(env, BTN_TRIGGER_HAPPY39));
result.Set("BTN_TRIGGER_HAPPY40", Napi::Number::New(env, BTN_TRIGGER_HAPPY40));

/* We avoid low common keys in module aliases so they don't get huge. */
result.Set("KEY_MIN_INTERESTING", Napi::Number::New(env, KEY_MIN_INTERESTING));

/*
* Relative axes
*/

result.Set("REL_X", Napi::Number::New(env, REL_X));
result.Set("REL_Y", Napi::Number::New(env, REL_Y));
result.Set("REL_Z", Napi::Number::New(env, REL_Z));
result.Set("REL_RX", Napi::Number::New(env, REL_RX));
result.Set("REL_RY", Napi::Number::New(env, REL_RY));
result.Set("REL_RZ", Napi::Number::New(env, REL_RZ));
result.Set("REL_HWHEEL", Napi::Number::New(env, REL_HWHEEL));
result.Set("REL_DIAL", Napi::Number::New(env, REL_DIAL));
result.Set("REL_WHEEL", Napi::Number::New(env, REL_WHEEL));
result.Set("REL_MISC", Napi::Number::New(env, REL_MISC));
/*
*  is reserved and should not be used in input drivers.
* It was used by HID as REL_MISC+1 and userspace needs to detect if
* the next REL_* event is correct or is just REL_MISC + n.
* We define here REL_RESERVED so userspace can rely on it and detect
* the situation described above.
*/
result.Set("REL_RESERVED", Napi::Number::New(env, REL_RESERVED));
result.Set("REL_WHEEL_HI_RES", Napi::Number::New(env, REL_WHEEL_HI_RES));
result.Set("REL_HWHEEL_HI_RES", Napi::Number::New(env, REL_HWHEEL_HI_RES));

/*
* Absolute axes
*/

result.Set("ABS_X", Napi::Number::New(env, ABS_X));
result.Set("ABS_Y", Napi::Number::New(env, ABS_Y));
result.Set("ABS_Z", Napi::Number::New(env, ABS_Z));
result.Set("ABS_RX", Napi::Number::New(env, ABS_RX));
result.Set("ABS_RY", Napi::Number::New(env, ABS_RY));
result.Set("ABS_RZ", Napi::Number::New(env, ABS_RZ));
result.Set("ABS_THROTTLE", Napi::Number::New(env, ABS_THROTTLE));
result.Set("ABS_RUDDER", Napi::Number::New(env, ABS_RUDDER));
result.Set("ABS_WHEEL", Napi::Number::New(env, ABS_WHEEL));
result.Set("ABS_GAS", Napi::Number::New(env, ABS_GAS));
result.Set("ABS_BRAKE", Napi::Number::New(env, ABS_BRAKE));
result.Set("ABS_HAT0X", Napi::Number::New(env, ABS_HAT0X));
result.Set("ABS_HAT0Y", Napi::Number::New(env, ABS_HAT0Y));
result.Set("ABS_HAT1X", Napi::Number::New(env, ABS_HAT1X));
result.Set("ABS_HAT1Y", Napi::Number::New(env, ABS_HAT1Y));
result.Set("ABS_HAT2X", Napi::Number::New(env, ABS_HAT2X));
result.Set("ABS_HAT2Y", Napi::Number::New(env, ABS_HAT2Y));
result.Set("ABS_HAT3X", Napi::Number::New(env, ABS_HAT3X));
result.Set("ABS_HAT3Y", Napi::Number::New(env, ABS_HAT3Y));
result.Set("ABS_PRESSURE", Napi::Number::New(env, ABS_PRESSURE));
result.Set("ABS_DISTANCE", Napi::Number::New(env, ABS_DISTANCE));
result.Set("ABS_TILT_X", Napi::Number::New(env, ABS_TILT_X));
result.Set("ABS_TILT_Y", Napi::Number::New(env, ABS_TILT_Y));
result.Set("ABS_TOOL_WIDTH", Napi::Number::New(env, ABS_TOOL_WIDTH));

result.Set("ABS_VOLUME", Napi::Number::New(env, ABS_VOLUME));
// result.Set("ABS_PROFILE", Napi::Number::New(env, ABS_PROFILE));

result.Set("ABS_MISC", Napi::Number::New(env, ABS_MISC));

/*
*  is reserved and should not be used in input drivers.
* It was used by HID as ABS_MISC+6 and userspace needs to detect if
* the next ABS_* event is correct or is just ABS_MISC + n.
* We define here ABS_RESERVED so userspace can rely on it and detect
* the situation described above.
*/
result.Set("ABS_RESERVED", Napi::Number::New(env, ABS_RESERVED));

result.Set("ABS_MT_SLOT", Napi::Number::New(env, ABS_MT_SLOT)); /* MT slot being modified */
result.Set("ABS_MT_TOUCH_MAJOR", Napi::Number::New(env, ABS_MT_TOUCH_MAJOR)); /* Major axis of touching ellipse */
result.Set("ABS_MT_TOUCH_MINOR", Napi::Number::New(env, ABS_MT_TOUCH_MINOR)); /* Minor axis (omit if circular) */
result.Set("ABS_MT_WIDTH_MAJOR", Napi::Number::New(env, ABS_MT_WIDTH_MAJOR)); /* Major axis of approaching ellipse */
result.Set("ABS_MT_WIDTH_MINOR", Napi::Number::New(env, ABS_MT_WIDTH_MINOR)); /* Minor axis (omit if circular) */
result.Set("ABS_MT_ORIENTATION", Napi::Number::New(env, ABS_MT_ORIENTATION)); /* Ellipse orientation */
result.Set("ABS_MT_POSITION_X", Napi::Number::New(env, ABS_MT_POSITION_X)); /* Center X touch position */
result.Set("ABS_MT_POSITION_Y", Napi::Number::New(env, ABS_MT_POSITION_Y)); /* Center Y touch position */
result.Set("ABS_MT_TOOL_TYPE", Napi::Number::New(env, ABS_MT_TOOL_TYPE)); /* Type of touching device */
result.Set("ABS_MT_BLOB_ID", Napi::Number::New(env, ABS_MT_BLOB_ID)); /* Group a set of packets as a blob */
result.Set("ABS_MT_TRACKING_ID", Napi::Number::New(env, ABS_MT_TRACKING_ID)); /* Unique ID of initiated contact */
result.Set("ABS_MT_PRESSURE", Napi::Number::New(env, ABS_MT_PRESSURE)); /* Pressure on contact area */
result.Set("ABS_MT_DISTANCE", Napi::Number::New(env, ABS_MT_DISTANCE)); /* Contact hover distance */
result.Set("ABS_MT_TOOL_X", Napi::Number::New(env, ABS_MT_TOOL_X)); /* Center X tool position */
result.Set("ABS_MT_TOOL_Y", Napi::Number::New(env, ABS_MT_TOOL_Y)); /* Center Y tool position */

/*
* Switch events
*/

result.Set("SW_LID", Napi::Number::New(env, SW_LID));   /* set = lid shut */
result.Set("SW_TABLET_MODE", Napi::Number::New(env, SW_TABLET_MODE));   /* set = tablet mode */
result.Set("SW_HEADPHONE_INSERT", Napi::Number::New(env, SW_HEADPHONE_INSERT));   /* set = inserted */
result.Set("SW_RFKILL_ALL", Napi::Number::New(env, SW_RFKILL_ALL));   /* rfkill master switch, type "any"
;  = radio enabled */
result.Set("SW_RADIO", Napi::Number::New(env, SW_RADIO)); /* deprecated */
result.Set("SW_MICROPHONE_INSERT", Napi::Number::New(env, SW_MICROPHONE_INSERT));   /* set = inserted */
result.Set("SW_DOCK", Napi::Number::New(env, SW_DOCK));   /* set = plugged into dock */
result.Set("SW_LINEOUT_INSERT", Napi::Number::New(env, SW_LINEOUT_INSERT));   /* set = inserted */
result.Set("SW_JACK_PHYSICAL_INSERT", Napi::Number::New(env, SW_JACK_PHYSICAL_INSERT));   /* set = mechanical switch set */
result.Set("SW_VIDEOOUT_INSERT", Napi::Number::New(env, SW_VIDEOOUT_INSERT));   /* set = inserted */
result.Set("SW_CAMERA_LENS_COVER", Napi::Number::New(env, SW_CAMERA_LENS_COVER));   /* set = lens covered */
result.Set("SW_KEYPAD_SLIDE", Napi::Number::New(env, SW_KEYPAD_SLIDE));   /* set = keypad slide out */
result.Set("SW_FRONT_PROXIMITY", Napi::Number::New(env, SW_FRONT_PROXIMITY));   /* set = front proximity sensor active */
result.Set("SW_ROTATE_LOCK", Napi::Number::New(env, SW_ROTATE_LOCK));   /* set = rotate locked/disabled */
result.Set("SW_LINEIN_INSERT", Napi::Number::New(env, SW_LINEIN_INSERT));   /* set = inserted */
result.Set("SW_MUTE_DEVICE", Napi::Number::New(env, SW_MUTE_DEVICE));   /* set = device disabled */
result.Set("SW_PEN_INSERTED", Napi::Number::New(env, SW_PEN_INSERTED));   /* set = pen inserted */
result.Set("SW_MACHINE_COVER", Napi::Number::New(env, SW_MACHINE_COVER));   /* set = cover closed */

/*
* Misc events
*/

result.Set("MSC_SERIAL", Napi::Number::New(env, MSC_SERIAL));
result.Set("MSC_PULSELED", Napi::Number::New(env, MSC_PULSELED));
result.Set("MSC_GESTURE", Napi::Number::New(env, MSC_GESTURE));
result.Set("MSC_RAW", Napi::Number::New(env, MSC_RAW));
result.Set("MSC_SCAN", Napi::Number::New(env, MSC_SCAN));
result.Set("MSC_TIMESTAMP", Napi::Number::New(env, MSC_TIMESTAMP));

/*
* LEDs
*/

result.Set("LED_NUML", Napi::Number::New(env, LED_NUML));
result.Set("LED_CAPSL", Napi::Number::New(env, LED_CAPSL));
result.Set("LED_SCROLLL", Napi::Number::New(env, LED_SCROLLL));
result.Set("LED_COMPOSE", Napi::Number::New(env, LED_COMPOSE));
result.Set("LED_KANA", Napi::Number::New(env, LED_KANA));
result.Set("LED_SLEEP", Napi::Number::New(env, LED_SLEEP));
result.Set("LED_SUSPEND", Napi::Number::New(env, LED_SUSPEND));
result.Set("LED_MUTE", Napi::Number::New(env, LED_MUTE));
result.Set("LED_MISC", Napi::Number::New(env, LED_MISC));
result.Set("LED_MAIL", Napi::Number::New(env, LED_MAIL));
result.Set("LED_CHARGING", Napi::Number::New(env, LED_CHARGING));

/*
* Autorepeat values
*/

result.Set("REP_DELAY", Napi::Number::New(env, REP_DELAY));
result.Set("REP_PERIOD", Napi::Number::New(env, REP_PERIOD));

/*
* Sounds
*/

result.Set("SND_CLICK", Napi::Number::New(env, SND_CLICK));
result.Set("SND_BELL", Napi::Number::New(env, SND_BELL));
result.Set("SND_TONE", Napi::Number::New(env, SND_TONE));

return result;
}
