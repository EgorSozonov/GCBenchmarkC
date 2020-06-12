#include <stdio.h>
#include <stdlib.h>


#define push(sp, n) (*((sp)++) = (n))
#define pop(sp) (*--(sp))
#define peek(sp) (*(sp))
#define stackSize(sp, stack) ((sp)-(stack))

const int HEIGHT = 2;
const int SIZE_REGION = 200000;

struct Tree {
    struct Tree* left;
    struct Tree* right;
    int vals[4];
};


struct Tree* createLeftTree(int payload[4], struct Tree** stck) {
    return NULL;
}

struct Tree* createTree(int payload[4]) {
    // The stack
    struct Tree** stack = malloc(HEIGHT * sizeof(struct Tree*));
    struct Tree** sp = stack;
    struct Tree* wholeTree = createLeftTree(payload, sp);
    printf("stack size is %d", stackSize(sp, stack));
    while (sp > stack) {
        //struct Tree* bottomElement = peek(sp);
        //if (stackSize(sp, stack) == HEIGHT)
    }
    return wholeTree;
    
}





int main(int argc, char** argv) {
    int numRegions = HEIGHT/SIZE_REGION + 1;
    printf("numRegions = %d", numRegions);
    struct Tree** regions = (struct Tree**)malloc(numRegions * sizeof(struct Tree*));
    for (int i = 0; i < numRegions; ++i) {
        regions[i] = (struct Tree*)malloc(SIZE_REGION * sizeof(struct Tree));
    }
    regions[0][0] = (struct Tree) { .left = NULL, .right = NULL, .vals = {1, 2, -1, -1} };

    printf("Processing tree with Regions...");




    return 0;
}

