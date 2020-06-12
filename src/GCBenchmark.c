#include <stdio.h>
#include <stdlib.h>


#define push(sp, n) (*((sp)++) = (n))
#define pop(sp) (*--(sp))
#define peek(sp) (*(sp))
#define stackSize(sp, stack) ((sp)-(stack))


const int HEIGHT = 2;
const int SIZE_REGION = 200000;


static struct Tree** regions;
static int currRegion = 0;
static int indFree = 0;
static struct Tree** stack;
static struct Tree** sp;


struct Tree {
    struct Tree* left;
    struct Tree* right;
    int vals[4];
};


struct Tree* allocateNode() {
    if (indFree == SIZE_REGION) {
        ++currRegion;
        indFree = 0;
    }
    struct Tree* region = regions[currRegion];
    struct Tree* result = &region[indFree];
    region[indFree++] = (struct Tree) { .left = NULL, .right = NULL, .vals = { 1, 2, -1, -1 } };
    printf("allocating a node...\n");
    return result;
}


struct Tree* createLeftTree(int height) {
    printf("createLeftTree %d\n", height);
    struct Tree* wholeTree = allocateNode();
    push(sp, wholeTree);
    for (int i = 1; i < height; ++i) {
        struct Tree* newTree = allocateNode();
        push(sp, newTree);
    }
    return wholeTree;
}


/*
val stack = Stack<Loc>()

            var bottomElement = stack.peek()
            if (bottomElement.arr[bottomElement.ind + 1] > -1 || stack.count() == height) {
                stack.pop()
                while (stack.any()) {
                    bottomElement = stack.peek()
                    if (bottomElement.arr[bottomElement.ind + 1] == -1) break
                    stack.pop()
                }
            }
            if (stack.any() ) {
                bottomElement = stack.peek()
                bottomElement.arr[bottomElement.ind + 1] = createLeftTree(height - stack.count(), payload, stack)
            }
        
*/


struct Tree* createTree() {
    // The stack
    stack = malloc(HEIGHT * sizeof(struct Tree*));
    sp = stack;
    struct Tree* wholeTree = createLeftTree(HEIGHT);
    
    while (sp > stack) {
        printf("sp > stack\n");
        struct Tree* bottomElement = peek(sp);
        printf("stack size is %d\n", stackSize(sp, stack));
        if (stackSize(sp, stack) == HEIGHT || bottomElement->right != NULL) {
            printf("popping from stack \n");
            pop(sp);
            printf("stack size is %d\n", stackSize(sp, stack));
            while (stackSize(sp, stack) > 0) {
                bottomElement = peek(sp);
                if (bottomElement->right == NULL) break;
                printf("popping from stack \n");
                pop(sp);
            }
        }
        if (sp > stack) {
            bottomElement = peek(sp);
            bottomElement->right = createLeftTree(HEIGHT - stackSize(sp, stack));
        }
    }
    printf("end of createTree \n");
    return wholeTree;
    
}


int main(int argc, char** argv) {
    int numRegions = HEIGHT/SIZE_REGION + 1;
    printf("numRegions = %d\n", numRegions);

    regions = (struct Tree**)malloc(numRegions * sizeof(struct Tree*));
    for (int i = 0; i < numRegions; ++i) {
        regions[i] = (struct Tree*)malloc(SIZE_REGION * sizeof(struct Tree));
    }

    //regions[0][0] = (struct Tree) { .left = NULL, .right = NULL, .vals = {1, 2, -1, -1} };

    printf("Processing tree with Regions...\n");
    createTree();

    return 0;
}

