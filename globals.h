#pragma once

enum KEYS {W, S, A, D, SPACE, F3};
bool keys[] = {false, false, false, false, false, false};

bool wPressed = false;
bool sPressed = false;
bool aPressed = false;
bool dPressed = false;
bool spacePressed = false;

enum SCREENSTATE {TITLESCREEN, GAMESCREEN, HELPSCREEN, OPTIONSCREEN, MENUSCREEN};
bool screenState[] = {false, false, false, false, false};

int mouseX = 0;
int mouseY = 0;

int counter255r = 35;
int counter255g = 10;
int counter255b = 55;
int counter185r = 35;
int counter185g = 10;
int counter185b = 55;
int counterHelp185r = 35;
int counterHelp185g = 10;
int counterHelp185b = 55;
int counterHelp255r = 35;
int counterHelp255g = 10;
int counterHelp255b = 55;
int counterGame185r = 35;
int counterGame185g = 10;
int counterGame185b = 55;
