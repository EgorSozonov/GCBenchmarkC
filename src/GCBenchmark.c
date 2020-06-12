#include <stdio.h>
#include <stdlib.h>


#define push(sp, n) (*((sp)++) = (n))
#define pop(sp) (*--(sp))
#define peek(sp) (*(sp))

const int HEIGHT = 2;
const int SIZE_REGION = 200000;

struct Tree {
    struct Tree* left;
    struct Tree* right;
    int vals[4];
};



void createTree(int payload[4]) {
    // The stack
    struct Tree* stack[] = malloc(HEIGHT * sizeof(struct Tree*));
    struct Tree** sp = stack;

    struct Tree* wholeTree = createLeftTree(payload, sp);
}

Tree* createLeftTree(payload, stck) {
    return null;
}

fun createTree(payload: Array<Int>) {
    if (height <= 0) return;
    val stack = Stack<Loc>()
    val wholeTree = createLeftTree(height, payload, stack)
    while (stack.any()) {
        var bottomElement = stack.peek()
            if (bottomElement.arr[bottomElement.ind + 1] > -1 || stack.count() == height) {
                stack.pop()
                    while (stack.any()) {
                        bottomElement = stack.peek()
                            if (bottomElement.arr[bottomElement.ind + 1] == -1) break
                                stack.pop()
                    }
            }
        if (stack.any()) {
            bottomElement = stack.peek()
                bottomElement.arr[bottomElement.ind + 1] = createLeftTree(height - stack.count(), payload, stack)
        }
    }
}


class Loc(val arr : Array<Int>, val ind : Int) {}


fun createLeftTree(height : Int, payload : Array<Int>, stack : Stack<Loc>) : Int {
    if (height == 0) return -1

        val wholeTree = allocateNode(payload)
        var currTree : Loc = toLoc(wholeTree)
        stack.push(currTree)
        for (i : Int in 1 until height) {
            val newTree = allocateNode(payload)
                currTree.arr[currTree.ind] = newTree
                currTree = toLoc(newTree)
                stack.push(currTree)
        }
    return wholeTree
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

