#ifndef GOTTI_H_INCLUDED
#define GOTTI_H_INCLUDED

#include "Elements.h"
#include "Board.h"

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

const float pieceVertices[7][100][2] =	{	// For 7 pieces
                                        {//For Rook
                                            {25, 10}, {25, 20}, {30, 20}, {50, 20}, {55, 20}, {55, 10}, {50, 25}, {30, 25}, {47, 45}, {53, 45},
                                            {53, 55}, {49, 55}, {49, 51}, {44, 51}, {44, 55}, {36, 55}, {36, 51}, {31, 51}, {31, 55}, {27, 55},
                                            {27, 45}, {33, 45}
                                        },

                                        {//For Pawn
                                            {25, 10}, {25, 13}, {27, 13}, {35, 20}, {35, 40}, {32, 40}, {32, 42}, {35, 42}, {33, 47}, {35, 52},
                                            {45, 52}, {47, 47}, {45, 42}, {48, 42}, {48, 40}, {45, 40}, {45, 20}, {53, 13}, {55, 13}, {55, 10}
                                        },

                                        {//For Knight
                                            {23, 10}, {23, 17}, {25, 17}, {28, 20}, {30, 20}, {38, 40}, {34, 43}, {28, 38}, {25, 40}, {30, 45},
                                            {22, 42}, {39, 63}, {41, 65}, {56, 49}, {46, 30}, {51, 20}, {53, 20}, {55, 17}, {57, 17}, {57, 10},
                                            {37, 52}, {39, 54}, {41, 52}, {39, 50}, {45,57}
                                        },

                                        {//For Bishop
                                            {25, 10}, {25, 17}, {30, 20}, {50, 20}, {55, 17}, {55, 10}, {47, 25}, {33, 25}, {45, 50}, {35, 50},
                                            {45, 51}, {35, 51}, {37, 53}, {34, 58}, {36, 60}, {35, 63}, {40, 69}, {45, 63}, {44, 60}, {46, 58},
                                            {43, 53}
                                        },

                                        {//For King
                                            {25, 7}, {25, 13}, {28, 13}, {33, 17}, {47, 17}, {52, 13}, {55, 13}, {55, 7}, {30, 22}, {32, 22},
                                            {48, 22}, {50, 22}, {32, 52}, {28, 52}, {28, 60}, {32, 60}, {32, 65}, {38, 65}, {38, 68}, {31, 68},
                                            {31, 73}, {38, 73}, {38, 76}, {42, 76}, {42, 73}, {49, 73}, {49, 68}, {42, 68}, {42, 65}, {48, 65},
                                            {48, 60}, {52, 60}, {52, 52}, {48, 52}
                                        },

                                        {//For Queen
                                            {55, 7}, {25, 7}, {27, 12}, {53, 12}, {55, 15}, {25, 15}, {32, 22}, {32, 41}, {28, 41}, {28, 45},
                                            {32, 45}, {32, 48}, {28, 48}, {28, 52}, {32, 52}, {32, 55}, {28, 60}, {28, 70}, {32, 70}, {32, 65},
                                            {35, 65}, {35, 70}, {39, 70}, {39, 65}, {42, 65}, {42, 70}, /* One missing point added to last*/ {46, 65}, {48, 65}, {48, 70}, {52, 70},
                                            {52, 60}, {48, 55}, {48, 52}, {52, 52}, {52, 48}, {48, 48}, {48, 45}, {52, 45}, {52, 41}, {48, 41}, {48, 22},
                                            {46, 70}
                                        }
                                    };
const int pieceTriangleIndices[7][50][3]={
                                        {//For Rook
                                            {0 ,1 ,4}, {0 ,4 ,5}, {2 ,7 ,6}, {2 ,6 ,3}, {7 ,21 ,8}, {7 ,8 ,6}, {20 ,19 ,18}, {20 ,18 ,17},
                                            {20 ,17 ,9}, {17 ,12 ,9}, {12 ,11 ,9}, {11 ,10 ,9}, {16 ,15 ,13}, {15 ,14 ,13}
                                        },

                                        {//For pawn
                                            {0 ,1 ,19}, {1 ,18 ,19}, {2 ,3 ,17}, {3 ,16 ,17}, {3 ,4 ,15}, {3 ,15 ,16}, {5 ,13 ,14}, {5 ,6 ,13},
                                            {7 ,11 ,12}, {7 ,10 ,11}, {7 ,9 ,10}, {7 ,8 ,9}
                                        },

                                        {//For Knight
                                            {0 ,1 ,18}, {0 ,18 ,19}, {2 ,3 ,17}, {3 ,16 ,17}, {4 ,14 ,15}, {4 ,5 ,14}, {5 ,13 ,14}, {5 ,6 ,13},
                                            {6 ,7 ,8}, {6 ,8 ,10}, {6 ,10 ,11}, {6 ,11 ,13}, {13, 11 ,12}//, {20, 21, 22}, {20, 22, 23}
                                        },

                                        {//For Bishop
                                            {0 ,1 ,2}, {0,2 , 5}, {2 ,4 , 5}, {2 ,3 ,4}, {2 ,7 ,3}, {3 ,7 ,6}, {7 ,9 ,8}, {7, 8, 6}, {9 ,11,8},
                                            {11,10,8}, {11,12,10}, {12,20 ,10}, {12,13 ,20}, {13, 19 ,20},  {13, 14, 19}, {14 ,18 ,19}, {14 ,15, 18},
                                            {15,17,18}, {15,16,17}
                                        },

                                        {//For King
                                            {0 ,1 ,7}, {1, 6 , 7}, {2 ,3 , 5}, {3 ,4 ,5}, {3 ,8 ,4}, {8 ,11 ,4}, {9 ,12 ,10}, {12, 33, 10}, {13 ,31,32},
                                            {13,14,31}, {15,16,30}, {16,29 ,30}, {17,22 ,28}, {22, 23 ,28},  {19, 20, 26}, {20 ,25 ,26}
                                        },

                                        {//For Queen
                                            {0 ,1 ,2}, {2, 3 , 0}, {2 ,4 , 3}, {2 ,5 ,4}, {5 ,6 ,4}, {6 ,40 ,4}, {6 ,7 ,40}, {7, 39, 40}, {8 ,37,38},
                                            {8,9,37}, {10,11,36}, {11,35 ,36}, {12,33 ,34}, {12, 13 ,33},  {14, 15, 32}, {15 ,31 ,32}, {15 ,16 ,31},
                                            {16, 30 , 31}, {16 ,19 , 30}, {16 ,17 ,19}, {17 ,18 ,19}, {19 ,27 ,30}, {20 ,21 ,23}, {21, 22, 23},
                                            {24 ,25,26}, {25,41,26}, {30,27,29}, {27,28 ,29}

                                        }
                                    };

const int pieceLineIndices[7][50][2] = 	{
                                        {0,1,1,4,4,5,5,0,2,7,7,6,6,3,7,21,6,8,20,9,20,19,19,18,18,17,17,16,16,15,15,14,14,13,13,12,12,11,11,10,10,9},

                                        {0,1,1,2,2,3,3,16,16,17,17,18,18,19,19,0,3,4,16,15,5,14,5,6,6,13,13,14,7,8,8,9,9,10,10,11,11,12},

                                        {0,1,1,18,18,19,19,0,2,3,3,16,16,17,4,5,5,6,6,7,7,8,8,9,8,10,10,11,11,24,11,12,12,13,13,14,14,15,20,21,21,22,22,23,23,20},

                                        {0,5,0,1,1,2,2,3,3,4,4,5,2,7,7,6,6,3,7,9,9,8,8,6,9,11,8,10,10,20,20,19,19,18,18,17,17,16,16,15,15,14,14,13,13,12,12,11},

                                        {0,1,1,2,2,3,3,4,4,5,5,6,6,7,7,0,3,8,8,11,11,4,9,12,12,33,33,10,13,14,14,31,31,32,32,13,15,16,16,29,29,30,17,18,22,23,23,24,21,22,23,24,18,19,19,20,20,21,24,25,25,26,26,27, 27, 28},

                                        {0,1,1,2,2,3,3,0,3,4,4,5,5,2,5,6,4,40,6,7,39,40,8,38,8,9,9,37,37,38,10,11,35,36,12,13,13,33,33,34,34,12,14,15,15,31,31,32,15,16,16,30,30,31,16,17,17,18,18,19,19,20,20,21,21,22,22,23,23,24,24,25,25,41,41,26,26,27,27,28,28,29,29,30}
                                    };
const int numberOfTriangles[7]={14, 12, 13, 19, 16, 28};
const int numberOfLines[7]={21, 19, 23, 24, 33,42};

const float pieceColor3f[2][3] = {{1.0, 1.0, 1.0}, {0.0, 0.0, 0.0}};

class gottiSet{
public:
    gottiSet();
    static float pieceBorderWidth;
    static piece BW[33];
    static void initPieces();
};


#endif // GOTTI_H_INCLUDED
