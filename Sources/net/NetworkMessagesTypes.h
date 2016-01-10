#pragma once

namespace MessageType
{
    // MESSAGES TO SERVER FROM CLIENT:
    const int INITAL_LOGIN_MESSAGE = 1;
    const int EXIT_CLIENT = 2;

    // MESSAGES TO CLIENT FROM SERVER:

    // ERROR MESSAGES:
    const int WRONG_GAME_VERSION = 401;
    const int WRONG_AUTHENTICATION = 402;
    const int UNDEFINED_ERROR = 403;
    const int EXIT_SERVER = 404;

    // NON ERROR MESSAGES:
    const int SUCCESS_CONNECTION = 201;
    const int MAP_UPLOAD = 202;
    const int NEW_TICK = 203;
    const int NEW_CLIENT = 204;

    // GAME MESSAGES
    const int ORDINARY = 1001;
    const int MESSAGE = 1002;

    const int MOUSE_CLICK = 1004;

    const int HASH = 1101;
    const int PING = 1102;
}